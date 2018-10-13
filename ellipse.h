#pragma once

#include "shape.h"

namespace geometry {
	class Ellipse : public Shape {
	public:
		Ellipse();

		virtual void setMagnitudes(double a, double b);
		virtual void setMagnitudeA(double a);
		virtual void setMagnitudeB(double b);
		virtual void setCircleRadius(double radius);
		virtual void setRotation(double rotation);

		virtual double getMagnitudeA() const;
		virtual double getMagnitudeB() const;
		virtual double getRotation() const;
		virtual double getRadius() const;
		
		virtual void draw() override;
	
	private:
		double m_rotation;
		double m_aMagnitude;
		double m_bMagnitude;	

		virtual void calcAreaPerim(double &a, double &b) override;
		Point2D rotatePoint(double xPoint, double yPoint) const;
	};
}