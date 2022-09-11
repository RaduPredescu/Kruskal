#include <fstream>
using namespace std;
ifstream fin("kruskal.in");
ofstream fout("kruskal.out");
struct muchie
{
    int x, y, c;
} G[1003], aux, sol[103];
int n, m, i, j, k, x, y, c, ct, n1, n2;
int L[103];

int main()
{
    fin >> n >> m;
    for(i=1; i<=m; ++i)
        fin >> G[i].x >> G[i].y >> G[i].c;
    for(i=1; i<m; ++i)
        for(j=i+1; j<=m; ++j)
            if (G[i].c > G[j].c)
                swap(G[i], G[j]);
    for(i=1; i<=n; ++i)
        L[i] = i;
    k = ct = 0;
    i = 1;
    while(k < n-1)
    {
        if (L[G[i].x] != L[G[i].y])
        {
            sol[++k] = G[i];
            ct += G[i].c;
            n1 = L[G[i].x];
            n2 = L[G[i].y];
            for(j=1; j<=n; ++j)
                if (L[j] == n2)
                    L[j] = n1;
        }
        ++i;
    }
    fout << ct << "\n";
    for(i=1; i<=k; ++i)
        fout << sol[i].x << " " << sol[i].y << "\n";
    return 0;
}