//---------------------------------------------------------------------------

#ifndef modifyH
#define modifyH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label2;
        TLabel *Label3;
        TEdit *edSerName;
        TEdit *edName;
        TEdit *edOtchestvo;
        TEdit *edBorn;
        TEdit *edDead;
        TEdit *edFoto;
        TButton *btnAdd;
        TEdit *edFile;
        TButton *btnCancel;
        TMemo *edResidence;
        TLabel *Label4;
        TButton *btnAddRel;
        TOpenDialog *OpenDialog;
        TButton *btnRel;
        TButton *btnDel;
        TButton *btnNo;
        TButton *btnQwes;
        TLabel *Qwes;
        TLabel *Label9;
        TEdit *edDir;
	TMemo *data;
	TButton *btnDir;
	TImage *imFoto;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall edFileDblClick(TObject *Sender);
        void __fastcall edFotoDblClick(TObject *Sender);
        void __fastcall btnQwesClick(TObject *Sender);
        void __fastcall btnNoClick(TObject *Sender);
        void __fastcall edDirDblClick(TObject *Sender);
        void __fastcall btnAddClick(TObject *Sender);
	void __fastcall btnDirClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
