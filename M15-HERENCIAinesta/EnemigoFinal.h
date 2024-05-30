#pragma once
#include "Personaje.h"
#include <iostream>

using namespace std;

class EnemigoFinal : public Personaje
{
private:
	int megaAttack;
	int hiperAttack;
	

public:

	//CONSTRUCTOR CON ELEMENTOS DE LA CLASE PADRE Y PROPIA
	EnemigoFinal(int pHp,
				std::string pName,
				int pAttack,
				int pPosicionX,
				int pPosicionY,
				int pMegaAttack,
				int pHiperAttack);
	EnemigoFinal();
	//GETTERS AND SETTERS
	int getMegaAttack();
	int getHiperAttack();
	

	void setMegaAttack(int pMegaAttack);
	void setHiperAttack(int pHiperAttack);
	

	//METODOS PROPIOS
	void printAllStats();


};

