//---------------------------------------------------------------------------
#include <jpeg.hpp>

#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
#include "Unit1.h"
#include "Unit3.h"
#include "Unit5.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
bool sort =false;
extern AnsiString name;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------




void __fastcall TForm1::DBGrid1TitleClick(TColumn *Column)
{
   ADOQuery1->Close();
   ADOQuery1->SQL->Clear();
     if (sort)
    {
    sort= false;
    ADOQuery1->SQL->Add("SELECT * FROM Product ORDER BY " + Column->FieldName + " DESC");
 }
 else
    {
    sort=true;
      ADOQuery1->SQL->Add("SELECT * FROM Product ORDER BY " + Column->FieldName + " ASC");
    }
      ADOQuery1->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1Change(TObject *Sender)
{
if(!Edit1->Text.IsEmpty()&&RadioButton1->Checked)
{
ADOQuery1->Filtered = false;
ADOQuery1->Filter = "[Название] LIKE '"+Edit1->Text+"%'";
ADOQuery1->Filtered = true;
}
else if(!Edit1->Text.IsEmpty()&&RadioButton2->Checked)
{
ADOQuery1->Filtered = false;
ADOQuery1->Filter = "[Фирма] LIKE '"+Edit1->Text+"%'";
ADOQuery1->Filtered = true;
}
else if(!Edit1->Text.IsEmpty()&&RadioButton3->Checked)
{
ADOQuery1->Filtered = false;
ADOQuery1->Filter = "[Болезни] LIKE '"+Edit1->Text+"%'";
ADOQuery1->Filtered = true;
}
else
{
ADOQuery1->Filtered = false;
ADOQuery1->Filter = "";
ADOQuery1->Filtered = true;
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
       Form2->Edit1->Text = "";
       Form2->Edit2->Text = "";
       Form2->Edit3->Text = "";
       Form2->Edit4->Text = "";
       Form2->Edit5->Text = "";
       Form2->Edit6->Text = ""; ;
       Form2->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
if (MessageBox(0,"Вы уверены?","Удаление записи",MB_YESNO|MB_ICONQUESTION) == IDYES)
{
  ADOQuery1->RecNo;
ADOQuery1->Delete();

}



}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    if(atoi( (Edit2->Text).c_str())!=0){
ADOQuery1->Edit();
ADOQuery1->FieldByName("Количество")->AsString = atoi( DBGrid1->Fields[3]->AsString.c_str() ) -   atoi( (Edit2->Text).c_str() );
ADOQuery1->Post();

     Form5->ADOQuery1->Insert();
     Form5->ADOQuery1->Edit();
     Form5->ADOQuery1->FieldByName("Название")->AsString = ADOQuery1->FieldByName("Название")->AsString;
     Form5->ADOQuery1->FieldByName("Количество")->AsString = atoi( (Edit2->Text).c_str() );
     Form5->ADOQuery1->FieldByName("Цена")->AsString = ADOQuery1->FieldByName("Цена")->AsString;
     Form5->ADOQuery1->FieldByName("Время_Продажи")->AsString = Now().DateString();
     Form5->ADOQuery1->FieldByName("Продавец")->AsString = name;
     Form5->ADOQuery1->Post();    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DBGrid1CellClick(TColumn *Column)
{
if(!(TBlobField*)ADOQuery1->FieldByName("Фото")->IsNull){
       if(!Image1->Visible)Image1->Visible=true;
       TMemoryStream* strm = new TMemoryStream;
       TJPEGImage *ptJpg=new TJPEGImage;
        ((TGraphicField*)ADOQuery1->FieldByName("Фото"))->SaveToStream(strm);
        strm->Seek(0,0);
        if (*(Word*)strm->Memory == 0xD8FF)Image1->Picture->Graphic=ptJpg;
        Image1->Picture->Graphic->LoadFromStream(strm);
        delete strm;
        delete ptJpg;
      }else
      Image1->Visible=false;
      Memo1->Text = ADOQuery1->FieldByName("Информация")->AsString   ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
Memo1->Text="";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
     Form2->Edit1->Text = Form1->ADOQuery1->FieldByName("Название")->AsString;
     Form2->Edit2->Text = Form1->ADOQuery1->FieldByName("Фирма")->AsString;
     Form2->Edit3->Text =  Form1->ADOQuery1->FieldByName("Болезни")->AsString;
     Form2->Edit4->Text =  Form1->ADOQuery1->FieldByName("Количество")->AsString;
     Form2->Edit5->Text =  Form1->ADOQuery1->FieldByName("Цена")->AsString;
     Form2->Edit6->Text = Form1->ADOQuery1->FieldByName("Срок годности")->AsString;
     if(!(TBlobField*)ADOQuery1->FieldByName("Фото")->IsNull){
       if(!Form2->Image1->Visible)Form2->Image1->Visible=true;
       TMemoryStream* strm = new TMemoryStream;
       TJPEGImage *ptJpg=new TJPEGImage;
        ((TGraphicField*)ADOQuery1->FieldByName("Фото"))->SaveToStream(strm);
        strm->Seek(0,0);
        if (*(Word*)strm->Memory == 0xD8FF)Form2->Image1->Picture->Graphic=ptJpg;
        Form2->Image1->Picture->Graphic->LoadFromStream(strm);
        delete strm;
        delete ptJpg;
      }else
      Form2->Image1->Visible=false;


      Form2->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
if(!Edit1->Text.IsEmpty())
{
ADOQuery1->Filtered = false;
ADOQuery1->Filter = "[Название] LIKE '"+Edit1->Text+"%'";
ADOQuery1->Filtered = true;
}
else
{
ADOQuery1->Filtered = false;
ADOQuery1->Filter = "";
ADOQuery1->Filtered = true;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
if(!Edit1->Text.IsEmpty())
{
ADOQuery1->Filtered = false;
ADOQuery1->Filter = "[Фирма] LIKE '"+Edit1->Text+"%'";
ADOQuery1->Filtered = true;
}
else
{
ADOQuery1->Filtered = false;
ADOQuery1->Filter = "";
ADOQuery1->Filtered = true;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton3Click(TObject *Sender)
{
if(!Edit1->Text.IsEmpty())
{
ADOQuery1->Filtered = false;
ADOQuery1->Filter = "[Болезни] LIKE '"+Edit1->Text+"%'";
ADOQuery1->Filtered = true;
}
else
{
ADOQuery1->Filtered = false;
ADOQuery1->Filter = "";
ADOQuery1->Filtered = true;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
Form3->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DataSource1DataChange(TObject *Sender,
      TField *Field)
{
if(!(TBlobField*)ADOQuery1->FieldByName("Фото")->IsNull){
       if(!Image1->Visible)Image1->Visible=true;
       TMemoryStream* strm = new TMemoryStream;
       TJPEGImage *ptJpg=new TJPEGImage;
        ((TGraphicField*)ADOQuery1->FieldByName("Фото"))->SaveToStream(strm);
        strm->Seek(0,0);
        if (*(Word*)strm->Memory == 0xD8FF)Image1->Picture->Graphic=ptJpg;
        Image1->Picture->Graphic->LoadFromStream(strm);
        delete strm;
        delete ptJpg;
      }else
      Image1->Visible=false;
      Memo1->Text = ADOQuery1->FieldByName("Информация")->AsString   ;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
Form5->ADOQuery1->First();
double a=0;
for (int i=0; i<Form5->ADOQuery1->RecordCount; i++)
{
     a+= StrToInt(Form5->ADOQuery1->FieldByName("Количество")->AsString)*StrToInt(Form5->ADOQuery1->FieldByName("Цена")->AsString) ;
     Form5->ADOQuery1->Next();
}
Form5->Edit1->Text = a;


    Form5->ComboBox1->Clear( );
    Form4->ADOQuery1->Close( );
    Form4->ADOQuery1->SQL->Clear( );
    Form4->ADOQuery1->SQL->Add( "SELECT login FROM logins" );
    Form4->ADOQuery1->Open( );
    Form5-> ComboBox1->Items->Add( "Все" );
    for(int i = 0; i < Form4->ADOQuery1->RecordCount; i++)
    {
        Form5-> ComboBox1->Items->Add( Form4->ADOQuery1->FieldByName
        ( "login" )->AsString );
        Form4->ADOQuery1->Next( );
    }
    Form5->ComboBox1->ItemIndex = 0;


Form5->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
Form1->Visible=false;
Form4->Edit1->Text="";
Form4->Edit2->Text="";
Form3->Visible=true;
}
//---------------------------------------------------------------------------

