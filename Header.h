#pragma once
#include <iostream>

using namespace std;

class Date
{
public:
	Date()
	{
		dd = 0;
		mm = 0;
		gg = 0;
	}

	Date(int d, int m, int g)
	{
		this->dd = d;
		this->mm = m;
		this->gg = g;
	}

	~Date()
	{
	}

	friend ostream& operator<<(ostream&, const Date&);

	friend istream& operator>>(istream&, Date&);

private:

	int dd;
	int mm;
	int gg;

};

class Product
{
protected:
	double price;
	int count;

public:
	
	void SetPrice(double price);

	void SetCnt(int count);

	double GetPrice() const;

	double GetCnt() const;

};

class Foodstuff : protected Product
{
public:
	Foodstuff() : Product()
	{
	}

	~Foodstuff()
	{
	}

	void SetManufacture(Date& obj);

	void SetExpiration(Date& obj);

	Date GetManufacture();

	Date GetExpiration();

private:

	

	Date Manufacture;

	Date Expiration;

};

