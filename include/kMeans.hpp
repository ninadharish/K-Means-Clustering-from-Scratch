#ifndef kmeans_hpp
#define kmeans_hpp

#include "point.hpp"
#include<vector>


class KMeans {
    public:
        int k_;
        int num_iter_;
        std::vector<Point> centroids_;
        void initCentroids(std::vector<Point>& pts);
        KMeans(int k, int num_iter=100);
        double calcualteEuclideanDistance(Point p1, Point p2);
        double calculateManhattanDistance(Point p1, Point p2);
        int predictCluser(Point& p);
        void fit(std::vector<Point>& pts);
        ~KMeans();
};

#endif