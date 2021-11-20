#include "ArrPokemon.h"
#include <stdlib.h>
#include <string>

using namespace System::Drawing;

ATTACK ruleta(){
		
	ATTACK dmg;
	int bot = rand() % 4;

	switch (bot)	{
	case 0:		dmg = ATTACK::ATAQUE1;		break;
	case 1:		dmg = ATTACK::ATAQUE2;		break;
	case 2:		dmg = ATTACK::ATAQUE3;		break;
	case 3:		dmg = ATTACK::ATAQUE4;		break;
	
	}


	return dmg;
}

char *subString(char *someString)
{
	int n = strlen(someString) - 5;
	char *novo = new char(n);

	strncpy(novo, someString, n);
	novo[n] = '\0';
	return novo;
}


void infopokemon(Graphics^gr, CPokemon*dato, int x, int y){

	Font^fuente = gcnew Font("Arial Black", 12);	

	
	gr->FillRectangle(Brushes::DarkGray, x-5, y-5, 210, 60);
	gr->FillRectangle(Brushes::LightGray, x, y, 200, 50);
	gr->DrawString(gcnew System::String(subString(dato->getnombre())), fuente, Brushes::Gray, x + 5, y + 5);
	gr->DrawString(dato->getvida().ToString(), fuente, Brushes::Red, x + 5, y + 25);
	gr->DrawString("/ "+dato->getvidamax().ToString(), fuente, Brushes::Red, x + 30, y + 25);

	float a = dato->getvidamax();
	float b = dato->getvida();

	gr->FillRectangle(Brushes::DarkRed, x + 80, y + 25, 100, 20);
	gr->FillRectangle(Brushes::Red, x + 80, y + 25, (int)(b/a*100), 20);
	
}

void dibujarpokemon(System::Drawing::Graphics^gr, CPokemon*dato, int x, int y){

	System::Drawing::Bitmap ^bmp1 = gcnew System::Drawing::Bitmap(gcnew System::String(dato->getnombre()));
	System::Drawing::Rectangle porcion1 = System::Drawing::Rectangle(0, 0, 80, 80);
	System::Drawing::Rectangle destino1 = System::Drawing::Rectangle(x, y, 80, 80);

	gr->FillEllipse(Brushes::LightCyan, x - 35, y + 50, 150, 30);
	gr->DrawImage(bmp1, destino1, porcion1, System::Drawing::GraphicsUnit::Pixel);
	delete bmp1;
}

void dibujarplayer(Graphics^gr,Entrenador*dato,int x,int y){


	System::Drawing::Bitmap ^bmp1 = gcnew System::Drawing::Bitmap(gcnew System::String(dato->getnombre()));
	System::Drawing::Rectangle porcion1 = System::Drawing::Rectangle(dato->getW()*dato->getindiceW(), dato->getH()*dato->getindiceH(), dato->getW(), dato->getH());
	System::Drawing::Rectangle destino1 = System::Drawing::Rectangle(x, y, dato->getW()/2, dato->getH()/2);

	bmp1->MakeTransparent(bmp1->GetPixel(1,1));
	gr->DrawImage(bmp1, destino1, porcion1, System::Drawing::GraphicsUnit::Pixel);	
	

	delete bmp1;
}

void cambioIndicePersonaje(Entrenador*dato,ATTACK turno){

	/*dato->setindiceH(dato->getindiceH() + 1);
	if (dato->getindiceH() > 2) dato->setindiceH(0);

*/
	if (ATTACK::DIRABAJO == turno) dato->setindiceW(0);
	if (ATTACK::DIRARRIBA == turno) dato->setindiceW(3);
	if (ATTACK::DIRDEREC == turno) dato->setindiceW(2);
	if (ATTACK::DIRZQ == turno) dato->setindiceW(1);

}

void dibujarmapa(Graphics^gr){
		
	System::Drawing::Bitmap ^bmp1 = gcnew System::Drawing::Bitmap(gcnew System::String("map01.png"));
	System::Drawing::Rectangle porcion1 = System::Drawing::Rectangle(0, 0, 1600, 1600);
	System::Drawing::Rectangle destino1 = System::Drawing::Rectangle(0, 0, 800, 800);
	gr->DrawImage(bmp1, destino1, porcion1, System::Drawing::GraphicsUnit::Pixel);

	delete bmp1;
}

void DibujarFoco(Graphics^gr, int x, int y){

	int w = gr->VisibleClipBounds.Width;
	int h = gr->VisibleClipBounds.Height;

	gr->FillRectangle(Brushes::Black, 0, 0, x - 32, h);
	gr->FillRectangle(Brushes::Black, 0, 0, w, y - 32);
	gr->FillRectangle(Brushes::Black, 0, y + 64, w, h - y - 64);
	gr->FillRectangle(Brushes::Black, x + 64, 0, w - x - 64, h);

}



