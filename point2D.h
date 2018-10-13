#pragma once

#include <math.h>

namespace geometry {
	class Point2D {
	public:
		Point2D();
		Point2D(int xIn, int yIn);

		int getX() const;
		int getY() const;

		void setX(int xIn);
		void setY(int yIn);
		void setPoint(int xIn, int yIn);

		/**
		* Requires: nothing
		* Modifies: x and y
		* Effects: moves the point by xOffset units along the x-axis
		*          and yOffset units along the y-axis
		*/
		void movePoint(int xOffset, int yOffset);

		// returns the distance between p1 and p2
		static double distance(const Point2D &p1, const Point2D &p2);
	private:
		int m_x;
		int m_y;
	};
}