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

	// ���������� ��������� ������ ������ ����
	friend ostream& operator<<(ostream&, const Date&);

	// ���������� ��������� ����� ������ ����
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
	/// ������ ����
	/// </summary>
	/// <param name="price"></param>
	void SetPrice(double price);

	/// <summary>
	/// ������ ���������� ������
	/// </summary>
	/// <param name="count"></param>
	void SetCnt(int count);

	/// <summary>
	/// ������ ����
	/// </summary>
	/// <returns>���� ������</returns>
	double GetPrice() const;

	/// <summary>
	/// ������ ���������� ������
	/// </summary>
	/// <returns>���������� ������</returns>
	int GetCnt() const;

	/// <summary>
	/// ������ ���� ������� ������
	/// </summary>
	/// <param name="">���� ������� ������</param>
	void SetDelivery(Date&);

	/// <summary>
	/// ������ ���� �������
	/// </summary>
	/// <param name="">���� �������</param>
	void SetSale(Date&);

	/// <summary>
	/// ������ ���� ������� ������
	/// </summary>
	/// <returns>���� ������� ������</returns>
	Date GetDelivery() const;

	/// <summary>
	/// ������ ���� ������� ������
	/// </summary>
	/// <returns>���� ������� ������</returns>
	Date GetSale() const;

	/// <summary>
	/// ����������� ������� 
	/// </summary>
	/// <returns>����� ��������������</returns>
	virtual string Accesories() = 0;

	/// <summary>
	/// ������ ��� �������� �����/��������
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

	// ���������� ��������� ����� ������ ��������
	friend istream& operator>>(istream&, Foodstuff&); 

	// ���������� ��������� ������ ������ ��������
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

	// ���������� ��������� ����� ������ ������
	friend istream& operator>>(istream&, Furniture&); 

	// ���������� ��������� ������ ������ ������
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

	// ���������� ��������� ����� ������ ����������
	friend istream& operator>>(istream&, Car&); 

	// ���������� ��������� ������ ������ ����������
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