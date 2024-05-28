#include "Header.h"


//#define DEBUGG

Date::Date()
{
#ifdef DEBUGG
	cout << "����������� ������ Date " << this << ' ' << __FILE__ << ' ' << __LINE__ << endl;
#endif // DEBUGG
	dd = 0;
	mm = 0;
	gg = 0;
}

Date::Date(int d, int m, int g)
{
	this->dd = d;
	this->mm = m;
	this->gg = g;
}

Date::~Date()
{
}

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

int Product::GetCnt() const
{
	return this->count;
}

istream& operator>>(istream& in, Date& obj)
{
	cout << "������� ���� (������ ��:��:����)\t";
	in >> obj.dd >> obj.mm >> obj.gg;
	return in;
}

ostream& operator<<(ostream& out, const Date& obj)
{
	out.fill('0');
	out <<  setw(2) << obj.dd << '.' << 
			setw(2) << obj.mm << '.' << 
			setw(4) << obj.gg << '\t';
	return out;
}

istream& operator>>(istream& in, Foodstuff& obj)
{
	cout << "������� ��������� ������(0 - ����, 1 - ����, 2 - ������, 3 - ������������� �������";
	in >> obj.num_categ;

	cout << "������� ���� �������� (������� ���)";
	in >> obj.expiration_date;

	cout << "������� ���� �����������";
	in >> obj.Delivery;

	cout << "������� ���� �������";
	in >> obj.Sale;

	cout << "������� ���� ������";
	in >> obj.price;

	cout << "������� ���������� ������";
	in >> obj.count;

	return in;
}

ostream& operator<<(ostream& out, const Foodstuff& obj)
{
	switch (obj.num_categ)
	{
	case obj.fish:
		out << "��������� ������ : ������������";
		break;
	case obj.meat:
		out << "��������� ������ : ����";
		break;
	case obj.milk:
		out << "��������� ������ : ������";
		break;
	case obj.bread:
		out << "��������� ������ : ������������� �������";
		break;

	default:
		out << "����� �����������!!!!!!!!!!";
		break;
	}
	out << "���� �������� ������ " << obj.expiration_date << endl;
	out << "���� ������ " << obj.price << endl;
	out << "���������� ������ " << obj.count << endl;
	out << "���� �����������" << obj.Delivery << endl;
	out << "���� �������" << obj.Sale << endl;
	return out;
}

istream& operator>>(istream& in, Furniture& obj)
{
	cout << "������� ����� ������";
	in >> obj.brand;

	cout << "������� ������ ������";
	in >> obj.name;

	cout << "������� ���� �����������";
	in >> obj.Delivery;

	cout << "������� ���� �������";
	in >> obj.Sale;

	cout << "������� ���� ������";
	in >> obj.price;

	cout << "������� ���������� ������";
	in >> obj.count;

	return in;
}

ostream& operator<<(ostream& out, const Furniture& obj)
{
	out << "����� ������ " << obj.brand << endl;
	out << "������ ������ " << obj.name << endl;
	out << "���� ������ " << obj.price << endl;
	out << "���������� ������ " << obj.count << endl;
	out << "���� �����������" << obj.Delivery << endl;
	out << "���� �������" << obj.Sale << endl;
	return out;
}

istream& operator>>(istream& in, Car& obj)
{
	cout << "������� ����� ����������";
	in >> obj.brand;

	cout << "������� ������ ����������";
	in >> obj.model;

	cout << "������� ���� �����������";
	in >> obj.Delivery;

	cout << "������� ���� �������";
	in >> obj.Sale;

	cout << "������� ���� ����������";
	in >> obj.price;

	cout << "������� ���������� �����������";
	in >> obj.count;

	return in;

}

ostream& operator<<(ostream& out, const Car& obj)
{
	out << "����� ���������� " << obj.brand << endl;
	out << "������ ���������� " << obj.model << endl;
	out << "���� ���������� " << obj.price << endl;
	out << "���������� ����������� " << obj.count << endl;
	out << "���� �����������" << obj.Delivery << endl;
	out << "���� �������" << obj.Sale << endl;
	return out;
}

Foodstuff::Foodstuff()
{
#ifdef DEBUGG
	cout << "����������� ������ Foodstuff " << this << ' ' << __FILE__ << ' ' << __LINE__ << endl;
#endif // DEBUGG
	this->expiration_date = 0;
}

Foodstuff::~Foodstuff()
{
}

//void Foodstuff::SetManufacture(Date& obj)
//{
//	this->Manufacture = obj;
//}
//
//void Foodstuff::SetExpiration(Date& obj)
//{
//	this->Expiration = obj;
//}
//
//Date Foodstuff::GetManufacture() const
//{
//	return Manufacture;
//}
//
//Date Foodstuff::GetExpiration() const
//{
//	return this->Expiration;
//}

string Foodstuff::Accesories()
{
	return " ����� ��� ";
}

void Product::SetDelivery(Date& obj)
{
	this->Delivery = obj;
}

void Product::SetSale(Date& obj)
{
	this->Sale = obj;
}

Date Product::GetDelivery() const
{
	return this->Delivery;
}

Date Product::GetSale() const
{
	return this->Sale;
}

Furniture::Furniture()
{
#ifdef DEBUGG
	cout << "����������� ������ Furniture " << this << ' ' << __FILE__ << ' ' << __LINE__ << endl;
#endif // DEBUGG
	this->count = 0;
	this->price = 0;
}

Furniture::~Furniture()
{

}

string Furniture::Accesories()
{
	return " ����� ������ ";
}

Car::Car()
{
#ifdef DEBUGG
	cout << "����������� ������ Car " << this << ' ' << __FILE__ << ' ' << __LINE__ << endl;
#endif // DEBUGG
}

Car::Car(string b, string m) : brand(b), model(m)
{
}

Car::~Car()
{
}

string Car::Accesories()
{
	return " ����� ������ ";
}

//Ecard::Ecard()
//{
//#ifdef DEBUGG
//	cout << "����������� ������ Ecard " << this << ' ' << __FILE__ << ' ' << __LINE__ << endl;
//#endif // DEBUGG
//
//}
//
//Ecard::~Ecard()
//{
//
//}

