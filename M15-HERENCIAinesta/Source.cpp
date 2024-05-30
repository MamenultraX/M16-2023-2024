#include <iostream>
#include <time.h>
#include "Personaje.h"
#include "EnemigoFinal.h"


//en esta funcion cojemos los parametros del mapa y el de moves para poder escribir por pantalla el mapa dependiendo los numeros asociados en el mapa se printeara una cosa o otra.
void crearMapa(string caracteresMapa[3], int mapa[5][5]) {
	
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			if (mapa[i][j] == 0 || mapa[i][j] == 2 || mapa[i][j] == 1)
			{
				cout << caracteresMapa[0];
			}
			
			else if (mapa[i][j] == 3)
			{
				cout << caracteresMapa[1];
			}
			else 
			{
				cout << caracteresMapa[2];
			}
		}
		cout << "\n";
	}
}


int main() {
	srand(time(NULL));
	//Variables que se usan simpre
	int num;

	
	
	//miramos donde puede haber enemigos
	int mapa[5][5];
	//creamos lo que irá en el mapa luego
	//espacio sin visitar o vacio: "-" espacio del jugador "*" espacio con montruo "!".
	string caracteresMapa[3] = { " - "," * "," ! "};


	//en este caso crearemos un total de 4 enemigos pequeños y un jefe que estara ne la salida
	Personaje guerrero(1500,"Guerrero",150,4,0);
	Personaje enemigo1(150,"Duende",50,1,0);
	Personaje enemigo2(150,"Duende",30,2,0);
	Personaje enemigo3(160,"Duende",20,3,0);
	Personaje enemigo4(305,"Duende",15,4,0);
	EnemigoFinal granEnemigo(1000, "Rey duende", 150, 0, 0,300,400);
	//pondremos que los espacion seguroas son 0 los enemigos son 1 y el boss es 2
	//primero rellenamos la array con todo 0 para luego añadir los enemigos
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			mapa[i][j] = 0;
			
		}
	}
	//Ahora ponemos un enemigo en cada fila en una columns random y les iremos dando valor a todos los personajes la fila ya esta hardcodeada no se puede aparecer en misma fila que enemigo
	
	//Enemigo 1
		num = rand() % 5;
		mapa[1][num] = 1;
		enemigo1.setPosicionY(num);
	//Enemigo 2
		num = rand() % 5;
		mapa[2][num] = 1;
		enemigo2.setPosicionY(num);
	//Enemigo 3
		num = rand() % 5;
		mapa[3][num] = 1;
		enemigo3.setPosicionY(num);
	//Enemigo 4
		num = rand() % 5;
		mapa[4][num] = 1;
		enemigo4.setPosicionY(num);
	
	//para finalizar ponemos el jefe en la fila 5 que en la array es la 0
		num = rand() % 5;
		mapa[0][num] = 2;
		granEnemigo.setPosicionY(num);
	
	//ahora colocamos al jugadoren la primera que es la ultima en el array usaremos el 3 como posicion inicial.
	do
	{
		
		if (true)
		{
			num = rand() % 5;
			if (mapa[4][num] ==0)
			{
				mapa[4][num] = 3;
				guerrero.setPosicionY(num);
			}
		}
	} while (mapa[4][num] !=3);

	
	bool end = false;
	while (!end)
	{

		for (size_t i = 0; i < 5; i++)
		{
			
			cout << "\n";
		}

		//creamos el mapa a partir de la funcion
		crearMapa(caracteresMapa, mapa);
		//dejamos elegir con wasd
		cout << "movimiento wasd\n";
		char letra;
		cin >>  letra;
		int x = guerrero.getPosicionX();
		int y = guerrero.getPosicionY();
		
		int antX = x;
		int antY = y;
		//la segunda condicion es para que no pete y "se salga de la pantalla"
		
		if (letra == 's' && x !=4 )
		{
			x += 1;
		}
		else if (letra == 'w' && x!=0  )
		{
			x -= 1;
		}
		else if (letra == 'd'  && y !=4 )
		{
			y += 1;
		}
		else if (letra == 'a' && y!=0  )
		{
			y -= 1;
		}
		else
		{
			cout << "tecla o movimiento incorrecto";
		}
		
		
		//comprobamos si hay algun enemigo en esa casilla
		if (mapa[x][y]==0)
		{
			mapa[x][y] = 3;
			mapa[antX][antY] = 0;
		
		}
		else if (mapa[x][y] == 1 || mapa[x][y] == 2)
		{
			if (mapa[x][y] == 2) {
				end = true;
			}
			mapa[x][y] = 4;
			mapa[antX][antY] = 0;
		}
		
			
		guerrero.setPosicionX(x);
		guerrero.setPosicionY(y);

		system("cls");

	}







	

}