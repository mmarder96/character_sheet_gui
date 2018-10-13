#pragma once

#include "graphics.hpp"
#include "point2D.h"
#include "shape.h"
#include <vector>

namespace geometry {
	class Line : public Shape {
	public:
		Line();
		Line(std::vector<Point2D> points);

		virtual void addPoint(Point2D point);
		virtual void addPoint(int x, int y);

		virtual void insertPoint(Point2D point, int index);
		virtual void setPoint(Point2D point, int index);
		virtual void delPoint(int index);
		virtual void setPoints(std::vector<Point2D> points);

		virtual std::vector<Point2D> getPoints() const;
		virtual Point2D getPoint(int index) const;

		virtual void draw() override;
		virtual double getAngle(int p0, int p1, int p2);


	protected:
		double m_width;

		std::vector<Point2D> m_points;

	private:
		virtual void calcAreaPerim(double &a, double &p) override;
	};
}