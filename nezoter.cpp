// 2014.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


using namespace std;



int main()
{
	int sorsz = 15;
	int usz = 20;

	string foglaltsag[15];
	string prioritas[15];

	//1. feladat

	ifstream fbe("foglaltsag.txt");
	for (int i = 0; i < sorsz; i++)
	{
		getline(fbe, foglaltsag[i]);
		//cout << foglaltsag[i] << endl;
	}

	ifstream pbe("kategoria.txt");
	for (int i = 0; i < sorsz; i++)
	{
		getline(pbe, prioritas[i]);
		//cout << prioritas[i] << endl;
	}

	cout << "2. feladat" << endl;
	int besor;
	int beszek;
	cout << "Adj meg egy sorszamot: ";
	cin >> besor;
	cout << "Adj meg egy szek szamot: ";
	cin >> beszek;

		if (foglaltsag[besor - 1][beszek-1] == 'o')
			cout << "A valasztott hely szabad." << endl;
		else
			cout << "A valasztott hely foglalt." << endl;

	cout << "3. feladat" << endl;
	int osszhely = sorsz * usz;
	int eladott = 0;

	for (int i = 0; i < sorsz; i++)
	{
		for (int j = 0; j < usz; j++)
		{
			if (foglaltsag[i][j] == 'x')
				eladott++;
		}
	}
	//cout << eladott << endl; //187 db
	float eseged = (float)eladott;
	float oseged = (float)osszhely;
	float szazalek = eseged / oseged;
	cout << "Az eloadasra eddig " << eladott << " jegyet adtak el, ez a nezoter ";
	cout << fixed << setprecision(0) << szazalek * 100 << " %-a." << endl;

	cout << "4. feladat" << endl;

	int kategoria[5];
	for (int i = 0; i < 5; i++)
	{
		kategoria[i] = 0;
	}

	for (int i = 0; i < sorsz; i++)
	{
		for (int j = 0; j < usz; j++)
		{
			if ((foglaltsag[i][j] == 'x') && (prioritas[i][j] == '1'))
				kategoria[0]++;
			else if ((foglaltsag[i][j] == 'x') && (prioritas[i][j] == '2'))
				kategoria[1]++;
			else if ((foglaltsag[i][j] == 'x') && (prioritas[i][j] == '3'))
				kategoria[2]++;
			else if ((foglaltsag[i][j] == 'x') && (prioritas[i][j] == '4'))
				kategoria[3]++;
			else if ((foglaltsag[i][j] == 'x') && (prioritas[i][j] == '5'))
				kategoria[4]++;
		}
	}

	int arseged = 0;
	int arseged2 = 0;
	for (int i = 0; i < 5; i++)
	{
		//cout <<i+1<<"    "<< kategoria[i] << endl;
		if (kategoria[i] > arseged)
		{
			arseged = kategoria[i];
			arseged2 = i;
		}
			
	}
	cout <<"A legtobb jegyet a(z) "<< arseged2+1 <<". arkategoriaban ertekesitettek."<< endl;

	cout << "5. feladat" << endl;
	int osszbevetel = 0;
	for (int i = 0; i < 5; i++)
	{
		if (i == 0)
			osszbevetel += kategoria[i] * 5000;
		else if (i == 1)
			osszbevetel += kategoria[i] * 4000;
		else if (i == 2)
			osszbevetel += kategoria[i] * 3000;
		else if (i == 3)
			osszbevetel += kategoria[i] * 2000;
		else if (i == 4)
			osszbevetel += kategoria[i] * 1500;
	}

	cout << "A szinhaz bevetele: " << osszbevetel << " ft lenne." << endl;


	cout << "6. feladat" << endl;

	int egyedulh = 0;
	string atmen;


	for (int i = 0; i < sorsz; i++)
	{
		atmen = 'x' + foglaltsag[i] + 'x';
		for (int j = 1; j < usz+1; j++)
		{
			if ((atmen[j] == 'o')&& (atmen[j + 1] == 'x') && (atmen[j-1] == 'x'))
				egyedulh++;
		}
	}
	cout <<"A nezozeren: "<< egyedulh <<" egyedul allo ures hely van."<< endl;


	cout << "7. feladat" << endl;

	string szabad[15];
	ofstream proba("szabad.txt");

	for (int i = 0; i < sorsz; i++)
	{
		szabad[i] = "xxxxxxxxxxxxxxxxxxxx";
	}

	for (int i = 0; i < sorsz; i++)
	{
		for (int j = 0; j < usz; j++)
		{
			if (foglaltsag[i][j] != 'x')
				szabad[i][j] = prioritas[i][j];
		}
		cout << szabad[i] << endl;
		proba << szabad[i] << endl;
	}
	

	return 0;
}
