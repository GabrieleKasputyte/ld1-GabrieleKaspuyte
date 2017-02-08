// ConsoleApplication23.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdlib>
#include <fstream> //aprasyta ivedimo is failo ir isvedimo srautu klase
#include <string>
#include <cstring>
using namespace std;

float skaiciavimas()
{

}

float salinimas()
{
	EILUTE A[10];
	int vt = 0;
	for (int i = 0; i < 10; i++)
	{
		if (A[i].metai < 2015)
		{
			for (vt = i; vt <= 10; vt++)
			{
				A[vt] = A[vt + 1];
			}
			i--;
		}
	}
}
float rikiavimas() // rikiuojama pagal metus
{
	int tvarkinga = 0;
	int i = 0;
	EILUTE A[10];
	EILUTE *tvarkinga = new EILUTE[10];
	for (int i = 0; i < 10; i++)
	{
		tvarkinga[i] = A[i];
	}
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = (i + 1); j < 11; j++)
		{
			if (tvarkinga[i].metai > tvarkinga[j].metai)
			{
				EILUTE laikinas = tvarkinga[i]; // reiksme laikinai saugoma naujame kintamajame
				tvarkinga[i] = tvarkinga[j];
				tvarkinga[j] = laikinas;
			}
		}
	}
	cout << "Atliekamas rikiavimas: " << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "Eil.nr - " << tvarkinga[i].skaicius << endl;
		cout << "Valstybinis numeris: " << tvarkinga[i].numeris << endl;
		cout << "Automobilio marke: " << tvarkinga[i].automarke << endl;
		cout << "Spalva: " << tvarkinga[i].spalva << endl;
		cout << "Pagaminimo metai: " << tvarkinga[i].metai << endl;
		cout << "Kuro tipas: " << tvarkinga[i].kuras << endl;
		cout << "Automobilio galingumas (kW): " << tvarkinga[i].galingumas << endl;
		cout << "Kuro sanaudos mieste: " << tvarkinga[i].sanaudosmieste << endl;
		cout << "Kuro sanaudos uzmiestyje: " << tvarkinga[i].sanaudosuzmiesty << endl;
		cout << "Automobilio modelis: " << tvarkinga[i].automodelis << endl;
	}
}

float spalva()
{
	EILUTE A[10];
	int i = 0;
	char x[15];

	cout << "Kokios spalvos automobilio noretumete? Variantai: Juoda, pilka, geltona, zalia, melyna" << endl;
	cout << "Iveskite viena varianta: ";
	cin >> x;

	for (int i = 0; i < 10; i++)
	{
		if (A[i].spalva == x)
		{
			spalvosspausdinimas();
		}
	}
}

float spalvosspausdinimas()
{
	EILUTE A[10];

}

struct EILUTE
{
	int skaicius;
	char numeris[6];
	char automarke[21];
	char spalva[20];
	int metai;
	char kuras[10];
	int galingumas;
	float sanaudosmieste;
	float sanaudosuzmiesty;
	char automodelis[15];
	float kurokaina;
};
int main()
{
	EILUTE A[10];
	ifstream D("auto.txt");
	int i = 0;
	while (!D.eof())
	{
		i++;
		D >> A[i].skaicius;
		cout << "Eil.nr - " << A[i].skaicius << endl;
		D >> A[i].numeris;
		cout << "Valstybinis numeris: " << A[i].numeris << endl;
		D >> A[i].automarke;
		cout << "Automobilio marke: " << A[i].automarke << endl;
		D >> A[i].spalva;
		cout << "Spalva: " << A[i].spalva << endl;
		D >> A[i].metai;
		cout << "Pagaminimo metai: " << A[i].metai << endl;
		D >> A[i].kuras;
		cout << "Kuro tipas: " << A[i].kuras << endl;
		D >> A[i].galingumas;
		cout << "Automobilio galingumas (kW): " << A[i].galingumas << endl;
		D >> A[i].sanaudosmieste;
		cout << "Kuro sanaudos mieste: " << A[i].sanaudosmieste << endl;
		D >> A[i].sanaudosuzmiesty;
		cout << "Kuro sanaudos uzmiestyje: " << A[i].sanaudosuzmiesty << endl;
		D >> A[i].automodelis;
		cout << "Automobilio modelis: " << A[i].automodelis << endl;
		system("pause");
	}
	cout << endl;
	cout << "Duomenys perskaityti" << endl;
	cout << endl;
	D.close();
	system("pause");
	return 0;
}

