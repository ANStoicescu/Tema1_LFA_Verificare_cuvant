#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("date.in");
int mat[100][100][100];
int init,pozition=-1,state=-1,n;
int finalstate[100];
char cuv[100];
bool ok;
bool DFS(int x,int state)
{
    while(cuv[state]=='L')
        state++;
    if (finalstate[pozition]!=0 && state==strlen(cuv))
        ok=1;
    else if(state<strlen(cuv))
            for(int i=1; i<=n; i++)
                if (mat[x][cuv[state]-96][i]){
                    pozition=i;
                    DFS(i,state+1);
                }
}
int main()
{

    f>>n;
    int maxi=0;
    for(int i=1; i<=n; i++)
    {
        int x,y;
        char c;
        f>>x>>y>>c;
        mat[x][c-96][y]=1;
        if(x>maxi)
            maxi=x;
        if(y>maxi)
            maxi=y;
    }
    n=maxi;
    f>>init;
    int nr;
    f>>nr;
    for(int i=0; i<nr; i++)
    {
        int x;
        f>>x;
        finalstate[x]=1;
    }
    f>>nr;
    f.getline(cuv,100);
    while(nr--)
    {
        f.getline(cuv,100);
        pozition=-1;state=-1;ok=0;
        if(cuv[0]=='L')
        {
            pozition=init;
            state=1;
            if (finalstate[pozition]!=0 && state==strlen(cuv))
                ok=1;
        }
        else
            DFS(init,0);
        if(ok)
            cout<<cuv<<"  Apartine\n";
        else
            cout<<cuv<<"  Nu apartine\n";
    }
}
