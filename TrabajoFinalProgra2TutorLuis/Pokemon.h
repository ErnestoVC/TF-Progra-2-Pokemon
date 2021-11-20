#pragma once
#include <string.h>
#include <stdlib.h>

public enum ATTACK { ATAQUE1, ATAQUE2, ATAQUE3, ATAQUE4,DIRABAJO,DIRARRIBA,DIRZQ,DIRDEREC };

class CPokemon
{
protected:
	int x, y, w, h;
	char* nombre;
	char* tipo;
	bool cara;
	int vida, exp, nivel,vidamax;
	int danio1, danio2, danio3, danio4;
	char* atq1;
	char* atq2;
	char* atq3;
	char* atq4;

	int WM, HM; //medallas
	bool victoria; //implementado
	int contador = 0; //implementado
	int indiceH, indiceW;
	

public:
	CPokemon();
	CPokemon(char* nombre,int x, int y, int w, int h);
	~CPokemon();


	int getx();
	int gety();
	int getw();
	int geth();
	char* getnombre();
	char* gettipo();
	bool getcara();
	int getvida();
	int getvidamax();
	int getexp();
	int getnivel();
	int getdanio1();
	int getdanio2();
	int getdanio3();
	int getdanio4();
	char* getatq1();
	char* getatq2();
	char* getatq3();
	char* getatq4();

	void setx(int nuevo);
	void sety(int nuevo);
	void setw(int nuevo);
	void seth(int nuevo);
	void setnombre(char* nuevo);
	void setcara(bool nuevo);
	void setvida(int nuevo);
	void setexp(int nuevo);
	void setnivel(int nuevo);

	void actualizar();
	virtual void TurnAttack(CPokemon*poke,ATTACK dmg);


	void Muestra_Pokebola(Graphics ^gr);
	bool pokevictoria(Graphics^gr); //implementado

};


CPokemon::CPokemon(){}

CPokemon::CPokemon(char*pnombre,int x, int y, int w ,int h){


	this->x = x;
	this->x = y;
	this->x = w;
	this->x = h;

	nombre= new char[100];
	strcpy(nombre, pnombre);
	tipo = new char[100];
	atq1 = new char[100];
	atq2 = new char[100];
	atq3 = new char[100];
	atq4 = new char[100];

	vidamax = 30 + rand() % 30;
	vida = vidamax;
	exp = rand() % 800;
	nivel = 1 + exp / 200;
	cara = true;
	danio1 = nivel+rand() % 4;
	danio2 = nivel+rand() % 4;
	danio3 = nivel*2 +rand() % 4;
	danio4 = nivel*2 +rand() % 4;

	contador = 0;
	indiceH = indiceW = 0;


}

CPokemon::~CPokemon(){}

int CPokemon::getx(){return x;}
int CPokemon::gety(){return y;}
int CPokemon::getw(){return w;}
int CPokemon::geth(){return h;}
char* CPokemon::getnombre(){return nombre;}
char* CPokemon::gettipo(){ return tipo; }
bool CPokemon::getcara(){return cara;}
int CPokemon::getvida(){return vida;}
int CPokemon::getvidamax(){ return vidamax; }
int CPokemon::getexp(){return exp;}
int CPokemon::getnivel(){return nivel;}
int CPokemon::getdanio1(){ return danio1; }
int CPokemon::getdanio2(){ return danio2; }
int CPokemon::getdanio3(){ return danio3; }
int CPokemon::getdanio4(){ return danio4; }
char* CPokemon::getatq1(){ return atq1; }
char* CPokemon::getatq2(){ return atq2; }
char* CPokemon::getatq3(){ return atq3; }
char* CPokemon::getatq4(){ return atq4; }

void CPokemon::setx(int nuevo){x=nuevo;}
void CPokemon::sety(int nuevo){y=nuevo;}
void CPokemon::setw(int nuevo){w=nuevo;}
void CPokemon::seth(int nuevo){h=nuevo;}
void CPokemon::setnombre(char* nuevo)
{
	strcpy(nombre,nuevo);
	Bitmap ^bmp = gcnew Bitmap(gcnew String(nombre));
	WM = bmp->Width / 8;
	HM = bmp->Height / 4;
	delete bmp;


}
void CPokemon::setcara(bool nuevo){cara=nuevo;}
void CPokemon::setvida(int nuevo){vida=nuevo;}
void CPokemon::setexp(int nuevo){exp=nuevo;}
void CPokemon::setnivel(int nuevo){nivel=nuevo;}

void CPokemon::TurnAttack(CPokemon*poke, ATTACK dmg){}


void CPokemon::actualizar(){

	if (exp >= 800){

		nivel = 1 + exp / 200;
		vidamax = vidamax + nivel * 10;
		danio1 = danio1 + nivel;
		danio2 = danio2 + nivel;
		danio3 = danio3 + nivel * 2;
		danio4 = danio4 + nivel * 2;

		vida = vidamax;
		exp = 0;

	}
}

	void CPokemon::Muestra_Pokebola(Graphics ^gr){

		System::Drawing::Bitmap ^muestra = gcnew System::Drawing::Bitmap(gcnew System::String("medallas.png"));
		System::Drawing::Rectangle porcion = System::Drawing::Rectangle(indiceW*WM, indiceH*HM, w, h);
		gr->DrawImage(muestra,800, 800, porcion, System::Drawing::GraphicsUnit::Pixel);




	}

	bool CPokemon::pokevictoria(Graphics^gr){ //implementado

		//victoria = 
		if (vidamax = 0)
		{
			contador = contador + 1;
			if (contador>0)
			//if (contador = 1)
			//{
				Muestra_Pokebola(gr);

			//}
		}

		return false;

	}





