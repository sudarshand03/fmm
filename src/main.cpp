#include <iostream>
#include "../include/point_source.hpp"

using namespace fmm;

int main() {
    PointSource<3> source(Vector<3>({{1.0, 2.0, 3.0}}), 5.0);
    std::cout << source << std::endl;
    return 0;
}
