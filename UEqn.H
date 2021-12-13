    // Solve the momentum equation

    fvVectorMatrix UEqn
    (
        fvm::ddt(U)
      + fvm::div(phi, U)
      + turbulence->divDevReff(U)
     ==
        fvOptions(U)
    );

    UEqn.relax();

    fvOptions.constrain(UEqn);

    if (pimple.momentumPredictor())
    {
        solve
        (
            UEqn
         ==
            fvc::reconstruct
            (
                (
                    -fvc::interpolate(rhok)*(g & mesh.Sf())
                   - fvc::snGrad(p_rgh)*mesh.magSf()
                )
            )
        );

        fvOptions.correct(U);
    }
