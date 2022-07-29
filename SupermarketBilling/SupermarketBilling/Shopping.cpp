#include "Shopping.h"

#include <iostream>
#include <fstream>
using namespace std;

Shopping::Shopping()
{
	
}

Shopping::~Shopping()
{
	
}

void Shopping::menu()
{
	m:
	int choice;
	string email;
	string password;

	cout << "\t\t\t\t__________________________________________________\n";
	cout << "\t\t\t\t                                                  \n";
	cout << "\t\t\t\t                Supermarket Main Menu             \n";
	cout << "\t\t\t\t                                                  \n";
	cout << "\t\t\t\t__________________________________________________\n";
	cout << "\t\t\t\t                                                  \n";
	cout << "\t\t\t\t |  1) Administrator        |\n";
	cout << "\t\t\t\t |						     |\n";
	cout << "\t\t\t\t |  2) Buyer                |\n";
	cout << "\t\t\t\t |						     |\n";
	cout << "\t\t\t\t |  3) Exit                 |\n";
	cout << "\t\t\t\t |						     |\n";
	cout << "\t\t\t\t Please select!";
	cin >> choice;

	switch (choice)
	{
	case 1:
		cout << "\t\t\t Please Login \n";
		cout << "\t\t\t Enter Email  \n";
		cin >> email;
		cout << "\t\t\t Password     \n";
		cin >> password;

		if((email=="matheus@email.com" && password=="matheus@123"))
		{
			administrator();
		}else
		{
			cout << "Invalid email/password";
		}
		break;
	case 2:
		{
		buyer();
		}
	case 3:
		{
		exit(0);
		}
		default:
		{
			cout << "Please select from the given options";
		}

	}
	goto m;
}

void Shopping::administrator()
{
	m:
	int choice;
	cout << "\n\n\n\t\t\t Administrator menu";
	cout << "\n\t\t\t |______1) Add the product______|";
	cout << "\n\t\t\t |                              |";
	cout << "\n\t\t\t |______2) Modify the product___|";
	cout << "\n\t\t\t |                              |";
	cout << "\n\t\t\t |______3) Delete the product___|";
	cout << "\n\t\t\t |                              |";
	cout << "\n\t\t\t |______4) Back to main menu____|";

	cout << "\n\n\t Please enter your choice ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		add();
		break;
	case 2:
		edit();
		break;
	case 3:
		rem();
		break;
	case 4:
		menu();

		default:
			cout << "Invalid choice!";
	}
	goto m;
}

void Shopping::buyer()
{
	m:
	int choice;
	cout << "\t\t\t Buyer      \n";
	cout << "\t\t\t______________";
	cout << "                    ";
	cout << "\t\t\t1) Buy product";
	cout << "                    ";
	cout << "\t\t\t2) Go back    ";
	cout << "\t\t\tEnter your choice: ";
	cin >> choice;

	switch (choice)
	{
		case 1:
			receipt();
			break;
		case 2:
			menu();
		default:
			cout << "Invalid choice!";
			break;
	}
	goto m;
}

void Shopping::add()
{
	m:
	fstream data;
	int c;
	int token = 0;
	float p;
	float d;
	string n;

	cout << "\n\n\t\t\t Add new product";
	cout << "\n\n\t Product code of the product: ";
	cin >> pcode;
	cout << "\n\n Name of the product: ";
	cin >> pname;
	cout << "\n\n\t Price of the product: ";
	cin >> price;
	cout << "\n\n\t Discount on product: ";
	cin >> dis;

	data.open("database.txt", ios::in);

	if(!data)
	{
		data.open("database.txt", ios::app|ios::out);
		data << "  " << pcode << "  " << pname << "  " << price << "  " << dis << "\n";
		data.close();
	}
	else
	{
		data >> c >> n >> p >> d;

		while (!data.eof())
		{
			if (c == pcode)
			{
				token++;
			}
			data >> c >> n >> p >> d;
		}
		data.close();


		if (token == 1)
			goto m;
		else
		{

			data.open("database.txt", ios::app | ios::out);
			data << "  " << pcode << "  " << pname << "  " << price << "  " << dis << "\n";
			data.close();
		}
	}
	cout << "\n\n\t\t Record inserted! ";
}

void Shopping::edit()
{
	fstream data, data1;
	int pkey;
	int token = 0;
	int c;
	float p;
	float d;
	string n;

	cout << "\n\t\t\t Modify the record";
	cout << "\n\t\t\t Product code: ";
	cin >> pkey;

	data.open("database.txt", ios::in);

	if(!data)
	{
		cout << "\n\nFile doesn't existe";
	}
	else
	{
		data1.open("database1.txt", ios::app | ios::out);

		data >> pcode >> pname >> price >> dis;
		while(!data.eof())
		{
			if(pkey == pcode)
			{
				cout << "\n\t\t Product new code: ";
				cin >> c;
				cout << "\n\t\t Name of the product: ";
				cin >> n;
				cout << "\n\t\t Price: ";
				cin >> p;
				cout << "\n\t\t Discount: ";
				cin >> d;
				data1 << " " << c << " " << n << " " << p << " " << d << " ";
				cout << "\n\n\t\t Record edited";
				token++;
			}
			else
			{
				data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
			}
			data >> pcode >> pname >> price >> dis;
		}
		data.close();
		data1.close();

		remove("database.txt");
		rename("database1.txt", "database.txt");

		if(token == 0)
		{
			cout << "\n\n Record not fount sorry";
		}
	}
}

void Shopping::rem()
{
	fstream data, data1;
	int pkey;
	int token = 0;
	cout << "\n\n\t Delete product";
	cout << "\n\n\t Product code: ";
	cin >> pkey;
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout << "\n\n File doesn't exist";
	}
	else
	{
		data1.open("database1.txt", ios::app | ios::out);
		data >> pcode >> pname >> price >> dis;
		while (!data.eof())
		{
			if(pcode == pkey)
			{
				cout << "\n\n\t Product deleted succesfully";
				token++;
			}
			else
			{
				data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
			}
			data >> pcode >> pname >> price >> dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt", "database.txt");

		if(token == 0)
		{
			cout << "\n\n Record not found";
		}
	}

}

void Shopping::list()
{
	fstream data;
	data.open("database.txt", ios::in);
	cout << "\n\n|_________________________________________\n";
	cout << "ProNo\t\tName\t\tPrice\n";
	cout << "\n\n|_________________________________________\n";
	data >> pcode >> pname >> price >> dis;
	while (!data.eof())
	{
		cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
		data >> pcode >> pname >> price >> dis;
	}
	data.close();
}

void Shopping::receipt()
{
	m:
	fstream data;

	int arrc[100];
	int arrq[100];
	char choice;
	int c = 0;
	float amount = 0;
	float dis = 0;
	float total = 0;

	cout << "\n\n=\t\t\t RECEIPT";
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout << "\n\n Empty database";
	}
	else
	{
		data.close();

		list();
		cout << "\n\n_________________________________________\n";
		cout << "\n\n|										  \n";
		cout << "\n\n			Please place the order   	  \n";
		cout << "\n\n|										  \n";
		cout << "\n\n_________________________________________\n";
		do
		{
			cout << "\n\nEnter Product code: ";
			cin >> arrc[c];
			cout << "\n\nEnter the product quantity";
			cin >> arrq[c];
			for (int i = 0; i < c; i++)
			{
				cout << "\n\n Duplicate product code. Please try again!";
				goto m;
			}
			c++;
			cout << "\n\n Do you want to buy another product? if yes then press y else no";
			cin >> choice;
		} while (choice == 'y');
		cout << "\n\n\t\t\t________________________RECEIPT__________________________\n";
		cout << "\nProduct No\t product Name\t product quantity\tprice\tAmount\tAmount with discount";

		for(int i = 0; i < c; i++)
		{
			data.open("database.txt", ios::in);
			data >> pcode >> pname >> price >> dis;
			while (!data.eof())
			{
				if(pcode == arrc[i])
				{
					amount = price * arrq[i];
					dis = amount - (amount * dis/100);
					total = total + dis;
					cout << "\n" << pcode << pname << arrq[i] << price << amount << dis;
				}
				data >> pcode >> pname >> price >> dis;
			}
		}
		data.close();
	}
	cout << "\n\n______________________________________________________";
	cout << "\t Total Amount: " << total;
}


