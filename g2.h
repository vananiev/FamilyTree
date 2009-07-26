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
void add(T &f,T &s,string &l);
int count(){return vetex.size();};
vector<T> find_pare(T& obj, vector<string> &ResultLinks);
vector<T> find(T& obj,vector<T> (*func)(T &,vector<T>&)) {return delete_duplicate((*func)(obj,vertex));};
vector<T> & delete_duplicate(vector<T> &v);
int modify(T& Old,T& New);
friend ostream &operator<<(ostream &stream,Graph<T> obj);
friend istream &operator>>(istream &stream,Graph<T> &obj);
};
//****************************************************************************
template <class T> vector<T> Graph<T>::find_pare(T& obj,vector<string> &ResultLinks=NULL)
{
        vector<T> result;
//поиск в ferst
        for(int i=0;i<ferst.size();i++)
                 if(vertex[ferst[i]]==obj)
                        {result.push_back(vertex[second[i]]);
                        ResultLinks.push_back(link[i]);}
//поиск second
        for(int i=0;i<second.size();i++)
                 if(vertex[second[i]]==obj)
                        {result.push_back(vertex[ferst[i]]);
                        ResultLinks.push_back("!"+link[i]);}
        return result;
};
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
        stream<<obj.vertex.size()<<" ";
        for(int i=0;i<obj.vertex.size();i++)
                stream<<obj.vertex[i]<<" ";
        stream<<obj.ferst.size()<<" ";
        for(int i=0;i<obj.ferst.size();i++)
                stream<<obj.ferst[i]<<" "<<obj.second[i]<<" "<<obj.link[i]<<" ";
        return stream;
};
//****************************************************************************
istream &operator>> (istream &stream,Graph<People> &obj)
{
        obj.Clear();
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
                obj.ferst.push_back(loadint);
                stream>>loadint;
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
#endif
 