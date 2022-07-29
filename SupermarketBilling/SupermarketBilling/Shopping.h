#pragma once
#include <string>
using namespace std;

class Shopping
{
private:
	int pcode;
	float price;
	float dis;
	string pname;

public:
	Shopping();
	~Shopping();
	void menu();
	void administrator();
	void buyer();
	void add();
	void edit();
	void rem();
	void list();
	void receipt();

};

