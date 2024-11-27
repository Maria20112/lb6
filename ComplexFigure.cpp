#include "ComplexFigure.h"

ComplexFigure::ComplexFigure(StackOfFigures& f, Triangle* tr, Circle* c) : Figure(o, R, color, colorpen), triangle(tr), circle(c)
{
	f.push(this);
}

void ComplexFigure::show()
{
	//cout << "ComplexFigure:" << '\n';
	circle->show();
	triangle->show();
}

void ComplexFigure::replace(Point o1)
{
	triangle->replace(o1);
	circle->replace(o1);
}

void ComplexFigure::hide() {
	triangle->hide();
	circle->hide();
};