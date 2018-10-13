#pragma once

#include "shape.h"

namespace geometry {
	class Rectangle : public Shape {
	public:
		Rectangle();

		Rectangle(double h, double w);

		virtual void setHeight(double h);
		virtual void setWidth(double w);

		virtual double getHeight();
		virtual double getWidth();

		virtual void onHoverColor(double r, double g, double b);
		virtual void setFill(color fill) override;
		virtual void setFill(double r, double g, double b) override;
		virtual void setIsInShape(double x = -1, double y = -1);

		virtual void draw() override;

	protected:
		double m_height;
		double m_width;

		bool m_hover = false;

	private:
		virtual void calcAreaPerim(double &a, double &p) override;
		
		color m_onHover;

	};
}