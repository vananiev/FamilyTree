#ifndef _PEOPLE
#define _PEOPLE
#include<string>
#include<vector>
#include<fstream.h>
String mon[]={"янв","фев","мар","апр","май","июн","июл","авг","сен","окт","ноя","дек"};
//****************************************************************************
class Time_Data{
public:
int sec;
int min;
int hour;
int day;
int month;
int year;
Time_Data(){Clear();};
void Clear(){sec=-1;
        min=-1;
        hour=-1;
        day=-1;
        month=-1;
        year=-1000000;};
String ToStr();
bool compare(Time_Data& obj);
bool operator == (Time_Data& op2);
friend ostream &operator<<(ostream &stream,Time_Data obj);
friend istream &operator>>(istream &stream,Time_Data &obj);
};
//****************************************************************************
bool Time_Data::operator == (Time_Data& op2)
{
        if(sec==op2.sec && min==op2.min && hour==op2.hour && day==op2.day && month==op2.month && year==op2.year)
                return true;
                else return false;
};
//****************************************************************************
ostream &operator<<(ostream &stream,Time_Data obj)
{
        stream<<obj.sec<<" ";
        stream<<obj.min<<" ";
        stream<<obj.hour<<" ";
        stream<<obj.day<<" ";
        stream<<obj.month<<" ";
        stream<<obj.year<<" ";
        return stream;
}
//****************************************************************************
istream &operator>>(istream &stream,Time_Data &obj)
{
        stream>>obj.sec;
        stream>>obj.min;
        stream>>obj.hour;
        stream>>obj.day;
        stream>>obj.month;
        stream>>obj.year;
        return stream;
}
//****************************************************************************
bool Time_Data::compare(Time_Data& obj)
{
        if(sec==-1 || sec==obj.sec)
        if(min==-1 || min==obj.min)
        if(hour==-1 || hour==obj.hour)
        if(day==1 || day==obj.day)
        if(month==-1 || month==obj.month)
        if(year==-1 || year==obj.year)
                return true;
        return false;
};
//****************************************************************************
String Time_Data::ToStr()
{
        String s="";
        if(hour!=-1)     s=IntToStr(hour)+" ";
        if(min!=-1)      s=(s="" ? "" : ": ")+IntToStr(min)+" ";
        if(sec!=-1)      s=(s="" ? "" : ": ")+IntToStr(sec)+" ";
        if(day!=-1)      s=IntToStr(day)+" ";
        if(month!=-1)    s=mon[month]+" ";
        if(year>-1000000)     s=IntToStr(year);
        return s;
};
//****************************************************************************
class People{
public:
string Name;
string SerName;
string Otchestvo;
Time_Data Born;
Time_Data Dead;
vector<string> Residence;
string file;
string foto;
string dir;
People(){clear();};
People(string Name_, string SerName_,string Otchestvo_){set(Name_, SerName_, Otchestvo_);};
People(string FIO){set(FIO);};
void clear(){Name="";SerName="";Otchestvo="";Born.Clear();Dead.Clear();Residence.clear();file="";foto="";dir="";};
bool set(string FIO);
bool set(string SerName_, string Name_,string Otchestvo_);
string get_FIO();
bool compare (People& obj);
bool compare (vector<string>& r);
bool operator == (People op2);
friend ostream &operator<<(ostream &stream,People obj);
friend istream &operator>>(istream &stream,People &obj);
};
//****************************************************************************
bool People::compare (People& obj){
        Time_Data N;
        if(Name=="" || obj.Name==Name)
        if(SerName=="" || obj.SerName==SerName)
        if(Otchestvo=="" || obj.Otchestvo==Otchestvo)
        if(Born==N || Born.compare(obj.Born))
        if(Dead==N || Dead.compare(obj.Dead))
        if(Residence.size()==0 || compare(obj.Residence))
                        return true;
        return false;
};
//****************************************************************************
bool People::compare (vector<string>& r)
{
        if(Residence.size()==0) return true;
        for(int i=0;i<r.size();i++)
                if(Residence[0]==r[i])
                        return true;
        return false;
};
//****************************************************************************
bool People::operator== (People op2){
        Time_Data N;
        if(op2.Name==Name)
        if(op2.SerName==SerName)
        if(op2.Otchestvo==Otchestvo)
        if(op2.Born==Born)
        if(op2.Dead==Dead)
                {if(Residence.size()!=op2.Residence.size())
                        return false;
                for(int i=0;i<Residence.size();i++)
                        if(Residence[i]!=op2.Residence[i])
                                return false;
                if(file==op2.file)
                if(foto==op2.foto)
                if(dir==op2.dir)
                return true;}
        return false;
};
//****************************************************************************
bool People::set(string FIO)
{
        int i=FIO.find(" ",0);
        if(i>0){
                SerName.assign(FIO,0,i);
                int j=FIO.find(" ",i+1);
                if (j>0){
                        Name.assign(FIO,i+1,j-i-1);
                        Otchestvo.assign(FIO,j+1,FIO.size()-j);}
                        else{
                        Name.assign(FIO,i+1,FIO.size()-i);
                        Otchestvo="";}
                }
                else{
                SerName=FIO;
                Name="";
                Otchestvo="";}
        return true;
}
//****************************************************************************
bool People::set(string SerName_, string Name_,string Otchestvo_)
{
        Name=Name_;
        SerName=SerName_;
        Otchestvo=Otchestvo_;
        return true;
};
//****************************************************************************
ostream &operator<<(ostream &stream,People obj)
{
        stream<<" Name "<<obj.Name<<" _ ";
        stream<<" SerName "<<obj.SerName<<" _ ";
        stream<<" Otchestvo "<<obj.Otchestvo<<" _ ";
        stream<<" Born "<<obj.Born<<" _ ";
        stream<<" Dead "<<obj.Dead<<" _ ";
        stream<<" foto "<<obj.foto<<" _ ";
        stream<<" file "<<obj.file<<" _ ";
        stream<<" dir "<<obj.dir<<" _ ";
        stream<<" Residence ";
        for(int i=0;i<obj.Residence.size();i++)
                stream<<obj.Residence[i]<<" ";
        stream<<" _ ";
        stream<<" #"<<endl;
        return stream;
}
//****************************************************************************
istream &operator>>(istream &stream,People &obj)
{
        char data[512];
        obj.clear();
        int cnt=0;
        do{
                stream>>data;
                if(!strcmp(data,"Name"))
                        {
                        stream>>data;
                        if(!strcmp(data,"_"))
                                obj.Name="";
                                else
                                obj.Name=data;
                        };
                if(!strcmp(data,"SerName"))
                        {
                        stream>>data;
                        if(!strcmp(data,"_"))
                                obj.SerName="";
                                else
                                obj.SerName=data;
                        };
                if(!strcmp(data,"Otchestvo"))
                        {
                        stream>>data;
                        if(!strcmp(data,"_"))
                                obj.Otchestvo="";
                                else
                                obj.Otchestvo=data;
                        }
                if(!strcmp(data,"Born"))
                        stream>>obj.Born;
                if(!strcmp(data,"Dead"))
                        stream>>obj.Dead;
                if(!strcmp(data,"foto"))
                        {
                        stream>>data;
                        if(!strcmp(data,"_"))
                                obj.foto="";
                                else
                                obj.foto=data;
                        }
                if(!strcmp(data,"file"))
                        {
                        stream>>data;
                        if(!strcmp(data,"_"))
                                obj.file="";
                                else
                                obj.file=data;
                        }
                if(!strcmp(data,"dir"))
                        {
                        stream>>data;
                        if(!strcmp(data,"_"))
                                obj.dir="";
                                else
                                obj.dir=data;
                        }
                if(!strcmp(data,"Residence"))
                        {
                        stream>>data;
                        while(strcmp(data,"_"))
                                {
                                obj.Residence.push_back(data);
                                stream>>data;
                                }
                        }
                   cnt++;
                }while(strcmp(data,"#") && cnt<64);
        return stream;
}
//****************************************************************************
string People::get_FIO()
{
        string res="";
        res=SerName + " " + Name + " " + Otchestvo;
        return res;
}
//****************************************************************************
#endif
