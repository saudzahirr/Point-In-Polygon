/*
 * Author: Saud Zahir
 * Date: June 17, 2024
 *
 *
 *  E(0, 2, 0) _________________  C(2, 2, 0)
 *             \                |
 *              \               |          * Q
 *               \              |
 *                \             |
 *    D(1/2, 1, 0) \            |
 *                 /    * P     |
 *                /             |
 *               /              |
 *              /               |
 *  A(0, 0, 0) /________________| B(2, 0, 0)
 *
 *
 * Test Points:
 *              P(1, 1, 0)
 *              Q(3, 7/4, 0)
*/

#include "point_in_polygon.h"


int main() {
    vector<Point> vertices;
    vertices.push_back(Point(0, 0, 0));
    vertices.push_back(Point(2, 0, 0));
    vertices.push_back(Point(2, 2, 0));
    vertices.push_back(Point(0, 2, 0));
    vertices.push_back(Point(0.5, 1, 0));

    Point P = {1, 1, 0};
    Point Q = {3, 1.75, 0};

    if (poinInPolygon(vertices, P) == true) {
        printf("Point (%.4f, %.4f, %.4f) is in polygon!\n", P.x, P.y, P.z);
    }
    else {
        printf("Point (%.4f, %.4f, %.4f) is not in polygon!\n", P.x, P.y, P.z);
    }

    if (poinInPolygon(vertices, Q) == true) {
        printf("Point (%.4f, %.4f, %.4f) is in polygon!\n", Q.x, Q.y, Q.z);
    }
    else {
        printf("Point (%.4f, %.4f, %.4f) is not in polygon!\n", Q.x, Q.y, Q.z);
    }

    return 0;
}
