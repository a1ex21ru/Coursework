#include "Header.h"

static int Menu();

static int SubMenu();

int main()
{
	setlocale(0, "ru");
	
	/*Date prihod;

	cin >> prihod;*/
	
	//Ecard ebook;

	/// Указатель для добавления объектов классов
	//Product* universal = nullptr;

	short choise = 0; // для выбора класса
	int var = 0; // для выбора действия
	
	int all_cnt = 0;

	int avto_count = 0;
	Car avto[MAX];

	int food_count = 0;
	Foodstuff food[MAX];

	int furniture_cnt = 0;
	Furniture furniture[MAX];

	while (true)
	{
		
		choise = Menu();

		
		if (choise == 1)
		{
			var = SubMenu();
			if (var == 1)
			{
				Car car_temp;

				cin >> car_temp;
					
				avto[avto_count++] = car_temp;
			}
			else if (var == 2)
			{
				/// При первом проходе сюда не заходить
				for (size_t i = 0; i < avto_count; i++)
				{
					cout << avto[i] << endl;
				}
			}
			else if (var == 3)
			{
				break;
			}
		}
		else if (choise == 2)
		{
			var = SubMenu();
			if (var == 1)
			{
				Foodstuff food_temp;

				cin >> food_temp;

				food[food_count++] = food_temp;
			}
			else if (var == 2)
			{
				/// функция для вывода массива элементов класса Продукты
			}
			else if (var == 3)
			{
				break;
			}
		}
		else if (choise == 3)
		{
			var = SubMenu();
			if (var == 1)
			{
				Furniture furniture_temp;

				cin >> furniture_temp;

				furniture[furniture_cnt++] = furniture_temp;
			}
			else if (var == 2)
			{
				/// функция для вывода массива элементов класса Мебель
			}
		}
		else
		{
			exit(3);
		}
		
		all_cnt++;

		system("cls");
	}
	
	

	return 0;
}


static int Menu()
{
	int choise;
	cout << setw(20) << left << "Автомобиль" << " ( 1 ) " << endl;
	cout << setw(20) << left << "Продукт " << " ( 2 )" << endl;
	cout << setw(20) << left << "Мебель " << " ( 3 )" << endl;
	cout << setw(20) << left << "Завершить работу " << " ( 0 )" << endl;
	cin >> choise;
	while (choise < 0 || choise > 3)
	{
		cout << "Неверный ввод значения\n Введите заново" << endl;
		cin >> choise;
	}
	return choise;
}

static int SubMenu()
{
	int choise;
	cout << setw(20) << left << "Добавить информацию" << "( 1 )" << endl;
	cout << setw(20) << left << "Каталог" << "( 2 )" << endl;
	cout << setw(20) << left << "Назад" << "( 0 )" << endl;
	cin >> choise;
	while (choise < 0 || choise > 2)
	{
		cout << "Неверный ввод значения\n Введите заново" << endl;
		cin >> choise;
	}
	return choise;
}