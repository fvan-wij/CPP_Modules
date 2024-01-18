#include "Point.hpp"
#include "Fixed.hpp"

static Fixed calculateAreaOfTriangle(Point const p1, Point const p2, Point const p3)
{
	return (((p1.getX() * p2.getY()) + (p2.getX() * p3.getY()) + (p3.getX() * p1.getY())
           - (p1.getY() * p2.getX()) - (p2.getY() * p3.getX()) - (p3.getY() * p1.getX())) / 2);
}

static Fixed	abs(Fixed value){
	if (value < 0)
		return (value * -1);
	else
	 	return (value);
}

static bool isPointOnLine(Point const point, Point const l1, Point const l2){
	return ((point.getY() - l1.getY()) * (l2.getX() - l1.getX()) == (point.getX() - l1.getX()) * (l2.getY() - l1.getY()));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point){

		if (point == a || point == b || point == c)
			return (false);
		if (isPointOnLine(point, a, b) || isPointOnLine(point, b, c) || isPointOnLine(point, c, a))
			return (false);

		Fixed area1 = abs(calculateAreaOfTriangle(a, b, point));
		Fixed area2 = abs(calculateAreaOfTriangle(b, c, point));
		Fixed area3 = abs(calculateAreaOfTriangle(c, a, point));
		Fixed sumTriangles = (area1 + area2 + area3);
		Fixed areaTriangle = abs(calculateAreaOfTriangle(a, b, c));
		if (sumTriangles == areaTriangle)
			return (true);
		else
			return (false);
};
