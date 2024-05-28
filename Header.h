#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
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

	// ���������� ��������� ����� ������ ��������
	friend istream& operator>>(istream&, Foodstuff&); 

	// ���������� ��������� ������ ������ ��������
	friend ostream& operator<<(ostream&, const Foodstuff&); 

private:

	enum categs {
		fish, meat, milk, bread
	};

	int num_categ;

	long expiration_date;

};

class Furniture : public Product
{
public:

	Furniture();

	~Furniture();

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

	string Accesories() override;

	// ���������� ��������� ����� ������ ����������
	friend istream& operator>>(istream&, Car&); 

	// ���������� ��������� ������ ������ ����������
	friend ostream& operator<<(ostream&, const Car&); 

private:

	string brand;

	string model;

};


//class Ecard : public Car, public Furniture, public Foodstuff
//{
//public:
//
//	Ecard();
//
//	~Ecard();
//
//	void SetCar(int price, string brand, string body_type, Date delivery, Date sale);
//
//
//private:
//	
//	Car cars[MAX];
//	Furniture furnutures[MAX];
//	Foodstuff foodstuffs[MAX];
//
//};

