#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;
int L,a;
const double PI=acos(-1);
int main()
{
    int T;
    scanf("%d",&T);
    while (T--){
        scanf("%d%d",&L,&a);
        a=a%90*PI/180;
        double x=L/(1+cos(a)+sin(a));
        x=L*L-x*x*sin(2*a);
        printf("%.2f\n",x);
    }
    return 0;
}
