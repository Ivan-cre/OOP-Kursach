#include<iostream>
#include<string>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<queue>
#pragma warning(disable:4996)

using namespace std;

class Base
{
public:
	virtual double Volume() = 0;
	virtual void Get() = 0;
	virtual void Get(string)=0;
	virtual void Set() = 0;
	string name;
	int type=0;
};



class Parallelepiped :public Base
{
protected:
	string name;
	double a, b, c;
public: 
	Parallelepiped();
	Parallelepiped(double, double, double);

	virtual void Set();
	void SetParalle(double, double, double);
	virtual void Get();
	virtual void Get(string);				// метод для чтения с файла

	string ParalleGetNam();
	virtual double Volume();				// обьем фигуры 

	Parallelepiped& operator= (const Parallelepiped&);
	Parallelepiped(Parallelepiped&);

	friend ostream& operator << (ostream&, const Parallelepiped&);
	friend istream& operator >> (istream&, Parallelepiped&);
};

class Pyramid :public Base
{
protected:
	string name;
	double a, b, h;

public:
	Pyramid();
	Pyramid(double, double, double);

	virtual void Set();
	void SetPyramid(double, double, double);
	virtual void Get();
	virtual void Get(string);						// метод для чтения с файла

	string PyrGetNam();
	virtual double Volume();						// обьем фигуры 

	Pyramid& operator= (const Pyramid&);
	Pyramid(Pyramid&);

	friend ostream& operator<< (ostream&, const Pyramid&);
	friend istream& operator >> (istream&, Pyramid&);

};

class Tetrahedron :public Base {

protected: 
	string name;
	double a;
public:
	Tetrahedron();
	Tetrahedron(double);

	virtual void Set();
	void SetTetra(string, double);
	virtual void Get();
	virtual void Get(string);						// метод для чтения с файла

	string TetraGetNam();
	virtual double Volume();						// обьем фигуры 

	Tetrahedron& operator= (const Tetrahedron&);
	Tetrahedron(Tetrahedron&);

	friend ostream& operator<< (ostream&, const Tetrahedron&);
	friend istream& operator >> (istream&, Tetrahedron&);

};

class Ball :public Base {

protected:
	string name;
	double r;
public:
	Ball();
	Ball(double);
	virtual void Set();
	void SetBall(string, double);
	virtual void Get();
	virtual void Get(string);						// метод для чтения с файла

	string BallGetNam();
	virtual double Volume();						// обьем фигуры 

	Ball& operator= (const Ball&);
	Ball(Ball&);

	friend ostream& operator<< (ostream&, const Ball&);
	friend istream& operator >> (istream&, Ball&);
};

class Conteiner
{
public:
	queue <Base*> Figura;
	double GetVolum();	// Вывод все объемов
	void Push();		// Добавление ел. в очеридь
	void Show();		// Вывод масива обьектов
	void Edit();		// Изменения данных елемента
	void Sort();		// Сортировка масива по обьему
	void Delete();		// Удаление выбраного елемента
	void Load();		// Загрузка из файла
	void Save();		// Сохранение в файл 
	void Menu();		// Меню программы
};

/*######################	Parallelepiped		######################*/

Parallelepiped::Parallelepiped()
{
	name = "Parallelepiped"; type = 1;
	a = 0;
	b = 0;
	c = 0;

}

Parallelepiped::Parallelepiped(double side1, double side2, double side3)
{
	name = "Parallelepiped"; type = 1;
	a = side1;
	b = side2;
	c = side3;
}

Parallelepiped& Parallelepiped::operator=(const Parallelepiped& ob)
{
	name = ob.name;
	a = ob.a;
	b = ob.b;
	c = ob.c;
	return *this; 
}

Parallelepiped::Parallelepiped(Parallelepiped& ob)
{
	name = ob.name;
	a = ob.a;
	b = ob.b;
	c = ob.c;
}

void Parallelepiped::Set()
{
	cout << "--------- Parallelepiped ---------" << endl;
	cout << "Сторона а: "; cin >> a; 
	cout << "Сторона b: "; cin >> b; 
	cout << "Сторона с: "; cin >> c; 
	cout << "----------------------------------" << endl;
}

void Parallelepiped::SetParalle(double side1, double side2, double side3)
{
	name = "Parallelepiped";
	a = side1;
	b = side2;
	c = side3;
}

void Parallelepiped::Get()
{
	cout <<name.append(' ',100).substr(0, 14)<< setw(2) << "|" << setw(3) << a << "  " << "|" << setw(3) << b << "  " << "|" << setw(3) << c << "  " << "|" << endl;
}

void Parallelepiped::Get(string path)
{
	ofstream fs;
	fs.open(path, fstream::app);
	fs << type << "\t" << a << "\t" << b << "\t" << c << endl;
}

string Parallelepiped::ParalleGetNam() 
{ 
	return name; 
}

double Parallelepiped::Volume() 
{ 
	cout << "Паралелепипед = ";
	return a * b * c;
}

ostream& operator<<(ostream& out, const Parallelepiped& figur)
{
	out << figur.name << "\n" << figur.a << "\t" << figur.b << "\t" << figur.c << endl;
	return out;
}

istream& operator>>(istream& in, Parallelepiped& figur)
{
	in >> figur.name >> figur.a >> figur.b >> figur.c;
	return in;
}


/*######################	Pyramid		######################*/

Pyramid::Pyramid()
{
	name = "Pyramid"; type = 2;
	a = 0;
	b = 0;
	h = 0; 
}

Pyramid::Pyramid(double side1, double side2, double height) 
{
	name = "Pyramid"; type = 2;
	a = side1; 
	b = side2;
	h = height;
}

Pyramid& Pyramid::operator=(const Pyramid& ob)
{
	name = ob.name;
	a = ob.a;
	b = ob.b;
	h = ob.h;
	return *this;
}

Pyramid::Pyramid(Pyramid& ob)
{
	name = ob.name;
	a = ob.a;
	b = ob.b;
	h = ob.h;
}

void Pyramid::Set()
{
	cout << "--------- Pyramid ---------" << endl;
	cout << "Сторона а: "; cin >> a;
	cout << "Сторона b: "; cin >> b;
	cout << "Высота h: "; cin >> h;
}

void Pyramid::SetPyramid(double side1, double side2, double height)
{
	name = "Pyramid";
	a = side1;
	b = side2;
	h = height;
}

void Pyramid::Get()
{
	 
	cout << name.append(' ', 100).substr(0, 7) << setw(9) << "|" << setw(3) << a << "  " << "|" << setw(3) << b << "  " << "|" << setw(3) << h << "  " << "|" << endl;
}

void Pyramid::Get(string path)
{
	ofstream fs;
	fs.open(path, fstream::app);
	fs << type << "\t" << a << endl;
}

string Pyramid::PyrGetNam()
{
	return name;
}

double Pyramid::Volume()
{
	cout << "Пирамида = ";
	return (a * b * h)/3;
}

ostream& operator<<(ostream& out, const Pyramid& figur)
{
	out << figur.name << "\n" << figur.a << "\t" << figur.b << "\t" << figur.h << endl;
	return out;
}

istream& operator>>(istream& in, Pyramid& figur)
{
	in >> figur.name >> figur.a >> figur.b >> figur.h;
	return in;
}


/*######################	Tetrahedron		######################*/

Tetrahedron::Tetrahedron()
{
	name = "Tetrahedron"; type = 3;
	a = 0;
}

Tetrahedron::Tetrahedron(double side)
{
	name = "Tetrahedron"; type = 3;
	a = side;
}

Tetrahedron& Tetrahedron::operator=(const Tetrahedron& ob)
{
	name = ob.name;
	a = ob.a;
	return *this;
}

Tetrahedron::Tetrahedron(Tetrahedron& ob)
{
	name = ob.name;
	a = ob.a;
}

void Tetrahedron::Set()
{
	cout << "--------- Tetrahedron ---------" << endl;
	cout << "Сторона а: "; cin >> a;
}

void Tetrahedron::SetTetra(string m, double stor)
{
	name = m;
	a = stor;
}

void Tetrahedron::Get()
{
	cout << name.append(' ', 100).substr(0, 11) << setw(5) << "|" << setw(3) << a << "  " << "|" << endl;
}

void Tetrahedron::Get(string path)
{
	ofstream fs;
	fs.open(path, fstream::app);
	fs << type << "\t" << a << endl;
}

string Tetrahedron::TetraGetNam()
{
	return name;
}

double Tetrahedron::Volume()
{
	cout << "Тетраедр = ";
	return (pow(a, 3) * sqrt(2)) / 12;
}

ostream& operator<<(ostream& out, const Tetrahedron& figur)
{
	out << figur.name << "\n" << figur.a << endl;
	return out;
}

istream& operator>>(istream& in, Tetrahedron& figur)
{
	in >> figur.name >> figur.a;
	return in;
}


/*######################	Ball	######################*/

Ball::Ball()
{
	name = "Ball  "; type = 4;
	r = 0.99;
}

Ball::Ball(double radius)
{
	name = "Ball  "; type = 4;
	r = radius;
}

Ball& Ball::operator=(const Ball& ob)
{
	name = ob.name;
	r = ob.r;
	return *this;
}

Ball::Ball(Ball& ob)
{
	name = ob.name;
	r = ob.r;
}

void Ball::Set()
{
	cout << "--------- Ball ---------" << endl;
	cout << "Радиус r: "; cin >> r;
}

void Ball::SetBall(string m, double radius)
{
	name = m;
	r = radius;
}

void Ball::Get()
{
	cout << name.append(' ', 100).substr(0, 6) << setw(10) << "|" << setw(3) << r << "  " << "|\t" << endl;
}

void Ball::Get(string path)
{
	ofstream fs;
	fs.open(path, fstream::app);
	fs << type << "\t" << r << endl;
}

string Ball::BallGetNam()
{
	return name;
}

double Ball::Volume()
{
	cout << "Сфера = ";
	return 4 / 3 * 3.14 * pow(r, 3);
}

ostream& operator<<(ostream& out, const Ball& figur)
{
	out << figur.name << "\n" << figur.r << endl;
	return out;
}

istream& operator>>(istream& in, Ball& figur)
{
	in >> figur.name >> figur.r;
	return in;
}

/*######################	Сonteiner	######################*/

void Conteiner::Push()
{
	double a, b, c, h, r;
	int select = 1;
	while (select != 0)
	{
		cout << "----------- Добавление -----------" << endl;
		cout << "1. Добавить Паралелепипед" << endl;
		cout << "2. Добавить Пирамиду" << endl;
		cout << "3. Добавить Tетраедр" << endl;
		cout << "4. Добавить Сферу" << endl;
		cout << "0. Назад в меню " << endl;
		cout << "Выберите пункт --> "; cin >> select;

		switch (select) 
		{
		case 1: { cout << "Ведите: a, b и c => "; cin >> a; cin >> b; cin >> c;
			Figura.push(new Parallelepiped(a, b, c)); break; }

		case 2: {
			cout << "Введите: a, b и h =>"; cin >> a >> b >> h;
			Figura.push(new Pyramid(a, b, h)); break; }

		case 3: { cout << "Введите: a => "; cin >> a;
			Figura.push(new Tetrahedron(a)); break; }

		case 4: {cout << "Введите: r => "; cin >> r;
			Figura.push(new Ball(r)); break; }
		case 0: break;
		default:cout << "Введите другое значение" << endl;
		}
		system("pause");
		system("cls");
	}
}

void Conteiner::Show()
{
	int count = 1;
	int select = 1;
	queue <Base*> tmp = Figura; 

	system("cls");

	cout << "------------- Вывод данных -------------" << endl;
	cout << "----------------------------------------" << endl;
	cout << "| № |      NAME      |  a  |  b  |  c  |" << endl;
	cout << "----------------------------------------" << endl;
	while(!tmp.empty())
	{
		cout << "| " << count++ << " | "; tmp.front()->Get(); tmp.pop();
	}
	system("pause");
}

void Conteiner::Edit()//редагування довільного елемента
{
	int i = 0, n;
	system("cls");
	this->Show();
	cout << "Введите номер редактируемого элемента -> ";
	cin >> n;
	if (n< 1 || n > Figura.size())
	{
		fprintf(stderr, "Элемент с номером % d не существует\n " , n); 
		system("pause");
		return;
	}
	n--;
	queue<Base*> tmp;
	Base* edi;
	while (i < n)
	{
		tmp.push(Figura.front()); Figura.pop(); i++;
	}
	edi = Figura.front(); Figura.pop(); edi->Set();
	Figura.push(edi);
	while (!tmp.empty())
	{
		Figura.push(tmp.front()); tmp.pop();
	}
	cout << "Редактирование прошло успешно" << endl;
	system("pause");
}

int minIndex(queue<Base*>& q, int sortedIndex)
{
	int min_index = -1;
	Base* min_val = q.front();
	int n = q.size();
	for (int i = 0; i < n; i++)
	{
		Base* curr = q.front();
		q.pop();

		if (curr->type <= min_val->type && i <= sortedIndex)
		{
			min_index = i;
			min_val = curr;
		}
		q.push(curr);
	}
	return min_index;
}

void insertMinToRear(queue<Base*>& q, int min_index)
{
	Base* min_val;
	int n = q.size();
	for (int i = 0; i < n; i++)
	{
		Base* curr = q.front();
		q.pop();
		if (i != min_index)
			q.push(curr);
		else
			min_val = curr;
	}
	q.push(min_val);
}

void sortQueue(queue<Base*>& q)
{
	for (int i = 1; i <= q.size(); i++)
	{
		int min_index = minIndex(q, q.size() - i);
		insertMinToRear(q, min_index);
	}
}

void Conteiner::Sort() // сортировка елементов за типом фигуры 
{
	sortQueue(Figura);
	cout << "Очередь отсортирована" << endl;
	system("pause");
}

void Conteiner::Delete()				//видалення довільного елемента з контейнера queue
{
	this->Show();
	int i = 0, n;
	cout << "Введите номер удаляемого элемента -> ";
	cin >> n;
	
	if (n< 1 || n > Figura.size())
	{
		fprintf(stderr, " Элемент с номером % d не существует\n" , n); return;
	}
	else {
		int len = Figura.size();
		for (int i = 1; i <= len; i++) {
			if (i != n) {
				Figura.push(Figura.front());
			}Figura.pop();
		}
		cout << " удалён.\n";
	}
	system("pause");
}

void Conteiner::Load()//читання з файлу та запис до контейнеру
{
	string namefile;
	cout << "Введите имя файла: ";	cin >> namefile;

	ifstream f(namefile, ios::in);

	if (f.is_open()) {
		string line;
		while (!f.eof()) {
			int t,a,b,c; f >> t;
			switch (t) {
			case 1: f >> a >> b >> c; Figura.push(new Parallelepiped(a,b,c)); break;
			case 2: f >> a >> b >> c; Figura.push(new Pyramid(a, b, c)); break;
			case 3: f >> a; Figura.push(new Tetrahedron(a)); break;
			case 4: f >> a; Figura.push(new Ball(a)); break;
			}
			Figura.back()->type = t;
		}
		f.close();
	}
	cout << "Файл загружен.\n";
}

void Conteiner::Save() 
{
	string path;

	cout << "Введите название файла в который хотите сохранить данные "; cin >> path;
	ofstream fs;
	fs.open(path, fstream::app);

	if (!fs.is_open())
	{
		cout << "Ошибка открытия файла!!!!" << endl;
	}
	else 
	{
		queue<Base*> tmp = Figura;
		while (!tmp.empty())
		{
			tmp.front()->Get(path); tmp.pop();
		}
		cout << "Сохранено в файл" << endl;
		system("pause");
	}
	fs.close();
}

double Conteiner::GetVolum() 
{
	queue<Base*> tmp = Figura;
	cout << "\t\t" << "Обьем фигур " << endl;
	cout << "------------------------------------------" << endl;
	/*cout << "Паралелепипед" << setw(2) << "|" << setw(2) << "Пирамидa" << setw(2) << "|" << setw(2) << "Tетраедр" << setw(2) << "|" << setw(2) << "Сфера" << setw(2) << "|" << endl;
	cout << "------------------------------------------\n";*/
	while (!tmp.empty())
	{
		cout << tmp.front()->Volume(); tmp.pop(); cout << endl;
	}
	system("pause");
	return 1;
}

void Conteiner::Menu()
{
	int select = 1;
	while (select != 0) 
	{
		system("cls");
		cout << "------------- Главное Меню -------------\n";
		cout << "----------------------------------------" << endl;
		cout << "| 1. Добавить ел. в очередь" << setw(14) << "|\n";
		cout << "| 2. Вывод данных" << setw(24) << "|\n";
		cout << "| 3. Изменить данные" << setw(21) << "|\n";
		cout << "| 4. Вывод всех обьемов" << setw(18) << "|\n";
		cout << "| 5. Сортировка данных (по типам фигур)" << "|\n";
		cout << "| 6. Удаление данных" << setw(21) << "|\n";
		cout << "| 7. Загрузить из файла данные" << setw(11) << "|\n";
		cout << "| 8. Сохранить елементы очереди в файл" << setw(3) << "|\n";
		cout << "| 0. Выход с программы" << setw(19) << "|\n";
		cout << "----------------------------------------" << endl;
		cout << "Выберите пункт: "; cin >> select;

		switch (select)
		{	
		case 1: 
		{
			system("cls");
			Push(); break;
		}
		case 2:
		{
			system("cls");
			Show(); break;
		}
		case 3:
		{
			system("cls");
			Edit(); break;
		}
		case 4: 
		{
			system("cls");
			GetVolum(); break;
		}
		case 5: 
		{
			system("cls");
			Sort(); break;
		}
		case 6:
		{
			system("cls");
			Delete(); break;
		}
		case 7:
		{
			system("cls");
			Load(); break;
		}
		case 8: 
		{
			system("cls");
			Save(); break;
		}
		case 0: exit(0); break;
		default:
			cout << "Введите другое число" << endl;
			system("pause");
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	Conteiner obj;
	obj.Menu();
	return 0;
}