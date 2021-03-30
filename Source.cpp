#include<iostream>
#include<cmath>
#include<fstream>
#include<queue>
#pragma warning(disable:4996)

using namespace std;

class Base
{
public:
	virtual double Volume() = 0;
};


class Parallelepiped :public Base
{
protected:
	string name_Paralle;
	double a, b, c;
public: 
	Parallelepiped();

	void SetParalle();
	void SetParalle(string n, double a, double b, double c);
	void GetParalle();

	string ParalleGetNam();
	virtual double Volume(); // обьем фигуры 

	Parallelepiped& operator= (const Parallelepiped& ob);
	Parallelepiped(Parallelepiped& ob);

	friend ostream& operator<< (ostream& out, const Parallelepiped& figur);
	friend istream& operator >> (istream& in, Parallelepiped& figur);
};

class Pyramid :public Base
{
protected:
	string name_Pyram;
	double a, b, h;

public:
	Pyramid();
	void SetPyramid();
	void SetPyramid(string n, double a, double b, double h);
	void GetPyramid();

	string PyrGetNam();
	virtual double Volume();

	Pyramid& operator= (const Pyramid& ob);
	Pyramid(Pyramid& ob);

	friend ostream& operator<< (ostream& out, const Pyramid& figur);
	friend istream& operator >> (istream& in, Pyramid& figur);

};

class Tetrahedron :public Base {

protected: 
	string name_Teatra;
	double a;
public:
	Tetrahedron();
	void SetTetra();
	void SetTetra(string n, double a);
	void GetTetra();

	string TetraGetNam();
	virtual double Volume();

	Tetrahedron& operator= (const Tetrahedron& ob);
	Tetrahedron(Tetrahedron& ob);

	friend ostream& operator<< (ostream& out, const Tetrahedron& figur);
	friend istream& operator >> (istream& in, Tetrahedron& figur);

};

class Ball :public Base {

protected:
	string name_Ball;
	double r;

public:
	Ball();
	void SetBall();
	void SetBall(string n, double r);
	void GetBall();

	string BallGetNam();
	virtual double Volume();

	Ball& operator= (const Ball& ob);
	Ball(Ball& ob);

	friend ostream& operator<< (ostream& out, const Ball& figur);
	friend istream& operator >> (istream& in, Ball& figur);
};

class Conteiner
{
protected: 
	queue <Base> Figura;
	double GetVolum();	// Вывод все объемов
	void Push();		// Добавление ел. в очеридь
	void Edit();		// Изменения данных елемента
	void Get();			// Вывод масива обьектов
	void Sort();		// Сортировка масива по обьему
	void Delete();		// Удаление выбраного елемента
	void Open();		// Загрузка из файла
	void Save();		// Сохранение в файл 
};

/*######################	Parallelepiped		######################*/

Parallelepiped::Parallelepiped()
{
	name_Paralle = "Паралелeпипед";
	a = 10.1;
	b = 5.5;
	c = 9.1;
}

Parallelepiped& Parallelepiped::operator=(const Parallelepiped& ob)
{
	name_Paralle = ob.name_Paralle;
	a = ob.a;
	b = ob.b;
	c = ob.c;
	return *this; 
}

Parallelepiped::Parallelepiped(Parallelepiped& ob)
{
	name_Paralle = ob.name_Paralle;
	a = ob.a;
	b = ob.b;
	c = ob.c;
}

void Parallelepiped::SetParalle()
{
	cout << "Название: "; cin >> name_Paralle;
	cout << "Сторона а: "; cin >> a; 
	cout << "Сторона b: "; cin >> b; 
	cout << "Сторона с: "; cin >> c; 
}

void Parallelepiped::SetParalle(string m, double stor1, double stor2, double stor3)
{
	name_Paralle = m;
	a = stor1;
	b = stor2;
	c = stor3;
}

void Parallelepiped::GetParalle()
{
	cout << name_Paralle << "\t" << a << "\t" << b << "\t" << c;
}

string Parallelepiped::ParalleGetNam() 
{ 
	return name_Paralle; 
}

double Parallelepiped::Volume() 
{ 
	cout << "Обьем паралелепипеда = ";
	return a * b * c; 
}

ostream& operator<<(ostream& out, const Parallelepiped& figur)
{
	out << figur.name_Paralle << "\t" << figur.a << "\t" << figur.b << "\t" << figur.c << endl;
	return out;
}

istream& operator>>(istream& in, Parallelepiped& figur)
{
	in >> figur.name_Paralle >> figur.a >> figur.b >> figur.c;
	return in;
}


/*######################	Pyramid		######################*/

Pyramid::Pyramid()
{
	name_Pyram = "Пирамида";
	a = 2.1;
	b = 3;
	h = 5.5;
}

Pyramid& Pyramid::operator=(const Pyramid& ob)
{
	name_Pyram = ob.name_Pyram;
	a = ob.a;
	b = ob.b;
	h = ob.h;
	return *this;
}

Pyramid::Pyramid(Pyramid& ob)
{
	name_Pyram = ob.name_Pyram;
	a = ob.a;
	b = ob.b;
	h = ob.h;
}

void Pyramid::SetPyramid()
{
	cout << "Название: "; cin >> name_Pyram;
	cout << "Сторона а: "; cin >> a;
	cout << "Сторона b: "; cin >> b;
	cout << "Высота h: "; cin >> h;
}

void Pyramid::SetPyramid(string m, double stor1, double stor2, double visota)
{
	name_Pyram = m;
	a = stor1;
	b = stor2;
	h = visota;
}

void Pyramid::GetPyramid()
{
	cout << name_Pyram << "\t" << a << "\t" << b << "\t" << h;
}

string Pyramid::PyrGetNam()
{
	return name_Pyram;
}

double Pyramid::Volume()
{
	cout << "Обьем пирамиды = ";
	return (a * b * h)/3;
}

ostream& operator<<(ostream& out, const Pyramid& figur)
{
	out << figur.name_Pyram << "\t" << figur.a << "\t" << figur.b << "\t" << figur.h << endl;
	return out;
}

istream& operator>>(istream& in, Pyramid& figur)
{
	in >> figur.name_Pyram >> figur.a >> figur.b >> figur.h;
	return in;
}


/*######################	Tetrahedron		######################*/

Tetrahedron::Tetrahedron()
{
	name_Teatra = "Тетраэдр";
	a = 12.1;
}

Tetrahedron& Tetrahedron::operator=(const Tetrahedron& ob)
{
	name_Teatra = ob.name_Teatra;
	a = ob.a;
	return *this;
}

Tetrahedron::Tetrahedron(Tetrahedron& ob)
{
	name_Teatra = ob.name_Teatra;
	a = ob.a;
}

void Tetrahedron::SetTetra()
{
	cout << "Название: "; cin >> name_Teatra;
	cout << "Сторона а: "; cin >> a;
}

void Tetrahedron::SetTetra(string m, double stor)
{
	name_Teatra = m;
	a = stor;
}

void Tetrahedron::GetTetra()
{
	cout << name_Teatra << "\t" << a;
}

string Tetrahedron::TetraGetNam()
{
	return name_Teatra;
}

double Tetrahedron::Volume()
{
	cout << "Обьем тетраэдра = ";
	return (pow(a, 3) * sqrt(2)) / 12;
}

ostream& operator<<(ostream& out, const Tetrahedron& figur)
{
	out << figur.name_Teatra << "\t" << figur.a << endl;
	return out;
}

istream& operator>>(istream& in, Tetrahedron& figur)
{
	in >> figur.name_Teatra >> figur.a;
	return in;
}


/*######################	Ball	######################*/

Ball::Ball()
{
	name_Ball = "";
	r = 0.99;
}

Ball& Ball::operator=(const Ball& ob)
{
	name_Ball = ob.name_Ball;
	r = ob.r;
	return *this;
}

Ball::Ball(Ball& ob)
{
	name_Ball = ob.name_Ball;
	r = ob.r;
}

void Ball::SetBall()
{
	cout << "Название: "; cin >> name_Ball;
	cout << "Радиус r: "; cin >> r;
}

void Ball::SetBall(string m, double radius)
{
	name_Ball = m;
	r = radius;
}

void Ball::GetBall()
{
	cout << name_Ball << "\t" << r;
}

string Ball::BallGetNam()
{
	return name_Ball;
}

double Ball::Volume()
{
	cout << "Обьем тетраэдра = ";
	return 4 / 3 * 3.14 * pow(r, 3);
}

ostream& operator<<(ostream& out, const Ball& figur)
{
	out << figur.name_Ball << "\t" << figur.r << endl;
	return out;
}

istream& operator>>(istream& in, Ball& figur)
{
	in >> figur.name_Ball >> figur.r;
	return in;
}

