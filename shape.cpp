#include "shape.h"

namespace geometry {
	Shape::Shape() : m_area(0), m_perimeter(0), m_fill({ 0, 0, 0 }) {

	}

	double Shape::getArea() const
	{
		return m_area;
	}

	double Shape::getPerimeter() const
	{
		return m_perimeter;
	}

	Point2D Shape::getCenter() const
	{
		return Point2D(m_x, m_y);
	}

	color Shape::getFill() const
	{
		return m_fill;
	}

	void Shape::offset(double x, double y)
	{
		m_x += x;
		m_y += y;
	}
	void Shape::setFill(color c)
	{
		m_fill = c;
	}

	void Shape::setFill(double r, double g, double b)
	{
		color c = { r, g, b };
		m_fill = c;
	}

	void Shape::setCenter(int x, int y)
	{
		m_x = x;
		m_y = y;
	}
}
