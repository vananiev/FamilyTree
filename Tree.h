//---------------------------------------------------------------------------

#ifndef TreeH
#define TreeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TfrmTree : public TForm
{
__published:	// IDE-managed Components
        TLabel *B;
        TMainMenu *Menu;
        TMenuItem *N1;
        TMenuItem *Roditeli;
        TMenuItem *Vertex;
        TGroupBox *Nastr;
        TLabel *Label1;
        TLabel *Label2;
        TScrollBar *sWidth;
        TScrollBar *sHeight;
        TLabel *Label3;
        TLabel *Label4;
        TScrollBar *s_k2;
        TScrollBar *s_k;
        TFontDialog *FontDialog;
        TColorDialog *ColorDialog;
        TButton *btnFont;
        TButton *btnColor;
        TMenuItem *Param;
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall FormDeactivate(TObject *Sender);
        void __fastcall FormPaint(TObject *Sender);
        void __fastcall FormClick(TObject *Sender);
        void __fastcall RoditeliClick(TObject *Sender);
        void __fastcall ParamClick(TObject *Sender);
        void __fastcall btnFontClick(TObject *Sender);
        void __fastcall btnColorClick(TObject *Sender);
        void __fastcall BClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmTree(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmTree *frmTree;
//---------------------------------------------------------------------------
#endif
