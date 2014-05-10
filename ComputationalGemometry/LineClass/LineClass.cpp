#include<cstdio>
#include<algorithm>
#include<cmath>
#define gi gI()

using namespace std;

const double eps = 1e-6;

typedef long long ll;

inline ll gI() {
    long long flag = 1, p = 0;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') flag = -1, c = getchar();
    while ('0' <= c && c <= '9') p = p * 10 + (c - '0'), c = getchar();
    return p * flag;
}

struct Point {
    double x, y;
    Point(double x, double y) : x(x), y(y) {}
    Point() : x(0), y(0) {}
    Point operator + (Point x) {
	return Point(this -> x + x.x, this -> y + x.y);
    }
    Point operator - (Point x) {
	return Point(this -> x - x.x, this -> y - x.y);
    }
    double operator ^ (Point x) {
	return this -> x * x.x + this -> y * x.y;
    }
    double operator * (Point x) {
	return this -> x * x.y - this -> y * x.x;
    }
};

typedef Point Vector;

struct Line {
    Point a, b;
    Line(double x1, double y1, double x2, double y2) : a(Point(x1, y1)), b(Point(x2, y2)) {}
    Line(Point a, Point b) : a(a), b(b) {}
    Line() : a(Point(0, 0)), b(Point(0, 0)) {}
    Vector v() {return b - a;}
    double len() {
	Vector temp = this -> v();
	return sqrt(temp ^ temp);
    }
};

inline bool isZero(double x) {if (fabs(x) <= eps) return true; else return false;}
inline int sgn(double x) {if (isZero(x)) return 0;if (x > 0) return 1; else return -1;}
Vector Vectorize(Point a, Point b) {
    return b - a;
}

bool isIntersect(Line a, Line b) {
    int judge1 = sgn((Vectorize(a.a, b.a) * Vectorize(a.a, b.b)) * (Vectorize(a.b, b.a) * Vectorize(a.b, b.b)));
    int judge2 = sgn((Vectorize(b.a, a.a) * Vectorize(b.a, a.b)) * (Vectorize(b.b, a.a) * Vectorize(b.b, a.b)));
    if (judge1 == -1 && judge2 == -1) return true;
    return false;
}

bool isPerpendicular(Line a, Line b) {
    int judge = Vectorize(a.a, a.b) ^ Vectorize(b.a, b.b);
    if (isZero(judge)) return true; else return false;
}

double distPointToLine(Point p, Line l) {
    return fabs((Vectorize(p, l.a) * Vectorize(p, l.b))) / l.len();
}

int main() {
    while (1) {
    puts("1: Line intersect and Perpendicular");
    puts("2: distance of Point to Line");
	int select = gi;
    if (select == 1) {
	puts("Input Line:");
	Line a = Line(gi, gi, gi, gi);
	Line b = Line(gi, gi, gi, gi);
	int judge = isIntersect(a, b) ;
	int judgePerp = isPerpendicular(a, b);
	if (judge) {
	    puts("Intersect");
	    if (judgePerp)
		puts("Perpendicular");
	    else
		puts("Not Perpendicular");
	}
	else
	    puts("Not Intersect");
    } else if (select == 2) {
	puts("Input Point:");
	Point p = Point(gi, gi);
	puts("Input Line:");
	Line l = Line(gi, gi, gi, gi);
	printf("%.6lf\n", distPointToLine(p, l));
    }
    }
    return 0;
}

