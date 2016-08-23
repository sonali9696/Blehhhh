//Moore's voting algo: there can be only one or no element with occurence
//greater than size/2 in an array i.e. majority element
//0.28 sec, rest algo: 0.30 sec
#include <cstdio>

int isMajority(int num, int a[], int n)
{
    int count = 0;
    for(int i=0;i<n;i++)
    {
        if(a[i] == num) count++;
    }
    if(count > n/2) return 1;
    else return 0;
}

int find_candidate(int a[], int n)
{
    int count = 1,index = 0;
    for(int i=1; i< n; i++)
    {
        if(a[i] == a[index]) count++;
        else count--;
        if(count == 0)
        {
            index = i;
            count = 1;
        }
    }
    return a[index];
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n];
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        int num = find_candidate(a,n);
        bool ans = isMajority(num,a,n);
        if(ans == 1) printf("YES %d\n\n",num);
        else printf("NO\n\n");
    }
}