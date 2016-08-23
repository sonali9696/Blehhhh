//BFS
#include <cstdio>
#include <limits.h>
#include <queue>
using namespace std;

int a[183][183];
int m,n;

void BFS(int i, int j)
{
    queue<int> q; //store row, col consecutively
    q.push(i);
    q.push(j);

    while(!q.empty())
    {
        int r = q.front();
        q.pop();
        int c = q.front();
        q.pop();

        int val = a[r][c];
        
        //up
        if(r-1 >=0 && a[r-1][c] > val + 1)
        {
            q.push(r-1);
            q.push(c);
            a[r-1][c] = val+1;
        } 

        //down
        if(r+1 < m && a[r+1][c] > val + 1)
        {
            q.push(r+1);
            q.push(c);
            a[r+1][c] = val+1;
        } 

        //left
        if(c-1 >=0 && a[r][c-1] > val + 1)
        {
            q.push(r);
            q.push(c-1);
            a[r][c-1] = val+1;
        } 

        //right
        if(c+1 >=0 && a[r][c+1] > val + 1)
        {
            q.push(r);
            q.push(c+1);
            a[r][c+1] = val+1;
        } 
    } 

}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&m,&n);
        char c;
        int row[m*n],col[m*n],pos=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++) 
            {
                scanf(" %c",&c);
                if(c == '1') 
                {
                    a[i][j] = 0;
                    row[pos] = i;
                    col[pos++] = j;
                }
                else a[i][j] = INT_MAX;
            } 
        }

        for(int i=0; i<pos; i++) BFS(row[i],col[i]);

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++) printf("%d ",a[i][j]);
            printf("\n");
        }

    }
}