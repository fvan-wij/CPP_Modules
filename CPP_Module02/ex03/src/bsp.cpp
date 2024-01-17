#include "Point.hpp"
#include "Fixed.hpp"

static Fixed	calculateAreaOfTriangle(Point const p1, Point const p2, Point const p3){
	std::cout << "testing p1.getX()" << p1.getX() << std::endl;
	return ((	(p1.getX() * (p2.getY() - p3.getY())) +
				(p2.getX() * (p3.getY() - p1.getY())) +
				(p3.getX() * (p1.getY() - p2.getY())) ) / 2);
}

static Fixed	abs(Fixed value){
	if (value < 0)
		return (value * -1);
	else
	 	return (value);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point){

		Fixed area1 = abs(calculateAreaOfTriangle(a, b, point));
		Fixed area2 = abs(calculateAreaOfTriangle(b, c, point));
		Fixed area3 = abs(calculateAreaOfTriangle(c, a, point));
		std::cout << "area1: " << area1.toFloat() << " area2: " << area2 << " area3: " << area3 << std::endl;
		Fixed sumTriangles = (area1 + area2 + area3);
		std::cout << "sumTriangles: " << sumTriangles << std::endl;
		Fixed areaTriangle = abs(calculateAreaOfTriangle(a, b, c));

		if (sumTriangles == areaTriangle)
			return (true);
		else
			return (false);
};
