#include <cstdio>
#include <math.h>
#include <iostream>
using namespace std;
float sqr(float a)
{
    return a*a;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double u,v,w,W,V,U;
        scanf("%lf %lf %lf %lf %lf %lf",&u,&v,&w,&W,&V,&U);
      //  double volume = sqrt(4*u*u*v*v*w*w- u*u*sqr((v*v+w*w - U*U)) - v*v*sqr((w*w+u*u - V*V))
       //      - w*w*sqr((u*u + v*v - W*W)) + (v*v +w*w - U*U)*(w*w+u*u- V*V)*(u*u+v*v - W*W))/12.0;
           double volume = sqrt(4*(pow(u,2)*pow(v,2)*pow(w,2)) - pow(u,2)*pow((pow(v,2)+pow(w,2)
            -pow(U,2)),2) - pow(v,2)*pow((pow(w,2)+pow(u,2)-pow(V,2)),2)
                 - pow(w,2)*pow((pow(u,2)+pow(v,2)-pow(W,2)),2) 
                    + (pow(v,2)+pow(w,2)-pow(U,2))*(pow(w,2)
                    +pow(u,2)-pow(V,2))*(pow(u,2)+pow(v,2)-pow(W,2)))/12.0;
        printf("%.4lf\n",volume);      
    }
}

/*int main()
{
        int i,j,k,l,n,m;
        double u,v,w,U,V,W,Volume,a,b=12;
        
            cin>>u>>v>>w>>W>>V>>U;
        a=4*(pow(u,2)*pow(v,2)*pow(w,2)) - pow(u,2)*pow((pow(v,2)+pow(w,2)-pow(U,2)),2) - pow(v,2)*pow((pow(w,2)+pow(u,2)-pow(V,2)),2) - pow(w,2)*pow((pow(u,2)+pow(v,2)-pow(W,2)),2) + (pow(v,2)+pow(w,2)-pow(U,2))*(pow(w,2)+pow(u,2)-pow(V,2))*(pow(u,2)+pow(v,2)-pow(W,2));
        Volume=sqrt(a);
        Volume/=b;
        printf("%.4lf\n",Volume);
}*/
