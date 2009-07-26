#ifndef _GRAPH2
#define _GRAPH2
#include <vector.h>
#include<People.h>
template <class T> class Graph{
public:
vector <T> vertex;
vector <string> link;
vector <int> ferst;
vector <int> second;
Graph(){Clear();};
Graph(T &f,T &s,string &l){add(f,s,l);};
void Clear(){vertex.clear();ferst.clear();second.clear();link.clear();}
void add(T &f,T &s,string &l);    //добавление новой связи
bool is_exist(T &f,T &s,string &l); //существует связь?
int count(){return vetex.size();};
vector<T> find_pare(T& obj, vector<string> &ResultLinks,vector<bool> &F);
vector<T> find_pare(T& obj,const string &Link);
vector<T> find(T& obj,vector<T> (*func)(T &,vector<T>&)) {return delete_duplicate((*func)(obj,vertex));};
vector<T> & delete_duplicate(vector<T> &v);
bool delete_vertex(T& obj);
bool add_vertex(T& obj);
bool is_exist_vertex(T& obj);
bool delete_link(T& f, T& s);
int modify(T& Old,T& New);
friend ostream &operator<<(ostream &stream,Graph<T> obj);
friend istream &operator>>(istream &stream,Graph<T> &obj);
};
//****************************************************************************
template <class T> vector<T> Graph<T>::find_pare(T& obj,vector<string> &ResultLinks=NULL,vector<bool> &F=NULL)
{
        vector<T> result;
//поиск в ferst
        for(int i=0;i<ferst.size();i++)
                 if(vertex[ferst[i]]==obj)
                        {result.push_back(vertex[second[i]]);
                        ResultLinks.push_back(link[i]);
                        F.push_back(true);}
//поиск second
        for(int i=0;i<second.size();i++)
                 if(vertex[second[i]]==obj)
                        {result.push_back(vertex[ferst[i]]);
                        ResultLinks.push_back(link[i]);
                        F.push_back(false);}
        return result;
};
//****************************************************************************
template<class T> vector<T> Graph<T>::find_pare(T& obj,const string &Link)
{
        vector<T> result;
//поиск в ferst
        for(int i=0;i<ferst.size();i++)
                 if(vertex[ferst[i]]==obj && link[i]==Link)
                        result.push_back(vertex[second[i]]);
//поиск second
        for(int i=0;i<second.size();i++)
                 if(vertex[second[i]]==obj && link[i]==Link)
                        result.push_back(vertex[ferst[i]]);
        return result;
}
//****************************************************************************
template<class T> vector<T> & Graph<T>::delete_duplicate(vector<T> &v)
{
       vector<People>::iterator p=v.begin();
       vector<People>::iterator t;
        for(register int i=0;i<v.size();i++)
                for(register int j=i+1;j<v.size();j++)
                          if(v[i]==v[j]){
                                t=p+j;
                                v.erase(t);
                                j--;}
        return v;
}
//****************************************************************************
ostream &operator<<(ostream &stream,Graph<People> obj)
{
        stream<<obj.vertex.size()<<endl;
        for(int i=0;i<obj.vertex.size();i++)
                stream<<obj.vertex[i]<<" ";
        stream<<obj.ferst.size()<<endl;
        for(int i=0;i<obj.ferst.size();i++)
                stream<<obj.ferst[i]<<" "<<obj.second[i]<<" "<<obj.link[i]<<endl;
        return stream;
};
//****************************************************************************
istream &operator>> (istream &stream,Graph<People> &obj)
{
        int correct=obj.vertex.size();//используется для корректировки связей при добавлении
        //переменные загрузки
        People loadppl;
        int loadint;
        string loadstring;
        int numver=0,numlink=0;
        stream>>numver;
        for(int i=0;i<numver;i++)
                {stream>>loadppl;
                obj.vertex.push_back(loadppl);};
        stream>>numlink;
        for(int i=0;i<numlink;i++)
                {
                stream>>loadint;
                loadint+=correct;
                obj.ferst.push_back(loadint);
                stream>>loadint;
                loadint+=correct;
                obj.second.push_back(loadint);
                stream>>loadstring;
                obj.link.push_back(loadstring);
                };
        return stream;
};
//****************************************************************************
template<class T>int Graph<T>::modify(T& Old,T& New)
{
        int cnt=0;
        //поиск
        for(int i=0;i<vertex.size();i++)
                 if(vertex[i]==Old) {vertex[i]=New;cnt++;};
        return cnt;
};
//****************************************************************************
template<class T> void Graph<T>::add(T &f,T &s,string &l)
{
        if(is_exist(f,s,l)) return;
        int i,j;
        //добавление ссылок на существующие элементы
        for(i=0;i<vertex.size();i++)
                if(vertex[i]==f)
                        {ferst.push_back(i);
                        goto makelink1;}
        //добавление новых несуществующих элементов
        if(i==vertex.size())
                {vertex.push_back(f);
                ferst.push_back(i);}
makelink1:
        //добавление ссылок на существующие элементы
        for(j=0;j<vertex.size();j++)
                if(vertex[j]==s)
                        {second.push_back(j);
                        goto makelink2;}
        //добавление новых несуществующих элементов
        if(j==vertex.size())
                {vertex.push_back(s);
                second.push_back(j);}
makelink2:
        link.push_back(l);
}
 //****************************************************************************
template <class T> bool Graph<T>::delete_vertex(T& obj)
{
        int del_num=-1;
//поиск объекта
        for(int i=0;i<vertex.size();i++)
                if(vertex[i]==obj)
                        {vertex.erase(&vertex[i]);
                        del_num=i;
                        break;}
        if(del_num!=-1)
                {
//удаление связей с данным объектом
                for(int i=0;i<ferst.size();i++)
                        if(ferst[i]==del_num || second[i]==del_num)
                                {ferst.erase(&ferst[i]);
                                second.erase(&second[i]);
                                link.erase(&link[i]);
                                i--;}
//корректировка номеров в связях
                for(int i=0;i<ferst.size();i++)
                        {if(ferst[i]>del_num) ferst[i]=ferst[i]-1;
                         if(second[i]>del_num) second[i]=second[i]-1;}
                return true;
                }else
                return false;
}
//****************************************************************************
template<class T> bool Graph<T>::delete_link(T& f, T& s)
{
        int f_num=-1;
        int s_num=-1;
//поиск объектов
        for(int i=0;i<vertex.size();i++)
                if(vertex[i]==f)
                        {f_num=i;
                        break;}
        for(int i=0;i<vertex.size();i++)
                if(vertex[i]==s)
                        {s_num=i;
                        break;}
        if(f_num!=-1 && s_num!=-1)
                for(int i=0;i<ferst.size();i++)
                        if(ferst[i]==f_num && second[i]==s_num || ferst[i]==s_num && second[i]==f_num)
//удаление связи
                                {ferst.erase(&ferst[i]);
                                second.erase(&second[i]);
                                link.erase(&link[i]);}
}
//****************************************************************************
template<class T> bool Graph<T>::is_exist(T &f,T &s,string &l)
{
        int i,j;
        //поиск
        for(i=0;i<vertex.size();i++)
                if(vertex[i]==f)
                        break;
        //если не существует
        if(i==vertex.size())
                return false;
        //поиск
        for(j=0;j<vertex.size();j++)
                if(vertex[j]==s)
                        break;
        //добавление новых несуществующих элементов
        if(j==vertex.size())
                return false;
        //поиск в связях
        for(int k=0;k<ferst.size();k++)
                if((ferst[k]==i && second[k]==j && l.find(link[k])!=string::npos) || (ferst[k]==j && second[k]==i && l.find(link[k])!=string::npos))
                        return true;
        return false;
}
//****************************************************************************
template <class T> bool Graph<T>::is_exist_vertex(T& obj)
{
        for(int i=0;i<vertex.size();i++)
               if(obj==vertex[i])
                        return true;
        return false;
}
//****************************************************************************
template <class T> bool Graph<T>::add_vertex(T& obj)
{
        if(is_exist_vertex(obj)) return false;
        vertex.push_back(obj);
        return true;
}
//****************************************************************************

#endif
