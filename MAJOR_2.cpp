#include <cstdio>
#include <map>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,num,flag=-1001;
        scanf("%d",&n);
        if(n == 0) 
        {
            printf("NO\n\n");
            continue;
        }
        map<int,int> m;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num);
            m[num]++;
            if(m[num] > (n/2))
            {
                flag = num;
            }
        }
        if(flag != -1001) printf("YES %d\n\n",flag);
        else printf("NO\n\n");
    }
}