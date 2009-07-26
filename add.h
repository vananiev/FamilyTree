//---------------------------------------------------------------------------

#ifndef addH
#define addH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TEdit *edSerName;
        TEdit *edName;
        TEdit *edOtchestvo;
        TEdit *edBorn;
        TEdit *edDead;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label2;
        TEdit *edFoto;
        TButton *btnAdd;
        TLabel *Label3;
        TEdit *edFile;
        TButton *btnCancel;
        TMemo *edResidence;
        TLabel *Label8;
        TLabel *lblRel;
        TLabel *Label7;
        TLabel *Label4;
        TComboBox *edLink;
        TOpenDialog *OpenDialog;
        TLabel *lblMer;
        TComboBox *lstS;
        TLabel *Label9;
        TEdit *edDir;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall edFotoDblClick(TObject *Sender);
        void __fastcall edFileDblClick(TObject *Sender);
        void __fastcall edLinkChange(TObject *Sender);
        void __fastcall edDirDblClick(TObject *Sender);
        void __fastcall btnAddClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
