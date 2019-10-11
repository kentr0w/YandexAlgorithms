#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

struct Point {
    double xDistance;
    double yDistance;
    double distanceFromCentre;
};

bool double_equals(double number) {
    return abs(static_cast<int>(number * 10000)) <= 10;
}

bool compare(const Point &firstElement, const Point &SecondElement) {
    double delta = firstElement.distanceFromCentre - SecondElement.distanceFromCentre;
    if (double_equals(delta))
        return firstElement.xDistance < SecondElement.xDistance;
    return delta < 0;
}

double DistanceFromCentre(Point point) {
    if (point.xDistance > 0)
        return sqrt(point.xDistance * point.xDistance + point.yDistance * point.yDistance);
    else
        return -sqrt(point.xDistance * point.xDistance + point.yDistance * point.yDistance);
}

double DistanceBetwenOnePoint(Point point, double deltaX) {
    return sqrt(pow(point.xDistance - deltaX, 2) + pow(point.yDistance, 2));
}

double binarySearchRadius(Point minpoint, Point maxpoint) {

    double left = minpoint.xDistance;
    double rigth = maxpoint.xDistance;
    double middle = (left + rigth) / 2;

    while (left < rigth) {

        middle = (left + rigth) / 2;

        double firstvar = (DistanceBetwenOnePoint(minpoint, middle));

        double secondvar = (DistanceBetwenOnePoint(maxpoint, middle));

        if (double_equals(firstvar - secondvar))
            break;

        if (DistanceBetwenOnePoint(minpoint, middle) > DistanceBetwenOnePoint(maxpoint, middle))
            rigth = middle - 0.0001;
        else
            left = middle + 0.0001;
    }
    return middle;
}

double FindMinRad(std::vector<Point> &points, size_t count, size_t countCorrectPoints) {

    double radius;

    double middle = binarySearchRadius(points[0],
                                       points[countCorrectPoints - 1]);
    double maxdist = 0;
    for (size_t i = 0; i < countCorrectPoints; ++i) {
        if (DistanceBetwenOnePoint(points[i], middle) > maxdist) {
            maxdist = DistanceBetwenOnePoint(points[i], middle);
        }
    }

    radius = maxdist;

    for (size_t index = 1; index <= count - countCorrectPoints; ++index) {

        maxdist = 0;

        middle = binarySearchRadius(points[index], points[index + countCorrectPoints - 1]);

        for (size_t jindex = index; jindex < index + countCorrectPoints; ++jindex) {
            double dist = DistanceBetwenOnePoint(points[jindex], middle);
            if (dist > maxdist) {
                maxdist = dist;
            }
        }

        if (maxdist < radius)
            radius = maxdist;
    }

    return radius;
}


int main() {

    size_t pointCount;
    size_t pointInclude;
    std::cin >> pointCount >> pointInclude;
    std::vector<Point> vectorpoints;
    for (size_t index = 0; index < pointCount; ++index) {
        int xDist, yDist;
        std::cin >> xDist >> yDist;
        Point pointer{};
        pointer.xDistance = xDist;
        pointer.yDistance = yDist;
        vectorpoints.push_back(pointer);
    }

    for (size_t index = 0; index < pointCount; ++index) {
        vectorpoints[index].distanceFromCentre = DistanceFromCentre(vectorpoints[index]);
    }

    std::sort(vectorpoints.begin(), vectorpoints.end(), compare);

    for(int i=0; i<pointCount; ++i)
        std::cout<<vectorpoints[i].xDistance<<std::endl;

    std::cout << FindMinRad(vectorpoints, pointCount, pointInclude) << std::endl;

    return 0;
}

