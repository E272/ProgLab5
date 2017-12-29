#include "Windows.h"
#include "massive.h"

MASSIVE::MASSIVE()
{
	maxsize = 0;
	index = 0;
	mas = new int[maxsize];
}

MASSIVE::MASSIVE(int x) {
	mas = new int[x];
}

MASSIVE::MASSIVE(const MASSIVE &obj)
{
	maxsize = obj.maxsize;
	mas = new int[obj.maxsize];
	for (int index = 0; index < obj.maxsize; index++)
		mas[index] = obj.mas[index];
}

void MASSIVE::ADD(int x, int pos)
{
	int* masbuf = new int[maxsize];

	for (int i = 0; i < maxsize; i++)
		masbuf[i] = mas[i];

	delete[]mas;

	mas = new int[++maxsize];

	for (int index = 0; index < pos + 1; index++)
		mas[index] = masbuf[index];

	mas[pos] = x;

	for (int index = pos + 1; index < maxsize; index++)
		mas[index] = masbuf[index - 1];
	index = 0;
}

int MASSIVE::FIND(int x)
{
	i = 0;
	while (mas[i++] != x);

	return i;
}

void MASSIVE::CHAN(int x, int nindex)
{
	if ((nindex > -1) && (nindex < maxsize))
	{
		mas[nindex] = x;

		cout << "Операция \"Замена\" Выполнена" << endl << endl;
	}
	else cout << "Операция не может быть выполнена" << endl << endl;
}

void MASSIVE::DEL(int findex)
{
	if ((findex > -1) && (findex <= maxsize))
	{
		int* masbuf = new int[maxsize - 1];

		i = 0;

		for (index = 0; index < findex - 1; i++, index++)
			masbuf[i] = mas[index];

		for (index = findex; index < maxsize; index++, i++)
			masbuf[i] = mas[index];

		delete[] mas;

		mas = new int[--maxsize];

		for (index = 0; index < maxsize; index++)
			mas[index] = masbuf[index];

		cout << "Операция \"Удаления\" Выполнена" << endl << endl;
	}
	else cout << "Операция не может быть выполнена" << endl << endl;
}

char* MASSIVE::OUTP()
{
	int a, m, k;
	int j = 0;
	char ss[7];

	char* str = new char[1];
	str[0] = '\0';
	int len_str = 0;

	for (int i = 0; i < maxsize; i++)
	{
		a = mas[i];
		k = 1;

		if (a == 0)
		{
			ss[j] = '0';
			j++;
		}

		while (a != 0) {
			a /= 10;
			k *= 10;
		}
		k /= 10;

		while (k != 0) {
			a = mas[i];
			char x = (a / k % 10) + 48;
			k /= 10;
			ss[j] = x;
			j++;
		}
		ss[j++] = '\0';
		m = strlen(ss);

		char* res = new char[len_str + m + 1];
		for (int l = 0; l < len_str; l++)
			res[l] = str[l];
		for (int l = 0; l < m; l++)
			res[len_str + l] = ss[l];
		res[len_str + m] = '\0';


		delete[] str;
		str = new char[len_str + m + 2];

		len_str += m;
		for (int l = 0; l < len_str; l++)
			str[l] = res[l];
		str[len_str] = ' ';
		str[len_str + 1] = '\0';

		len_str += 1;
		j = 0;
		delete[] res;
	}

	return str;
}

void MASSIVE::SORT()
{
	int a = maxsize - 1;

	for (; a > 0; a--)
		for (index = 0; index < a; index++)
			if (mas[index] > mas[index + 1])
			{
				int max = mas[index];
				mas[index] = mas[index + 1];
				mas[index + 1] = max;
			}
}

void MASSIVE::FMAX()
{
	int indmax;
	int max = 0;

	for (index = 0; index<maxsize; index++)
		if (mas[index] > max)
		{
			max = mas[index];
			indmax = index;
		}

	cout << "Индекс максимального = " << indmax << ".Его значение = " << mas[indmax] << endl << endl;
}

void MASSIVE::FMIN()
{
	int indmin;
	int min = 65000;

	for (index = 0; index != maxsize; index++)
		if (mas[index] < min)
		{
			min = mas[index];
			indmin = index;
		}

	cout << "Индекс минимального= " << indmin << ". Его значени= " << mas[indmin] << endl << endl;
}

int MASSIVE::operator[] (int i)
{
	return mas[i];
}

MASSIVE& MASSIVE::operator= (MASSIVE &obj)
{
	if (this == &obj)
	{
		return *this;
	}

	delete[] mas;
	maxsize = obj.maxsize;
	mas = new int[obj.maxsize];
	for (int index = 0; index < obj.maxsize; index++)
		mas[index] = obj.mas[index];

	return *this;
}

MASSIVE& operator+ (MASSIVE &obj, int x)
{
	obj.ADD(x, obj.GetSize());

	return obj;
}

MASSIVE& MASSIVE::operator-- ()
{
	DEL(GetSize());
	return *this;
}

MASSIVE MASSIVE::operator-- (int)
{
	MASSIVE buf(*this);

	DEL(GetSize());
	return buf;
}

MASSIVE& operator- (MASSIVE &obj, int x)
{
	if (obj.FIND(x) == -1)
	{
		cout << "Отсутствует элемент массива" << endl;
		return obj;
	}
	else
	{
		obj.DEL(obj.FIND(x));
		return obj;
	}
}

MASSIVE MASSIVE::operator+ (MASSIVE &obj)
{
	MASSIVE buf;
	for (int i = 0; i < this->maxsize; i++)
		buf.ADD(this->mas[i], buf.maxsize);

	for (int i = 0; i < obj.maxsize; i++)
		buf.ADD(obj.mas[i], buf.maxsize);

	return buf;
}

MASSIVE MASSIVE::operator- (MASSIVE &obj)
{
	MASSIVE buf;

	for (int i = 0; i < this->maxsize; i++) {
		int founded = this->mas[i];
		int j = 0;
		for (; j < obj.maxsize; j++) {
			if (obj.mas[j] == founded)
				break;
		}
		if (j == obj.maxsize)
			buf.ADD(founded, buf.maxsize);
	}
	return buf;
}

ostream& operator<< (ostream& os, MASSIVE &obj)
{
	for (int i = 0; i < obj.maxsize; i++)
		os << obj[i] << " ";
	os << endl;

	return os;
}

ofstream& operator<<(ofstream& os, MASSIVE &obj)
{
	os << obj.maxsize << " ";
	for (int i = 0; i < obj.maxsize; i++)
		os << obj[i] << " ";
	os << endl;

	return os;
}

istream& operator>> (istream& is, MASSIVE &obj)
{
	int x;

	is >> x;

	obj.ADD(x, obj.maxsize);

	return is;
}

ifstream& operator>> (ifstream& is, MASSIVE &obj)
{
	is >> obj.maxsize;
	delete[]obj.mas;
	obj.mas = new int[obj.maxsize];
	for (int i = 0; i < obj.maxsize; i++)
		is >> obj.mas[i];

	return is;
}

ifstream& MASSIVE::input(ifstream& is)
{
	is.read((char*)&maxsize, sizeof(int));
	delete[] mas;
	mas = new int[maxsize];
	for (int i = 0; i < maxsize; i++)
		is.read((char*)&mas[i], sizeof(int));

	return is;
}

ofstream& MASSIVE::output(ofstream& os)
{
	os.write((char*)&maxsize, sizeof(int));
	for (int i = 0; i < maxsize; i++)
		os.write((char*)&mas[i], sizeof(int));

	return os;
}

int MASSIVE::GetSize()
{
	return maxsize;
}

MASSIVE:: ~MASSIVE()
{
	delete[] mas;
}