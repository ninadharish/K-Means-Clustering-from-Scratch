#include "kMeans.hpp"

void KMeans::initCentroids(std::vector<Point>& pts) {
    centroids_.clear();
    for (int i = 0; i < k_; i++) {
        centroids_.push_back(pts[i]);
    }
}

KMeans::KMeans(int k, int num_iter) {
    k_ = k;
    num_iter_ = num_iter;
}

double KMeans::calcualteEuclideanDistance(Point p1, Point p2) {
    double dx = p1.get_x() - p2.get_x();
    double dy = p1.get_y() - p2.get_y();
    return dx * dx + dy * dy;
}

double KMeans::calculateManhattanDistance(Point p1, Point p2) {
    return std::abs(p1.get_x() - p2.get_x()) + std::abs(p1.get_y() - p2.get_y());
}

int KMeans::predictCluser(Point& p) {
    double best_dist = 9.0;
    int best_idx = 0;
    for (int j = 0; j < k_; j++) {
        double d = calcualteEuclideanDistance(p, centroids_[j]);
        if (d < best_dist) {
            best_dist = d;
            best_idx = j;
        }
    }
    return best_idx;
}

void KMeans::fit(std::vector<Point>& pts) {
    initCentroids(pts);
    std::vector<int> labels(pts.size(), 0);
    bool changed = true;
    int iter = 0;

    while (changed && (iter < num_iter_)) {
        changed = false;
        ++iter;

        for (int i = 0; i < pts.size(); i++) {
            int best_idx = predictCluser(pts[i]);
            if (labels[i] != best_idx) {
                labels[i] = best_idx;
                changed = true;
            }
        }

        std::vector<Point> newCentroids(k_, {0.0, 0.0});
        std::vector<int> counts_(k_, 0);
        for (int i = 0; i < pts.size(); i++) {
            int lbl = labels[i];
            newCentroids[lbl].x += pts[i].x;
            newCentroids[lbl].y += pts[i].y;
            ++counts_[lbl];
        }
        for (int j = 0; j < k_; j++) {
            if (counts_[j] > 0) {
                newCentroids[j].x /= counts_[j];
                newCentroids[j].y /= counts_[j];
            }
        }
        centroids_ = std::move(newCentroids);
    }
}

KMeans::~KMeans() {}