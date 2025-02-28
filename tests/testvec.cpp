// src/testvec.cpp
#include <iostream>
#include "../include/vector.hpp"  // Include the Vector class

using namespace fmm;  // Use the fmm namespace for convenience

void runVectorTests() {
    std::cout << "========== Vector Class Test ==========\n";

    // Create 3D vectors
    Vector<3> vec1({{1.0, 2.0, 3.0}});  // Initialize with values
    Vector<3> vec2(2.0);  // All components set to 2.0

    // Print vectors
    std::cout << "vec1: " << vec1 << "\n";
    std::cout << "vec2: " << vec2 << "\n";

    // Test element access
    std::cout << "vec1[0]: " << vec1[0] << ", vec1[1]: " << vec1[1] << ", vec1[2]: " << vec1[2] << "\n";

    // Vector addition
    Vector<3> sum = vec1 + vec2;
    std::cout << "vec1 + vec2 = " << sum << "\n";

    // Vector subtraction
    Vector<3> diff = vec1 - vec2;
    std::cout << "vec1 - vec2 = " << diff << "\n";

    // Scalar multiplication
    Vector<3> scaled = vec1 * 3.0;
    std::cout << "vec1 * 3.0 = " << scaled << "\n";

    // Scalar division
    Vector<3> divided = vec1 / 2.0;
    std::cout << "vec1 / 2.0 = " << divided << "\n";

    // Dot product
    double dotProd = vec1.dot(vec2);
    std::cout << "Dot product of vec1 and vec2 = " << dotProd << "\n";

    // Norm and squared norm
    std::cout << "Norm of vec1: " << vec1.norm() << "\n";
    std::cout << "Squared norm of vec1: " << vec1.normSquared() << "\n";

    std::cout << "========== End of Test ==========\n";
}

int main() {
    runVectorTests();
    return 0;
}
