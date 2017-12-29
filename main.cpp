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
	cout << "������ � ��������" << endl;
	cout << "1. ����������" << endl;
	cout << "2. �����" << endl;
	cout << "3. ������" << endl;
	cout << "4. ��������" << endl;
	cout << "5. ����� ������� � ������� �����" << endl;
	cout << "6. ����������" << endl;
	cout << "7. ����� �������������" << endl;
	cout << "8. ����� ������������" << endl;
	cout << "9.(������ ��� �����������) ���������� ������� ���������� �������" << endl;
	cout << "10. ����� �������� ������� �� ������" << endl;
	cout << "11.(��� ��������) ����� �������" << endl;
	cout << "12. �������� ���������� ��������" << endl;
	cout << "13. �������� �������� �� ��������" << endl;
	cout << "14. ��������� cycle_massive" << endl;
	cout << "15. ��������� queue_massive" << endl;
	cout << "0. EXIT" << endl;
	cout << "�������� ��������-";
}

void MENU_CYCLE()
{
	cout << "������ � ������������ cycle" << endl;
	cout << "1. ������ ������������ ����� ���������" << endl;
	cout << "2. ����������" << endl;
	cout << "3. �����" << endl;
	cout << "4. ������" << endl;
	cout << "5. ��������" << endl;
	cout << "6. �����" << endl;
	cout << "7. ����������" << endl;
	cout << "8. (������ ��� �����������) ���������� ������� ���������� �������" << endl;
	cout << "9. ����� � �������� ����" << endl;
	cout << "10. ����� � ��������� ����" << endl;
	cout << "11. ���������� �� ���������� �����" << endl;
	cout << "12. ���������� �� ��������� �����" << endl;
	cout << "0. ����� � ��������� �������" << endl;
	cout << "�������� ��������";
}

void MENU_QUEUE()
{
	cout << "������ � ������������ queue" << endl;
	cout << "1. ����������" << endl;
	cout << "2. �����" << endl;
	cout << "3. ������" << endl;
	cout << "4. ��������" << endl;
	cout << "5. �����" << endl;
	cout << "6. ����������" << endl;
	cout << "7. (������ ��� �����������) ���������� ������� ���������� �������" << endl;
	cout << "8. ����� � �������� ����" << endl;
	cout << "9. ����� � ��������� ����" << endl;
	cout << "10. ���������� �� ���������� �����" << endl;
	cout << "11. ���������� �� ��������� �����" << endl;
	cout << "12. ����� ������� ��������" << endl;
	cout << "0. ����� � ��������� �������" << endl;
	cout << "�������� ��������";
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
		cout << "�������� ������ �������� �������:" << endl;
		cout << "1. ���������� � ����������" << endl;
		cout << "2. ���������� �� ���������� �����" << endl;
		cout << "3. ���������� �� ��������� �����" << endl;
		cout << "0. EXIT" << endl;
		cin >> number;

		switch (number)
		{
		case 1:
			cout << "������� ���������� ����������=";
			cin >> x;
			cout << "������� ��������";
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
			cout << "��� ����� ��������." << endl;
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
		case 1:						//����������
			cout << "1. ���������� � ������" << endl;
			cout << "2. ��������� � �����" << endl;
			cout << "3. ���������� � �������" << endl;
			cout << "4. ������������ ���������� � �����" << endl;
			cout << "������� ����� �������� ";
			cin >> number;
			switch (number)
			{
			case 1:
				cout << "������� ��������-";
				cin >> x;
				massive->ADD(x, 0);
				break;

			case 2:
				cout << "������� ��������-";
				cin >> *massive;
				break;

			case 3:
				cout << "������� �������-";
				cin >> posi;
				if (posi > massive->GetSize())
				{
					cout << "������� ������� �� ��������� �������" << endl;
					break;
				}
				cout << "������� ��������-";
				cin >> x;
				massive->ADD(x, posi);
				break;

			case 4:
				cout << "������� ���-�� ���������� ";
				cin >> posi;
				for (i = 0; i < posi; i++)
					cin >> *massive;
				break;
			}
			break;

		case 2:						//�����
			cout << "������� ��������-";
			cin >> x;
			cout << "������ �������� ����� � �������=" << massive->FIND(x) << "." << endl << endl;
			break;

		case 3:						//������
			cout << "������� ����� ��������-";
			cin >> i;
			cout << "������� ����� ��������-";
			cin >> x;
			massive->CHAN(x, i);
			break;

		case 4:						//��������
			cout << "������� ����� ���������� ��������-";
			cin >> i;
			massive->DEL(i);
			break;

		case 5:						//����� ������� � ������� �����
			str = massive->OUTP();
			cout << str << endl;
			delete[] str;
			break;

		case 6:						//����������
			massive->SORT();
			break;

		case 7:						//����� �������������
			massive->FMAX();
			break;

		case 8:						//����� ������������
			massive->FMIN();
			break;

		case 9:						//��������� ���������� �������(������ ��� ������������)
			srand(time(NULL));
			cout << "������� ���������� ���������-";
			cin >> size;
			for (int i = 0; i < size; i++)
			{
				int x = Rand(100);
				massive->ADD(x, massive->GetSize());
			}
			break;

		case 10:					//����� �������� �� ������
			cout << "������� ������ ��������-";
			cin >> x;
			cout << "������� ��� ������� " << x << " =" << (*massive)[x - 1] << endl;
			break;

		case 11:					//����� �������
			cout << *massive;
			break;

		case 12:
			(*massive)--;
			break;

		case 13:
			cout << "������� ����� ��� ��������-";
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
					cout << "������� ���� ����������� ���������=";
					cin >> x;
					cycle_massive = new Cycle_massive(x);
					break;

				case 2:
					cout << "������� ��������-";
					cin >> x;
					cycle_massive->ADD(x,0);
					break;

				case 3:
					cout << "������� ��������-";
					cin >> x;
					cout << "������ �������� ����� � �������=" << cycle_massive->FIND(x) << "." << endl << endl;
					break;

				case 4:
					cout << "������� ����� ��������-";
					cin >> i;
					cout << "������� ����� ��������-";
					cin >> x;
					cycle_massive->CHAN(x, i);
					break;

				case 5:
					cout << "������� ����� ���������� ��������-";
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
					cout << "������� ���������� ���������-";
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
					cout << "������� ��������-";
					cin >> x;
					queue_massive->ADD(x, 0);
					break;

				case 2:
					cout << "������� ��������-";
					cin >> x;
					cout << "������ �������� ����� � �������=" << queue_massive->FIND(x) << "." << endl << endl;
					break;

				case 3:
					cout << "������� ����� ��������-";
					cin >> i;
					cout << "������� ����� ��������-";
					cin >> x;
					queue_massive->CHAN(x, i);
					break;

				case 4:
					cout << "������� ����� ���������� ��������-";
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
					cout << "������� ���������� ���������-";
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
					cout << "������ �������="<<queue_massive->Get();
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
			cout << "����� �������� ���" << endl;
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
	cout << "��������� ���������" << endl;
	system("pause");
}