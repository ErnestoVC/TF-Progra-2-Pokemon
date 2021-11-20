#pragma once
#include <string.h>



class Medalla
{
	int x;
	int y;
	int dx;
	int h; int indiceH;
	int w; int indiceW;
	char *imagen;
public:
	Medalla(void);
	~Medalla(void);
	Medalla(int px, int py, char *pImagen);

	int GET_X();
	int GET_Y();
	int GET_H();
	int GET_W();
	int GET_dx();

	void MostrarMedalla(System::Drawing::Graphics ^gr);

};

Medalla::Medalla(void){}
Medalla::~Medalla(void){}
Medalla::Medalla(int px, int py, char *pImagen)
{
	
	x = px;
	y = py;
	imagen = new char[50];
	strcpy(imagen, pImagen);
	dx = 0;

	System::Drawing::Bitmap^bmp = gcnew System::Drawing::Bitmap(gcnew System::String(imagen));
	w = bmp->Width / 8;
	h = bmp->Height/1;
	indiceH = indiceW = 0;
}


int Medalla::GET_X(){ return x; }
int Medalla::GET_Y(){ return y; }
int Medalla::GET_H(){ return h; }
int Medalla::GET_W(){ return w; }
int Medalla::GET_dx(){ return dx; }

void Medalla::MostrarMedalla(System::Drawing::Graphics ^gr)
{
	System::Drawing::Bitmap ^Medalla = gcnew System::Drawing::Bitmap(gcnew System::String("Dibujo3.jpg"));
	System::Drawing::Rectangle porcion = System::Drawing::Rectangle(indiceW*w, indiceH*h, w, h);
	gr->DrawImage(Medalla, x, y, porcion, System::Drawing::GraphicsUnit::Pixel);
	//gr->DrawImage(Medalla,x+w,y,porcion,System::Drawing::GraphicsUnit::Pixel);
	//gr->DrawImage(Medalla,x+w+w,y,porcion,System::Drawing::GraphicsUnit::Pixel);

}

