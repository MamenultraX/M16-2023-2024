#include <iostream>
#include <time.h>
using namespace std;

//variabes
int rombos[13] = { 1,1,1,1,1,1,1,1,1,1,1,1,1 };
int corazones[13] = { 1,1,1,1,1,1,1,1,1,1,1,1,1 };
int picas[13] = { 1,1,1,1,1,1,1,1,1,1,1,1,1 };
int treboles[13] = { 1,1,1,1,1,1,1,1,1,1,1,1,1 };
int puntosJugador = 0;
int puntosBanca = 0;
int num;
bool banca21 = false;
char pedir = 's';
bool noSeRepite = false;
string palo;

void cartas(string& palo, int& num, int& repartirCarta, char pedir) {
	//Numeracion de las cartas segun el valor de la array

	if (repartirCarta < 10 && repartirCarta>0)
	{
		num = repartirCarta + 1;
		cout << num << " de " << palo << "\n";
	}
	else if (repartirCarta >= 10)
	{

		num = 10;
		if (repartirCarta == 10)
		{
			cout << "J de " << palo << "\n";
		}
		else if (repartirCarta == 11)
		{
			cout << "Q de " << palo << "\n";
		}
		else if (repartirCarta == 12)
		{
			cout << "K de " << palo << "\n";
		}
	}

	if (repartirCarta == 0 && pedir == 's')
	{
		do
		{


			cout << "You AS de " << palo << " is a 1 or an 11\n";
			cin >> num;
			repartirCarta = num;
			
		} while (num != 1 && num != 11);
		cout << repartirCarta << " de " << palo << "\n";
	}
	if (repartirCarta == 0 && pedir == 'n')
	{
		if (puntosBanca <= 10)
		{
			num = 11;
			repartirCarta = 11;
		}
		else if (puntosBanca > 10)
		{
			num = 1;
			repartirCarta = 1;
		}
		cout << "A of " << palo << "\n";
		cout << repartirCarta << " de " << palo << "\n";
	}
	
}
void repartir(int& num) {

    int repartirPalo;
    int repartirCarta;
    noSeRepite = false;
    do
    {
        repartirPalo = rand() % 4 + 1;
        repartirCarta = rand() % 13;

        if (repartirPalo == 1 && corazones[repartirCarta] == 1)
        {
            corazones[repartirCarta] == 0;
            noSeRepite == true;
            palo = "corazones";

        }


        if (repartirPalo == 2 && rombos[repartirCarta] == 1)
        {
            rombos[repartirCarta] == 0;
            noSeRepite == true;
            palo = "rombos";

        }

        if (repartirPalo == 3 && picas[repartirCarta] == 1)
        {
            picas[repartirCarta] == 0;
            noSeRepite == true;
            palo = "picas";

        }

        if (repartirPalo == 4 && treboles[repartirCarta] == 1)
        {
            treboles[repartirCarta] == 0;
            noSeRepite == true;
            palo = "treboles";

        }

    } while (noSeRepite = false);
	cartas(palo, num, repartirCarta, pedir);
	
}


int main()
{
	srand(time(NULL));
	//INICIO
	cout << "---> BIENVENIDO A JV BLACKJACK <---\n";
	cout << "Hecho por Nilo Iñesta y Arnau Pedrola\n";
	system("pause");
	system("cls");

	//REP 2 cartas jugador

	for (size_t i = 0; i < 2; i++)
	{
		repartir(num);
		puntosJugador += num;
	}
	cout << "Tienes " << puntosJugador << " puntos\n";

	//1 carata banca
	pedir = 'n';
	repartir(num);
	puntosBanca += num;
	system("pause");
	//Quiere otra cara el jugador
	do{
		cout << "Quieres otra carta\n";
		cout << "si o no? \n";
		cin >> pedir;
		system("cls");
	} while (pedir != 's' && pedir != 'n');
	while (pedir == 's')
	{
		repartir(num);
			puntosJugador += num;

			if (puntosJugador>21)
			{
				pedir = 'n';
				cout << "Tienes " << puntosJugador << " puntos\n";
				system("pause");
				system("cls");

			}
			else {
				do {
					cout << "Quieres otra carta\n";
					cout << "si o no? \n";
					cin >> pedir;
					system("cls");
				} while (pedir != 's' && pedir != 'n');
			}
	}
	if (puntosJugador<=21)
	{
		do
		{
			repartir(num);
			puntosBanca += num;
			cout << "La banca tiene " << puntosBanca << " puntos\n";
		} while (puntosBanca<=puntosJugador);
	}

	if (puntosBanca <= 21)
	{
		cout << "Has perdido :_(";
	}
	else cout << "Has ganado!!!";




}