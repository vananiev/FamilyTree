//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TEdit *edSerName;
        TMemo *data;
        TListBox *Relative;
        TLabel *Label2;
        TButton *btnFind;
        TLabel *Label3;
        TComboBox *lstPpl;
        TEdit *edName;
        TEdit *edOtchestvo;
        TEdit *edBorn;
        TEdit *edDead;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TEdit *edResidence;
        TMainMenu *Menu1;
        TMenuItem *N1;
        TMenuItem *N3;
        TMenuItem *N4;
        TButton *btnModify;
        TButton *btnAddRel2;
        TMenuItem *N2;
        TMenuItem *N5;
        TMenuItem *N6;
        TOpenDialog *OpenDialog;
        TSaveDialog *SaveDialog;
        TMenuItem *N7;
        TButton *btnAddRelEx;
        TButton *btnDelRel;
        TMenuItem *N8;
        TMenuItem *N9;
        TMenuItem *N10;
        TButton *btnDir;
        TMenuItem *CreateTree;
	TImage *imFoto;
        void __fastcall btnFindClick(TObject *Sender);
        void __fastcall lstPplChange(TObject *Sender);
        void __fastcall btnModifyClick(TObject *Sender);
        void __fastcall RelativeMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall btnAddRel2Click(TObject *Sender);
        void __fastcall btnAddRelClick(TObject *Sender);
        void __fastcall N5Click(TObject *Sender);
        void __fastcall N6Click(TObject *Sender);
        void __fastcall N3Click(TObject *Sender);
        void __fastcall N4Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall N7Click(TObject *Sender);
        void __fastcall btnAddRelExClick(TObject *Sender);
        void __fastcall btnDelRelClick(TObject *Sender);
        void __fastcall RelativeDblClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall N8Click(TObject *Sender);
        void __fastcall N9Click(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall N10Click(TObject *Sender);
        void __fastcall btnDirClick(TObject *Sender);
        void __fastcall CreateTreeClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
