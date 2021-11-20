#pragma once
#include "Juego.h"
#include "Medallas.h"
#include "Pokebolas.h"
namespace TrabajoFinalProgra2TutorLuis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		Medalla*objMedallas;
	public:
		void  Cambiar_Medalla(Medalla *nuevo)
		{
			objMedallas = nuevo;
		}
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			game = new CJuego();

			System::Random ^Azar = gcnew System::Random(System::DateTime::Now.Ticks);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>

		~MyForm()
		{
			if (components)
			{
				delete components;

			}
			delete objGame;
		}
	private: System::Windows::Forms::Timer^  timer1;
	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		Batalla*objGame;
		CJuego*game;
		Pokebolas*objpoke;
		int contador = 0;
		int cantidad = 0;
		int captura = 0;
		//int contadorpokebola = 0;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 762);
			this->ControlBox = false;
			this->Name = L"MyForm";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->Text = L"POKEMON";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::MyForm_KeyPress);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {


		System::Drawing::Graphics^gr = this->CreateGraphics();
		System::Drawing::BufferedGraphicsContext^bgc = BufferedGraphicsManager::Current;
		System::Drawing::BufferedGraphics^bg = bgc->Allocate(gr, this->ClientRectangle);

		//objGame->dibujarbatalla(bg->Graphics);

		if (contador == 0) game->Dibujar_Contenedor(bg->Graphics);

		if (contador == 1)
		{
			objGame->Dibujar_instrucciones(bg->Graphics);

		}


		if (contador > 1)
		{

			game->Mostrartodo(bg->Graphics);

			if (cantidad % 2 == 1)
			{
				game->Dibujar_Info(bg->Graphics);
			}
		}

		if (captura == 1)

			objpoke->Mostrar(bg->Graphics);
	
	

		//if (contadorpokebola == 1)
		//{
		//	System::Drawing::Bitmap ^bmp = gcnew  System::Drawing::Bitmap(gcnew System::String("Dibujo3.jpg"));
		//		System::Drawing::Rectangle porcion = System::Drawing::Rectangle(0, 0, 800, 600); //cuanto se va a mostrar
		//		bmp->MakeTransparent(bmp->GetPixel(1, 1));
		//		gr->DrawImage(bmp, 0, 0, porcion, System::Drawing::GraphicsUnit::Pixel);
		//		delete bmp;
		//}
			
		
		bg->Render(gr);
		delete bg;
		delete bgc;
		delete gr;

	}
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

		if (e->KeyCode == Keys::A) game->RecibirOrden(ATTACK::ATAQUE1);
		if (e->KeyCode == Keys::S) game->RecibirOrden(ATTACK::ATAQUE2);
		if (e->KeyCode == Keys::Z) game->RecibirOrden(ATTACK::ATAQUE3);
		if (e->KeyCode == Keys::X) game->RecibirOrden(ATTACK::ATAQUE4);
		if (e->KeyCode == Keys::Down) game->RecibirOrden(ATTACK::DIRABAJO);
		if (e->KeyCode == Keys::Up) game->RecibirOrden(ATTACK::DIRARRIBA);
		if (e->KeyCode == Keys::Right) game->RecibirOrden(ATTACK::DIRDEREC);
		if (e->KeyCode == Keys::Left) game->RecibirOrden(ATTACK::DIRZQ);

		if (e->KeyCode == Keys::Space)
		{
			contador++;
		}
		if (e->KeyCode == Keys::P)
		{
			cantidad++;
		}

		if (e->KeyCode == Keys::C)
		{
			captura++;
		}


	}
	private: System::Void MyForm_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	

	
	}
};
}

