#include "EnemigoFinal.h"

//Conectamos el enemigos con el enemigo final paraq poder hacer la herencia de clases


//Para hacer la erencia cojemos los valores ya definidos en la clase Enemigo y aparte añadimos el ataque especial.
//Esto es el contructor de la clase EnemigoFinal
EnemigoFinal::EnemigoFinal(int pHp,
						   std::string pName,
						   int pAttack,
						   int pPosicionX,
						   int pPosicionY,
						   int pMegaAttack,
						   int pHiperAttack) : Personaje(pHp,
														pName,
														pAttack,
														pPosicionX,
														pPosicionY) { megaAttack = pMegaAttack;
																	hiperAttack = pHiperAttack;
																  }

EnemigoFinal::EnemigoFinal()
{
}


//GETTERS AND SETTERS
int EnemigoFinal::getMegaAttack() {
	return megaAttack;
}

int EnemigoFinal::getHiperAttack()
{
	return hiperAttack;
}

void EnemigoFinal::setMegaAttack(int pMegaAttack)
{
	megaAttack = pMegaAttack;
}

void EnemigoFinal::setHiperAttack(int pHiperAttack)
{
	hiperAttack = pHiperAttack;
}






//METODOS PROPIOS
void EnemigoFinal::printAllStats() {
	cout << "El enemigo final: " << getName() << endl;
	cout << "La vida del enemigo final es: " << getHp() << endl;
	cout << "El ataque normal del enemigo final es: " << getAttack() << endl;
	cout << "La posicion es: " << getPosicionX()<<","<<getPosicionY() << endl;
	cout << "El ataque final del enemigo es: " << getMegaAttack() << endl;
	
}