#pragma once
#include <string.h>



class Pokebola
{
	int x;
	int y;
	int dx;
	int h; int indiceH;
	int w; int indiceW;
	char *imagen;
public:
	Pokebola(void);
	~Pokebola(void);
	Pokebola(int px, int py, char *pImagen);

	int GET_X();
	int GET_Y();
	int GET_H();
	int GET_W();
	int GET_dx();

	void MostrarPokebola(System::Drawing::Graphics ^gr);

};

Pokebola::Pokebola(void){}
Pokebola::~Pokebola(void){}
Pokebola::Pokebola(int px, int py, char *pImagen)
{

	x = px;
	y = py;
	imagen = new char[50];
	strcpy(imagen, pImagen);
	dx = 0;

	System::Drawing::Bitmap^bmp = gcnew System::Drawing::Bitmap(gcnew System::String(imagen));
	w = bmp->Width  ;
	h = bmp->Height /1;
	indiceH = indiceW = 0;
}


int Pokebola::GET_X(){ return x; }
int Pokebola::GET_Y(){ return y; }
int Pokebola::GET_H(){ return h; }
int Pokebola::GET_W(){ return w; }
int Pokebola::GET_dx(){ return dx; }

void Pokebola::MostrarPokebola(System::Drawing::Graphics ^gr)
{
	System::Drawing::Bitmap ^Pokebola = gcnew System::Drawing::Bitmap(gcnew System::String("pokecaptura.jpg"));
	System::Drawing::Rectangle porcion = System::Drawing::Rectangle(indiceW*w, indiceH*h, w, h);
	gr->DrawImage(Pokebola, x, y, porcion, System::Drawing::GraphicsUnit::Pixel);
	//gr->DrawImage(Pokebola,x+w,y,porcion,System::Drawing::GraphicsUnit::Pixel);
	//gr->DrawImage(Pokebola,x+w+w,y,porcion,System::Drawing::GraphicsUnit::Pixel);
	
}