#include <iostream>

using namespace std;

double help(double* Arg, int size, int p1, int p2)
{
	double result=0;
	for (int i = 0; i < size; i++)
	{
		result += pow(Arg[i], p1)*pow(Arg[i], p2);
	}
	return result;
}


double** macierz(double*Arg, double* Val, int size, int wielomian)
{
	double** macierz = new double*[wielomian + 1];
	for (int i = 0; i < wielomian + 1; i++)
	{
		macierz[i] = new double[wielomian + 1];
	}

	for (int i = 0; i < wielomian + 1; i++)
	{
		for (int j = 0; j < wielomian + 1; j++)
		{
			macierz[i][j] = help(Arg, size, i, j);
		}
	}

	return macierz;
}

double res(double* Arg,double* Val,int size, int wielomian,int p)
{
	double result = 0;
	for (int i = 0; i < size; i++)
	{
		result += Val[i] * pow(Arg[i], p);
	}
	return result;
}


double* wynik(double* Arg,double* Val,int size,int wielomian)
{
	double* wynik = new double[wielomian + 1];

	for (int i = 0; i < wielomian + 1; i++)
	{
		wynik[i] = res(Arg, Val, size, wielomian, i);
	}

	return wynik;

}


int main()
{
	cout << "Podaj liczbe znanych punktow" << endl;
	int size;
	cin >> size;
	cout << "Podaj ich kolejne wartosci" << endl;
	double* Arg = new double[size];
	double* Val = new double[size];

	for (int i = 0; i < size; i++)
	{
		cout << "Podaj x" << i << endl;
		cin >> Arg[i];
		cout << "Podaj y" << i << endl;
		cin >> Val[i];
	}

	cout << "Podaj stopien poszukiwanego wielomianu" << endl;
	int wielomian;
	cin >> wielomian;

	double** M = macierz(Arg,Val,size,wielomian);

	/*
	for (int i = 0; i < wielomian + 1; i++)
	{
		for (int j = 0; j < wielomian + 1; j++)
		{
			cout << M[i][j] << "  ";
		}
		cout << endl;
	}
	*/
	double* R = wynik(Arg, Val, size, wielomian);
	
	for (int i = 0; i < wielomian+1; i++)
	{
		cout << R[i] << endl;
	}
	


	delete[] R;
	for (int i = 0; i < wielomian + 1; i++)
	{
		delete[] M[i];
	}

	delete[] M;

	delete[] Arg;
	delete[] Val;

	system("pause");
}