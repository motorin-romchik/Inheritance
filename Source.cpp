#include <string>
#include <iostream>
#include <Windows.h>
#include "Source.h"
#include <chrono>
void fun(int choose);
using namespace std;
class engine {
protected:
	string name;
public:
	engine() {
		name = "empty";
	}
	engine(string t) {
		this->name = t;
	}
	engine(engine& D) {
		this->name = D.name;
	}
	virtual ~engine(){}
	virtual void Out() = 0;
	virtual void In() = 0;
};
class ICE : public engine
{
	int price;

public:
	
	ICE() :
		engine() {
		price = 0;
	}
	ICE(ICE& D): 
		engine(D) {
		this->price = D.price;
	
	}

	ICE(int p,string t):
	  engine(t){
		this->price = p;
	}
	virtual ~ICE() {
		price = 0;
	}
	void Out() {
		cout << "����:" << price<<endl;
		cout << "���:"; cout << name;

	}
	void In() {
		cout << "����:"; cin >> price;
		cout << "���:"; cin >> name;
	}
	double price_pro() {
		return (double)(price*100);
	}

};
class TRE : public engine
{

	int oct_n;

public:
	TRE():engine() {
		oct_n = 0;
	}
	TRE(TRE& D): engine(D)
	{
		this->oct_n = D.oct_n;
	}
	TRE(int g,string t): engine(t){
		this->oct_n = g;
	}
	virtual ~TRE() {
		oct_n = 0;
	}
	void Out() {
		cout << "�����_�:" << oct_n << endl;
		cout << "���:"; cout << name;

	}
	void In() {
		cout << "�����_�:"; cin >> oct_n;
		cout << "���:"; cin >> name;
	}
	double oct_pro() {
		return (double)(oct_n * 100);
	}
};

class diesel : public engine {

	int smoke;
public:
	diesel() :
		engine() {
		smoke = 0;
	}
	diesel(diesel& D) :
		engine(D) {
		this->smoke = D.smoke;

	}

	diesel(int p, string t) :
		engine(t) {
		this->smoke = p;
	}
	virtual ~diesel() {
		smoke = 0;
	}
	void Out() {
		cout << "���_�:" << smoke << endl;
		cout << "���:"; cout << name;

	}
	void In() {
		cout << "���_�:"; cin >> smoke;
		cout << "���:"; cin >> name;
	}
	double smoke_pro() {
		return (double)(smoke * 100);
	}

	
};
void fun(int choose) {
	switch (choose) {
	case 1: {
		system("cls");
		cout << "�� ������� ��������� ����������� ��������!\n";
		int size;
		cout << "����� ���-��?\n";
		cin >> size;
		engine** m1 = new  engine * [size];
		cout << "������� ���� � ��� ���\n";
		for (int k = 0;k < size;k++) {
			m1[k] = new ICE();
			m1[k]->In();


		}
		cout << endl << endl << "...........................................";
		cout << endl << "�����....\n";
		cout << "����� ������� �������� ��������� ������. �� �����.\n";
		for (int k = 0;k < size;k++) {
			m1[k]->Out();
			cout << endl;
		}
	
		cout << "���������� �� ������������ � ����������� � �����\n";
		int bum ;
		cout << "����� ���-��?\n";
		cin >> bum;
		engine** mn = new  engine * [bum];
		engine ** mo = new engine*[bum] ;
		//ICE mh (5, "cnh");

		for (int i = 0; i < bum;i++) {
			mn[i] = new ICE(2, "ldf");
			mn[i]->In();
			mo[i] = new ICE(*(ICE*)mn[i]);
		}
		cout << "����� ������� �������� ������. ������������� � �����.\n";
		for (int i = 0;i < bum;i++) {
			mn[i]->Out();
			cout << endl;
		}
		cout << "����� ������� �������� ��������� ������. �����\n";
		for (int k = 0;k < bum;k++) {
			mo[k]->Out();
			cout << endl;
		}
		cout << "����� ������������ ������!!!\n";
		for (int k = 0;k < bum;k++) {
			cout << (*(ICE*)mo[k]).price_pro() << endl;
		}
		break;
	}
	case 2: {
		system("cls");
		cout << "�� ������� ��������������� ��������� !\n";
		int size;
		cout << "����� ���-��?\n";
		cin >> size;
		engine ** m1 = new engine* [size];
		cout << "������� ������������ ���\n";
		for (int k = 0;k < size;k++) {
			m1[k] = new TRE();
			m1[k]->In();
		}
		cout << "�����....\n";
		for (int k = 0;k < size;k++) {
			m1[k]->Out();
			cout << endl;
		}
		cout << "���������� �� ������������ � ����������� � �����\n";
		int bum;
		cout << "����� ���-��?\n";
		cin >> bum;
		engine** mn = new  engine * [bum];
		engine** mo = new engine * [bum];
		for (int i = 0; i < size;i++) {
			mn[i] = new TRE(2, "ldf");
			mn[i]->In();
			mo[i] = new TRE(*(TRE*)mn[i]);

		}
		cout << "����� ������� �������� ����. �������. � �����.\n";
		for (int i = 0;i < bum;i++) {
			mn[i]->Out();
		}
		cout << "����� ������� �������� ��������� ������. �����\n";
		for (int k = 0;k < bum;k++) {
			mo[k]->Out();
			cout << endl;
		}
		break;
		
		cout << "����� ������������ ������!!!\n";
		for (int k = 0;k < bum;k++) 
			cout << (*(TRE*)mo[k]).oct_pro() << endl;
		
		}
		
	case 3:
	{
		system("cls");
		cout << "�� ������� ��������� ��������� !\n";
		int size;
		cout << "����� ���-��?\n";
		cin >> size;
		engine** m1 = new engine*[size];
		cout << "������� ������������ ���\n";
		for (int k = 0;k < size;k++) {
			m1[k] = new diesel();
			m1[k]->In();
		}
		cout << "�����....\n";
		for (int k = 0;k < size;k++) {
			m1[k]->Out();
			cout << endl;
		}
		cout << "���������� �� ������������ � ����������� � �����\n";
		int bum;
		cout << "����� ���-��?\n";
		cin >> bum;
		engine** mn = new  engine * [bum];
		engine** mo = new engine * [bum];
		for (int i = 0; i < size;i++) {
			mn[i] = new diesel(2, "ldf");
			mn[i]->In();
			mo[i] = new diesel(*(diesel*)mn[i]);

		}
		cout << "����� ������� �������� ����. �������. � �����.\n";
		for (int i = 0;i < bum;i++) {
			mn[i]->Out();
		}
		cout << "����� ������� �������� ��������� ������. �����\n";
		for (int k = 0;k < bum;k++) {
			mo[k]->Out();
		}
		break;
		cout << "����� ������������ ������!!!\n";
		for (int k = 0;k < bum;k++)
			cout << (*(diesel*)mo[k]).smoke_pro() << endl;
	}

	case 4:
		exit(0);
		break;
	}
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	for (;;) {
		cout << "�������� ��� ���������!\n";
		cout << "1. ����������� ��������\n";
		cout << "2. ���������������\n";
		cout << "3. ���������\n";
		cout << "4. �����....\n";


		int choose = 0;
		cin >> choose;
		fun(choose);
	}
	

	}