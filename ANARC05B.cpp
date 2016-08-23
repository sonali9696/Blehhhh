//linear approach --> TLE
#include <cstdio>
#define LL long long int
LL max(LL a, LL b)
{
    return (a>=b)?a:b;
}

LL doubleHelix(int a[], int m, int b[], int n, int i, int j,int sum) //we begin from a
{
    if(i == m) return sum;

    while(b[j] < a[i] && j != n) j++; //these elements will never be common+low value so skip
    if(j == n) j--;
    if(b[j] == a[i])
    {
        return max(doubleHelix(a,m,b,n,i+1,j+1,sum+a[i]),doubleHelix(b,n,a,m,j+1,i+1,sum+b[j]) );
    }
    else return doubleHelix(a,m,b,n,i+1,j,sum+a[i]);
}

int main()
{
    int m,n;
    while(1)
    {
        scanf("%d",&m);
        if(m == 0) return 0;
        int a[m];
        for(int i=0; i<m; i++) scanf("%d",&a[i]);
        int n;
        scanf("%d",&n);
        int b[n];
        for(int i=0; i<n; i++) scanf("%d",&b[i]);
        LL sum = max ( doubleHelix(a,m,b,n,0,0,0) , doubleHelix(b,n,a,m,0,0,0));
        printf("%lli\n",sum);
    }
}