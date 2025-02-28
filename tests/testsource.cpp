#include <iostream>
#include "../include/balanced_fmm_tree.hpp"

using namespace fmm;

int main() {
    // Create some sample point sources in 3D
    std::vector<PointSource<3>> sources = {
        PointSource<3>({{1.0, 2.0, 3.0}}, 5.0),
        PointSource<3>({{4.0, 5.0, 6.0}}, -3.0),
        PointSource<3>({{7.0, 8.0, 9.0}}, 2.0)
    };

    // Create an FMM Tree with these sources
    BalancedFmmTree<3> tree(sources, 2, 1e-6);
    tree.printTree();

    return 0;
}
