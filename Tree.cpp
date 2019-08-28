//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Tree.h"
#include "main.h"
#include<graph.h>
#include<People.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmTree *frmTree;
#define _num 100000     //����� ������
#define _pok 1024    //����� ���������
int x;               //����� ������ �� ������� ������
int z;
int Level[_pok];   //����� ����� � ����������
int cnt;                //����� ������
float _k = 1.2;             //����, ����������� ���������� �/� ��������� �� �����������
float _k2 = 10;          //����, ����������� ���������� �/� ��������� �� ���������
People Koren;     //������ ������
int max_width;    //������������ ������
InLevel[_pok];  //����� ������� �� ����� ���������� ������ � ������
TLabel* A[_num];        //����. ����� ������
short int X[_num][2];short int Y[_num][2];   //�����
vector <People> exist; //������ �������� �����
int kor=_pok;     //��������� � ������� ��������� ������ ������
extern Graph<People> g;
extern vector<People> vp;
void find_people_in_level(People &p = Koren,int cur=_pok/2); //����� ����� � ����������
void CreateTree(People &p = Koren,int predok = -1,int cur=0);
void Find_Root(People &p = vp[0],int cur = _pok/2 );
//---------------------------------------------------------------------------
__fastcall TfrmTree::TfrmTree(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmTree::FormActivate(TObject *Sender)
{
      //---���������� ������---
        //��������
                for(int i=0; i < _pok;i++)
                        Level[i] = 0;
        //����� �����
                kor=_pok;     //��������� � ������� ��������� ������ ������
                exist.clear();
                if(Form1->lstPpl->ItemIndex == -1)
                        Find_Root();   //������ ������
                        else{
                        Roditeli->Checked = false;                            //�� ���������� ��������� ��������
                        Koren = vp[Form1->lstPpl->ItemIndex];}        //������ �� ���������� ��������

        //��������� ����� ����� � ����������
                exist.clear();
                find_people_in_level();
         //����� ������ ���������
                //���� 1 ��������� (��� �� �� ������� Level[0])
                int f=0;
                for(int i=0;i<_pok;i++)
                        if(Level[i]!=0){f=i;break;}
                //����������� (������ ��� �� ������� Level[0])
                for(int i=f,j=0;j<_pok;i++,j++)
                        if(i<_pok)Level[j] = Level[i];
                                else Level[j]=0;
                //����� ����� ������
                cnt=0;
                for(int i=0;i<_pok;i++)
                        cnt +=Level[i];
         //���� ����� �������������� ���������
         int max=0;
         for(int i=0;i<_pok;i++)
                if(Level[i]>max) max = Level[i];
         //������������ ������ (� ������ ����, ������������ ���������� �/� ���������)
         max_width=(max+1)*(int)(B->Width*_k);
         //������ ���� ������ c �����
         x=0;
         z=0;
         exist.clear();
         for(int i=0;i<_pok;i++)
                InLevel[i]=0;
         for(int i=0;i<_num;i++)
                {X[i][0]=0;
                X[i][1]=0;
                Y[i][0]=0;
                Y[i][1]=0;}
         CreateTree(); //�������������
                
}
//-------------����� �����--------------------------------------------------
void Find_Root(People &p,int cur)
{
       exist.push_back(p);   //���������
       //���� ������ ������
       if(cur<kor)
                {kor = cur; Koren = p;}   //��������� �����
        vector<string> Lnk;
        vector<People> vrel;
        Lnk.clear();
        vrel.clear();
        vector<bool> Ferst;
        vector<string>::iterator l=Lnk.begin();
        vrel=g.find_pare(p,Lnk,Ferst);
        for(int i=0;i<vrel.size();i++)
                {//��� ��� ����?
                int y=0;
                for(y=0;y<exist.size();y++)
                        {if(exist[y] == vrel[i])
                                break;
                        }
                //���� �� ����
                if(y==exist.size() && exist.size()!=0) {
                        if(Lnk[i].find("������(�)")!=string::npos)
                                Find_Root(vrel[i],cur);          //������(�)
                                else {if(Ferst[i]==false)
                                        Find_Root(vrel[i],cur+1);//���(����)
                                        else
                                        Find_Root(vrel[i],cur-1);//����(����)
                                        }
                        }
                }
}
//-------------����� ����� � ����������--------------------------------------
void find_people_in_level(People &p,int cur )
{
       Level[cur]++;
       exist.push_back(p);   //���������
        vector<string> Lnk;
        vector<People> vrel;
        Lnk.clear();
        vrel.clear();
        vector<bool> Ferst;
        vector<string>::iterator l=Lnk.begin();
        vrel=g.find_pare(p,Lnk,Ferst);
                //������� ����� �������(�)
                for(int n=0;n<vrel.size() ;n++)
                        if(Lnk[n].find("������(�)")!=string::npos)
                                {//��� ��� ����?
                                int y=0;
                                for(y=0;y<exist.size();y++)
                                        if(exist[y] == vrel[n])
                                                break;
                                //���� �� ����
                                if(y==exist.size()&& exist.size()!=0)
                                        find_people_in_level(vrel[n],cur);           //������(�)
                                }
                //����� �����
                for(int n=0;n<vrel.size() ;n++)
                        if(Lnk[n].find("���(����)")!=string::npos && Ferst[n] == false)
                                {//��� ��� ����?
                                int y=0;
                                for(y=0;y<exist.size();y++)
                                        if(exist[y] == vrel[n])
                                                break;
                                //���� �� ����
                                if(y==exist.size()&& exist.size()!=0)
                                        find_people_in_level(vrel[n],cur+1);           //���(����)

                                }
                //���������� ����(����)
                for(int n=0;n<vrel.size() && frmTree->Roditeli->Checked;n++)
                        if(Lnk[n].find("���(����)")!=string::npos && Ferst[n] == true)
                                {//��� ��� ����?
                                int y=0;
                                for(y=0;y<exist.size();y++)
                                        if(exist[y] == vrel[n])
                                                break;
                                //���� �� ����
                                if(y==exist.size()&& exist.size()!=0)
                                        find_people_in_level(vrel[n],cur-1);           //����(����)
                                }
}
//----------------������ ������----------------------------------------------
void CreateTree(People &p, int predok,int cur)
{
       exist.push_back(p);   //���������
       //�������� ������
       A[x] = new TLabel(frmTree);
       A[x]->OnClick =frmTree->B->OnClick;
       A[x]->Font = frmTree->B->Font;
       A[x]->Width = frmTree->B->Width;
       A[x]->Color=frmTree->B->Color;
       A[x]->AutoSize = false;
       A[x]->Parent = frmTree;  //��� ����������� �� �����
       //��������� �� ������ � ������ vp[]
       int n = Form1->lstPpl->Items->Count;
       for(int i=0;i<n;i++)
                if(p == vp[i]) A[x]->Tag = i;
       //��������
       A[x]->Left = 1.0*max_width * (InLevel[cur]+1)/(Level[cur]+1);
       InLevel[cur]++;
       A[x]->Top = 1.0*cur*A[x]->Height*_k2;
       A[x]->Caption = (p.Name+" "+p.SerName).c_str();
       //�����
       if(predok!=-1){
                X[z][0]=A[predok]->Left+A[predok]->Width/2.0;
                Y[z][0]=A[predok]->Top+A[predok]->Height/2.0;
                X[z][1]=A[x]->Left+A[x]->Width/2.0;
                Y[z][1]=A[x]->Top+A[x]->Height/2.0;
                z++;
                }
       int pr=x;
       x++;
        vector<string> Lnk;
        vector<People> vrel;
        Lnk.clear();
        vrel.clear();
        vector<bool> Ferst;
        vector<string>::iterator l=Lnk.begin();
        vrel=g.find_pare(p,Lnk,Ferst);
                //������� ����� �������(�), ��� ��������������� ������
                for(int n=0;n<vrel.size() ;n++)
                        if(Lnk[n].find("������(�)")!=string::npos)
                                {//��� ��� ����?
                                int y=0;
                                for(y=0;y<exist.size();y++)
                                        if(exist[y] == vrel[n])
                                                break;
                                //���� �� ����
                                if(y==exist.size()&& exist.size()!=0)
                                        CreateTree(vrel[n],pr,cur);           //������(�)
                                }
                //����� �����
                for(int n=0;n<vrel.size() ;n++)
                        if(Lnk[n].find("���(����)")!=string::npos && Ferst[n] == false)
                                {//��� ��� ����?
                                int y=0;
                                for(y=0;y<exist.size();y++)
                                        if(exist[y] == vrel[n])
                                                break;
                                //���� �� ����
                                if(y==exist.size()&& exist.size()!=0)
                                        CreateTree(vrel[n],pr,cur+1);           //���(����)

                                }
                //���������� ����(����)
                for(int n=0;n<vrel.size() && frmTree->Roditeli->Checked;n++)
                        if(Lnk[n].find("���(����)")!=string::npos && Ferst[n] == true)
                                {//��� ��� ����?
                                int y=0;
                                for(y=0;y<exist.size();y++)
                                        if(exist[y] == vrel[n])
                                                break;
                                //���� �� ����
                                if(y==exist.size()&& exist.size()!=0)
                                        CreateTree(vrel[n],pr,cur-1);           //����(����)
                                break;
                                }
}
//--------------------------------------------------------------------------
void __fastcall TfrmTree::FormDeactivate(TObject *Sender)
{
        //�������� �����������
         for(int i=0; i<x; i++)
                delete A[i];
         cnt=0;
}
//--------������������� ����� �����------------------------------------------
void __fastcall TfrmTree::FormPaint(TObject *Sender)
{
        for(int i=0;i<_num;i++)
                if(X[i][0]!=0)
                        {Canvas->MoveTo(X[i][0] - HorzScrollBar->Position,Y[i][0] - VertScrollBar->Position);
                        Canvas->LineTo(X[i][1]- HorzScrollBar->Position,Y[i][1]- VertScrollBar->Position);}
                        else
                        break;
}
//---------------------------------------------------------------------------
void __fastcall TfrmTree::FormClick(TObject *Sender)
{
        frmTree->Repaint();        
}
//---------------------------------------------------------------------------
void __fastcall TfrmTree::RoditeliClick(TObject *Sender)
{
        Roditeli->Checked = !Roditeli->Checked;
        //����� ������������� ������
        FormDeactivate(frmTree);
        FormActivate(frmTree);
        frmTree->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TfrmTree::ParamClick(TObject *Sender)
{
        Param->Checked = !Param->Checked;
        if(Param->Checked)
                //�������� ���������
                {Nastr->Visible=true;
                sWidth->Position = B->Width ;
                sHeight->Position = B->Height ;
                s_k->Position = _k*10;
                s_k2->Position = _k2*10;
                FontDialog->Font = B->Font;
                ColorDialog->Color = B->Color;
                }else{//���������
                Nastr->Visible=false;
                B->Width = sWidth->Position;
                B->Height = sHeight->Position;
                _k = s_k->Position / 10.0;
                _k2 = s_k2->Position /10.0;
                B->Font = FontDialog->Font;
                B->Color = ColorDialog->Color;
                //����� ������������� ������
                FormDeactivate(frmTree);
                FormActivate(frmTree);
                frmTree->Repaint();
                }
}
//---------------------------------------------------------------------------

void __fastcall TfrmTree::btnFontClick(TObject *Sender)
{
        FontDialog->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TfrmTree::btnColorClick(TObject *Sender)
{
        ColorDialog->Execute();        
}
//---------------------------------------------------------------------------
void __fastcall TfrmTree::BClick(TObject *Sender)
{
        //�������� ��������
        Form1->lstPpl->ItemIndex = ((TLabel*)Sender)->Tag;
        //��������� ���������� � ������� ����
        Form1->lstPplChange(Sender);
        //�������� ��������
        Form1->btnModifyClick(Sender);
        //����� ������������� ������
        //FormDeactivate(frmTree);
        //FormActivate(frmTree);
        //frmTree->Repaint();
}
//---------------------------------------------------------------------------

