    singlePhaseTransportModel laminarTransport(U, phi);

    // Thermal expansion coefficient [m3/Kg]
    dimensionedScalar beta(laminarTransport.lookup("beta"));

    // Reference density [Kg/m3]
    dimensionedScalar DRef(laminarTransport.lookup("DRef"));

    // Laminar Schmidt number
    dimensionedScalar Sc(laminarTransport.lookup("Sc"));

    // Turbulent Schmidt number
    dimensionedScalar Sct(laminarTransport.lookup("Sct"));
