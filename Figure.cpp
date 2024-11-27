#include "Figure.h"

string Border::getMessage() const { return mes; }

string Attributes::getMessage() const { return "Error: " + mes + ". ѕараметры фигуры не должны быть отрицательными"; }

Figure::Figure(Point o0, int r, COLORREF c, COLORREF p) : o(o0), R(r), color(c), colorpen(p)
{
	hwnd = GetConsoleWindow();
	hdc = GetDC(hwnd);
	GetClientRect(hwnd, &rt);
};

void Figure::show()
{
	HPEN pen = CreatePen(PS_SOLID, 2, colorpen);
	SelectObject(hdc, pen);
	HBRUSH brush = CreateSolidBrush(color);
	SelectObject(hdc, brush);
}

void Figure::replace(Point o1)
{
	if (o.x < 0) throw Attributes("Replace: x");
	if (o.y < 0) throw Attributes("Replace: y");
	if (R < 0) throw Attributes("Replace: R");
	o.x = o1.x;
	o.y = o1.y;
}

void Figure::hide()
{
	HPEN pen = CreatePen(PS_SOLID, 2, GetBkColor(hdc));
	HBRUSH brush = CreateSolidBrush(GetBkColor(hdc));
	SelectObject(hdc, brush);
	SelectObject(hdc, pen);
}

void StackOfFigures::show() {
	for (auto i : c)
		i->show();
}

StackOfFigures::~StackOfFigures() {
	c.clear();
}