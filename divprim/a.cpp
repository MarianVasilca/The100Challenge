#include<fstream>
#include<cstring>
#include<vector>
#define maxN 1000001
using namespace std;

ifstream f("divprim.in");
ofstream g("divprim.out");

vector<int> v[8];
int ciur[maxN],maxx;
void ciurr()
{   int i;
    for(i=2;i<=maxx;i++)
    {
        if(ciur[i] == 0 )
        {
            ciur[i]=1;
            for(int j=i+i;j<=maxx;j+=i)
                ciur[j]++;
        }
        v[ciur[i]].push_back(i);
    }
}
int main()
{
    int t,x,y,poz;
    f>>t;
    while(t--){
        f>>x>>y;
        maxx=max(maxx,x);
    }
    ciurr();
    f.seekg(ios_base::beg);
    f>>t;
    while(t--)
    {
        f>>x>>y;
         poz =  lower_bound(v[y].begin(),v[y].end(),x)-v[y].begin() ;
         if(poz == 0 ){
            g<<poz<<'\n';
            continue;
         }

            g<<v[y][poz-1] <<'\n';
    }
    return 0;
}