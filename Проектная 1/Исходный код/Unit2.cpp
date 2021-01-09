//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button1Click(TObject *Sender)
{

if(Edit1->Text!="" && Edit2->Text!="" && Edit3->Text!="" && Edit4->Text!="" && Edit5->Text!="" && Edit6->Text!="")
        {
        Form1->ADOQuery1->Edit();
        Form1->ADOQuery1->FieldByName("Название")->AsString = Edit1->Text;
        Form1->ADOQuery1->FieldByName("Фирма")->AsString = Edit2->Text;
        Form1->ADOQuery1->FieldByName("Болезни")->AsString = Edit3->Text;
        Form1->ADOQuery1->FieldByName("Количество")->AsString = Edit4->Text;
        Form1->ADOQuery1->FieldByName("Цена")->AsString = Edit5->Text;
        Form1->ADOQuery1->FieldByName("Срок годности")->AsString = Edit6->Text;



        if(Image1->Picture->Graphic != 0)
                {
                Form1->ADOQuery1->Edit();
                TMemoryStream* strm = new TMemoryStream();
                Image1->Picture->Graphic->SaveToStream(strm);
                ((TGraphicField*)Form1->ADOQuery1->FieldByName("Фото"))->LoadFromStream(strm);
                delete strm;
                }
        Form1->ADOQuery1->Post();
        Form2->Close();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
if (OpenPictureDialog1->Execute())
        {
                AnsiString CurrentFile = OpenPictureDialog1->FileName;
                Image1->Picture->LoadFromFile(CurrentFile);
        }        
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{
Form2->Close();
}
//---------------------------------------------------------------------------


