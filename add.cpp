//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include<fstream.h>
#include<graph.h>
#include<People.h>
extern Graph<People> g;
extern vector<People> vall;
extern char dir[MAX_PATH];   //директория программы
#include "add.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
String replase_str(String &s);
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
        edResidence->Clear();
        edLink->ItemIndex=0;
        OpenDialog->InitialDir=dir;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::edFotoDblClick(TObject *Sender)
{
        if(OpenDialog->Execute())
                edFoto->Text=OpenDialog->FileName;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::edFileDblClick(TObject *Sender)
{
        if(OpenDialog->Execute())
                edFile->Text=OpenDialog->FileName;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::edLinkChange(TObject *Sender)
{
        if(edLink->ItemIndex!=0) //отец(мать) или сын дочь
                {lblMer->Visible=true;
                lstS->Visible=true;
                }
                else{
                lblMer->Visible=false;
                lstS->Visible=false;}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::edDirDblClick(TObject *Sender)
{
      //  if(OpenDialog->Execute())
      //          edDir->Text=OpenDialog->FileName;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btnAddClick(TObject *Sender)
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


