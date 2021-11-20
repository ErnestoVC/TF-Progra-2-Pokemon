#pragma once
#include "Pokemon.h"

class ArrPokemon
{
	CPokemon**arreglo;
	int N;


public:
	ArrPokemon();
	~ArrPokemon();
	void agregar(CPokemon*dato);
	int getN();
	void intercambiar(int pos, int dest);
	CPokemon* getPokemon(int indice);
	

};



ArrPokemon::ArrPokemon(){
	arreglo = NULL;
	N = 0;
}


ArrPokemon::~ArrPokemon()
{
	for (int i = 0; i < N; i++)
		delete arreglo[i];
	delete arreglo;
}
void ArrPokemon::agregar(CPokemon*dato){

	CPokemon** auxiliar = new CPokemon*[N + 1];
	if (auxiliar != NULL)
	{
		for (int i = 0; i<N; i++)
			auxiliar[i] = arreglo[i];
		auxiliar[N] = dato;
		N++;
		if (arreglo != NULL)
			delete arreglo;
		arreglo = auxiliar;
	}
}


void ArrPokemon::intercambiar(int pos, int dest){}
int ArrPokemon::getN(){ return N; }
CPokemon* ArrPokemon::getPokemon(int indice){ return arreglo[indice]; }
