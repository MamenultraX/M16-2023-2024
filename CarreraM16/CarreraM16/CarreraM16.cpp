#include "Clase.h"
#include <string>

//todas las librerias estan en la clase

using namespace std;


//Declaracion de variables del juego Main
int velocidad;
int distancia;
bool nitro;
string nombre;



int main()
{
	//Inicio juego 
	cout << "--->Bienvenido a tu primera carrera de Formula 1<--\n";
	cout << "Tienes 5 turnos para llegar mas lejos que tu rival, puedes usar nitro una vez para dar un pequeño empujon.\n";
	//Formula1

	cout << "Como te llamas?\n";
	cin >> nombre;

	Formula formula1(0, 0, true, nombre);

	//Formula2

	cout << "Quien es tu rival?\n";
	cin >> nombre;

	Formula formula2(0, 0, true, nombre);

	cout << "Comienza la carrera de " + formula1.getNom() + " contra " + formula2.getNom() + "\n";
	system("pause");
	system("cls");
	//Iniciamos los 5 turnos con for
	for (size_t i = 0; i < 5; i++)
	{



		//inicializacion random para dado
		srand(time(NULL));

		//condicional usar nitro
		if (formula1.getNitro() == true) {
			string quiereNitro = "";
			//pregunar si quiere el nitro en esta ronda

			while (quiereNitro != "si" && quiereNitro != "no")
			{
				cout << "¿Quieres usar nitro?\n";
				cout << "si o no\n";
				cin >> quiereNitro;

				if (quiereNitro == "si")
				{

					//declaramos el nitro como false porque se ha usado
					formula1.setNitro(false);
					//el barco 1 jugador principal tiene un 50% de exito del nitro
					int number = rand() % 2;
					//si sale 0 la velocidad se duplica y si sale 1 es la mitad
					if (number == 0)
					{

						formula1.setVel(formula1.getVel() * 2);
					}
					else
					{

						formula1.setVel(formula1.getVel() / 2);
					}
				}

			}
		}

		//numero aleatorio entre 1 y 6 para un coche y el otro
		int dado1 = rand() % 6 + 1;
		int dado2 = rand() % 6 + 1;

		//Tirar dado
		cout << "Momento para tirar el dado, presiona enter para lanzarlo \n";
		system("pause");

		//decir tu numero de dado i el del rival
		cout << "tu puntuacion: " << dado1 << " tu rival: " << dado2 << "\n";

		system("pause");


		//velocidad a cada barco mas la velocidad anterior
		formula1.setVel(dado1 + formula1.getVel());
		formula2.setVel(dado2 + formula1.getVel());

		//distancia actual del barco que es la distancia actual mas la velocidad actual
		formula1.setDis(formula1.getDis() + formula1.getVel());
		formula2.setDis(formula2.getDis() + formula2.getVel());

		//resultados
		formula1.getVelDis();
		formula2.getVelDis();
		system("pause");
		system("cls");

	}
	//Acabados 5 turnos
	if (formula1.getDis() < formula2.getDis())
	{
		cout << "-->Has perdido otra vez sera<--\n";
	}
	else if (formula1.getDis() > formula2.getDis()) {
		cout << "-->Has ganado, bien hecho <--\n";
	}
	else
	{
		cout << "-->Habeis empatado. Buena carrera<--";
	}
}

