struct Atom {
    double atomic_number;
    double x, y, z; // atomic coordinates
    std::vector<Shell> shells; // vector of electron shells
};

struct Shell {
    int n, l; // principal quantum number and orbital quantum number
    double energy; // energy of the shell
    std::vector<Orbital> orbitals; // vector of atomic orbitals
};

struct Orbital {
    double n, l, m; // quantum numbers
    double radius; // radius of the orbital
    std::vector<double> coefficient; // vector of coefficients for APW expansion
};

