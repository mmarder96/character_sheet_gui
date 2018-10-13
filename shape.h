#pragma once

#include "graphics.hpp"
#include "point2D.h"
#include <vector>
#include <math.h>

#define PI 3.14159265

namespace geometry {
	struct color {
		double red;
		double green;
		double blue;
	};

	class Shape {
	public:
		Shape();

		double getArea() const;
		double getPerimeter() const;
		Point2D getCenter() const;
		color getFill() const;

		virtual void setFill(color c);
		virtual void setFill(double r, double g, double b);
		void setCenter(int x, int y);
		void offset(double x, double y);


		virtual void draw() = 0;
	protected:
		virtual void calcAreaPerim(double &a, double &p) = 0;

		double m_area;
		double m_perimeter;
		color m_fill;

		int m_x;
		int m_y;
	};
}