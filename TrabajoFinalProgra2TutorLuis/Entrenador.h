#pragma once
#include <stdio.h>
#include <string.h>
enum Direccion { Izquierda, Derecha, Ninguno, Arriba, Abajo };

using namespace System;
using namespace System::Drawing;
#include "ArrPokemon.h"
#include "Pokemon.h"
class Entrenador{

	ArrPokemon*poke;
	
	char*nombre;
	int x, y,W,H,indiceW,indiceH,medallas;
	int WM, HM; //medallas
	int dx, dy;
	bool victoria; //implementado
	int contador = 0; //implementado

public:
	Entrenador();
	Entrenador(char*pnombre, int x, int y, int W, int H);
	~Entrenador();

	char*getnombre();
	int getx();
	int gety();
	int getW();
	int getH();
	int getdx();
	int getdy();
	int getindiceW();
	int getindiceH();
	ArrPokemon* getarray();
	
	void set_dx_dy(Direccion teclapulsada);
	void setnombre(char* dato);
	void setx(int dato);
	void sety(int dato);
	void setindiceW(int dato);
	void setindiceH(int dato);

	void Mostrar(Graphics ^gr);
	void Mover(Graphics ^gr, Direccion teclapulsada);

	bool pokevictoria(Graphics^gr); //implementado
	void Muestra_Pokebola(Graphics ^gr);
};


Entrenador::Entrenador(){}

Entrenador::Entrenador(char*pnombre, int x, int y, int W, int H){
	nombre = new char(100);
	strcpy(nombre, pnombre);
	this->x= x;
	this->y = y;
	this->W = W;
	this->H = H;
	medallas = 0;
	indiceH = indiceW = 0;

	dx = dy = 0;
	poke = new ArrPokemon();

}

Entrenador::~Entrenador(){
	delete nombre;
}

void Entrenador::set_dx_dy(Direccion teclapulsada)
{
	switch (teclapulsada)
	{
	case Arriba:
		dx = 0; dy = -5
			;
		break;
	case Abajo:
		dx = 0; dy = 5;
		break;
	case Izquierda:
		dx = -5; dy = 0;
		break;
	case Derecha:
		dx = 5; dy = 0;
		break;
	case Ninguno:
		dx = 0; dy = 0;
		//indiceh = 0;
		indiceW = 0;
		break;
	default:
		break;
	}
}
char*Entrenador::getnombre(){ return nombre; }
int Entrenador::getx(){return x;}
int Entrenador::gety(){return y;}
int Entrenador::getW(){return W;}
int Entrenador::getH(){return H;}
int Entrenador::getindiceW(){return indiceH;}
int Entrenador::getindiceH(){return indiceW;}
ArrPokemon* Entrenador::getarray(){return poke;}

void Entrenador::setnombre(char*dato){
	strcpy(nombre,dato);
	Bitmap ^bmp = gcnew Bitmap(gcnew String(nombre));
	W = bmp->Width / 8;
	H = bmp->Height / 4;
	WM = bmp->Width / 8;
	HM = bmp->Height / 4;
	delete bmp;
}
void Entrenador::Mostrar(System::Drawing::Graphics ^gr)
{
	System::Drawing::Bitmap ^bmp = gcnew System::Drawing::Bitmap(gcnew System::String(nombre));
	System::Drawing::Rectangle porcion = System::Drawing::Rectangle(indiceW*W, indiceH*H, W, H);
	System::Drawing::Rectangle zoom = System::Drawing::Rectangle(x, y, W * 1, H * 1);

	gr->DrawImage(bmp, zoom, porcion, System::Drawing::GraphicsUnit::Pixel);

}

void Entrenador::Mover(Graphics^gr, Direccion teclapulsada)
{
	if (teclapulsada == Direccion::Abajo) indiceH = 0;
	if (teclapulsada == Direccion::Izquierda) indiceH = 1;
	if (teclapulsada == Direccion::Derecha) indiceH = 2;
	if (teclapulsada == Direccion::Arriba) indiceH = 3;
	indiceW++;
	if (indiceW > 3) indiceW = 0;


	x = x + dx;
	y = y + dy;
	Mostrar(gr);
}

void Entrenador::setx(int dato){ x = dato; }
void Entrenador::sety(int dato){ y = dato; }
void Entrenador::setindiceW(int dato){ indiceW = dato; }
void Entrenador::setindiceH(int dato){ indiceH = dato; }



//
//void Entrenador::Muestra_Pokebola(Graphics ^gr){
//
//	System::Drawing::Bitmap ^muestra = gcnew System::Drawing::Bitmap(gcnew System::String("medallas.png"));
//	System::Drawing::Rectangle porcion = System::Drawing::Rectangle(indiceW*WM, indiceH*HM ,W, H);
//	gr->DrawImage(muestra, x, y, porcion, System::Drawing::GraphicsUnit::Pixel);
//
//
//		
//	
//}

//bool Entrenador::pokevictoria(Graphics^gr){ //implementado
//
//	//victoria = 
//	if (vidamax=0)
//	{
//		contador = contador + 1;
//		if (contador = 1)
//		{
//			Muestra_Pokebola(gr);
//
//		}
//	}
//
//	return false;
//
//}
