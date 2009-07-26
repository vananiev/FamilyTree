//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "YesNo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm5::FormShow(TObject *Sender)
{
        Width=lblText->Width+100;
        if(Width < 300) Width=300;
        btnYes->Left=Width-250;
        btnNo->Left=btnYes->Left+100;
}
//---------------------------------------------------------------------------
