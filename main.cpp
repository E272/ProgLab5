#include "iostream"
#include "Windows.h"
#include "ctime"
#include "cycle.h"
#include "queue.h"

#pragma once

int Rand(int M)
{
	int x = 1 + rand() % M;
	return x;
}

void MENU()
{
	cout << "Работа с массивом" << endl;
	cout << "1. Добавление" << endl;
	cout << "2. Поиск" << endl;
	cout << "3. Замена" << endl;
	cout << "4. Удаление" << endl;
	cout << "5. Вывод массива в удобной форме" << endl;
	cout << "6. Сортировка" << endl;
	cout << "7. Поиск максимального" << endl;
	cout << "8. Поиск минимального" << endl;
	cout << "9.(только для демострации) Заполнение массива случайными числами" << endl;
	cout << "10. Вывод элемента массива по номеру" << endl;
	cout << "11.(для проверки) Вывод массива" << endl;
	cout << "12. Удаление последнего элемента" << endl;
	cout << "13. Удаление елемента по значению" << endl;
	cout << "14. Наследник cycle_massive" << endl;
	cout << "15. Наследник queue_massive" << endl;
	cout << "0. EXIT" << endl;
	cout << "Выберете операцию-";
}

void MENU_CYCLE()
{
	cout << "Работа с наследиником cycle" << endl;
	cout << "1. Задать максимальное число элементов" << endl;
	cout << "2. Добавление" << endl;
	cout << "3. Поиск" << endl;
	cout << "4. Замена" << endl;
	cout << "5. Удаление" << endl;
	cout << "6. Вывод" << endl;
	cout << "7. Сортировка" << endl;
	cout << "8. (только для демострации) Заполнение массива случайными числами" << endl;
	cout << "9. Вывод в бинарный файл" << endl;
	cout << "10. Вывод в текстовый файл" << endl;
	cout << "11. Заполнение из текстового файла" << endl;
	cout << "12. Заполнение из бинарного фойла" << endl;
	cout << "0. Выход к основному массиву" << endl;
	cout << "Выберете операцию";
}

void MENU_QUEUE()
{
	cout << "Работа с наследиником queue" << endl;
	cout << "1. Добавление" << endl;
	cout << "2. Поиск" << endl;
	cout << "3. Замена" << endl;
	cout << "4. Удаление" << endl;
	cout << "5. Вывод" << endl;
	cout << "6. Сортировка" << endl;
	cout << "7. (только для демострации) Заполнение массива случайными числами" << endl;
	cout << "8. Вывод в бинарный файл" << endl;
	cout << "9. Вывод в текстовый файл" << endl;
	cout << "10. Заполнение из текстового файла" << endl;
	cout << "11. Заполнение из бинарного фойла" << endl;
	cout << "12. Вывод первого элемента" << endl;
	cout << "0. Выход к основному массиву" << endl;
	cout << "Выберете операцию";
}

void main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char a;
	int x, size, number, i, pr, posi;
	char* str = nullptr;
	MASSIVE* massive = new MASSIVE();
	x = 0;
	pr = 0;

	Cycle_massive* cycle_massive = new Cycle_massive(0);

	Queue_massive* queue_massive = new Queue_massive();
	
	
	while (1 > 0)
	{
		cout << "Выберите способ создания объекта:" << endl;
		cout << "1. Заполнение с клавиатуры" << endl;
		cout << "2. Заполнение из текстового файла" << endl;
		cout << "3. Заполнение из бинарного файла" << endl;
		cout << "0. EXIT" << endl;
		cin >> number;

		switch (number)
		{
		case 1:
			cout << "Введите количество добавлений=";
			cin >> x;
			cout << "Введете значения";
			for (i = 0; i < x; i++)
				cin >> *massive;
			pr = -1;
			break;

		case 2:
		{
			ifstream text("Text.txt", ios::in);
			text >> *massive;
			pr = -1;
			text.close();
			break;
		}

		case 3:
		{
			ifstream bin("Bin.bin", ios::binary);
			massive->input(bin);
			pr = -1;
			bin.close();
			break;
		}

		case 0:
			exit(1);

		default:
			cout << "Нет такой операции." << endl;
			system("pause");
			break;
		}

		if (pr == -1)
		{
			pr = 0;
			break;
		}
	}

	system("cls");

	while (1 > 0)
	{
		MENU();
		cin >> number;
		system("cls");


		switch (number)
		{
		case 1:						//Добавление
			cout << "1. Добавление в начало" << endl;
			cout << "2. Добавлене в конец" << endl;
			cout << "3. Добавление в позицию" << endl;
			cout << "4. Многократное добавление в конец" << endl;
			cout << "Введите номер операции ";
			cin >> number;
			switch (number)
			{
			case 1:
				cout << "Введите значение-";
				cin >> x;
				massive->ADD(x, 0);
				break;

			case 2:
				cout << "Введите значение-";
				cin >> *massive;
				break;

			case 3:
				cout << "Введите позицию-";
				cin >> posi;
				if (posi > massive->GetSize())
				{
					cout << "Позиция выбрана за пределами массива" << endl;
					break;
				}
				cout << "Введите значение-";
				cin >> x;
				massive->ADD(x, posi);
				break;

			case 4:
				cout << "Введите кол-во добавлений ";
				cin >> posi;
				for (i = 0; i < posi; i++)
					cin >> *massive;
				break;
			}
			break;

		case 2:						//Поиск
			cout << "Введите значение-";
			cin >> x;
			cout << "Индекс искомого числа в массиве=" << massive->FIND(x) << "." << endl << endl;
			break;

		case 3:						//Замена
			cout << "Введите номер элемента-";
			cin >> i;
			cout << "Введите новое значение-";
			cin >> x;
			massive->CHAN(x, i);
			break;

		case 4:						//Удаление
			cout << "Введите номер удаляемого элемента-";
			cin >> i;
			massive->DEL(i);
			break;

		case 5:						//Вывод массива в удобной форме
			str = massive->OUTP();
			cout << str << endl;
			delete[] str;
			break;

		case 6:						//Сортировка
			massive->SORT();
			break;

		case 7:						//Поиск максимального
			massive->FMAX();
			break;

		case 8:						//Поиск минимального
			massive->FMIN();
			break;

		case 9:						//Рандомное заполнение массива(только для демонстрации)
			srand(time(NULL));
			cout << "Введите количество элементов-";
			cin >> size;
			for (int i = 0; i < size; i++)
			{
				int x = Rand(100);
				massive->ADD(x, massive->GetSize());
			}
			break;

		case 10:					//Вывод элемента по номеру
			cout << "Введите индекс элемента-";
			cin >> x;
			cout << "Элемент под номером " << x << " =" << (*massive)[x - 1] << endl;
			break;

		case 11:					//Вывод массива
			cout << *massive;
			break;

		case 12:
			(*massive)--;
			break;

		case 13:
			cout << "Введите число для удаления-";
			cin >> x;
			*massive = *massive - x;
			break;

		case 14:
			system("cls");
			
			while (1 > 0)
			{
				MENU_CYCLE();
				cin >> number;
				system("cls");

				switch (number)
				{
				case 1:
					cout << "Введите макс колическтво элементов=";
					cin >> x;
					cycle_massive = new Cycle_massive(x);
					break;

				case 2:
					cout << "Введите значение-";
					cin >> x;
					cycle_massive->ADD(x,0);
					break;

				case 3:
					cout << "Введите значение-";
					cin >> x;
					cout << "Индекс искомого числа в массиве=" << cycle_massive->FIND(x) << "." << endl << endl;
					break;

				case 4:
					cout << "Введите номер элемента-";
					cin >> i;
					cout << "Введите новое значение-";
					cin >> x;
					cycle_massive->CHAN(x, i);
					break;

				case 5:
					cout << "Введите номер удаляемого элемента-";
					cin >> i;
					cycle_massive->DEL(i);
					break;

				case 6:
					cout << *cycle_massive;
					break;

				case 7:
					cycle_massive->SORT();
					break;

				case 8:
					srand(time(NULL));
					cout << "Введите количество элементов-";
					cin >> size;
					for (int i = 0; i < size; i++)
					{
						int x = Rand(100);
						cycle_massive->ADD(x, cycle_massive->GetSize());
					}
					break;

				case 9:
				{
					ofstream obin("Bin.bin", ios::binary);
					if (!obin) {
						cerr << "Error: unable to write to Bin.bin" << endl;
						exit(1);
					}
					cycle_massive->output(obin);

					obin.close();
					break;
				}
				case 10:
				{
					ofstream otext("Text.txt", ios::out);
					if (!otext) 
					{
						cerr << "Error: unable to read to Text.txt" << endl;
						exit(1);
					}
					otext << *cycle_massive;

					otext.close();
					break;
				}

				case 11:
				{
					ifstream text("Text.txt", ios::in);
					if (!text) {
						cerr << "Error: unable to read to Text.txt" << endl;
						exit(1);
					}
					text >> *cycle_massive;

					text.close();
					break;
				}

				case 12:
				{
					ifstream bin("Bin.bin", ios::binary);
					if (!bin) {
						cerr << "Error: unable to write to Bin.bin" << endl;
						exit(1);
					}
					cycle_massive->input(bin);

					bin.close();
					break;
				}

				case 0:						//EXIT
					pr = -1;
					break;
				}
				
				if (pr == -1)
				{	
					pr = 0;
					break;
				}
			}
					
			break;
		
		case 15:
			system("cls");

			while (1 > 0)
			{
				MENU_QUEUE();
				cin >> number;
				system("cls");

				switch (number)
				{
				case 1:
					cout << "Введите значение-";
					cin >> x;
					queue_massive->ADD(x, 0);
					break;

				case 2:
					cout << "Введите значение-";
					cin >> x;
					cout << "Индекс искомого числа в массиве=" << queue_massive->FIND(x) << "." << endl << endl;
					break;

				case 3:
					cout << "Введите номер элемента-";
					cin >> i;
					cout << "Введите новое значение-";
					cin >> x;
					queue_massive->CHAN(x, i);
					break;

				case 4:
					cout << "Введите номер удаляемого элемента-";
					cin >> i;
					queue_massive->DEL(i);
					break;

				case 5:
					cout << *queue_massive;
					break;

				case 6:
					queue_massive->SORT();
					break;

				case 7:
					srand(time(NULL));
					cout << "Введите количество элементов-";
					cin >> size;
					for (int i = 0; i < size; i++)
					{
						int x = Rand(100);
						queue_massive->ADD(x, queue_massive->GetSize());
					}
					break;

				case 8:
				{
					ofstream obin("Bin.bin", ios::binary);
					if (!obin) {
						cerr << "Error: unable to write to Bin.bin" << endl;
						exit(1);
					}
					queue_massive->output(obin);

					obin.close();
					break;
				}
				case 9:
				{
					ofstream otext("Text.txt", ios::out);
					if (!otext)
					{
						cerr << "Error: unable to read to Text.txt" << endl;
						exit(1);
					}
					otext << *queue_massive;

					otext.close();
					break;
				}

				case 10:
				{
					ifstream text("Text.txt", ios::in);
					if (!text) {
						cerr << "Error: unable to read to Text.txt" << endl;
						exit(1);
					}
					text >> *queue_massive;

					text.close();
					break;
				}

				case 11:
				{
					ifstream bin("Bin.bin", ios::binary);
					if (!bin) {
						cerr << "Error: unable to write to Bin.bin" << endl;
						exit(1);
					}
					queue_massive->input(bin);

					bin.close();
					break;
				}

				case 12:
					cout << "Первый элемент="<<queue_massive->Get();
					break;

				case 0:						//EXIT
					pr = -1;
					break;
				}

				if (pr == -1)
				{
					pr = 0;
					break;
				}
			}

			break;

		case 0:						//EXIT
			pr = -1;
			break;

		default:
			cout << "Такой операции нет" << endl;
			break;
		}
		if (pr == -1) break;

		system("pause");
		system("cls");
	}

	delete queue_massive;
	delete cycle_massive;
	delete massive;
	system("cls");
	cout << "Программа закончена" << endl;
	system("pause");
}