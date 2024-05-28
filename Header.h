#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <conio.h>
#include <string>

const int MAX = 10;

using namespace std;

class Date
{
public:

	Date();

	Date(int d, int m, int g);

	~Date();

	// Перегрузка оператора вывода класса Дата
	friend ostream& operator<<(ostream&, const Date&);

	// Перегрузка оператора ввода класса Дата
	friend istream& operator>>(istream&, Date&);

private:

	int dd;
	int mm;
	int gg;

};

class Product : virtual protected Date
{
public:
	/// <summary>
	/// Сеттер цены
	/// </summary>
	/// <param name="price"></param>
	void SetPrice(double price);

	/// <summary>
	/// Сеттер количества товара
	/// </summary>
	/// <param name="count"></param>
	void SetCnt(int count);

	/// <summary>
	/// Геттер цены
	/// </summary>
	/// <returns>Цена товара</returns>
	double GetPrice() const;

	/// <summary>
	/// Геттер количества товара
	/// </summary>
	/// <returns>Количество товара</returns>
	int GetCnt() const;

	/// <summary>
	/// Сеттер даты прихода товара
	/// </summary>
	/// <param name="">Дата прихода товара</param>
	void SetDelivery(Date&);

	/// <summary>
	/// Сеттер даты продажи
	/// </summary>
	/// <param name="">Дата продажи</param>
	void SetSale(Date&);

	/// <summary>
	/// Геттер даты прихода товара
	/// </summary>
	/// <returns>Дата прихода товара</returns>
	Date GetDelivery() const;

	/// <summary>
	/// Геттер даты продажи товара
	/// </summary>
	/// <returns>Дата продажи товара</returns>
	Date GetSale() const;

	/// <summary>
	/// Виртуальная функция 
	/// </summary>
	/// <returns>Класс принадлежности</returns>
	virtual string Accesories() = 0;

	/// <summary>
	/// Геттер для названия фирмы/компании
	/// </summary>
	/// <returns></returns>
	virtual string getBrand() = 0;

protected:

	double price = -1;

	int count = 0;

	Date Delivery;

	Date Sale;

};

class Foodstuff : public Product
{
public:

	Foodstuff();

	~Foodstuff();

	string Accesories() override;

	string getBrand() override;

	int getCateg() const;

	// перегрузка оператора ввода класса Продукты
	friend istream& operator>>(istream&, Foodstuff&); 

	// перегрузка оператора вывода класса Продукты
	friend ostream& operator<<(ostream&, const Foodstuff&); 

private:

	enum categs {
		fish, meat, milk, bread
	};

	int num_categ;

	string brand;

};

class Furniture : public Product
{
public:

	Furniture();

	~Furniture();

	string getRoom();

	string getBrand() override;

	string getName();

	string Accesories() override;

	// Перегрузка оператора ввода класса Мебель
	friend istream& operator>>(istream&, Furniture&); 

	// Перегрузка оператора вывода класса Мебель
	friend ostream& operator<<(ostream&, const Furniture&); 

private:
	
	string room;

	string brand;

	string name;

};

class Car : public Product
{
public:

	Car();

	Car(string b_c, string m);

	~Car();

	void setBrand(string s);

	void setModel(string s);

	void setNomer(string s);

	string getBrand();

	string getModel();

	string getNomer();

	string Accesories() override;

	// Перегрузка оператора ввода класса Автомобиль
	friend istream& operator>>(istream&, Car&); 

	// Перегрузка оператора вывода класса Автомобиль
	friend ostream& operator<<(ostream&, const Car&); 

private:

	string brand;

	string model;

	string gos_nomer;

};

void DeleteCar(Car* cars, int& count);

void DeleteFoodstuff(Foodstuff foods[], int& count);

void DeleteFurniture(Furniture furniture[], int& count);

void controlReg(string& str);