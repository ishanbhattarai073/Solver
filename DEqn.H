{
    alphat = turbulence->nut()/Sct;
    alphat.correctBoundaryConditions();

    volScalarField alphaEff("alphaEff", turbulence->nu()/Sc + alphat);

    fvScalarMatrix DEqn
    (
        fvm::ddt(D)
      + fvm::div(phi, D)
      - fvm::laplacian(alphaEff, D)
     ==
        //radiation->ST(rhoCpRef, D)
       fvOptions(D)
    );

    DEqn.relax();

    fvOptions.constrain(DEqn);

    DEqn.solve();

    //radiation->correct();

    fvOptions.correct(D);

    rhok = 1.0 - beta*(D - DRef);
}
