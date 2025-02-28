#pragma once
#include <vector>
#include <iostream>
#include "vector.hpp"
#include "point_source.hpp"

namespace fmm {

template <std::size_t dimension>
class BalancedFmmTree {
public:
    std::vector<PointSource<dimension>> sources;  // List of sources
    int maxSourcesPerLeaf;  // Max sources per node before subdivision
    double accuracy;  // Precision parameter

    struct Node {
        Vector<dimension> center;  // Center of the region
        double size;               // Size of the region
        std::vector<PointSource<dimension>> containedSources;  // Sources in this node
        std::vector<Node> children;  // Child nodes for subdivision

        Node(const Vector<dimension>& c, double s) : center(c), size(s) {}
    };

    Node root;  // Root of the tree

    // Constructor: Initializes tree and builds it
    BalancedFmmTree(const std::vector<PointSource<dimension>>& src, int maxPerLeaf, double eps)
        : sources(src), maxSourcesPerLeaf(maxPerLeaf), accuracy(eps),
          root(Vector<dimension>({{0.0, 0.0}}), 1.0) {  // Ensure 2D center at (0,0)
        buildTree(root, sources);
    }

    // Print tree for debugging
    void printTree() const {
        std::cout << "Balanced FMM Tree: " << sources.size() << " sources, max " 
                  << maxSourcesPerLeaf << " per leaf, accuracy " << accuracy << "\n";
    }

private:
    void buildTree(Node& node, const std::vector<PointSource<dimension>>& pts) {
        node.containedSources = pts;

        // If the number of sources is small, stop subdivision
        if (pts.size() <= maxSourcesPerLeaf) return;

        // Create 4 subregions for 2D space (quadtree)
        std::array<Vector<dimension>, 4> childCenters = {
            node.center + Vector<dimension>({{ node.size / 2,  node.size / 2 }}),
            node.center + Vector<dimension>({{ node.size / 2, -node.size / 2 }}),
            node.center + Vector<dimension>({{-node.size / 2,  node.size / 2 }}),
            node.center + Vector<dimension>({{-node.size / 2, -node.size / 2 }})
        };

        double newSize = node.size / 2.0;
        for (const auto& center : childCenters) {
            node.children.emplace_back(center, newSize);
        }

        // Distribute sources to child nodes
        for (const auto& source : pts) {
            for (auto& child : node.children) {
                if (isInside(source, child)) {
                    child.containedSources.push_back(source);
                    break;
                }
            }
        }

        // Recursively build the tree
        for (auto& child : node.children) {
            buildTree(child, child.containedSources);
        }
    }

    // Check if a source belongs inside a given node
    bool isInside(const PointSource<dimension>& source, const Node& node) const {
        Vector<dimension> diff = source.position - node.center;
        return (std::abs(diff[0]) <= node.size / 2) && (std::abs(diff[1]) <= node.size / 2);
    }
};

}  // namespace fmm
