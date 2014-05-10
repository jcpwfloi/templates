#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

const double eps = 1e-6;

struct Point {
    double x, y;
    Point(double x, double y) : x(x), y(y) {}
    Point() : x(0), y(0) {}
    Point operator + (Point &x) {
	return Point(this -> x + x.x, this -> y + x.y);
    }
    Point operator - (Point &x) {
	return Point(this -> x - x.x, this -> y - x.y);
    }
    double operator ^ (Point &x) {
	return this -> x * x.x + this -> y * x.y;
    }
    double operator * (Point &x) {
	return this -> x * x.y - this -> y * x.x;
    }
};

struct Line {
    Point a, b;
    Line(double x1, double y1, double x2, double y2) : a(Point(x1, y1)), b(Point(x2, y2)) {}
    Line(Point a, Point b) : a(a), b(b) {}
    Line() : a(Point(0, 0)), b(Point(0, 0)) {}
};

typedef Point Vector;

int main() {
    return 0;
}
