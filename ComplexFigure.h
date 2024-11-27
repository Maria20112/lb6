#pragma once
#include "Triangle.h"
#include "Circle.h"
#include "Figure.h"

class ComplexFigure: public Figure
{
public:
	ComplexFigure(StackOfFigures& f, Triangle* tr, Circle* c);
	void show() override;
	void hide() override;
	void replace(Point o1) override;
private:
	Triangle* triangle;
	Circle* circle;
};