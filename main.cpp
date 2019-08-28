//---------------------------------------------------------------------------

#include <vcl.h>
#include<windows.h>
#include<fstream.h>
#include<graph.h>
#include<People.h>
#pragma hdrstop
#include<variables.h>
#include "main.h"
#include "add.h"
#include "add_exist.h"
#include "modify.h"
#include "YesNo.h"
#include "Tree.h"
#include "fstream.h"
#include "dir.h"
//*****************************************************************
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
vector<People> Find(People &obj,vector<People>& v);
void clear();
void modify(bool Rel=false);
void add_rel(bool Rel=false);
void add_rel_exist(bool Rel=false);
void add_vertex();
void del_vertex();
void open_tree(bool Add=false);
//*****************************************************************
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        
}
//*****************************************************************
void __fastcall TForm1::btnFindClick(TObject *Sender)
{
        //clear
        clear();
        // ������� ������ ������
        ppl.clear();
        ppl.set(edSerName->Text.c_str(),edName->Text.c_str(),edOtchestvo->Text.c_str());
        if(edBorn->Text!="")
                ppl.Born.year=StrToInt(edBorn->Text);
        if(edDead->Text!="")
                ppl.Dead.year=StrToInt(edDead->Text);
        if(edResidence->Text!="")
                ppl.Residence.push_back(edResidence->Text.c_str());
        vp=g.find(ppl,Find);
        for(int i=0;i<vp.size();i++)
                 lstPpl->Items->Add((vp[i].SerName+" "+vp[i].Name+" "+vp[i].Otchestvo).c_str());
}
//*****************************************************************
vector<People> Find(People &obj,vector<People>& v)
{
        vector<People> result;
//�����
        for(int i=0;i<v.size();i++)
                 if(obj.compare(v[i]))
                        result.push_back(v[i]);
        return result;
}
//*****************************************************************
void __fastcall TForm1::lstPplChange(TObject *Sender)
{
        //���������� ��������� � data
        String Sdir=dir;
        String Sfoto;
        String Sfile;
        if(data->Text!="" && vp[LastPpl].file=="")
        	{
                ShowMessage("���������� � �������� �� ����� ���� ���������, �.�. �� ������ ���� ��� ����������. ������� ��� � ����������.");
                return;
                }
        if(LastPpl!=-1 && vp[LastPpl].file!="")
                {if(vp[LastPpl].file[0]=='\\')
                        Sfile=Sdir + vp[LastPpl].file.c_str();
                        else
                        Sfile=vp[LastPpl].file.c_str();
                data->Lines->SaveToFile(Sfile);
                }
        LastPpl=lstPpl->ItemIndex;
        //clear
        data->Lines->Clear();
        Relative->Clear();
        //������������
        Lnk.clear();
        string stmp;
        vector<bool> Ferst;
        vector<string>::iterator l=Lnk.begin();
        vrel=g.find_pare(vp[lstPpl->ItemIndex],Lnk,Ferst);
        for(int i=0;i<vrel.size();i++)
                {if(Ferst[i]==true)
                        {if(Lnk[i].find("���(����)")!=string::npos)
                                Relative->Items->Add((vrel[i].SerName+" "+vrel[i].Name+" "+vrel[i].Otchestvo + "        /   ����(����)").c_str());
                                else
                                Relative->Items->Add((vrel[i].SerName+" "+vrel[i].Name+" "+vrel[i].Otchestvo + "        /   ������(�)").c_str());
                        }else
                        Relative->Items->Add((vrel[i].SerName+" "+vrel[i].Name+" "+vrel[i].Otchestvo+"        /   " + Lnk[i]).c_str());
                }
        //foto
        if(vp[lstPpl->ItemIndex].foto[0]=='\\')
                Sfoto=Sdir + vp[lstPpl->ItemIndex].foto.c_str();
                else
                Sfoto=vp[lstPpl->ItemIndex].foto.c_str();
        ifstream in(Sfoto.c_str());
        if(in)
                {in.close();
                imFoto->Picture->LoadFromFile(Sfoto);
                }
                else
                imFoto->Picture=NULL;
        //����� � �����
        if(vp[lstPpl->ItemIndex].file[0]=='\\')
                Sfile=Sdir + vp[lstPpl->ItemIndex].file.c_str();
                else
                Sfile=vp[lstPpl->ItemIndex].file.c_str();
        ifstream in2(Sfile.c_str());
        if(in2)
                {in2.close();
                data->Lines->LoadFromFile(Sfile);}
                else
                data->Lines->Clear();
        //�����
        if(strlen(vp[lstPpl->ItemIndex].dir.c_str())!=0)
                    btnDir->Visible=true;
                    else
                    btnDir->Visible=false;
}
//*****************************************************************
void __fastcall TForm1::btnModifyClick(TObject *Sender)
{
        N3Click(this);
}
//*****************************************************************
void __fastcall TForm1::RelativeMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(Relative->ItemIndex==-1) return;
        if(Button==1) btnDelRel->Visible=true;
}
//*****************************************************************
void clear()
{
        Form1->lstPpl->ItemIndex=-1;
        ppl.clear();
        vp.clear();
        vrel.clear();
        Form1->lstPpl->Items->Clear();
        Form1->data->Clear();
        Form1->Relative->Clear();
        Form1->data->Lines->Clear();
        Form1->imFoto->Picture=NULL;
        LastPpl=-1;
}
//*****************************************************************
void modify(bool Rel)
{
        if(Rel)
                {if(Form1->Relative->ItemIndex==-1) return;}
                else
                {if(Form1->lstPpl->ItemIndex==-1) return;}
        //�������������� ������
        Form3=new TForm3(Form1);
//��������� �� ������
        vector<People>::iterator p;
        if(Rel)
                {p=vrel.begin();
                p+=Form1->Relative->ItemIndex;}
                else
                {p=vp.begin();
                p+=Form1->lstPpl->ItemIndex;}
        //��������� ������
        Form3->edName->Text=(*p).Name.c_str();
        Form3->edSerName->Text=(*p).SerName.c_str();
        Form3->edOtchestvo->Text=(*p).Otchestvo.c_str();
        if((*p).Born.year!=-1000000)
                Form3->edBorn->Text=IntToStr((*p).Born.year);
                else
                Form3->edBorn->Text="";
        if((*p).Dead.year!=-1000000)
                Form3->edDead->Text=IntToStr((*p).Dead.year);
                else
                Form3->edDead->Text="";;
        for(int i=0;i<(*p).Residence.size();i++)
                Form3->edResidence->Lines->Add((*p).Residence[i].c_str());
        Form3->edFoto->Text=(*p).foto.c_str();
        Form3->edFile->Text=(*p).file.c_str();
        Form3->edDir->Text=(*p).dir.c_str();
        //������ � �����
        String Sfile;
        String Sdir=dir;
        if((*p).file[0]=='\\')
                Sfile=Sdir + (*p).file.c_str();
                else
                Sfile=(*p).file.c_str();
        ifstream in2(Sfile.c_str());
        if(in2)
                {in2.close();
                Form3->data->Lines->LoadFromFile(Sfile);}
                else
                Form3->data->Lines->Clear();
        //foto
        String Sfoto;
        if((*p).foto[0]=='\\')
                Sfoto=Sdir + (*p).foto.c_str();
                else
                Sfoto=(*p).foto.c_str();
        ifstream in(Sfoto.c_str());
        if(in)
                {in.close();
                Form3->imFoto->Picture->LoadFromFile(Sfoto);
                }
                else
                Form3->imFoto->Picture=NULL;
        //����� ����
show_for_edit:
        int ResultModal=Form3->ShowModal();
	if (ResultModal==mrCancel){
                delete Form3;
                return;}
        //���������
        ppl.clear();
        ppl.set(Form3->edSerName->Text.c_str(),Form3->edName->Text.c_str(),Form3->edOtchestvo->Text.c_str());
        if(Form3->edBorn->Text!="")
                ppl.Born.year=StrToInt(Form3->edBorn->Text);
                else
                ppl.Born.year=-1000000;
        if(Form3->edDead->Text!="")
                ppl.Dead.year=StrToInt(Form3->edDead->Text);
                else
                ppl.Dead.year=-1000000;
        for(int i=0;i<Form3->edResidence->Lines->Count;i++)
                if(Form3->edResidence->Lines->Strings[i].Length()!=0)
                        ppl.Residence.push_back(Form3->edResidence->Lines->Strings[i].c_str());
        if(Form3->edFoto->Text!="")
                ppl.foto=Form3->edFoto->Text.c_str();
        if(Form3->edFile->Text!="")
                ppl.file=Form3->edFile->Text.c_str();
        if(Form3->edDir->Text!="")
                ppl.dir=Form3->edDir->Text.c_str();
         if(ppl.file!="")
                {if(ppl.file[0]=='\\')
                        Sfile=Sdir + ppl.file.c_str();
                        else
                        Sfile=ppl.file.c_str();
                Form3->data->Lines->SaveToFile(Sfile);
                }
        else if(Form3->data->Text!="")
        	{
                ShowMessage("���������� � �������� �� ���������, �.�. �� ������ ���� ��� ����������.");
        	goto show_for_edit;
                }
        //�������� �� �������������
        if(g.is_exist_vertex(ppl))
                {
                //ShowMessage("��������� �� ���������, �.�. ���� ������� ��� ���������� ��� ������ �� ������ �� ������.");
                }
        if(g.modify(*p,ppl)==-1)
                ShowMessage("������. ���������� ��� ���.");
        //��������� ������
        int t = Form1->lstPpl->ItemIndex;
        Form1->btnFindClick(Form1);
        Form1->lstPpl->ItemIndex = t;
        //����� ���� ���������� ������ ������������
	if (ResultModal==mrYes) add_rel(Rel);
        //����� ���� ���������� ������������� ������������
	if (ResultModal==mrAll) add_rel_exist(Rel);
        //�������� �������
        if (ResultModal==mrAbort)
                g.delete_vertex(*p);
        Form1->btnFindClick(Form1);
        delete Form3;
}
//*****************************************************************
void add_rel(bool Rel)
{
        if(Rel)
                {if(Form1->Relative->ItemIndex==-1) return;}
                else
                {if(Form1->lstPpl->ItemIndex==-1) return;}
//�������� ������������
        Form2=new TForm2(Form1);
//��������� �� ������ ������������
        vector<People>::iterator p;
        if(Rel)
                {p=vrel.begin();
                p+=Form1->Relative->ItemIndex;}
                else
                {p=vp.begin();
                p+=Form1->lstPpl->ItemIndex;}
        Form2->lblRel->Caption=((*p).SerName+" "+(*p).Name+" "+(*p).Otchestvo).c_str();
//������ ��������� ���������
        People pplNull;
        vs=g.find(pplNull,Find);
        for(int i=0;i<vs.size();i++)
                 Form2->lstS->Items->Add((vs[i].SerName+" "+vs[i].Name+" "+vs[i].Otchestvo).c_str());
        Form2->lstS->Items->Add("����������");
//����� �����
	if (Form2->ShowModal()==mrCancel){
                delete Form2;
                return;}
//�������� ������ �������
        ppl.clear();
        ppl.set(Form2->edSerName->Text.c_str(),Form2->edName->Text.c_str(),Form2->edOtchestvo->Text.c_str());
        if(Form2->edBorn->Text!="")
                ppl.Born.year=StrToInt(Form2->edBorn->Text);
        if(Form2->edDead->Text!="")
                ppl.Dead.year=StrToInt(Form2->edDead->Text);
        for(int i=0;i<Form2->edResidence->Lines->Count;i++)
                if(Form2->edResidence->Lines->Strings[i].Length()!=0)
                        ppl.Residence.push_back(Form2->edResidence->Lines->Strings[i].c_str());
//�������� �� �������������
        if(g.is_exist_vertex(ppl))
                {ShowMessage("������.���� ������� ��� c���������.");
                return;}
//����������
        if(Form2->edFoto->Text!="")
                ppl.foto=Form2->edFoto->Text.c_str();
//���������� �����
	String PplDir;
        String ProgDir=dir;
	if(Form2->edDir->Text=="")
        	{
                String mkd =  "\\data\\" + Form2->edSerName->Text + "_" + Form2->edName->Text + "_" + Form2->edOtchestvo->Text;
                PplDir = mkd;
                unsigned int cnt=0;
                while(mkdir((ProgDir + PplDir).c_str()))
                	{
                        cnt++;
                        if(cnt>100)
                        	{
                                ShowMessage("������.�� ������� ������� ����� � ���� �� ���������.");
                                PplDir = "";
                                break;
                                }
                	PplDir = mkd + "-" +IntToStr(cnt) ; //������
                        }
                }
        else
        	PplDir = Form2->edDir->Text;
        ppl.dir=PplDir.c_str();
//���������� ����� ����������
	if(PplDir!="")
        	{
		String PplFile;
       		if(Form2->edFile->Text=="")
                	PplFile = PplDir + "\\info.txt";
        	else
        		PplFile=Form2->edFile->Text;
        	ofstream out((ProgDir + PplFile).c_str());
		out.close();
        	ppl.file=PplFile.c_str();
                }
//
        if(Form2->edLink->ItemIndex==1)   //���� ���(����)
                {g.add(ppl,*p,"���(����)");
                if(Form2->lstS->ItemIndex!=-1 && Form2->lstS->ItemIndex!=(Form2->lstS->Items->Count-1))      //���� �� ����������
                        {g.add(ppl,vs[Form2->lstS->ItemIndex],"���(����)");
                        g.add(*p,vs[Form2->lstS->ItemIndex],"������(�)");} //�����
                }
        if(Form2->edLink->ItemIndex==2)   //���� ����(����)
                {g.add(*p,ppl,"���(����)");
                if(Form2->lstS->ItemIndex!=-1 && Form2->lstS->ItemIndex!=(Form2->lstS->Items->Count-1))      //���� �� ����������
                        {g.add(*p,vs[Form2->lstS->ItemIndex],"���(����)");
                        g.add(ppl,vs[Form2->lstS->ItemIndex],"������(�)");} //�����
                }
        if(Form2->edLink->ItemIndex==0)   //������(�)
                        g.add(ppl,*p,Form2->edLink->Text.c_str());
        Form1->btnFindClick(Form1);
        delete Form2;
}
//*****************************************************************
void add_rel_exist(bool Rel)
{
        if(Rel)
                {if(Form1->Relative->ItemIndex==-1) return;}
                else {if(Form1->lstPpl->ItemIndex==-1) return;}
//�������� ������������� ������������
        Form4=new TForm4(Form1);
//��������� �� ������ ������������
        vector<People>::iterator p;
        if(Rel)
                {p=vrel.begin();
                p+=Form1->Relative->ItemIndex;}
                else
                {p=vp.begin();
                p+=Form1->lstPpl->ItemIndex;}
        Form4->lblRel->Caption=((*p).SerName+" "+(*p).Name+" "+(*p).Otchestvo).c_str();
//������ ��������� �������������
        People pplNull;
        vall=g.find(pplNull,Find);
        for(int i=0;i<vall.size();i++)
                 Form4->lstPpl->Items->Add((vall[i].SerName+" "+vall[i].Name+" "+vall[i].Otchestvo).c_str());
//���������� �����
        ptemp=*p;
        if (Form4->ShowModal()==mrCancel){
                delete Form4;
                return;}
//
        int sel=Form4->lstPpl->ItemIndex;
        if(sel==-1) return;
        if(Form4->edLink->ItemIndex==1)   //���� ���(����)
                {g.add(vall[sel],*p,"���(����)");
                if(Form4->lstS->ItemIndex!=-1 && Form4->lstS->ItemIndex!=(Form4->lstS->Items->Count-1))      //���� �� ����������
                        {g.add(vall[sel],vs[Form4->lstS->ItemIndex],"���(����)");
                        g.add(*p,vs[Form4->lstS->ItemIndex],"������(�)");} //�����
                }
        if(Form4->edLink->ItemIndex==2)                 //���� ����(����)
                {g.add(*p,vall[sel],"���(����)");
                        if(Form4->lstS->ItemIndex!=-1 && Form4->lstS->ItemIndex!=(Form4->lstS->Items->Count-1))      //���� �� ����������
                                {g.add(*p,vs[Form4->lstS->ItemIndex],"���(����)");
                                g.add(vall[sel],vs[Form4->lstS->ItemIndex],"������(�)");} //�����
                }
        if(Form4->edLink->ItemIndex==0)                 //������(�)
                g.add(vall[sel],*p,Form4->edLink->Text.c_str());
        Form1->btnFindClick(Form1);
        delete Form4;
}
//*****************************************************************
void __fastcall TForm1::btnAddRel2Click(TObject *Sender)
{
        N4Click(this);
}
//*****************************************************************

void __fastcall TForm1::btnAddRelClick(TObject *Sender)
{
        add_rel(true);        
}
//*****************************************************************
void __fastcall TForm1::N5Click(TObject *Sender)
{
        open_tree();
}
//*****************************************************************
void __fastcall TForm1::N6Click(TObject *Sender)
{
     if(SaveDialog->Execute()){
        ofstream out((SaveDialog->FileName).c_str(),ios::out | ios::trunc);
        if(!out) {ShowMessage("������ ��� ������� ��������� ����.");return;}
        out<<g;
        out.close();}
}
//*****************************************************************
void __fastcall TForm1::N3Click(TObject *Sender)
{
        modify();
}
//*****************************************************************
void __fastcall TForm1::N4Click(TObject *Sender)
{
        add_rel();
}
//*****************************************************************
void __fastcall TForm1::FormCreate(TObject *Sender)
{
        clear();
        ifstream in("data.rel");
        if(in){
                in>>g;
                in.close();
                //�������
                clear();}
                else{
                People an[2];
                an[0].set("? ? ?");
                an[1].set("?? ?? ??");
                g.Clear();
                g.add(an[0],an[1],"���(����)");}
        GetCurrentDirectory(sizeof(dir),dir);
}
//*****************************************************************
void __fastcall TForm1::N7Click(TObject *Sender)
{
        add_rel_exist();
}
//*****************************************************************
void __fastcall TForm1::btnAddRelExClick(TObject *Sender)
{
        N7Click(this);
}
//*****************************************************************
void __fastcall TForm1::btnDelRelClick(TObject *Sender)
{
        g.delete_link(vp[lstPpl->ItemIndex],vrel[Relative->ItemIndex]);
        btnDelRel->Visible=false;
        lstPplChange(this);        
}
//*****************************************************************
void __fastcall TForm1::RelativeDblClick(TObject *Sender)
{
        if(Relative->ItemIndex==-1) return;
        modify(true);
}
//*****************************************************************
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
//���������� ��������� � data
        String Sdir=dir;
        String Sfoto;
        String Sfile;
        if(LastPpl!=-1 && vp[LastPpl].file!="")
                {if(vp[LastPpl].file[0]=='\\')
                        Sfile=Sdir + vp[LastPpl].file.c_str();
                        else
                        Sfile=vp[LastPpl].file.c_str();
                data->Lines->SaveToFile(Sfile);
                }
//���������� � ����
        if(FileAdr=="")
                N6Click(this);
                else
                {
                Form5=new TForm5(Form1);
                Form5->lblText->Caption="��������� ���������?";
                if(Form5->ShowModal()==mrYes){
                        ofstream out(FileAdr.c_str(),ios::out | ios::trunc);
                        if(!out) {ShowMessage("������ ��� ������� ��������� ����.");return;}
                        out<<g;
                        out.close();
                        ShowMessage("��� ��������� ���������.");}
                }
}
//*****************************************************************
void __fastcall TForm1::N8Click(TObject *Sender)
{
        add_vertex();
}
//*****************************************************************
void add_vertex()
{
//
        Form2=new TForm2(Form1);
        Form2->edLink->Visible=false;
        Form2->Label7->Visible=false;
        Form2->Label8->Visible=false;
        Form2->lblRel->Visible=false;
//����� �����
	if (Form2->ShowModal()==mrCancel){
                delete Form2;
                return;}
//�������� ������ �������
        ppl.clear();
        ppl.set(Form2->edSerName->Text.c_str(),Form2->edName->Text.c_str(),Form2->edOtchestvo->Text.c_str());
        if(Form2->edBorn->Text!="")
                ppl.Born.year=StrToInt(Form2->edBorn->Text);
        if(Form2->edDead->Text!="")
                ppl.Dead.year=StrToInt(Form2->edDead->Text);
        for(int i=0;i<Form2->edResidence->Lines->Count;i++)
                if(Form2->edResidence->Lines->Strings[i].Length()!=0)
                        ppl.Residence.push_back(Form2->edResidence->Lines->Strings[i].c_str());
        if(Form2->edFoto->Text!="")
                ppl.foto=Form2->edFoto->Text.c_str();
        if(Form2->edFile->Text!="")
                ppl.file=Form2->edFile->Text.c_str();
        if(Form2->edDir->Text!="")
                ppl.dir=Form2->edDir->Text.c_str();
//����������
        if(g.add_vertex(ppl)==false)
                ShowMessage("���� ������� ��� ��������.");
        clear();
        Form1->btnFindClick(Form1);
//
        Form2->edLink->Visible=true;
        Form2->Label7->Visible=true;
        Form2->Label8->Visible=true;
        Form2->lblRel->Visible=true;
        delete Form2;
}
//****************************************************************************
void __fastcall TForm1::N9Click(TObject *Sender)
{
        del_vertex();
}
//***************************************************************************
void del_vertex()
{
        if(Form1->lstPpl->ItemIndex==-1) return;
        Form5->lblText->Caption=((String)"�������� " + vp[Form1->lstPpl->ItemIndex].get_FIO().c_str() + " �� ���� ������. ����� ������� ��� ����������� ����� � ���� ���������.");
        if(Form5->ShowModal()==mrYes) {
                if(g.delete_vertex(vp[Form1->lstPpl->ItemIndex])==false)
                        ShowMessage("��������� ������ ��� ��������");
                clear();
                Form1->btnFindClick(Form1);}
}
//***************************************************************************
void __fastcall TForm1::FormActivate(TObject *Sender)
{
        btnFindClick(Form1);
}
//***************************************************************************
void __fastcall TForm1::N10Click(TObject *Sender)
{
        open_tree(true);
}
//***************************************************************************
void open_tree(bool Add)
{
     if(Form1->OpenDialog->Execute()){
        ifstream in((Form1->OpenDialog->FileName).c_str());
        if(!in) {ShowMessage("������ ��� ������� ������� ����.");return;}
//���������� ��� ������� �� �����
        if(Add==false)
                g.Clear();
        in>>g;
        in.close();
        //�������
        clear();
        FileAdr=Form1->OpenDialog->FileName;
        ShowMessage("������ ���������.");
        Form1->btnFindClick(Form1);}
}
//***************************************************************************
void __fastcall TForm1::btnDirClick(TObject *Sender)
{
        char tmp[MAX_PATH];
        tmp[0]=0;
        strcpy(tmp,dir);
        strcat(tmp,vp[lstPpl->ItemIndex].dir.c_str());
        ShellExecuteA(0, NULL,tmp, NULL, NULL, 1);
}
//***************************************************************************
void __fastcall TForm1::CreateTreeClick(TObject *Sender)
{
        frmTree->Show();
}
//***************************************************************************
