#include "Header.h"

void Product::SetPrice(double price)
{
	this->price = price;
}

void Product::SetCnt(int count)
{
	this->count = count;
}

double Product::GetPrice() const
{
	return this->price;
}

double Product::GetCnt() const
{
	return this->count;
}

ostream& operator<<(ostream& out, const Date& obj)
{
	out << obj.dd << " : " << obj.mm << " : " << obj.gg << '\t';
	return out;
}

istream& operator>>(istream& in, Date& obj)
{
	in >> obj.dd >> obj.mm >> obj.gg;
	return in;
}

void Foodstuff::SetManufacture(Date& obj)
{
	this->Manufacture = obj;
}

void Foodstuff::SetExpiration(Date& obj)
{
	this->Expiration = obj;
}

Date Foodstuff::GetManufacture()
{
	return this->Manufacture;
}

Date Foodstuff::GetExpiration()
{
	return this->Expiration;
}

