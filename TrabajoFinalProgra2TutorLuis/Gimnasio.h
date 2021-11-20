#pragma once
#include <string.h>
enum DireccionGimnasio{ izquierdaFon, derechaFon, ningunoFon };
class Gimnasio
{
	int x;
	int y;
	int dx;
	int h; int indiceH;
	int w; int indiceW;
	bool eliminar;
	char *imagen;
public:
	Gimnasio(void);
	~Gimnasio(void);
	Gimnasio(int px, int py, char *pImagen);

	void SET_Eliminar(bool nuevo);

	bool GET_Eliminar();
	int GET_X();
	int GET_Y();
	int GET_H();
	int GET_W();
	int GET_dx();

	void Mostrar(System::Drawing::Graphics ^gr);
	void Mover(System::Drawing::Graphics ^gr, DireccionGimnasio moverse);
};

Gimnasio::Gimnasio(void){}
Gimnasio::~Gimnasio(void){}
Gimnasio::Gimnasio(int px, int py, char *pImagen)
{
	eliminar = false;
	x = px;
	y = py;
	imagen = new char[50];
	strcpy(imagen, pImagen);
	dx = 0;

	System::Drawing::Bitmap^bmp = gcnew System::Drawing::Bitmap(gcnew System::String(imagen));
	w = bmp->Width / 1;
	h = bmp->Width / 1;
	indiceH = indiceW = 0;
}

void Gimnasio::SET_Eliminar(bool nuevo){ eliminar = nuevo; }

bool Gimnasio::GET_Eliminar(){ return eliminar; }
int Gimnasio::GET_X(){ return x; }
int Gimnasio::GET_Y(){ return y; }
int Gimnasio::GET_H(){ return h; }
int Gimnasio::GET_W(){ return w; }
int Gimnasio::GET_dx(){ return dx; }

void Gimnasio::Mostrar(System::Drawing::Graphics ^gr){
	System::Drawing::Bitmap ^Gimnasio = gcnew System::Drawing::Bitmap(gcnew System::String(imagen));
	System::Drawing::Rectangle porcion = System::Drawing::Rectangle(indiceW*w, indiceH*h, w, h);
	gr->DrawImage(Gimnasio, x, y, porcion, System::Drawing::GraphicsUnit::Pixel);
	//gr->DrawImage(fondo,x+w,y,porcion,System::Drawing::GraphicsUnit::Pixel);
	//gr->DrawImage(fondo,x+w+w,y,porcion,System::Drawing::GraphicsUnit::Pixel);
}
void Gimnasio::Mover(System::Drawing::Graphics ^gr, DireccionGimnasio moverse)
{
	if (moverse == derechaFon) dx = 10;
	if (moverse == izquierdaFon) dx = -10;
	if (moverse == ningunoFon) dx = 0;
	if (x + dx>1 || x + w + dx<gr->VisibleClipBounds.Width) dx = 0;
	
	x += dx;
	Mostrar(gr);

}
