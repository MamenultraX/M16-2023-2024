#pragma once
#include  <iostream>
class Personaje
{

private:
	int hp;
	std::string name;
	int attack;
	int posicionX;
	int posicionY;

public:
	//constructor
	Personaje(int pHp, std::string pName, int pAttack, int pPosicionX, int pPosicionY);
	Personaje();
	//getters
	int getHp();

	std::string getName();

	int getAttack();

	int getPosicionX();
	int getPosicionY();

	//setters

	void setHp(int php);

	void setName(std::string pname);

	void setAttack(int pattack);

	void setPosicionX(int pPosicionX);
	void setPosicionY(int pPosicionY);

	//metodos propios

	void printStatus();

};

