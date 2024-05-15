#include "Header.h"


//#define DEBUGG

Date::Date()
{
#ifdef DEBUGG
	cout << "Конструктор класса Date " << this << ' ' << __FILE__ << ' ' << __LINE__ << endl;
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
	cout << "Введите дату (формат дд:мм:гггг)\t";
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
	cout << "Введите категорию товара(0 - рыба, 1 - мясо, 2 - молоко, 3 - хлебобулочные изделия";
	in >> obj.num_categ;

	cout << "Введите срок годности (укажите дни)";
	in >> obj.expiration_date;

	cout << "Введите дату поступления";
	in >> obj.Delivery;

	cout << "Введите дату продажи";
	in >> obj.Sale;

	cout << "Введите цену товара";
	in >> obj.price;

	cout << "Введите количество товара";
	in >> obj.count;

	return in;
}

ostream& operator<<(ostream& out, const Foodstuff& obj)
{
	switch (obj.num_categ)
	{
	case obj.fish:
		out << "Категория товара : морепродукты";
		break;
	case obj.meat:
		out << "Категория товара : мясо";
		break;
	case obj.milk:
		out << "Категория товара : молоко";
		break;
	case obj.bread:
		out << "Категория товара : хлебобулочные изделия";
		break;

	default:
		out << "Пощёл нахуййййййй!!!!!!!!!!";
		break;
	}
	out << "Срок годности товара " << obj.expiration_date << endl;
	out << "Цена товара " << obj.price << endl;
	out << "Количество товара " << obj.count << endl;
	out << "Дата поступления" << obj.Delivery << endl;
	out << "Дата продажи" << obj.Sale << endl;
	return out;
}

istream& operator>>(istream& in, Furniture& obj)
{
	cout << "Введите марку мебели";
	in >> obj.brand;

	cout << "Введите модель мебели";
	in >> obj.name;

	cout << "Введите дату поступления";
	in >> obj.Delivery;

	cout << "Введите дату продажи";
	in >> obj.Sale;

	cout << "Введите цену мебели";
	in >> obj.price;

	cout << "Введите количество мебели";
	in >> obj.count;

	return in;
}

ostream& operator<<(ostream& out, const Furniture& obj)
{
	out << "Марка мебели " << obj.brand << endl;
	out << "Модель мебели " << obj.name << endl;
	out << "Цена мебели " << obj.price << endl;
	out << "Количество мебели " << obj.count << endl;
	out << "Дата поступления" << obj.Delivery << endl;
	out << "Дата продажи" << obj.Sale << endl;
	return out;
}

istream& operator>>(istream& in, Car& obj)
{
	cout << "Введите марку автомобиля";
	in >> obj.brand;

	cout << "Введите модель автомобиля";
	in >> obj.model;

	cout << "Введите дату поступления";
	in >> obj.Delivery;

	cout << "Введите дату продажи";
	in >> obj.Sale;

	cout << "Введите цену автомобиля";
	in >> obj.price;

	cout << "Введите количество автомобилей";
	in >> obj.count;

	return in;

}

ostream& operator<<(ostream& out, const Car& obj)
{
	out << "Марка автомобиля " << obj.brand << endl;
	out << "Модель автомобиля " << obj.model << endl;
	out << "Цена автомобиля " << obj.price << endl;
	out << "Количество автомобилей " << obj.count << endl;
	out << "Дата поступления" << obj.Delivery << endl;
	out << "Дата продажи" << obj.Sale << endl;
	return out;
}

Foodstuff::Foodstuff()
{
#ifdef DEBUGG
	cout << "Конструктор класса Foodstuff " << this << ' ' << __FILE__ << ' ' << __LINE__ << endl;
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
	return " класс Еда ";
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
	cout << "Конструктор класса Furniture " << this << ' ' << __FILE__ << ' ' << __LINE__ << endl;
#endif // DEBUGG
	this->count = 0;
	this->price = 0;
}

Furniture::~Furniture()
{

}

string Furniture::Accesories()
{
	return " класс Мебель ";
}

Car::Car()
{
#ifdef DEBUGG
	cout << "Конструктор класса Car " << this << ' ' << __FILE__ << ' ' << __LINE__ << endl;
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
	return " класс Машина ";
}

//Ecard::Ecard()
//{
//#ifdef DEBUGG
//	cout << "Конструктор класса Ecard " << this << ' ' << __FILE__ << ' ' << __LINE__ << endl;
//#endif // DEBUGG
//
//}
//
//Ecard::~Ecard()
//{
//
//}

