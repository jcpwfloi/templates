//ntr zjh
//Orz LXLWDGY WJMZBMR ftiasch tourist sevenkplus
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

//utilities
double const EPS = 1e-6;
bool iszero(double x) {return fabs(x) < EPS;}

typedef Point Vector;

struct Point {
    double x, y;
    Point() : x(0), y(0) {}
    Point(double x, double y) : x(x), y(y) {}
    Vector operator + (Vector x) {return Vector(this -> x + x.x, this -> y + x.y);}
    Vector operator - (Vector x) {return Vector(this -> x - x.x, this -> y - x.y);}
    double operator ^ (Vector x) {return this -> x * x.x + this -> y * x.y;}
    double operator * (Vector x) {return this -> x * x.y - this -> y * x.x;}
    double len() {return sqrt(*this ^ *this);}
    Vector Rotate(double omega) {return Vector(x * cos(omega) - y * sin(omega), y * cos(omega) + x * sin(omega));}
};

struct Line {
};

struct Circle {
};

struct Polygon {
};

int main() {
    return 0;
}
