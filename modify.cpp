//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modify.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
extern char dir[MAX_PATH];   //директория программы
String replase_str(String &s);
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormCreate(TObject *Sender)
{
        edResidence->Clear();        
}
//---------------------------------------------------------------------------
void __fastcall TForm3::edFileDblClick(TObject *Sender)
{
        if(OpenDialog->Execute())
                edFile->Text=OpenDialog->FileName;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::edFotoDblClick(TObject *Sender)
{
        if(OpenDialog->Execute())
                edFoto->Text=OpenDialog->FileName;        
}
//---------------------------------------------------------------------------
void __fastcall TForm3::btnQwesClick(TObject *Sender)
{
        btnDel->Visible=true;
        btnQwes->Visible=false;
        Qwes->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::btnNoClick(TObject *Sender)
{
        btnDel->Visible=false;
        btnQwes->Visible=true;
        Qwes->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::edDirDblClick(TObject *Sender)
{
        //if(OpenDialog->Execute())
         //       edDir->Text=OpenDialog->FileName;        
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TForm3::btnAddClick(TObject *Sender)
{
        edFoto->Text=replase_str(edFoto->Text);
        edFile->Text=replase_str(edFile->Text);
        edDir->Text=replase_str(edDir->Text);
}
//---------------------------------------------------------------------------
String replase_str(String &s)
{
//удаление основной директории
        if(!strcmp(dir,s.SubString(0,strlen(dir)).c_str()))
                s=s.SubString(strlen(dir)+1,s.Length());
//проверка на пробелы
char t[MAX_PATH];
        t[0]=0;
        strcpy(t,s.c_str());
        for(int i=0;t[i];i++)
                if(t[i]==' ')
                        {ShowMessage("В именах файлов не должно быть символов пробела. Ссылка удалена.");
                         s="";
                         return s;}
        return s;
}
//---------------------------------------------------------------------------







void __fastcall TForm3::btnDirClick(TObject *Sender)
{
        if(edDir->Text!="")
        	{
                String Sdir=dir;
        	ShellExecuteA(0, NULL,(Sdir + edDir->Text).c_str(), NULL, NULL, 1);
                }
}
//---------------------------------------------------------------------------

