#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <windows.h>
#include <windowsx.h>
#include <string>
using namespace std;

/*Бояринова 23ВП1 вариант 3 
Прямоугольный треугольник, вписанный в окружность; базовый класс; агрегация; стек как динамический массив
*/

class Border {
public:
	Border(string m): mes(m) { };
	virtual string getMessage() const;
private:
	string mes;
};

class Attributes {
public:
	Attributes(string m) : mes(m) { };
	virtual string getMessage() const;
private:
	string mes;
};

struct Point
{
	int x, y;
	friend std::ostream& operator<< (std::ostream& out, Point& a) {
		out << a.x << ", " << a.y << "\n";
		return out;
	}
};

class Figure
{
public:
	Figure(Point o0, int r, COLORREF c, COLORREF p); 
	virtual void show();
	virtual void replace(Point o1);
	virtual void hide();
protected:
	Point o;
	int R;
	HWND hwnd;
	HDC hdc;
	RECT rt;
	COLORREF color;
	COLORREF colorpen;
	HPEN pen;
	HBRUSH brush;
};

class StackOfFigures : public stack <Figure*, vector <Figure*>>
{
public:
	stack <Figure*, vector <Figure*>> v;
	StackOfFigures() {};
	void show();
	~StackOfFigures();
};