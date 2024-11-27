// OOP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Figure.h"
#include "Triangle.h"
#include "Circle.h"
#include "ComplexFigure.h"

int main()
{
    const int NotUsed = system("color F0");
    SetConsoleTitle((LPCWSTR)L"23VP1_3");
    setlocale(LC_ALL, "Russian");
    StackOfFigures f;
    try {
        Triangle* a = new Triangle(f, { 200, 300 }, 100, RGB(255, 255, 0), RGB(0, 0, 0));
        /*(new Circle(f, {70, 70}, 30, RGB(0, 255, 0), RGB(0, 0, 0)))->show();
        (new Circle(f, { 350, 150 }, 100, RGB(255, 0, 0), RGB(0, 0, 255)))->show();
        (new Triangle(f, { 500, 400 }, 70, RGB(255, 255, 0), RGB(120, 120, 0)))->show();
        (new Triangle(f, { 700, 200 }, 150, RGB(0, 255, 255), RGB(0, 255, 0)))->show();
        (new Triangle(f, { 100, 300 }, 70, RGB(0, 255, 0), RGB(0, 0, 0)))->show();
        //new Triangle(f, { 350, -150 }, 50, RGB(255, 0, 0), RGB(0, 0, 0));
        (new Circle(f, { 500, 250 }, 100, RGB(255, 255, 0), RGB(0, 0, 0)))->show();
        (new Triangle(f, { 70, 100 }, 50, RGB(0, 255, 0), RGB(255, 0, 255)))->show();
        (new Circle(f, { 450, 250 }, 100, RGB(255, 255, 0), RGB(0, 0, 255)))->show();
        (new Circle(f, { 700, 250 }, 60, RGB(0, 255, 255), RGB(0, 255, 0)))->show();
        //(new Triangle(f, { 800, 70 }, 150, RGB(0, 255, 0), RGB(0, 0, 0)))->show();
        //(new Circle(f, { 1000, 70 }, 20, RGB(0, 255, 0), RGB(0, 255, 0)))->show();*/
        ComplexFigure* comp = new ComplexFigure(f, new Triangle(f, { 600, 300 }, 150, RGB(255, 255, 0), RGB(0, 0, 0)),
            new Circle(f, { 170, 70 }, 20, RGB(0, 255, 0), RGB(0, 0, 0)));
        Sleep(1200);
        f.show();
        Sleep(1000);
        a->replace({850, 350});
        f.show();
    }
    catch (const Border& ex) 
    {
        cout << ex.getMessage() << '\n';
    }
    catch (const Attributes& ex)
    {
        cout << ex.getMessage() << '\n';
    }
    Sleep(3600);
    COORD p = { 5, 25 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
