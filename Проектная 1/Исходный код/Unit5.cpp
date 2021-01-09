//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
bool sort = false;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Button1Click(TObject *Sender)
{

Form5->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::DBGrid1TitleClick(TColumn *Column)
{
ADOQuery1->Close();
   ADOQuery1->SQL->Clear();
     if (sort)
    {
    sort= false;
    ADOQuery1->SQL->Add("SELECT * FROM benefit ORDER BY " + Column->FieldName + " DESC");
 }
 else
    {
    sort=true;
      ADOQuery1->SQL->Add("SELECT * FROM benefit ORDER BY " + Column->FieldName + " ASC");
    }
      ADOQuery1->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::ComboBox1Change(TObject *Sender)
{
if(ComboBox1->Text=="Все")
{
ADOQuery1->Filtered = false;
ADOQuery1->Filter = "";
ADOQuery1->Filtered = true;
}
else{
ADOQuery1->Filtered = false;
ADOQuery1->Filter = "[Продавец] LIKE '"+ComboBox1->Text+"%'";
ADOQuery1->Filtered = true;

Form5->ADOQuery1->First();
double a=0;
for (int i=0; i<Form5->ADOQuery1->RecordCount; i++)
{
     a+= StrToInt(Form5->ADOQuery1->FieldByName("Количество")->AsString)*StrToInt(Form5->ADOQuery1->FieldByName("Цена")->AsString) ;
     Form5->ADOQuery1->Next();
}
Form5->Edit1->Text = a;      }
}
//---------------------------------------------------------------------------

void __fastcall TForm5::DateTimePicker1Change(TObject *Sender)
{
WideString W;
TDateTime T0 = DateTimePicker1->DateTime;
TDateTime T1 = DateTimePicker2->DateTime;
ADOQuery1->Close();
ADOQuery1->SQL->Clear();
 ADOQuery1->Parameters->AddParameter()->Name="D0";
    ADOQuery1->Parameters->AddParameter()->Name="D1";
    ADOQuery1->Parameters->ParamByName("D0")->Value = T0;
    ADOQuery1->Parameters->ParamByName("D1")->Value = T1;

    W = "SELECT * FROM benefit WHERE  Время_продажи >= :D0 and Время_продажи <= :D1";
    ADOQuery1->SQL->Add(W);
    ADOQuery1->Open();
    Form5->ADOQuery1->First();
double a=0;
for (int i=0; i<Form5->ADOQuery1->RecordCount; i++)
{
     a+= StrToInt(Form5->ADOQuery1->FieldByName("Количество")->AsString)*StrToInt(Form5->ADOQuery1->FieldByName("Цена")->AsString) ;
     Form5->ADOQuery1->Next();
}
Form5->Edit1->Text = a;  
}
//---------------------------------------------------------------------------

void __fastcall TForm5::DateTimePicker2Change(TObject *Sender)
{
WideString W;
TDateTime T0 = DateTimePicker1->DateTime;
TDateTime T1 = DateTimePicker2->DateTime;
ADOQuery1->Close();
ADOQuery1->SQL->Clear();
 ADOQuery1->Parameters->AddParameter()->Name="D0";
    ADOQuery1->Parameters->AddParameter()->Name="D1";
    ADOQuery1->Parameters->ParamByName("D0")->Value = T0;
    ADOQuery1->Parameters->ParamByName("D1")->Value = T1;

    W = "SELECT * FROM benefit WHERE  Время_продажи >= :D0 and Время_продажи <= :D1";
    ADOQuery1->SQL->Add(W);
    ADOQuery1->Open();
    Form5->ADOQuery1->First();
double a=0;
for (int i=0; i<Form5->ADOQuery1->RecordCount; i++)
{
     a+= StrToInt(Form5->ADOQuery1->FieldByName("Количество")->AsString)*StrToInt(Form5->ADOQuery1->FieldByName("Цена")->AsString) ;
     Form5->ADOQuery1->Next();
}
Form5->Edit1->Text = a;       
}
//---------------------------------------------------------------------------

