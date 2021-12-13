    Info<< "Reading thermophysical properties\n" << endl;

    Info<< "Reading field D\n" << endl;
    volScalarField D
    (
        IOobject
        (
            "D",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

/* 
		IOobject::AUTO_WRITE
			),
			mesh,
			dimensionedScalar("rhoprime_uprime",dimensionSet(1,-2,-1,0,0,0,0), 0.0)
	); 

	volScalarField rhoprime_vprime
	(
		IOobject
			(
				"rhoprime_vprime",
				runTime.timeName(),
				mesh,
				IOobject::READ_I

*/


    Info<< "Reading field p_rgh\n" << endl;
    volScalarField p_rgh
    (
        IOobject
        (
            "p_rgh",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

    Info<< "Reading field U\n" << endl;
    volVectorField U
    (
        IOobject
        (
            "U",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

/*
volVectorField umean
    (
        IOobject
        (
            "umean",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::AUTO_WRITE

        ),
        mesh,
		dimensionedVector
      		(
           		"umean",
           		U.dimensions(), // Or Umean.dimensions()
           		vector (0,0,0)
      		)

    );

volVectorField Ufluc
(
     IOobject
     (
         "Ufluc",
         runTime.timeName(),
         mesh,
           IOobject::NO_READ,
         IOobject::AUTO_WRITE
     ),
     mesh,
       dimensionedVector
      (
           "zero",
           U.dimensions(), // Or Umean.dimensions()
           vector (0,0,0)
      )
 );

volScalarField uprime
	(
		IOobject
			(
				"uprime",
				runTime.timeName(),
				mesh,
				IOobject::READ_IF_PRESENT,
				IOobject::AUTO_WRITE
			),
			mesh,
			dimensionedScalar("uprime", U.dimensions(), 0.0)
	); 


volScalarField vprime
	(
		IOobject
			(
				"vprime",
				runTime.timeName(),
				mesh,
				IOobject::READ_IF_PRESENT,
				IOobject::AUTO_WRITE
			),
			mesh,
			dimensionedScalar("vprime", U.dimensions(), 0.0)
	); 

volScalarField wprime
	(
		IOobject
			(
				"wprime",
				runTime.timeName(),
				mesh,
				IOobject::READ_IF_PRESENT,
				IOobject::AUTO_WRITE
			),
			mesh,
			dimensionedScalar("wprime", U.dimensions(), 0.0)
	); 


volScalarField uprime2
	(
		IOobject
			(
				"uprime2",
				runTime.timeName(),
				mesh,
				IOobject::READ_IF_PRESENT,
				IOobject::AUTO_WRITE
			),
			mesh,
			dimensionedScalar("uprime2", dimensionSet(0,2,-2,0,0,0,0), 0.0)
	); 


volScalarField vprime2
	(
		IOobject
			(
				"vprime2",
				runTime.timeName(),
				mesh,
				IOobject::READ_IF_PRESENT,
				IOobject::AUTO_WRITE
			),
			mesh,
			dimensionedScalar("vprime2", dimensionSet(0,2,-2,0,0,0,0), 0.0)
	); 

volScalarField wprime2
	(
		IOobject
			(
				"wprime2",
				runTime.timeName(),
				mesh,
				IOobject::READ_IF_PRESENT,
				IOobject::AUTO_WRITE
			),
			mesh,
			dimensionedScalar("wprime2", dimensionSet(0,2,-2,0,0,0,0), 0.0)
	); 

volScalarField uprime2mean
	(
		IOobject
			(
				"uprime2mean",
				runTime.timeName(),
				mesh,
				IOobject::READ_IF_PRESENT,
				IOobject::AUTO_WRITE
			),
			mesh,
			dimensionedScalar("uprime2mean", dimensionSet(0,2,-2,0,0,0,0), 0.0)
	); 


volScalarField vprime2mean
	(
		IOobject
			(
				"vprime2mean",
				runTime.timeName(),
				mesh,
				IOobject::READ_IF_PRESENT,
				IOobject::AUTO_WRITE
			),
			mesh,
			dimensionedScalar("vprime2mean", dimensionSet(0,2,-2,0,0,0,0), 0.0)
	); 

volScalarField wprime2mean
	(
		IOobject
			(
				"wprime2mean",
				runTime.timeName(),
				mesh,
				IOobject::READ_IF_PRESENT,
				IOobject::AUTO_WRITE
			),
			mesh,
			dimensionedScalar("wprime2mean", dimensionSet(0,2,-2,0,0,0,0), 0.0)
	); 


volScalarField Tke
	(
		IOobject
			(
				"Tke",
				runTime.timeName(),
				mesh,
				IOobject::READ_IF_PRESENT,
				IOobject::AUTO_WRITE
			),
			mesh,
			dimensionedScalar("Tke", dimensionSet(0,2,-2,0,0,0,0), 0.0)
	);

volScalarField kuprime
	(
		IOobject
			(
				"kuprime",
				runTime.timeName(),
				mesh,
				IOobject::READ_IF_PRESENT,
				IOobject::AUTO_WRITE
			),
			mesh,
			dimensionedScalar("kuprime", dimensionSet(0,3,-3,0,0,0,0), 0.0)
	);

volScalarField kvprime
	(
		IOobject
			(
				"kvprime",
				runTime.timeName(),
				mesh,
				IOobject::READ_IF_PRESENT,
				IOobject::AUTO_WRITE
			),
			mesh,
			dimensionedScalar("kvprime", dimensionSet(0,3,-3,0,0,0,0), 0.0)
	);

volScalarField kwprime
	(
		IOobject
			(
				"kwprime",
				runTime.timeName(),
				mesh,
				IOobject::READ_IF_PRESENT,
				IOobject::AUTO_WRITE
			),
			mesh,
			dimensionedScalar("kwprime", dimensionSet(0,3,-3,0,0,0,0), 0.0)
	);


volScalarField kuprimeMean
	(
		IOobject
			(
				"kuprimeMean",
				runTime.timeName(),
				mesh,
				IOobject::READ_IF_PRESENT,
				IOobject::AUTO_WRITE
			),
			mesh,
			dimensionedScalar("kuprimeMean", dimensionSet(0,3,-3,0,0,0,0), 0.0)
	);

volScalarField kvprimeMean
	(
		IOobject
			(
				"kvprimeMean",
				runTime.timeName(),
				mesh,
				IOobject:

volScalarField kwprimeMean
	(
		IOobject
			(
				"kwprimeMean",
				runTime.timeName(),
				mesh,
				IOobject::READ_IF_PRESENT,
				IOobject::AUTO_WRITE
			),
			mesh,
			dimensionedScalar("kwprimeMean", dimensionSet(0,3,-3,0,0,0,0), 0.0)
	);



volScalarField uPrimeVprimeMean
	(
		IOobject
			(
				"uPrimeVprimeMean",
				runTime.timeName(),
				mesh,
				IOobject::READ_IF_PRESENT,
				IOobject::AUTO_WRITE
			),
			mesh,
			dimensionedScalar("uPrimeVprimeMean", dimensionSet(0,2,-2,0,0,0,0), 0.0)
	);

volScalarField uPrimeWprimeMean
	(
		IOobject
			(
				"uPrimeWp
*/

    #include "createPhi.H"

    #include "readTransportProperties.H"

    Info<< "Creating turbulence model\n" << endl;
    autoPtr<incompressible::turbulenceModel> turbulence
    (
       incompressible::turbulenceModel::New(U, phi, laminarTransport)
    );


    // Kinematic density for buoyancy force
    volScalarField rhok
    (
        IOobject
        (
            "rhok",
            runTime.timeName(),
            mesh
        ),
        1.0 - beta*(D - DRef)
    );

    // kinematic turbulent thermal thermal conductivity m2/s
    Info<< "Reading field alphat\n" << endl;
    volScalarField alphat
    (
        IOobject
        (
            "alphat",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

    Info<< "Calculating field g.h\n" << endl;
    volScalarField gh("gh", g & mesh.C());
    surfaceScalarField ghf("ghf", g & mesh.Cf());

    volScalarField p
    (
        IOobject
        (
            "p",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::AUTO_WRITE
        ),
        p_rgh + rhok*gh
    );

    label pRefCell = 0;
    scalar pRefValue = 0.0;
    setRefCell
    (
        p,
        p_rgh,
        mesh.solutionDict().subDict("PIMPLE"),
        pRefCell,
        pRefValue
    );

    if (p_rgh.needReference())
    {
        p += dimensionedScalar
        (
            "p",
            p.dimensions(),
            pRefValue - getRefCellValue(p, pRefCell)
        );
    }

