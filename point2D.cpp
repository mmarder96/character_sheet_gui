#include "point2D.h"

namespace geometry {
	Point2D::Point2D() : m_x(0), m_y(0) {
	}

	Point2D::Point2D(int xIn, int yIn) : m_x(xIn), m_y(yIn) {
	}
	int Point2D::getX() const
	{
		return m_x;
	}
	int Point2D::getY() const
	{
		return m_y;
	}
	void Point2D::setX(int xIn)
	{
		m_x = xIn;
	}
	void Point2D::setY(int yIn)
	{
		m_y = yIn;
	}
	void Point2D::setPoint(int xIn, int yIn)
	{
		m_x = xIn;
		m_y = yIn;
	}
	void Point2D::movePoint(int xOffset, int yOffset)
	{
		m_x += xOffset;
		m_y += yOffset;
	}
	double Point2D::distance(const Point2D &p1, const Point2D &p2)
	{
		return sqrt(pow((p2.getX() - p1.getX()), 2) + pow((p2.getY() - p1.getY()), 2));
	}
}
