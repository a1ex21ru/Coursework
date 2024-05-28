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
	bool validInput = false;
	while (!validInput)
	{
		cout << "(������ ��:��:����)\t";

		int tempDD, tempMM, tempGG;

		// ��������� ��������� �������� � ��������� ����������
		if (!(in >> tempDD >> tempMM >> tempGG))
		{
			cout << "������������ ����. ���������� ��� ���." << endl;
			in.clear(); // ������� ����� ������
			in.ignore(numeric_limits<streamsize>::max(), '\n'); // ���������� ����� �����
			continue; // ��������� � ������ �����
		}

		// ��������� ������������ ��������� ������
		if (tempDD < 1 || tempDD > 31 || tempMM < 1 || tempMM > 12 || tempGG < 1900)
		{
			cout << "������������ ������. ���������� ��� ���." << endl;
			continue; 
		}

		// ���� ������ ���������, �� ���������� �� � ����� ������
		obj.dd = tempDD;
		obj.mm = tempMM;
		obj.gg = tempGG;
		validInput = true;
	}

	return in;
}

ostream& operator<<(ostream& out, const Date& obj)
{
	out << setfill('0') // ������������� ����������� ������
		<< setw(2) << obj.dd << '.'
		<< setw(2) << obj.mm << '.'
		<< setw(4) << obj.gg
		<< setfill(' '); // ���������� ����������� ������� �� ������
	return out;
}

istream& operator>>(istream& in, Foodstuff& obj)
{
	cout << "������� ��������� ������(0 - ����, 1 - ����, 2 - ������, 3 - ������������� �������\t";
	in >> obj.num_categ;

	in.ignore(numeric_limits<streamsize>::max(), '\n');
	
	cout << "������� �������� �������������\t";
	getline(in, obj.brand);
	controlReg(obj.brand);

	cout << "������� ���� �����������\t";
	in >> obj.Delivery;

	cout << "������� ���� �������\t";
	in >> obj.Sale;

	cout << "������� ���� ������\t";
	in >> obj.price;

	cout << "������� ���������� ������\t";
	in >> obj.count;

	return in;
}

ostream& operator<<(ostream& out, const Foodstuff& obj)
{
	switch (obj.num_categ)
	{
	case obj.fish:
		out << "��������� ������ : ������������" << endl;
		break;
	case obj.meat:
		out << "��������� ������ : ����" << endl;
		break;
	case obj.milk:
		out << "��������� ������ : ������" << endl;
		break;
	case obj.bread:
		out << "��������� ������ : ������������� �������" << endl;
		break;

	default:
		out << "��������� ����������!!!!!!!!!!";
		break;
	}
	out << "�������������\t" << obj.brand << endl;
	out << "���� ������\t" << obj.price << endl;
	out << "���������� ������\t" << obj.count << endl;
	out << "���� �����������\t" << obj.Delivery << endl;
	out << "���� �������\t" << obj.Sale << endl;
	return out;
}

istream& operator>>(istream& in, Furniture& obj)
{
	/// ������� ������
	in.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "������� ����� ������:\t";
	getline(in, obj.brand);
	controlReg(obj.brand);

	cout << "������� ������ ������:\t";
	getline(in, obj.name);
	controlReg(obj.name);

	cout << "������� ���� �����������:\t";
	in >> obj.Delivery;

	cout << "������� ���� �������:\t";
	in >> obj.Sale;

	cout << "������� ���� ������:\t";
	in >> obj.price;

	cout << "������� ���������� ������:\t";
	in >> obj.count;

	return in;
}

ostream& operator<<(ostream& out, const Furniture& obj)
{
	out << "����� ������:\t" << obj.brand << endl;
	out << "������ ������:\t" << obj.name << endl;
	out << "���� ������:\t" << obj.price << endl;
	out << "���������� ������:\t" << obj.count << endl;
	out << "���� �����������:\t" << obj.Delivery << endl;
	out << "���� �������:\t" << obj.Sale << endl;
	return out;
}

istream& operator>>(istream& in, Car& obj)
{
	in.ignore(numeric_limits<streamsize>::max(), '\n');
	
	cout << "������� ����� ����������\t";
	getline(in, obj.brand);
	controlReg(obj.brand);

	cout << "������� ������ ����������\t";
	getline(in, obj.model);
	controlReg(obj.model);

	cout << "������� ��������������� ����� ����������\t";
	getline(in, obj.gos_nomer);
	for (char& ch : obj.gos_nomer)
	{
		ch = toupper(ch);
	}

	cout << "������� ���� �����������\t";
	in >> obj.Delivery;

	cout << "������� ���� �������\t";
	in >> obj.Sale;

	cout << "������� ���� ����������\t";
	in >> obj.price;

	cout << "������� ���������� �����������\t";
	in >> obj.count;

	return in;

}

ostream& operator<<(ostream& out, const Car& obj)
{
	out << "����� ����������:\t" << obj.brand << endl;
	out << "������ ����������:\t" << obj.model << endl;
	out << "���� ����������:\t" << setprecision(8) << obj.price << endl;
	out << "���������� �����������:\t" << obj.count << endl;
	out << "���� �����������:\t" << obj.Delivery << endl;
	out << "���� �������:\t" << obj.Sale << endl;
	return out;
}

Foodstuff::Foodstuff()
{
#ifdef DEBUGG
	cout << "����������� ������ Foodstuff " << this << ' ' << __FILE__ << ' ' << __LINE__ << endl;
#endif // DEBUGG
	this->num_categ = 0;
}

Foodstuff::~Foodstuff()
{
}

string Foodstuff::Accesories()
{
	return " ����� ��� ";
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
	cout << "����������� ������ Furniture " << this << ' ' << __FILE__ << ' ' << __LINE__ << endl;
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

void Car::setBrand(string s)
{
	this->brand = s;
}

void Car::setModel(string s)
{
	this->model = s;
}

void Car::setNomer(string s)
{
	this->gos_nomer = s;
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

void DeleteCar(Car* cars, int& count)
{
	string brand, model, gos_num;
	cout << "������� ����� ����������: ";
	cin >> brand;
	cout << "������� ������ ����������: ";
	cin >> model;
	cout << "������� ��������������� ����� ����������: ";
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
		cout << "���������� �� ������." << endl;
		return;
	}

	for (int i = index; i < count - 1; i++)
	{
		cars[i] = cars[i + 1];
	}
	count--;
	cout << "���������� ������� ������." << endl;
}

void DeleteFoodstuff(Foodstuff foods[], int& count)
{
	int category;
	string brand;
	cout << "������� ��������� ������ (0 - ����, 1 - ����, 2 - ������, 3 - ������������� �������): ";
	cin >> category;
	cout << "������� �������� �������������" << endl;
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
		cout << "������ ����� �� ������." << endl;
		return;
	}

	for (int i = index; i < count - 1; i++)
	{
		foods[i] = foods[i + 1];
	}
	count--;
	cout << "����� ������� ������." << endl;
}

void DeleteFurniture(Furniture furniture[], int& count)
{
	string brand, name;
	cout << "������� ����� ������: ";
	cin >> brand;
	cout << "������� ������ ������: ";
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
		cout << "������ �� �������." << endl;
		return;
	}

	for (int i = index; i < count - 1; i++)
	{
		furniture[i] = furniture[i + 1];
	}
	count--;
	cout << "������ ������� �������." << endl;
}

void controlReg(string& str)
{
	int cnt = 0;
	for (char &ch : str)
	{
		if (cnt++ == 0)
		{
			ch = toupper(ch);
		}
		else {
			ch = tolower(ch);
		}
	}
}