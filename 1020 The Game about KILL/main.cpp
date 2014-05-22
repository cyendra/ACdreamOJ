#include <iostream>

using namespace std;
typedef long long LL;
LL f[33];
int n;
int main()
{
    f[0]=1;
    for (int i=1;i<=31;i++){
        f[i]=f[i-1]*2;
    }
    while (cin>>n){
        int m;
        for (m=0;m<31;m++){
            if (f[m+1]>n) break;
        }
        int d=n-f[m];
        cout<<1+d*2<<endl;
    }
    return 0;
}
