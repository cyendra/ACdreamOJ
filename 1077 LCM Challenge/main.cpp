#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long LL;
LL n;
LL gcd(LL x,LL y){
    return y==0?x:gcd(y,x%y);
}
LL lcm(LL x,LL y){
    return x/gcd(x,y)*y;
}

int main()
{
    while (cin>>n){
        if (n>5) {
            if (n&1) cout<<n*(n-1)*(n-2)<<endl;
            else{
                LL ans=(n-1)*(n-2)*(n-3);
                LL t=n*(n-1);
                for (int i=n-3;i*t>ans;i-=2){
                    if (lcm(t,i)>ans) {
                        ans=lcm(t,i);
                        break;
                    }
                }
                cout<<ans<<endl;
            }
        }
        else if (n==5) cout<<60<<endl;
        else if (n==4) cout<<12<<endl;
        else if (n==3) cout<<6<<endl;
        else if (n==2) cout<<2<<endl;
        else if (n==1) cout<<1<<endl;

    }
    return 0;
}
