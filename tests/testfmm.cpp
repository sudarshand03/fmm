// src/testfmm.cpp
#include <iostream>
#include "../include/balanced_fmm_tree.hpp"

using namespace fmm;

int main() {
    std::cout << "========== Testing Balanced FMM Tree ==========\n";

    // Create sample 2D point sources
    std::vector<PointSource<2>> sources = {
        PointSource<2>(Vector<2>({{1.0, 2.0}}), 5.0),
        PointSource<2>(Vector<2>({{4.0, 5.0}}), -3.0),
        PointSource<2>(Vector<2>({{7.0, 8.0}}), 2.0),
        PointSource<2>(Vector<2>({{-2.0, -3.0}}), 4.0),
        PointSource<2>(Vector<2>({{-4.0, -1.0}}), -1.0),
        PointSource<2>(Vector<2>({{6.0, -2.0}}), 3.0)
    };

    // Initialize the FMM Tree with max 2 sources per leaf and accuracy 1e-6
    BalancedFmmTree<2> tree(sources, 2, 1e-6);
    
    // Print the tree structure for debugging
    tree.printTree();

    std::cout << "========== Test Completed ==========\n";
    return 0;
}
