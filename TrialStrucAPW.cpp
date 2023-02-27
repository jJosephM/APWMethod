#include <vector>
#include <cmath>

// Define structs for atomic system
struct Atom {
    double x, y, z; // Coordinates of atom
    double charge; // Charge of atom
};

struct WaveFunction {
    double a; // Lattice constant
    double kx, ky, kz; // Wavevector
    int l, m; // Angular momentum quantum numbers
};

struct APW {
    Atom atom; // Atom at center of sphere
    double R; // Radius of sphere
    std::vector<WaveFunction> wave_functions; // Vector of wave functions for each l, m
};

// Calculate energy eigenvalues and eigenvectors for given APW
void calculate_APW_energy(APW apw, double E_min, double E_max, double delta_E) {
    // Define constants
    const double pi = 3.14159265358979323846;
    const double hbar = 1.054571817e-34; // Planck's constant divided by 2pi, in Joule seconds
    const double m_e = 9.10938356e-31; // Mass of electron, in kg
    const double e = 1.602176634e-19; // Elementary charge, in Coulombs

    // Loop over energy range
    for (double E = E_min; E <= E_max; E += delta_E) {
        // Calculate k vector magnitude
        double k_mag = std::sqrt(2.0 * m_e * (E - apw.atom.charge * e) / hbar / hbar);

        // Loop over wave functions
        for (auto& wf : apw.wave_functions) {
            // Calculate radial function R_l(k*r)
            double R_l = std::pow(apw.R, wf.l + 1) / std::pow(k_mag, wf.l + 2);
            // Calculate spherical harmonic Y_lm(theta, phi)
            double Y_lm = std::sqrt((2 * wf.l + 1) / (4 * pi)) * std::assoc_legendre(wf.l, wf.m, std::cos(theta)) * std::exp(std::complex<double>(0, wf.m * phi));
            // Calculate value of wave function at r=R
            double psi_R = R_l * Y_lm;

            // Calculate energy
            double energy = E - hbar * hbar * k_mag * k_mag / 2 / m_e;

            // Print energy and wave function values
            std::cout << "Energy: " << energy << " Joules\n";
            std::cout << "Wave function value at r=R: " << psi_R << "\n";
        }
    }
}

