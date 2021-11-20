#pragma once
#include "Pokemon.h"
class CPokeElectrico : public CPokemon
{



public:
	CPokeElectrico();
	CPokeElectrico(char*nombre, int x, int y, int w, int h);
	~CPokeElectrico();
	void TurnAttack(CPokemon*poke, ATTACK dmg);
	void actualizar(){}
};


CPokeElectrico::CPokeElectrico(){}
CPokeElectrico::CPokeElectrico(char*nombre, int x, int y, int w, int h) :CPokemon(nombre, x, y, w, h){

	strcpy(tipo, "AGUA");
	strcpy(atq1, "Aqua Ring");
	strcpy(atq2, "Bubble");
	strcpy(atq3, "Origin Pulse");
	strcpy(atq4, "Hydro Canon");
}

CPokeElectrico::~CPokeElectrico(){}


void CPokeElectrico::actualizar(){}

void CPokeElectrico::TurnAttack(CPokemon*poke, ATTACK dmg){


	if (strcmp(poke->gettipo(), "ELECTRICO")){

		switch (dmg)	{
		case ATAQUE1:	poke->setvida(poke->getvida() - danio1);		break;
		case ATAQUE2:	poke->setvida(poke->getvida() - danio2);		break;
		case ATAQUE3:	poke->setvida(poke->getvida() - danio3);		break;
		case ATAQUE4:	poke->setvida(poke->getvida() - danio4);		break;
		default:	break;
		}
	}

	if (strcmp(poke->gettipo(), "FUEGO")){

		switch (dmg)	{
		case ATAQUE1:	poke->setvida(poke->getvida() - danio1);		break;
		case ATAQUE2:	poke->setvida(poke->getvida() - danio2);		break;
		case ATAQUE3:	poke->setvida(poke->getvida() - danio3);		break;
		case ATAQUE4:	poke->setvida(poke->getvida() - danio4);		break;
		default:	break;
		}
	}
	if (strcmp(poke->gettipo(), "AGUA")){

		switch (dmg)	{
		case ATAQUE1:	poke->setvida(poke->getvida() - danio1 - danio1 / 4);		break;
		case ATAQUE2:	poke->setvida(poke->getvida() - danio2 - danio2 / 4);		break;
		case ATAQUE3:	poke->setvida(poke->getvida() - danio3 - danio3 / 4);		break;
		case ATAQUE4:	poke->setvida(poke->getvida() - danio4 - danio4 / 4);		break;
		default:	break;
		}
	}
	if (strcmp(poke->gettipo(), "VEGETAL")){

		switch (dmg)	{
		case ATAQUE1:	poke->setvida(poke->getvida() - danio1 - danio1 / 4);		break;
		case ATAQUE2:	poke->setvida(poke->getvida() - danio2 - danio2 / 4);		break;
		case ATAQUE3:	poke->setvida(poke->getvida() - danio3 - danio3 / 4);		break;
		case ATAQUE4:	poke->setvida(poke->getvida() - danio4 - danio4 / 4);		break;
		default:	break;
		}
	}


}