//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "sSkinManager"
#pragma link "sButton"
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm3::FormCreate(TObject *Sender)
{
Image1->Picture->LoadFromFile("image.jpg");        
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
Form1->Button1->Visible=false;
Form1->Button2->Visible=false;
Form1->Button3->Visible=false;
Form1->Button4->Visible=false;
Form1->Edit2->Visible=false;
Form1->Label2->Visible=false;
Form1->Visible=true;
Form3->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button2Click(TObject *Sender)
{
Form4->Visible=true;
Form3->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button3Click(TObject *Sender)
{
MessageBox(0,"Аптектрон v1.0.0\nРазработчики:\nГалиуллин Тимур\nИлхомжонов Джамшид\nУктамов Нурали\n\nЭлектронная почта:\nandroidsmallmeat@gmail.com","О программе",MB_OK);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button4Click(TObject *Sender)
{
Form3->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::sButton1Click(TObject *Sender)
{
Form1->Button1->Visible=false;
Form1->Button2->Visible=false;
Form1->Button3->Visible=false;
Form1->Button4->Visible=false;
Form1->Edit2->Visible=false;
Form1->Label2->Visible=false;
Form1->Button5->Visible=false;
Form1->Visible=true;
Form3->Visible=false;        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::sButton2Click(TObject *Sender)
{
Form4->Visible=true;
Form3->Visible=false;        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::sButton3Click(TObject *Sender)
{
MessageBox(0,"Аптектрон v1.2.0\nРазработчики:\nГалиуллин Тимур\nИлхомжонов Джамшид\nУктамов Нурали\n\nЭлектронная почта:\nandroidsmallmeat@gmail.com","О программе",MB_OK);
        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::sButton4Click(TObject *Sender)
{
Form3->Close();
}
//---------------------------------------------------------------------------

