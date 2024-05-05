#pragma once
#include <iostream>
#include <time.h>
using namespace std;


class Formula {

private:
	//Variables
	int velocidad;
	int distancia;
	bool nitro;
	string nombre;

public:

	//Getters
	int getVel();
	int getDis();
	bool getNitro();
	string getNom();

	//Stetters
	void setVel(int pVel);
	void setDis(int pDis);
	void setNitro(bool pNitro);
	void setNom(string pNom);

	//Constructor principal
	Formula(int pVel, int pDis, bool pNitro, string pNom);

	//Constructor Vacio
	Formula();

	//Metodos propios
	void getAllParams();
	void getVelDis();


};