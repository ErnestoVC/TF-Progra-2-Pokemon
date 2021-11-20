#pragma once

namespace TrabajoFinalProgra2TutorLuis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
#include "Juego.h"
#include "MyForm.h"
#include "Medallas.h"

	/// <summary>
	/// Resumen de MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
		CJuego *objJuego;
		Medalla* objMedallas;
		int contadorpoke = 0;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Timer^  timer2;
	TrabajoFinalProgra2TutorLuis::MyForm ^ segundo_form;

	public:
		MyForm1(void)
		{
			objJuego = new	CJuego();
			objMedallas = new Medalla();
			InitializeComponent();

			InitializeComponent();
			segundo_form = gcnew TrabajoFinalProgra2TutorLuis::MyForm();
			segundo_form->Cambiar_Medalla(objMedallas);
			
			segundo_form->Show();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm1::timer2_Tick);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(267, 762);
			this->Name = L"MyForm1";
			this->Text = L"Medallas Ganadas";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm1::MyForm1_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
		System::Drawing::Graphics ^gr = this->CreateGraphics();
		System::Drawing::BufferedGraphicsContext ^bc = System::Drawing::BufferedGraphicsManager::Current;
		System::Drawing::BufferedGraphics ^bg = bc->Allocate(gr, this->ClientRectangle);
		bg->Graphics->Clear(System::Drawing::Color::White);
		if (contadorpoke > 0)
		{
			objMedallas->MostrarMedalla(bg->Graphics);
		}
	
		//objArrFigura->Mover_Figuras(bg->Graphics);
		bg->Render(gr);
		delete bg;
		delete bc;
		delete gr;
		//objJuego->RecibirOrden();
		//timer2->Enabled = false;
		//objArrFigura->Eliminar_Todos(); podria canjearse por dinero
		timer2->Enabled = true;
	}
	private: System::Void MyForm1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

		if (e->KeyCode == Keys::M) { contadorpoke++; }
	}
	};
}
