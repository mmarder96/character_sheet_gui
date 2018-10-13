#include "line.h"

namespace geometry {
	Line::Line() : m_width(0) {
	}
	Line::Line(std::vector<Point2D> points) : m_width(0)
	{
		m_points = points;
	}
	void Line::addPoint(Point2D point)
	{
		m_points.push_back(point);
	}
	void Line::addPoint(int x, int y)
	{
		m_points.push_back(Point2D(x, y));
	}
	void Line::insertPoint(Point2D point, int index)
	{
		m_points.insert(m_points.begin() + index, point);
	}
	void Line::setPoint(Point2D point, int index)
	{
		if (index < m_points.size() || index >= 0) {
			m_points[index] = point;
		}
	}
	void Line::delPoint(int index)
	{
		m_points.erase(m_points.begin() + index);
	}
	void Line::setPoints(std::vector<Point2D> points)
	{
		m_points = points;
	}
	std::vector<Point2D> Line::getPoints() const
	{
		return m_points;
	}
	Point2D Line::getPoint(int index) const
	{
		return m_points[index];
	}
	void Line::draw()
	{
		
	}
	void Line::calcAreaPerim(double & a, double & p)
	{
		m_area = -1;
		m_perimeter = -1;
	}
	double Line::getAngle(int index0, int index1, int index2)
	{
		auto p0 = m_points[index0];
		auto p1 = m_points[index1];
		auto p2 = m_points[index2];
		double a = pow(p1.getX() - p0.getX(), 2) + pow(p1.getY() - p0.getY(), 2);
		double b = pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2);
		double c = pow(p2.getX() - p0.getX(), 2) + pow(p2.getY() - p0.getY(), 2);
		return acos((a + b - c) / sqrt(4 * a * b)) * 180 / PI;
	}
}
