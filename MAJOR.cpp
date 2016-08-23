#include <cstdio>
#include <cstring>
int count[1000001];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(count,0,sizeof(count));
        int n,num,flag=-1001;
        scanf("%d",&n);
        if(n == 0) 
        {
            printf("NO\n\n");
            continue;
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num);
            if(num < 0) num = 1000 + (-1 * num);
            count[num]++;
            if(count[num] > (n/2)) 
            {
                if(num > 1000) num = -1 * (num - 1000);
                flag = num;
            } 
        }
        if(flag != -1001) printf("YES %d\n\n",flag);
        else printf("NO\n\n");
    }
}