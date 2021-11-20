#pragma once
#include "Entrenador.h"
#include "Header.h"
#include "Medallas.h"
//#include "Pokebolas.h"



using namespace System;
using namespace System::Drawing;


class Batalla
{
	Entrenador*boy1;

	Entrenador*boy2;

	CPokemon*pokemon1;
	CPokemon*pokemon2;

	CPokemon*pokemon3;
	CPokemon*pokemon4;


	int indice1;
	int indice2;
	char* Ganador;
	int timer;
	bool turnoataque;
	bool fin;
	bool victoria; //implementado
	int contador ; //implementado

	CPokemon*poke1;
	CPokemon*poke2;
	/*Pokebolas*poke;*/
	


public:
	Batalla();
	Batalla(Entrenador* boy1, Entrenador* boy2);
	~Batalla();
	void dibujarbatalla(Graphics^gr);
	void emularbatalla(ATTACK TURNO);
	bool getfin();

	bool pokevictoria(); //implementado
	void Muestra_Pokebola(System::Drawing::Graphics ^gr);

	void Dibujar_instrucciones(Graphics^gr);
	void Dibuja_Ganador(Graphics^gr);

	void Batalla::Dibuja_Pokecaptura(Graphics^gr);
	};



	Batalla::Batalla()
	{

	}

	Batalla::Batalla(Entrenador* boy1, Entrenador* boy2){
		this->boy1 = boy1;
		this->boy2 = boy2;
		contador = 0;
		timer = 0;
		turnoataque = true;
		fin = false;
		indice1 = 0;
		indice2 = 0;
		Ganador = new char[100];

	}

	Batalla::~Batalla()
	{



	}

	void Batalla::dibujarbatalla(Graphics^gr){

		poke1 = boy1->getarray()->getPokemon(indice1);
		poke2 = boy2->getarray()->getPokemon(indice2);

		if (fin == false){

			//draw batalla
			dibujarpokemon(gr, poke1, 400, 30);
			dibujarpokemon(gr, poke2, 100, 250);

			gr->FillRectangle(Brushes::Gray, 0, 450, 800, 160); //afuera
			gr->FillRectangle(Brushes::LightGray, 10, 460, 390, 60); //adentro1 780   140
			gr->FillRectangle(Brushes::LightGray, 410,460, 390, 60); //adentro2
			gr->FillRectangle(Brushes::LightGray, 10, 530, 390, 60); //adentro3
			gr->FillRectangle(Brushes::LightGray, 410, 530, 390, 60); //adentro4
			String^dialogo1 = "Ataque 1 (A)";
			Font ^fuente1 = gcnew Font("Lucida Sans", 32);
			SolidBrush^brocha1 = gcnew SolidBrush(Color::Yellow);
			gr->DrawString(dialogo1, fuente1, brocha1, 10, 460);

			String^dialogo2 = "Ataque 2 (S)";
			Font ^fuente2 = gcnew Font("Lucida Sans", 32);
			SolidBrush^brocha2 = gcnew SolidBrush(Color::Yellow);
			gr->DrawString(dialogo2, fuente2, brocha2, 410, 460);

			String^dialogo3 = "Ataque 3 (Z)";
			Font ^fuente3 = gcnew Font("Lucida Sans", 32);
			SolidBrush^brocha3 = gcnew SolidBrush(Color::Yellow);
			gr->DrawString(dialogo3, fuente3, brocha3, 10, 530);

			String^dialogo4 = "Ataque 4 (X)";
			Font ^fuente4 = gcnew Font("Lucida Sans", 32);
			SolidBrush^brocha4 = gcnew SolidBrush(Color::Yellow);
			gr->DrawString(dialogo4, fuente4, brocha4, 410, 530);

			//tiempo de batalla
			if (turnoataque == true){

				infopokemon(gr, poke2, 300, 250);
				infopokemon(gr, poke1, 100, 50);
			}
			else
			{
				timer++;
				contador++;
			}

			if (timer > 8){
				timer = 0;
				turnoataque = true;
			}

			//avance de batalla
			if (poke1->getvida() <= 0) {
				++indice1;
				if (indice1 > 5 || indice1 >= boy1->getarray()->getN()) 
				{
					fin = true;
						
					if (fin == true)
					{
						Ganador = boy2->getnombre();
						/*poke->Mostrar_Pokes(gr);*/
					
						Dibuja_Ganador(gr);
						
						//gr->FillRectangle(Brushes::White, 0, 0, 800, 800);
						//String^dialogo1 = "Pikachu GANA!";
						//Font ^fuente1 = gcnew Font("Lucida Sans", 32);
						//SolidBrush^brocha1 = gcnew SolidBrush(Color::Black);
						//gr->DrawString(dialogo1, fuente1, brocha1, 120, 600);

						}
						
					}
					
		
				
			}
			
			if (poke2->getvida() <= 0) {
				++indice2;
				if (indice2 > 5 || indice1 >= boy2->getarray()->getN()) {
					
					if (timer > 120)
					{
						timer = 119;
						fin = true;

						Ganador = boy1->getnombre();
						gr->FillRectangle(Brushes::Gray, 50, 350, 500, 400);
						String^dialogo1 = "Bulbasaur GANA!";
						Font ^fuente1 = gcnew Font("Arial", 26);
						SolidBrush^brocha1 = gcnew SolidBrush(Color::Cyan);
						gr->DrawString(dialogo1, fuente1, brocha1, 120, 600);
					}
					else
					{
						timer++;
					}
				}

			}

			

		}
		else
		{
			turnoataque = false;
			gr->FillRectangle(Brushes::Gray, 50, 350, 500, 400);

			gr->DrawString(gcnew String(Ganador), gcnew Font("Arial", 24), Brushes::Black, 5, 15);

		}

	}

	void Batalla::emularbatalla(ATTACK TURNO){

		if (turnoataque == true)
		{
			poke1->TurnAttack(poke2, TURNO);
			poke2->TurnAttack(poke1, ruleta());

			turnoataque = false;
		}


	}

	bool Batalla::getfin(){ return fin; }



	void Batalla::Dibujar_instrucciones(Graphics^gr){
		String^dialogo = " Instrucciones";
		Font ^fuente = gcnew Font("Arial", 30);
		SolidBrush^brocha = gcnew SolidBrush(Color::White);
		gr->DrawString(dialogo, fuente, brocha, 220, 100);

		String^dialogo2 = "Para poder mover al personaje utilize las direccionales.";
		Font ^fuente2 = gcnew Font("Arial", 20);
		SolidBrush^brocha2 = gcnew SolidBrush(Color::White);
		gr->DrawString(dialogo2, fuente2, brocha2, 50, 260);


		String^dialogo3 = "En la batalla se utilizarán las teclas A S Z X";
		Font ^fuente3 = gcnew Font("Arial", 20);
		SolidBrush^brocha3 = gcnew SolidBrush(Color::White);
		gr->DrawString(dialogo3, fuente3, brocha3, 90, 320);

		String^dialogo5 = " Buen juego :)";
		Font ^fuente5 = gcnew Font("Arial", 26);
		SolidBrush^brocha5 = gcnew SolidBrush(Color::White);
		gr->DrawString(dialogo5, fuente5, brocha5, 220, 450);

		String^dialogo4 = "Presiona 'Space' para continuar...";
		Font ^fuente4 = gcnew Font("Arial", 26);
		SolidBrush^brocha4 = gcnew SolidBrush(Color::White);
		gr->DrawString(dialogo4, fuente4, brocha4, 120, 600);

		
	}

	void Batalla::Dibuja_Ganador(Graphics^gr){
	gr->FillRectangle(Brushes::White, 0, 0, 800, 800);
	String^dialogo1 = "Pikachu GANA!";
	Font ^fuente1 = gcnew Font("Lucida Sans", 36);
	SolidBrush^brocha1 = gcnew SolidBrush(Color::Black);
	gr->DrawString(dialogo1, fuente1, brocha1, 120, 400);

	String^dialogo2 = "HAS GANADO UNA MEDALLA!";
	Font ^fuente2 = gcnew Font("Lucida Sans", 32);
	SolidBrush^brocha2 = gcnew SolidBrush(Color::Black);
	gr->DrawString(dialogo2, fuente2, brocha2, 100, 500);

	String^dialogo3 = "Presiona 'M' para guardarla";
	Font ^fuente3 = gcnew Font("Lucida Sans", 32);
	SolidBrush^brocha3 = gcnew SolidBrush(Color::Black);
	gr->DrawString(dialogo3, fuente3, brocha3, 100, 550);

	String^dialogo4 = "Presiona 'C' para capturar al pokemon oponente";
	Font ^fuente4 = gcnew Font("Lucida Sans", 32);
	SolidBrush^brocha4 = gcnew SolidBrush(Color::Black);
	gr->DrawString(dialogo4, fuente4, brocha4, 50, 600);
	}


	//void Batalla::Dibuja_Pokecaptura(Graphics^gr){

	//	System::Drawing::Bitmap ^bmp = gcnew  System::Drawing::Bitmap(gcnew System::String("pokecaptura.jpg"));
	//	System::Drawing::Rectangle porcion = System::Drawing::Rectangle(0, 0, 800, 800);
	//	gr->DrawImage(bmp, 0, 0, porcion, System::Drawing::GraphicsUnit::Pixel);


	//}