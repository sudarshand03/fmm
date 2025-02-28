#pragma once
#include "vector.hpp"
#include <iostream>

namespace fmm
{

    template <std::size_t dimension>
    class PointSource
    {
    public:
        Vector<dimension> position; // Position of the point source
        double strength;            // Charge/mass/intensity of the source

        // Default constructor initializes at origin with zero charge
        PointSource() : position(Vector<dimension>()), strength(0.0) {}

        // Constructor that initializes position and strength
        PointSource(const Vector<dimension> &pos, double s) : position(pos), strength(s) {}

        // Constructor that allows initialization using std::array
        PointSource(const std::array<double, dimension> &posArray, double s)
            : position(Vector<dimension>(posArray)), strength(s) {}

        // Access position components using indexing
        double &operator[](std::size_t index) { return position[index]; }
        
        const double &operator[](std::size_t index) const { return position[index]; }

        // Get source strength
        double getStrength() const { return strength; }

        // Compare two point sources
        bool operator==(const PointSource &rhs) const
        {
            return (this->strength == rhs.strength) && (this->position == rhs.position);
        }

        // Print the PointSource
        friend std::ostream &operator<<(std::ostream &os, const PointSource &p)
        {
            os << "PointSource(position: " << p.position << ", strength: " << p.strength << ")";
            return os;
        }
    };

} // namespace fmm
