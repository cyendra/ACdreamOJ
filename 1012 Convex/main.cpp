#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;
const double PI=acos(-1);
int main()
{
    int n;
    double r;
    while (cin>>n>>r){
        double ans=0;
        int a;
        r=r*r/2;
        for (int i=1;i<=n;i++){
            cin>>a;
            ans+=r*sin(a*PI/180);
        }
        printf("%.3f\n",ans);
    }
    return 0;
}
