//TLE
#include <cstdio>
#include <limits.h>
#include <math.h>
#include <cstring>

int dist[200][200];

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
        
        //input & initialize dist[][]
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

        for(int i=0;i<m;i++)
        {
            for(int j=0; j<n; j++)
            {
                if(dist[i][j] == 0) continue;
                int q = INT_MAX;
                for(int k=0; k<r; k++)
                {
                    int i2 = row[k], j2 = col[k];
                    int num = fabs(i-i2) + fabs(j-j2);
                    if(num < q) q = num;
                }       
                dist[i][j] = q; 
            }
        }        

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++) printf("%d ",dist[i][j]);
            printf("\n");
        }

    }
}