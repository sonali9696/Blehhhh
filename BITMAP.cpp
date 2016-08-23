//TLE
#include <cstdio>
#include <cstring>
#include <limits.h>
using namespace std;

int dist[183][183];

void bitmap(int m, int n, int i, int j, int val)
{
    if(dist[i][j] > val + 1) dist[i][j] = val+1;
    else return;

    //following only if present value was just now updated
    if(j + 1 < n)  bitmap(m,n,i,j+1, dist[i][j]);
    if(i -1  >= 0)  bitmap(m,n,i-1,j, dist[i][j]);
    if(i + 1 < m)  bitmap(m,n,i+1,j, dist[i][j]);
    if(j - 1 >= 0) bitmap(m,n,i,j-1, dist[i][j]);    
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int m,n;
        scanf("%d %d",&m,&n);
        char ch;
        scanf("%c",&ch);//new line
        int a[m][n];
        int row[m*n],r=0;
        int col[m*n],c=0;
        memset(dist,INT_MAX,sizeof(dist));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                scanf("%c",&ch);
                a[i][j] = ch - '0';
                if(a[i][j] == 1)
                {
                    dist[i][j] = 0;
                    row[r++] = i;
                    col[c++] = j;
                }
                else dist[i][j] = INT_MAX;
            }
            scanf("%c",&ch); //for new line
        }

        for(int i=0,j=0; i<r; i++,j++)
        {
            if(col[j] + 1 < n)  bitmap(m,n,row[i],col[j]+1, dist[row[i]][col[j]]);
            if(row[i] -1  >= 0) bitmap(m,n,row[i]-1,col[j],dist[row[i]][col[j]]);
            if(row[i] + 1 < m)  bitmap(m,n,row[i]+1,col[j],dist[row[i]][col[j]]);
            if(col[j] - 1 >= 0) bitmap(m,n,row[i],col[j]-1,dist[row[i]][col[j]]);
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++) printf("%d ",dist[i][j]);
            printf("\n");
        }

    }
}