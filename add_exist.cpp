//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include<fstream.h>
#include<graph.h>
#include<People.h>
#include "add_exist.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
extern Graph<People> g;
extern vector<People> vs;      //������(�)
extern vector<People> vall;
extern People ptemp;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::edLinkChange(TObject *Sender)
{
        if(lstPpl->ItemIndex==-1) return;
        if(edLink->ItemIndex==2) //����(����)
                {vs=g.find_pare(vall[lstPpl->ItemIndex],"������(�)"); //������� �������
                if(vs.size()!=0){
                        lblMer->Visible=true;
                        lblWho->Visible=false;
                        lblNotMer->Visible=false;
                        lstS->Clear();
                        lblWho->Caption=vall[lstPpl->ItemIndex].get_FIO().c_str();
                        for(int i=0;i<vs.size();i++)
                                lstS->Items->Add(vs[i].get_FIO().c_str());
                        lstS->Items->Add("����������");
                        lstS->Visible=true;
                        }
                        else
                        {//���������� ���, �.�. ������ �� ������
                        lblNotMer->Visible=true;
                        lblWho->Caption=vall[lstPpl->ItemIndex].get_FIO().c_str();
                        lblWho->Visible=true;
                        lblMer->Visible=false;
                        lstS->Visible=false;
                        }
                }

        if(edLink->ItemIndex==1) //���(����)
                {vs=g.find_pare(ptemp,"������(�)"); //������� �������
                if(vs.size()!=0){
                        lblMer->Visible=true;
                        lblWho->Visible=false;
                        lblNotMer->Visible=false;
                        lstS->Clear();
                        lblWho->Caption=ptemp.get_FIO().c_str();
                        for(int i=0;i<vs.size();i++)
                                lstS->Items->Add(vs[i].get_FIO().c_str());
                        lstS->Items->Add("����������");
                        lstS->Visible=true;
                        }
                        else
                        {//���������� ���, �.�. ������ �� ������
                        lblNotMer->Visible=true;
                        lblWho->Caption=vall[lstPpl->ItemIndex].get_FIO().c_str();
                        lblWho->Visible=true;
                        lblMer->Visible=false;
                        lstS->Visible=false;
                        }
                }
        if(edLink->ItemIndex==0){ //�������(�)
                lblWho->Visible=false;
                lblMer->Visible=false;
                lblNotMer->Visible=false;
                lstS->Visible=false;}
}
//---------------------------------------------------------------------------

void __fastcall TForm4::FormCreate(TObject *Sender)
{
        lstPpl->ItemIndex=0;
        edLink->ItemIndex=0;       
}
//---------------------------------------------------------------------------



