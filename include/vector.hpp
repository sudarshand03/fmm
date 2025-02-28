#ifndef VECTOR_HPP
#define VECTOR_HPP

// Ensure the file is only included once
#pragma once

// Standard library headers
#include <array>    // Provides std::array (fixed-size container)
#include <iostream> // Provides std::ostream for printing
#include <cmath>    // Provides sqrt(), abs(), hypot() for norm calculations
#include <cassert>  // Provides assert() for runtime error checking
#include <numeric>  // Provides std::inner_product() for dot product calculations

namespace fmm
{

    // Template class for a d-dimensional vector
    template <std::size_t dimension>
    class Vector
    {
    public:
        // Data structure to store vector components
        std::array<double, dimension> components;

        // -------------------------------
        // Constructors
        // -------------------------------

        // Default constructor: initializes all components to zero
        Vector()
        {
            components.fill(0.0);
        }

        // Constructor that initializes vector with given values
        explicit Vector(const std::array<double, dimension> &initialValues)
        {
            components = initialValues;
        }

        // Constructor that sets all components to the same value
        explicit Vector(double fillValue)
        {
            components.fill(fillValue);
        }

        // -------------------------------
        // Access Operators
        // -------------------------------

        // Get or modify a component of the vector
        double &operator[](std::size_t index)
        {
            assert(index < dimension && "Index out of bounds");
            return components[index];
        }

        // Get a component (read-only version)
        const double &operator[](std::size_t index) const
        {
            assert(index < dimension && "Index out of bounds");
            return components[index];
        }

        // -------------------------------
        // Arithmetic Operations
        // -------------------------------

        // Add two vectors
        Vector operator+(const Vector &other) const
        {
            Vector result;
            for (std::size_t i = 0; i < dimension; ++i)
            {
                result.components[i] = components[i] + other.components[i];
            }
            return result;
        }

        // Subtract two vectors
        Vector operator-(const Vector &other) const
        {
            Vector result;
            for (std::size_t i = 0; i < dimension; ++i)
            {
                result.components[i] = components[i] - other.components[i];
            }
            return result;
        }

        // Unary minus (negate the vector)
        Vector operator-() const
        {
            return (*this) * (-1.0);
        }

        // Multiply vector by a scalar
        Vector operator*(double scalar) const
        {
            Vector result;
            for (std::size_t i = 0; i < dimension; ++i)
            {
                result.components[i] = components[i] * scalar;
            }
            return result;
        }

        // Divide vector by a scalar
        Vector operator/(double scalar) const
        {
            assert(scalar != 0 && "Division by zero error!");
            return (*this) * (1.0 / scalar);
        }

        // Compound assignment: Add another vector to this vector
        Vector &operator+=(const Vector &other)
        {
            *this = *this + other;
            return *this;
        }

        // Compound assignment: Subtract another vector from this vector
        Vector &operator-=(const Vector &other)
        {
            *this = *this - other;
            return *this;
        }

        // Compound assignment: Multiply this vector by a scalar
        Vector &operator*=(double scalar)
        {
            *this = *this * scalar;
            return *this;
        }

        // Compound assignment: Divide this vector by a scalar
        Vector &operator/=(double scalar)
        {
            *this = *this / scalar;
            return *this;
        }

        // -------------------------------
        // Vector Operations
        // -------------------------------

        // Compute the dot product of two vectors
        double dot(const Vector &other) const
        {
            return std::inner_product(components.begin(), components.end(),
                                      other.components.begin(), 0.0);
        }

        // Compute the Euclidean norm (length of the vector)
        double norm() const
        {
            return std::sqrt(this->dot(*this)); // sqrt(sum of squared components)
        }

        // Compute the squared norm (avoids square root for efficiency)
        double normSquared() const
        {
            return this->dot(*this);
        }

        // -------------------------------
        // Utility Functions
        // -------------------------------

        // Returns a reference to the underlying data array
        std::array<double, dimension> &data()
        {
            return components;
        }

        // Returns a read-only reference to the underlying data array
        const std::array<double, dimension> &data() const
        {
            return components;
        }

        // Fill all components of the vector with a specified value
        void fill(double value)
        {
            components.fill(value);
        }

        // -------------------------------
        // I/O Operations
        // -------------------------------

        // Print the vector in a readable format
        friend std::ostream &operator<<(std::ostream &os, const Vector &vec)
        {
            os << "(";
            for (std::size_t i = 0; i < dimension; ++i)
            {
                os << vec.components[i];
                if (i < dimension - 1)
                {
                    os << ", ";
                }
            }
            os << ")";
            return os;
        }

        // Scalar multiplication on the left: Allows (scalar * vector)
        friend Vector operator*(double scalar, const Vector &vec)
        {
            return vec * scalar;
        }
    };

} // namespace fmm

#endif // VECTOR_HPP
