#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <fstream>

using namespace std;

void firstTask();
void secondTask();
void individualTask();
void additionalTask();

void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	while (true)
	{

		cout << "\t\t\t/////      /////  ////////  //////     ///  ///      ///\n";
		cout << "\t\t\t//////    //////  ////////  //////     ///  ///      ///\n";
		cout << "\t\t\t///  //////  ///  ///       /// ///    ///  ///      ///\n";
		cout << "\t\t\t///   ////   ///  //////    ///  ///   ///  ///      ///\n";
		cout << "\t\t\t///          ///  //////    ///   ///  ///  ///      ///\n";
		cout << "\t\t\t///          ///  ///       ///    /// ///  ///      ///\n";
		cout << "\t\t\t///          ///  ////////  ///     //////  ///      ///\n";
		cout << "\t\t\t///          ///  ////////  ///      /////  ////////////\n";
		cout << "\t\t\t--------------------------------------------------------\n";


		cout << "\t\t\t\t\t|1)Задание 1             |\n\t\t\t\t\t|2)Задание 2             |\n\t\t\t\t\t" <<
			"|3)Индивидуальное задание|\n\t\t\t\t\t|4)Дополнительное задание|\n\t\t\t\t\t---------------" <<
			"-----------\n\t\t\t\t\tВыбор: ";
		int menuChoice; cin >> menuChoice;

		switch (menuChoice)
		{
		case(1): { std::system("cls"); firstTask();      break; }
		case(2): { std::system("cls"); secondTask();     break; }
		case(3): { std::system("cls"); individualTask(); break; }
		case(4): { std::system("cls"); additionalTask(); break; }
		default: {std::cout << "Введено неверное значение..."; _getch(); std::system("cls"); break; }
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region firstGeneralTask

//Задание 1
//	Необходимо модифицировать программу, созданную по первому общему заданию из
//	прошлой лабораторной работы.Создать шаблон заданного класса IntSetMassive.Теперь класс
//	должен называться SetMassive и должен работать как минимум с любыми стандартными типами
//	данных(int, double, string и т.д.).


template<typename T>
class SetMassive
{
public:

	SetMassive()
	{
		this->pHead = nullptr;
		this->SIZE = 0;
	}
	~SetMassive()
	{
		clearAll();
	}
	int getSize()
	{
		return SIZE;
	}
	void pushBack(const T data)
	{
		if (SetMassive::chekValue(data))
			return;
		if (this->pHead == nullptr)
		{
			this->pHead = new Mass(data);
		}
		else {
			Mass* pTemp = this->pHead;
			while (pTemp->pNext != nullptr)
			{
				pTemp = pTemp->pNext;
			}
			pTemp->pNext = new Mass(data);
		}
		this->SIZE++;
	}
	void PrintMass()
	{
		Mass* pTemp = this->pHead;
		while (pTemp != nullptr)
		{
			cout << pTemp->data << " ";
			pTemp = pTemp->pNext;
		}
	}
	void deleteMass(const int index)
	{
		int counter = 0;
		Mass* pTemp = this->pHead;

		if (counter == index)
		{
			this->pHead = this->pHead->pNext;
			delete pTemp;
		}

		else
		{

			for (; counter < index - 1; counter++)
			{
				pTemp = pTemp->pNext;
			}

			Mass* pTempForDelete = pTemp->pNext;
			pTemp->pNext = pTempForDelete->pNext;
			delete pTempForDelete;
		}

		this->SIZE--;
	}
	void clearAll()
	{
		for (int i = 0; i < getSize(); i++)
		{
			deleteMass(i);
		}

		this->SIZE = 0;
	}
	bool chekValue(const T value)
	{
		Mass* pTemp = this->pHead;
		while (pTemp != nullptr) {
			if (pTemp->data == value)
			{
				return true;
			}
			pTemp = pTemp->pNext;
		}
		return false;
	}
	void operator+(const T data)
	{
		SetMassive::pushBack(data);
	}
	void operator+(const SetMassive& other)
	{
		Mass* pTemp = other.pHead;
		while (pTemp != nullptr)
		{
			SetMassive::pushBack(pTemp->data);
			pTemp = pTemp->pNext;
		}
	}
	void operator-(const T data)
	{
		if (SetMassive::chekValue(data))
		{
			deleteMass(getIndexOfValue(data));
		}
		else {
			cout << "none";
		}
	}
	void operator-(const SetMassive& other)
	{
		Mass* pTemp = other.pHead;
		while (pTemp != nullptr)
		{
			if (SetMassive::chekValue(pTemp->data))
			{
				cout << pTemp->data << " ";
			}
			pTemp = pTemp->pNext;
		}
		cout << "\n\t";
	}
	int& operator[](const int index)
	{
		Mass* pTemp = this->pHead;

		if (index == 0)
		{
			return pTemp->data;
		}

		else {
			int counter = 0;
			while (counter != index)
			{
				pTemp = pTemp->pNext;
				counter++;
			}
			return pTemp->data;
		}
	}
	int getIndexOfValue(const T value)
	{
		int counter = 0;
		Mass* pTemp = this->pHead;
		while (pTemp->data != value)
		{
			pTemp = pTemp->pNext;
			counter++;
		}
		return counter;
	}
	operator int() const
	{
		return SIZE;
	}

private:
	class Mass
	{
	public:
		T data;
		Mass* pNext;
		Mass(T data = 0, Mass* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int SIZE;
	Mass* pHead;
};

void firstTask()
{
	SetMassive<int> it1;

	it1.pushBack(1);
	it1.pushBack(1);
	it1.pushBack(2);
	it1.pushBack(3);
	it1.pushBack(4);

	SetMassive<int> it2;

	it2.pushBack(3);
	it2.pushBack(4);
	it2.pushBack(5);
	it2.pushBack(6);
	it2.pushBack(7);;

	SetMassive<string> it3;

	it3.pushBack("aaaaa");
	it3.pushBack("bbbbb");
	it3.pushBack("ccccc");

	SetMassive<string> it4;

	it4.pushBack("aaaaa");
	it4.pushBack("bbbbb");
	it4.pushBack("eeeee");
	it4.pushBack("fffff");

//////////////////////////////////////////////
	cout << "1-е множество: ";
	it1.PrintMass();

	cout << "\n2-е множество: ";
	it2.PrintMass();

	cout << "\n3-е множество: ";
	it3.PrintMass();

	cout << "\n4-е множество: ";
	it4.PrintMass();

//////////////////////////////////////////////	
	cout << "\n\nДобавили число в 1-е множество (17): ";
	it1 + 17;
	it1.PrintMass();

	cout << "\n\nУдалили число из 1-го множества (17): ";
	it1 - 17;
	it1.PrintMass();
//////////////////////////////////////////////
	cout << "\n\nПересечение множеств (1 и 2): ";
	it1 - it2;

	cout << "\n\nПересечение множеств (3 и 4): ";
	it3 - it4;
//////////////////////////////////////////////
	cout << "\n\nОбъединение множеств (1 и 2): ";
	it1 + it2;
	it1.PrintMass();

	cout << "\n\nОбъединение множеств (3 и 4): ";
	it3 + it4;
	it3.PrintMass();
//////////////////////////////////////////////
	cout << "\n\nВозврат мощности множества (2): ";

	int n = it2;
	cout << n;

	cout << "\n\nВозврат мощности множества (4): ";

	int g = it4;
	cout << g;
//////////////////////////////////////////////

	_getch(); system("cls");
}

#pragma endregion 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region secondTask
//Задание 2
//	На основе примера из теоретической части создайте интерфейс генератора ключей
//	IKeyGeneratable.Этот интерфейс должен иметь виртуальную функцию get(), которая возвращает в
//	виде строки сгенерированный ключ.
//	Создайте два класса - реализации интерфейса.
//	Первый класс(RandomKeyGenerator) должен в конструкторе принимать число – это
//	количество цифр в ключе.При вызове метода get() объект данного класса должен выдавать
//	случайное число из заданного количества цифр.К примеру, если количество – 5, то возвращаемые
//	значения : 10246, 56483, 78500, 00021 и т.д.
//	Первый класс(OrderKeyGenerator) должен в конструкторе принимать строку – с этой строки
//	должен начинаться каждый ключ.При вызове метода get() объект данного класса должен
//	последовательно выдавать числа, начиная с 0, вместе со строкой.К примеру, если задана строка
//	«key» то возвращаемые значения : key0, key1, key2, key3 и т.д.
//	Создайте в интерфейсе соответствующие функции - фабрики.Продемонстрируйте работу
//	через интерфейс на примере.

class IKeyGeneratable
{
public:
	virtual string get() = 0;
	static IKeyGeneratable* RKG(int n);
	static IKeyGeneratable* OKG(string str);
};

class RandomKeyGenerator : public IKeyGeneratable
{
public:
	RandomKeyGenerator() {}
	RandomKeyGenerator(int n)
	{
		this->n = n;
		size += 1;
	}
	string get() override
	{
		string str;
		srand(time(NULL));
		for (int i = 0; i < n; i++)
		{
			str += to_string(0 + rand() % 9);
		}
		return str;
	}
	friend IKeyGeneratable* IKeyGeneratable::RKG(int n);
	int GetN()
	{
		return n;
	}
protected:
	int n, size;
};

class OrderKeyGenerator : IKeyGeneratable, RandomKeyGenerator
{
public:
	OrderKeyGenerator() {}
	OrderKeyGenerator(string str)
	{
		this->str = str;
	}
	string get() override
	{
		str += to_string(size);
		return str;
	}
	friend IKeyGeneratable* IKeyGeneratable::OKG(string str);
private:
	string str;
};

IKeyGeneratable* IKeyGeneratable::RKG(int n)
{
	return static_cast<IKeyGeneratable*>(new RandomKeyGenerator(n));
}

IKeyGeneratable* IKeyGeneratable::OKG(string str)
{
	return static_cast<IKeyGeneratable*>(new OrderKeyGenerator(str));
}

void secondTask()
{
	IKeyGeneratable* a;
	a = IKeyGeneratable::OKG("Str");
	cout << a->get() << " : ";

	a = IKeyGeneratable::RKG(7);
	cout << a->get() << endl;
	
	cout << "\n\n\n";

	a = IKeyGeneratable::OKG("Key");
	cout << a->get() << " : ";

	a = IKeyGeneratable::RKG(8);
	cout << a->get() << endl;

	_getch();
	system("cls");
}

#pragma endregion

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region individualTask
//	Внесите в готовую программу из предыдущей лабораторной работы следующие изменения :
//	Измените класс списка – теперь это должен быть шаблон класса.Теперь вместо указателя на
//	абстрактный класс данных используйте тип, определяемый шаблоном.Этим типом может быть
//	один из подклассов данных.При необходимости перегрузите соответствующие операции.
//	Создайте интерфейсный класс, через который должна быть организована работа со списком.
//	Объявите в нем функцию - фабрику создающую список.Учтите, что интерфейсный класс также
//	должен быть реализован через шаблон, чтобы работать с шаблоном класса списка(как минимум
//	функция - фабрика должна быть шаблоном).

#include "Readers.h"

void individualTask()
{
	_getch();
}

#pragma endregion

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void additionalTask()
{
	_getch();
}