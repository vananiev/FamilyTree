//---------------------------------------------------------------------------

#ifndef add_existH
#define add_existH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label8;
        TLabel *lblRel;
        TLabel *Label7;
        TComboBox *edLink;
        TButton *btnAdd;
        TButton *btnCancel;
        TComboBox *lstPpl;
        TLabel *Label1;
        TLabel *lblMer;
        TLabel *lblNotMer;
        TLabel *lblWho;
        TComboBox *lstS;
        void __fastcall edLinkChange(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
