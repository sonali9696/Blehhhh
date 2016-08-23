#include <cstdio>
#include <cstring>
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1; t<=T; t++)
    {
        int b,interactions;
        scanf("%d %d",&b,&interactions);
        int bug[b+1]; //bug[0] not used
        memset(bug,-1,sizeof(bug));
        //-1: gender undetermined
        //0: male
        //1: female
        int flag = 0;
        while(interactions--)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            if(bug[x] == -1 && bug[y] == -1)
            {
                //following may be reverse. What to do
                bug[x] = 0;
                bug[y] = 1;
            }
            else if(bug[x] != -1 && bug[y] == -1)
            {
                if(bug[x] == 0) bug[y] = 1;
                else bug[y] = 0;
            }
            else if(bug[x] == -1 && bug[y] != -1)
            {
                if(bug[y] == 0) bug[x] = 1;
                else bug[x] = 0;
            }
            else if( (bug[x] == 0 && bug[y] == 0) || (bug[x] == 1 && bug[y] == 1)) //homo
            {
                flag = 1;
                break;
            }
            //else a female and male doing it :P (affair)
        }
        printf("Scenario #%d:\n",t);
        if(flag == 1) printf("Suspicious bugs found!\n");
        else printf("No suspicious bugs found!\n");
        //print stmt:
    }
}