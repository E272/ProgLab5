#pragma once
#ifndef _MASSIVE_H
#define _MASSIVE_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

using namespace std;

class MASSIVE
{
	friend MASSIVE& operator+ (MASSIVE &obj, int x);

	friend MASSIVE& operator- (MASSIVE &obj, int x);

private:
	int index;
	int i;

public:
	MASSIVE();

	MASSIVE(const MASSIVE &obj);

	virtual void ADD(int x, int pos);

	int FIND(int x);

	void CHAN(int x, int nindex);

	void DEL(int findex);

	char* OUTP();

	void SORT();

	void FMAX();

	void FMIN();

	int operator[] (int i);

	MASSIVE& operator= (MASSIVE &obj);

	MASSIVE& operator--	();

	MASSIVE operator-- (int);

	MASSIVE operator+ (MASSIVE &obj);

	MASSIVE operator- (MASSIVE &obj);

	friend ostream& operator<< (ostream& os, MASSIVE &obj);

	friend ofstream& operator<< (ofstream& os, MASSIVE &obj);

	friend istream& operator>> (istream& is, MASSIVE &obj);

	friend ifstream& operator>> (ifstream& is, MASSIVE &obj);

	ifstream& input(ifstream& is);

	ofstream& output(ofstream& os);

	int GetSize();

	~MASSIVE();

protected:
	int maxsize;

	int* mas;

	MASSIVE(int x);
};
#endif