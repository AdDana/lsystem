#include "MyForm.h"
#include <iostream>
#include <math.h>

#include <Windows.h>
#include <string>
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>

using namespace msclr::interop;
using namespace Project4;
using namespace std;


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}


string kk = "";
int iteration;

void Project4::MyForm::parser()
{
int a,r=0; //кол-во итер

iteration = (int)Convert::ToDouble(textBox1->Text);

//a = Int32::Parse(textBox1->Text);

String^ pravilo = textBox4->Text;//F+F-F-F+F
string k;
a = k.length();
string basestring;




k=marshal_as<string>(textBox5->Text);

for (int j = 0; j < iteration; j++)
{
	a = k.length();
	for (int i = 0; i < a; i++)
	{		

		switch (k[i])
		{
		case 'F':
			//kk += k;
			//k.erase(i, 1);
			kk+= marshal_as<string>(textBox4->Text);//F+F-F-F+F
			break;
		case '+':
			kk += '+';
			//kk.insert(i, "+");
			break;
		case '-':
			kk += '-';
			//kk.insert(i, "-");
			break;
		default:

			break;

		}
		
	}
	//a = r;
	k = kk;	
	kk = "";	
}
kk = k;
}


//Graphics ^ g = pictureBox1->CreateGraphics();

void Project4::MyForm::drawline(int x1, int y1,int angle)
{
	double pi = acos(-1);
	double radians = angle / 180.0 * pi;

	double endx = cos(radians)*delta;
	double endy = sin(radians)*delta;


	
	Pen ^ blackPen = gcnew Pen(Color::Black, 0.5);
	
	g->DrawLine(blackPen, x1, y1, x1+endx, y1+endy);
	
	base_x = x1 + endx;
	base_y = y1 + endy;
}


void Project4::MyForm::drawtree()
{
	//kk.insert(0, marshal_as<string>(textBox5->Text));

	System::String^ fd = marshal_as<System::String^>(kk);
	textBox2->Text = fd;

	
		for (int i = 0; i < kk.length(); i++)
		{

			switch (kk[i])
			{
			case 'F':

				drawline(base_x, base_y, baseangle);

				break;
			case '+':

				baseangle += 90;

				break;
			case '-':

				baseangle -= 90;

				break;
			default:
				break;

			}

		

	}



}
