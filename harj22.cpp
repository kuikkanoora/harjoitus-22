/*************************************************************************************************************************************************************
*Teht�v�: Harjoitus22
*Tekij�: Noora Kuikka
*PVM: 25.11.2013
*Kuvaus:
*Tee ohjelma, joka toimii henkil�rekisterin� (max 10).
*Ohjelma antaa k�ytt�j�lle seuraavan valikon:
*
*VALIKKO
*0 Lopeta
*1 Lisaa henkilo
*2 Nayta kaikki henkilot
*
*Tallenna henkil�iden tiedot tietuetaulukkoon.
*Tallennettavia tietoja ovat
*etunimi (merkkijono)
*koulumatka (liukuluku)
*hatun koko (kokonaisluku)
*
*Toteuta ensin koko ohjelma p��ohjelmana. 
*
*T�m�n j�lkeen lis�� seuraavat aliohjelmat:
*a) int Valikko(void);
*
*b) void TulostaHenkilo(TIEDOT );
*c) void TulostaKaikkiHenkilot(TIEDOT [], int lkm);
*d) void LisaaHenkilo(TIEDOT [], int *lkm);
*Versio 1.0 H4719 25.11.2013
**************************************************************************************************************************************************************/

#include <iostream>
using namespace std;

struct PEOPLE
{
	char name[20];
	double journey;
	int size;
};

const int MAX_ARRAY = 10;

int Menu(void);
void PrintAll(PEOPLE per[], int num);
void AddPerson(PEOPLE [], int *num);
void PrintPerson(PEOPLE num[]);

int main()
{
	int choice = 0;
	int num = 0;
	bool cont = true;
	PEOPLE per[MAX_ARRAY];

	do
	{
		cout << "\nThe number of people in the array: " << num << endl;
		cout << "Max. 10." << endl;
		choice = Menu();
		cout << endl;

		switch (choice)
		{
		case 0:
			{
				cout << "\nExiting program...\n";
				cont = false;
				break;
			}
		case 1:
			{
			    if(num < 10)
				{
					AddPerson(per, &num);
				}
                else
				{
					cout << "You have reached the maximum amount of people this array can store." << endl;
				}
				break;
			}
		case 2:
			{
				PrintPerson(per);
				break;
			}
		case 3:
			{
				PrintAll(per, num);
				break;
			}
		default:
			{
				cout << "\nIncorrect input. Enter either '0', '1', '2' or '3'.\n";
				break;
			}
		}
	}

	while (cont == true);
}

int Menu(void)
{
	int choice;

	cout << "\n*MENU*\n";
	cout << "\n0. Exit\n";
	cout << "\n1. Add person to array\n";
	cout << "\n2. Print person in array\n";
	cout << "\n3. Print all people in array\n" << endl;
	cin >> choice;

	return choice;
}

void PrintAll(PEOPLE per[], int num)
{
	cout << "Listing people..." << endl;
	for (int ind = 0; (ind < num); ind++)
	{
		cout << "\nName: " << per[ind].name << endl;
		cout << "Distance: " << per[ind].journey << "km" << endl; 
		cout << "Hat size: " << per[ind].size << endl;
		cout << endl;
	}
}

void AddPerson(PEOPLE p_per[], int *per_num)
{
	cout << "\nEnter the first name:\n";
	cin >> p_per[*per_num].name;
	cout << "\nEnter the distance to school:\n";
	cin >> p_per[*per_num].journey;
	cout << "\nEnter the hat size:\n";
	cin >> p_per[*per_num].size;

	(*per_num)++;
}

void PrintPerson(PEOPLE p_per[])
{
	int numb;
	cout << "Enter a number:" << endl;
	cin >> numb;
	if (numb > 10)
	{
		cout << "Incorrect input, the maximum number of people in the array is 10." << endl;
	}
	else
	{
		cout << "Name: " << p_per[numb-1].name << endl;
		cout << "Distance: " << p_per[numb-1].journey << "km" << endl;
		cout << "Hat size: " << p_per[numb-1].size << endl;
	}
}