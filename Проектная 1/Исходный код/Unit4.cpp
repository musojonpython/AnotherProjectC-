//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit1.h"
#include "Unit3.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
AnsiString name;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button3Click(TObject *Sender)
{
if(Edit3->Visible==false)
   {Edit3->Visible=true;
   Edit4->Visible=true;
   Edit5->Visible=true;
   Label4->Visible=true;
   Label5->Visible=true;
   Label6->Visible=true;}
   AnsiString log = Edit1->Text,
           pas = Edit2->Text,
           logb,pasb;
bool right = false;
ADOQuery1->First();

                for (int i=0;i<ADOQuery1->RecordCount;i++)
                {
                 logb=ADOQuery1->FieldByName("login")->AsString;
                 pasb=ADOQuery1->FieldByName("password")->AsString;
                 if(log == logb && pas == pasb) {right = true; break;}
                 ADOQuery1->Next();
                }

  if((Edit4->Text==Edit5->Text )&& right==true&&Edit4->Text!="")
  {
        ADOQuery1->Insert();
        ADOQuery1->Edit();
        ADOQuery1->FieldByName("login")->AsString = Edit3->Text;
        ADOQuery1->FieldByName("password")->AsString = Edit4->Text;
        ADOQuery1->Post();
        Label3->Caption  = "Добавлен администратор";
        Edit3->Text = "";
        Edit4->Text = "";
        Edit5->Text = "";
        Label3->Visible=true;
    }
    else if(Edit4->Text!=Edit5->Text)
   { Label3->Caption="Пароли не совпадают";
    Label3->Visible=true; }
    else if(right!=true)
  {  Label3->Caption="Введите данные администратора";
    Label3->Visible=true;  }
  }
//---------------------------------------------------------------------------

void __fastcall TForm4::Button2Click(TObject *Sender)
{
AnsiString log = Edit1->Text,
           pas = Edit2->Text,
           logb,pasb;
bool right = false;
ADOQuery1->First();

                for (int i=0;i<ADOQuery1->RecordCount;i++)
                {
                 logb=ADOQuery1->FieldByName("login")->AsString;
                 pasb=ADOQuery1->FieldByName("password")->AsString;
                 if(log == logb && pas == pasb) {right = true; break;}
                 ADOQuery1->Next();
                }
if(right==true)
{
Form1->Button1->Visible=true;
Form1->Button2->Visible=true;
Form1->Button3->Visible=true;
Form1->Button4->Visible=true;
Form1->Edit2->Visible=true;
Form1->Label2->Visible=true;
Form1->Button5->Visible=true;
Form1->Button6->Visible=true;
Form1->Visible=true;
Form3->Visible=false;
name=log;

}
else
{

Edit2->Text="";
Label3->Visible=true;
}

    
}
//---------------------------------------------------------------------------


void __fastcall TForm4::FormClose(TObject *Sender, TCloseAction &Action)
{
Form3->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button1Click(TObject *Sender)
{
   Edit3->Visible=false;
   Edit4->Visible=false;
   Edit5->Visible=false;
   Label4->Visible=false;
   Label5->Visible=false;
   Label6->Visible=false;
   Edit1->Text = "";
   Edit2->Text = "";
   Edit3->Text = "";
   Edit4->Text = "";
   Edit5->Text = "";
   Form3->Visible=true;
   Form4->Visible=false;
}
//---------------------------------------------------------------------------




void __fastcall TForm4::FormCreate(TObject *Sender)
{
Edit1->OnKeyPress;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Edit2KeyPress(TObject *Sender, char &Key)
{
if (Key==13)
Button2Click(Sender);
}
//---------------------------------------------------------------------------

