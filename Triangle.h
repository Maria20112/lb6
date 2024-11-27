#pragma once
#include "Figure.h"

class Triangle : public Figure
{
public:
	Triangle(StackOfFigures& f, Point o, int R, COLORREF c, COLORREF p);
	void show() override;
	void replace(Point o1) override;
	void hide() override;
private:
	Point a, b, c;
};