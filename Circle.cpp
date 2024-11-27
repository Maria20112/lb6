#include "Circle.h"

Circle::Circle(StackOfFigures& f, Point o, int r, COLORREF c, COLORREF p) : Figure(o, r, c, p)
{
	if (o.x < 0) throw Attributes("Circle: x");
	if (o.y < 0) throw Attributes("Circle: y");
	if (R < 0) throw Attributes("Circle: R");
	f.push(this);
}

void Circle::show()
{
	Figure::show();
	if (o.x - R <= rt.left) throw Border("Circle нарушает левую границу окна");
	if (o.x + R >= rt.right) throw Border("Circle нарушает правую границу окна");
	if (o.y - R <= rt.top) throw Border("Circle нарушает верхнюю границу окна");
	if (o.y + R >= rt.bottom) throw Border("Circle нарушает нижнюю границу окна");
    Ellipse(hdc, o.x - R, o.y - R, o.x + R, o.y + R);
    DeleteObject(pen);
    DeleteObject(brush);
}

void Circle::hide()
{
	Figure::hide();
	Ellipse(hdc, o.x - R, o.y - R, o.x + R, o.y + R);
	DeleteObject(pen);
	DeleteObject(brush);
}

void Circle::replace(Point o1)
{
	hide();
	Figure::replace(o1);
	show();
}