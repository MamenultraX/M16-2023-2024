#pragma once
#include "Clase.h"


//Getters
int Formula::getVel()
{
	return velocidad;
}

int Formula::getDis()
{
	return distancia;
}

bool Formula::getNitro()
{
	return nitro;
}

string Formula::getNom()
{
	return nombre;
}



//Setters

void Formula::setVel(int pVel)
{
	velocidad = pVel;
}

void Formula::setDis(int pDis)
{
	distancia = pDis;
}

void Formula::setNitro(bool pNitro)
{
	nitro = pNitro;
}

void Formula::setNom(string pNom)
{
	nombre = pNom;
}


//Vonstructor principal
Formula::Formula(int pVel, int pDis, bool pNitro, string pNom)
{
	velocidad = pVel;
	distancia = pDis;
	nitro = pNitro;
	nombre = pNom;
}
//Constructor vacio
Formula::Formula()
{}

//Metodo propio
void Formula::getAllParams()
{
	//todas las variables privdas
	cout << "Velocidad: " << velocidad << ", Distancia: " << distancia << ", Nitro: ";

	//Comprovar si esta el nitro activo
	if (nitro)
	{
		cout << "Sí ";
	}
	else cout << "No ";
	cout << "Nombre: " << nombre;
}

void Formula::getVelDis()
{
	cout << nombre << ":\n" << "Velocidad: " << velocidad << ", Distancia: " << distancia << "\n";
}




