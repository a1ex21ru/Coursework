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
	cout << "(формат дд:мм:гггг)\t";

	// Временные переменные для хранения введенных значений
	int tempDD, tempMM, tempGG;

	// Считываем введенные значения в временные переменные
	in >> tempDD >> tempMM >> tempGG;

	// Проверяем корректность введенных данных
	if (tempDD < 1 || tempDD > 31 || tempMM < 1 || tempMM > 12 || tempGG < 1950)
	{
		cout << "Некорректные данные. Попробуйте еще раз." << endl;
		in.clear(); // Очищаем флаги потока
		in.ignore(numeric_limits<streamsize>::max(), '\n'); // Сбрасываем буфер ввода
		return in;
	}

	// Если данные корректны, то записываем их в члены класса
	obj.dd = tempDD;
	obj.mm = tempMM;
	obj.gg = tempGG;

	return in;
}

ostream& operator<<(ostream& out, const Date& obj)
{
	out << setfill('0') // Устанавливаем заполнитель нулями
		<< setw(2) << obj.dd << '.'
		<< setw(2) << obj.mm << '.'
		<< setw(4) << obj.gg
		<< setfill(' '); // Возвращаем заполнитель обратно на пробел
	return out;
}

istream& operator>>(istream& in, Foodstuff& obj)
{
	cout << "Введите категорию товара(0 - рыба, 1 - мясо, 2 - молоко, 3 - хлебобулочные изделия";
	in >> obj.num_categ;

	cout << "Введите название производителя\t";
	//in >> obj.brand;
	getline(in, obj.brand);

	cout << "Введите дату поступления\t";
	in >> obj.Delivery;

	cout << "Введите дату продажи\t";
	in >> obj.Sale;

	cout << "Введите цену товара\t";
	in >> obj.price;

	cout << "Введите количество товара\t";
	in >> obj.count;

	return in;
}

ostream& operator<<(ostream& out, const Foodstuff& obj)
{
	switch (obj.num_categ)
	{
	case obj.fish:
		out << "Категория товара : морепродукты" << endl;
		break;
	case obj.meat:
		out << "Категория товара : мясо" << endl;
		break;
	case obj.milk:
		out << "Категория товара : молоко" << endl;
		break;
	case obj.bread:
		out << "Категория товара : хлебобулочные изделия" << endl;
		break;

	default:
		out << "Категория отсутсвует!!!!!!!!!!";
		break;
	}
	out << "Производитель\t" << obj.brand << endl;
	out << "Цена товара\t" << obj.price << endl;
	out << "Количество товара\t" << obj.count << endl;
	out << "Дата поступления\t" << obj.Delivery << endl;
	out << "Дата продажи\t" << obj.Sale << endl;
	return out;
}

istream& operator>>(istream& in, Furniture& obj)
{
	cout << "Введите марку мебели:\t";
	getline(in, obj.brand);
	//in >> obj.brand;

	cout << "Введите модель мебели:\t";
	getline(in, obj.name);

	cout << "Введите дату поступления:\t";
	in >> obj.Delivery;

	cout << "Введите дату продажи:\t";
	in >> obj.Sale;

	cout << "Введите цену мебели:\t";
	in >> obj.price;

	cout << "Введите количество мебели:\t";
	in >> obj.count;

	return in;
}

ostream& operator<<(ostream& out, const Furniture& obj)
{
	out << "Марка мебели:\t" << obj.brand << endl;
	out << "Модель мебели:\t" << obj.name << endl;
	out << "Цена мебели:\t" << obj.price << endl;
	out << "Количество мебели:\t" << obj.count << endl;
	out << "Дата поступления:\t" << obj.Delivery << endl;
	out << "Дата продажи:\t" << obj.Sale << endl;
	return out;
}

istream& operator>>(istream& in, Car& obj)
{
	cout << "Введите марку автомобиля\t";
	getline(in, obj.brand);
	//in >> obj.brand;

	cout << "Введите модель автомобиля\t";
	getline(in, obj.model, '\n');
	//in >> obj.model;

	cout << "Введите государственный номер автомобиля\t";
	getline(in, obj.gos_nomer);

	cout << "Введите дату поступления\t";
	in >> obj.Delivery;

	cout << "Введите дату продажи\t";
	in >> obj.Sale;

	cout << "Введите цену автомобиля\t";
	in >> obj.price;

	cout << "Введите количество автомобилей\t";
	in >> obj.count;

	return in;

}

ostream& operator<<(ostream& out, const Car& obj)
{
	out << "Марка автомобиля:\t" << obj.brand << endl;
	out << "Модель автомобиля:\t" << obj.model << endl;
	out << "Цена автомобиля:\t" << fixed << setprecision(12) << obj.price << endl;
	out << "Количество автомобилей:\t" << obj.count << endl;
	out << "Дата поступления:\t" << obj.Delivery << endl;
	out << "Дата продажи:\t" << obj.Sale << endl;
	return out;
}

Foodstuff::Foodstuff()
{
#ifdef DEBUGG
	cout << "Конструктор класса Foodstuff " << this << ' ' << __FILE__ << ' ' << __LINE__ << endl;
#endif // DEBUGG
	this->num_categ = 0;
}

Foodstuff::~Foodstuff()
{
}

string Foodstuff::Accesories()
{
	return " класс Еда ";
}

string Foodstuff::getBrand() 
{
	return string(this->brand);
}

int Foodstuff::getCateg() const
{
	return this->num_categ;
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

string Furniture::getRoom()
{
	return string(this->room);
}

string Furniture::getBrand()
{
	return string(this->brand);
}

string Furniture::getName()
{
	return string(this->name);
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

string Car::getBrand()
{
	return string(this->brand);
}

string Car::getModel()
{
	return string(this->model);
}

string Car::getNomer()
{
	return string(this->gos_nomer);
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

void DeleteCar(Car* cars, int& count)
{
	string brand, model, gos_num;
	cout << "Введите марку автомобиля: ";
	cin >> brand;
	cout << "Введите модель автомобиля: ";
	cin >> model;
	cout << "Введите государственный номер автомобиля: ";
	cin >> gos_num;

	int index = -1;
	for (int i = 0; i < count; i++)
	{
		if (cars[i].getBrand() == brand && cars[i].getModel() == model && cars[i].getNomer() == gos_num)
		{
			index = i;
			break;
		}
	}

	if (index == -1)
	{
		cout << "Автомобиль не найден." << endl;
		return;
	}

	for (int i = index; i < count - 1; i++)
	{
		cars[i] = cars[i + 1];
	}
	count--;
	cout << "Автомобиль успешно удален." << endl;
}

void DeleteFoodstuff(Foodstuff foods[], int& count)
{
	int category;
	string brand;
	cout << "Введите категорию товара (0 - рыба, 1 - мясо, 2 - молоко, 3 - хлебобулочные изделия): ";
	cin >> category;
	cout << "Введите название производителя" << endl;
	cin >> brand;

	int index = -1;
	for (int i = 0; i < count; i++)
	{
		if (foods[i].getCateg() == category && foods[i].getBrand() == brand)
		{
			index = i;
			break;
		}
	}

	if (index == -1)
	{
		cout << "Данный товар не найден." << endl;
		return;
	}

	for (int i = index; i < count - 1; i++)
	{
		foods[i] = foods[i + 1];
	}
	count--;
	cout << "Товар успешно удален." << endl;
}

void DeleteFurniture(Furniture furniture[], int& count)
{
	string brand, name;
	cout << "Введите марку мебели: ";
	cin >> brand;
	cout << "Введите модель мебели: ";
	cin >> name;

	int index = -1;
	for (int i = 0; i < count; i++)
	{
		if (furniture[i].getBrand() == brand && furniture[i].getName() == name)
		{
			index = i;
			break;
		}
	}

	if (index == -1)
	{
		cout << "Мебель не найдена." << endl;
		return;
	}

	for (int i = index; i < count - 1; i++)
	{
		furniture[i] = furniture[i + 1];
	}
	count--;
	cout << "Мебель успешно удалена." << endl;
}
