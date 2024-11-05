#include<iostream>
#include<cmath>

// Electric_Field class definition
class Electric_Field {
private:
    double *E; // Pointer to dynamically allocated array for x, y, z components
public:
    Electric_Field() {
        E = new double[3]{0.0, 0.0, 0.0};       //the default initialization
    }

    Electric_Field(double ex, double ey, double ez) {
        E = new double[3]{ex, ey, ez};
    }

    ~Electric_Field() {     //destructor
        delete[] E;
    }

    double calculateMagnitude() {
        return std::sqrt(E[0] * E[0] + E[1] * E[1] + E[2] * E[2]);
    }

    double getX() { return E[0]; }
    double getY() { return E[1]; }
    double getZ() { return E[2]; }

    void setX(double ex) { E[0] = ex; }
    void setY(double ey) { E[1] = ey; }
    void setZ(double ez) { E[2] = ez; }

    double calculateInnerProduct() {
        return E[0] * E[0] + E[1] * E[1] + E[2] * E[2];
    }
};

// Magnetic_Field class definition
class Magnetic_Field {
private:
    double *B;
public:
    Magnetic_Field() {
        B = new double[3]{0.0, 0.0, 0.0};       //default initialization
    }

    Magnetic_Field(double bx, double by, double bz) {
        B = new double[3]{bx, by, bz};
    }

    ~Magnetic_Field() {     //destructor
        delete[] B;
    }

    double calculateMagnitude() {
        return std::sqrt(B[0] * B[0] + B[1] * B[1] + B[2] * B[2]);
    }

    double getX() { return B[0]; }
    double getY() { return B[1]; }
    double getZ() { return B[2]; }

    void setX(double bx) { B[0] = bx; }
    void setY(double by) { B[1] = by; }
    void setZ(double bz) { B[2] = bz; }

    void calculateUnitVector(double &ux, double &uy, double &uz) {
        double magnitude = calculateMagnitude();
        ux = B[0] / magnitude;
        uy = B[1] / magnitude;
        uz = B[2] / magnitude;
    }
};

int main() {
    Electric_Field E_default;
    Electric_Field E_components(1e5, 10.9, 1.7e2);
    Magnetic_Field M_default;
    Magnetic_Field M_components(2e5, 16.8, 1.8e2);

    // Set values using setters
    E_default.setX(3.5e4);
    E_default.setY(2.1);
    E_default.setZ(7.8e1);

    M_default.setX(4.6e5);
    M_default.setY(5.3);
    M_default.setZ(8.9e2);

    // Calculate and output magnitudes
    std::cout << "Electric Field Magnitude (default): " << E_default.calculateMagnitude() << std::endl;
    std::cout << "Electric Field Magnitude (components): " << E_components.calculateMagnitude() << std::endl;

    std::cout << "Magnetic Field Magnitude (default): " << M_default.calculateMagnitude() << std::endl;
    std::cout << "Magnetic Field Magnitude (components): " << M_components.calculateMagnitude() << std::endl;

    // Calculate and output inner product for electric field
    std::cout << "Electric Field Inner Product: " << E_components.calculateInnerProduct() << std::endl;

    // Calculate and output unit vector for magnetic field
    double ux, uy, uz;
    M_components.calculateUnitVector(ux, uy, uz);
    std::cout << "Magnetic Field Unit Vector: (" << ux << ", " << uy << ", " << uz << ")" << std::endl;

    return 0;
}
