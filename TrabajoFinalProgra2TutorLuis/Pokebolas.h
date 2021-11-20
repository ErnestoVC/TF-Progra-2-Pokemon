#pragma once

class Pokebolas{
private:
	//Atributos
	int x, y, dx, dy, w, h, fila, columna;

public:
	//constructor, destructor y sobrecarga
	Pokebolas(void);
	~Pokebolas(void);
	Pokebolas(int px, int py, char *archivo, int nrofilas, int nrocolumnas);
	//MÉTODOS DE ACCESO
	//SET
	
	void SET_dx(int nuevo);
	void SET_dy(int nuevo);
	//GET
	
	int GET_x();
	int GET_y();
	//Métodos para graficar
	void Mostrar(System::Drawing::Graphics ^gr);
	
};

//constructor, destructor y sobrecarga
Pokebolas::Pokebolas(void){}
Pokebolas::~Pokebolas(void){}
Pokebolas::Pokebolas(int px, int py, char *archivo, int nrofilas, int nrocolumnas){
	x = px; y = py;
	dx = dy = 1;
	System::Drawing::Bitmap ^bmp = gcnew System::Drawing::Bitmap(gcnew System::String(archivo));
	w = bmp->Width / nrocolumnas;
	h = bmp->Height / nrofilas;
	delete bmp;
	fila = 0;
	columna = 0;
	
}
//MÉTODOS DE ACCESO

void Pokebolas::SET_dx(int nuevo){ dx = nuevo; }
void Pokebolas::SET_dy(int nuevo){ dy = nuevo; }
//GET

int Pokebolas::GET_x(){ return x; }
int Pokebolas::GET_y(){ return y; }
//Métodos para graficar
void Pokebolas::Mostrar(System::Drawing::Graphics ^gr){
	System::Drawing::Rectangle porcion = System::Drawing::Rectangle(columna*w, fila*h, w, h);
	System::Drawing::Bitmap ^bmp = gcnew System::Drawing::Bitmap("pokebolassprite.png");
	gr->DrawImage(bmp, x, y, porcion, System::Drawing::GraphicsUnit::Pixel);
	fila++;
	if (fila>1)
		fila = 0;
}
