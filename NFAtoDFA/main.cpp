#include <iostream>
#include <fstream>
#include<string>
#include<set>
using namespace std;
ifstream f("nfa.in");
ofstream g("dfa.out");
class AFN
{
    set<int> stare;
    set<int> finals;
    set<char> alfabet;
    int ns,nl,start,nfinal,t,tranx[100][100];
public:
    AFN()
    {
        int i,j,curent,fstate;
        char lit;
        f>>ns>>nl; // ns = numarul de stari / nl = nr de litere
        for (i=1; i<=ns; ++i)
        {
            f>>curent; // starile
            stare.insert(curent);
        }

        for (i=1; i<=nl; ++i)
        {
            f>>lit; // literele
            alfabet.insert(lit);
        }

        f>>start; // starea initiala
        f>>nfinal; // numarul starilor finale
        for (i=1; i<=nfinal; ++i)
        {
            f>>fstate; // stari finale
            finals.insert(fstate);
        }
        for(i=0; i<100; ++i)
            for(j=0; j<100; ++j)
            {
                tranx[i][j]=-1; //matricea de tranzitii
            }
    }

    ~AFN() {}

    void matranz()
    {
        int st,dr,i;
        char simbol;
        f>>t; // numarul de tranzitii
        for (i=1; i<=t; ++i)
        {
            f>>st; // starea 1
            f>>simbol; // litera
            f>>dr; // starea 2
            tranx[st][simbol]=dr;
        }
    }
    void convertToDfa()
    {
        g<<"starea initiala: "<<start<<endl;


    }
};

int main()
{string nfa[100][100];
set<string> coada;
char start,lix;
int nstari,nlitere,O=0,x;
f>>nstari>>nlitere;
for(int i=0;i<nstari;++i)
{f>>lix;
// g<<lix<<" ";
 x=lix-'a';
 for(int k=0;k<nlitere;++k)
 {
     f>>nfa[x][k];
   //  cout<<nfa[x][k]<<" ";
 }
//cout<<endl;
}
for(int k=0;k<nlitere;++k)
        g<<nfa[0][k]<<" ";
for(int i=0;i<nstari;++i)
{
    for(int k=0;k<nlitere;++k)
    coada.insert(nfa[i][k]);
}
while(!coada.empty()){
string b;
b=coada.begin();

}

    return 0;
}

