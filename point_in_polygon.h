/*
 * Author: Saud Zahir
 * Date: June 17, 2024
 * Description:
                In computational geometry, the point-in-polygon problem
                determines whether a given point in the plane lies inside,
                outside, or on the boundary of a polygon. This algorithm
                calculates the sum of angles between the test point
                and the edges of the polygon. If the total angle sum
                is 360 degrees (or 2π radians), the point is inside the polygon;
                otherwise, it is outside.

                This method works reliably for convex polygons and
                in some cases for concave polygons. However, it may fail
                in extreme cases involving complex concave polygons.
                For complex concave polygons, it is recommended to divide
                the polygon into smaller convex sub-polygons and apply
                the algorithm to each sub-polygon to determine if the point 
                is inside.
*/

#pragma once

#include <iostream>
#include <vector>
#include <cmath>


using namespace std;


struct Point {
    float x, y, z;

    // Constructor to initialize a Point
    Point(float x, float y, float z) : x(x), y(y), z(z) {}
};


inline Point operator+(Point a, Point b) {
    return Point{a.x + b.x, a.y + b.y, a.z + b.z};
}

inline Point operator-(Point a, Point b) {
    return Point{a.x - b.x, a.y - b.y, a.z - b.z};
}

double dot(Point a, Point b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

double norm(Point p) {
    return sqrt(dot(p, p));
}

bool poinInPolygon(vector<Point> vertices, Point p) {
    double angle;
    for(size_t i = 0; i < vertices.size(); ++i) {
        if (i != vertices.size() - 1) {
            Point a = vertices[i];
            Point b = vertices[i + 1];

            // cos(theta) = P.Q/(|P|*|Q|)
            angle += acos(dot(p - a, p - b)/(norm(p - a) * norm(p - b)));
        }

        else {
            Point a = vertices[i];
            Point b = vertices[0];

            angle += acos(dot(p - a, p - b)/(norm(p - a) * norm(p - b)));
        }
    }

    return angle == 2*M_PI;
};
