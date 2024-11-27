#include "Triangle.h"

Triangle::Triangle(StackOfFigures& f, Point o, int R, COLORREF color, COLORREF p) : Figure(o, R, color, p)
{
	if (o.x < 0) throw Attributes("Triangle: x");
	if (o.y < 0) throw Attributes("Triangle: y");
	if (R < 0) throw Attributes("Triangle: R");
	a.x = o.x;
	a.y = o.y + R;
	b.x = o.x;
	b.y = o.y - R;
	c.x = o.x + R;
	c.y = o.y;
	f.push(this);
}

void Triangle::show()
{
	Figure::show();
	if (o.y - R <= rt.top) throw Border("Triangle нарушает верхнюю границу окна");
	if (o.x + R >= rt.right) throw Border("Triangle нарушает правую границу окна");
	if (o.x - R <= rt.left) throw Border("Triangle нарушает левую границу окна");
	if (o.y + R >= rt.bottom) throw Border("Triangle нарушает нижнюю границу окна");
	POINT points[] = { {a.x, a.y}, {b.x, b.y}, {c.x, c.y} };
	Polygon(hdc, points, 3);
	DeleteObject(pen);
	DeleteObject(brush);
}

void Triangle::replace(Point o1)
{
	hide();
	int R = a.y - o.y;
	Figure::replace(o1);
	a.x = o.x;
	a.y = o.y + R;
	b.x = o.x;
	b.y = o.y - R;
	c.x = o.x + R;
	c.y = o.y;
	show();
}

void Triangle::hide()
{
	Figure::hide();
	POINT points[] = { {a.x, a.y}, {b.x, b.y}, {c.x, c.y} };
	Polygon(hdc, points, 3);
	DeleteObject(pen);
	DeleteObject(brush);
}