#include <iostream>
#include <cmath> //необходимо подключить для использования sqrt() - функции вычисления квадратного корня
using namespace std;

// структура - пользовательский тип данных; в отличие от класса, 
// статус доступа по умолчанию public (у класса private)
struct Vector
{
	int x1, y1, x2, y2;

	Vector() // это конструктор...
	{
		cin >> x1 >> y1 >> x2 >> y2;
	}

	Vector(int _x1, int _y1, int _x2, int _y2) // и это конструктор... Он перегружен
	{
		x1 = _x1;
		y1 = _y1;
		x2 = _x2;
		y2 = _y2;
	}

	float size() // это метод...
	{
		return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	}
};

Vector max(Vector v1, Vector v2) // возвращаем вектор, у которого больше длина (size) с:
{

	if (v1.size() > v2.size())
	{
		return v1;
	}
	else
	{
		return v2;
	}
}

int main()
{
	cout << "Enter coords (x1, y1, x2, y2) for 2 vectors" << endl;
	Vector v1, v2(); // эти записи равнозначны; вызывается конструктор Vector()
	Vector v3(1, 1, 1, 1); // вызывается конструктор Vector(int, int, int, int)
	/* 
	наличие двух и более функций с одним именем 
	(например, int function(), int function(int arg), float function()), 
	но разными параметрами, называется перегрузкой функции (функция function перегружена)
	*/
	cout << "Max vector" << max(v1, v2).x1 << ' ' << max(v1, v2).y1 << ' ' 
				<< max(v1, v2).x2 << ' ' << max(v1, v2).y2 << endl;
	
	int a, b;
	cout << "Enter 2 numbers to compare: ";
	cin >> a >> b;
	cout << "Max number" << max (a, b) << endl;
}