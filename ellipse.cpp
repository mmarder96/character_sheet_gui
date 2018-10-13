#include "ellipse.h"


namespace geometry {
	Ellipse::Ellipse() : m_aMagnitude(0), m_bMagnitude(0), m_rotation(0) {
	}
	void Ellipse::setMagnitudes(double a, double b)
	{
		m_aMagnitude = a;
		m_bMagnitude = b;
	}
	void Ellipse::setMagnitudeA(double a)
	{
		m_aMagnitude = a;
	}
	void Ellipse::setMagnitudeB(double b)
	{
		m_bMagnitude = b;
	}
	void Ellipse::setCircleRadius(double radius)
	{
		if (radius < 0) {
			radius = 0;
		}
		else {
			m_aMagnitude = radius;
			m_bMagnitude = radius;
		}
	}
	void Ellipse::setRotation(double rotation)
	{
		m_rotation = rotation * PI / 180.0;
	}
	double Ellipse::getMagnitudeA() const
	{
		return m_aMagnitude;
	}
	double Ellipse::getMagnitudeB() const
	{
		return m_bMagnitude;
	}
	double Ellipse::getRotation() const
	{
		return m_rotation * 180 / PI;
	}
	double Ellipse::getRadius() const
	{
		if (m_aMagnitude == m_bMagnitude) {
			return m_aMagnitude;
		}
		
		return -1;
	}
	void Ellipse::draw()
	{

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(m_fill.red, m_fill.green, m_fill.blue);
		glVertex2i(m_x, m_y);
		for(int i = 0; i <= 361; ++i) {
			double t = i * PI / 180.0;
			Point2D tempPoint = rotatePoint(m_aMagnitude * cos(t) + m_x, m_bMagnitude * sin(t) + m_y);
			glVertex2i(tempPoint.getX(), tempPoint.getY());
		}
		glEnd();

	}
	void Ellipse::calcAreaPerim(double & a, double & b)
	{
		a = -1;
		b = -1;
	}
	Point2D Ellipse::rotatePoint(double xPoint, double yPoint) const
	{
		double x, y;
		x = ((xPoint - m_x) * cos(m_rotation)) - ((yPoint - m_y) * sin(m_rotation)) + m_x;
		y = ((xPoint - m_x) * sin(m_rotation)) + ((yPoint - m_y) * cos(m_rotation)) + m_y;
		return Point2D(x, y);
	}
}