#pragma once
#include "Figure.h"

class Circle : public Figure
{
public:
	Circle(StackOfFigures& f, Point o, int r, COLORREF c, COLORREF p);
	void show() override;
	void hide() override;
	void replace(Point o1) override;
};
