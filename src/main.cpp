#include "kMeans.hpp"
#include<random>

int main() {
    std::vector<Point> data;

    std::mt19937 gen{std::random_device{}()};
    std::normal_distribution<double> blob1(0.0, 1.0);
    std::normal_distribution<double> blob2(5.0, 1.0);

    // Generate two clusters
    for (int i = 0; i < 100; ++i) {
        data.push_back({blob1(gen), blob1(gen)});
        data.push_back({blob2(gen), blob2(gen)});
    }

    KMeans km(3, 100);
    km.fit(data);

    std::cout << "Centroids:\n";
    for (auto& c : km.centroids_) {
        c.print();
    }
}