#include "rectangle.h"
namespace geometry {
	Rectangle::Rectangle() : m_height(0), m_width(0) {
	}

	Rectangle::Rectangle(double h, double w) : m_height(h), m_width(w)
	{
	}

	void Rectangle::setHeight(double h)
	{
		m_height = h;
		calcAreaPerim(m_area, m_perimeter);
	}

	void Rectangle::setWidth(double w)
	{
		m_width = w;
		calcAreaPerim(m_area, m_perimeter);
	}

	double Rectangle::getHeight()
	{
		return m_height;
	}

	double Rectangle::getWidth()
	{
		return m_width;
	}

	void Rectangle::onHoverColor(double r, double g, double b)
	{
		color hoverColor = { r, g, b };
		m_onHover = hoverColor;
	}

	void Rectangle::setFill(color fill)
	{
		m_fill = fill;
		m_onHover = fill;
	}

	void Rectangle::setFill(double r, double g, double b)
	{
		color c = { r, g, b };
		m_fill = c;
		m_onHover = c;
	}

	void Rectangle::draw()
	{
		if (m_hover) {
			glColor3f(m_onHover.red, m_onHover.green, m_onHover.blue);
		}
		else {
			glColor3f(m_fill.red, m_fill.green, m_fill.blue);
		}
		glBegin(GL_QUADS);
		glVertex2i(m_x - m_width / 2, m_y + m_height / 2);
		glVertex2i(m_x + m_width / 2, m_y + m_height / 2);
		glVertex2i(m_x + m_width / 2, m_y - m_height / 2);
		glVertex2i(m_x - m_width / 2, m_y - m_height / 2);
		glEnd();
	}

	void Rectangle::calcAreaPerim(double & a, double & p)
	{
		a = m_width * m_height;
		p = (2 * m_width) + (2 * m_height);
	}
	void Rectangle::setIsInShape(double x, double y)
	{
		if (x >= m_x + m_width / 2 || x <= m_x - m_width / 2) m_hover = false;
		else if (y >= m_y + m_height / 2 || y <= m_y - m_height / 2) m_hover =  false;
		else m_hover = true;
	}
}
