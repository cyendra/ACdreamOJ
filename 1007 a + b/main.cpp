#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
const LL MOD = 10000000007;

LL multi(LL a,LL b,LL m)
{
    LL ans=0;
    a%=m;
    b%=m;
    while(b){
        if(b & 1) ans=(ans+a)%m;
        b>>=1;
        a=(a+a)%m;
    }
    return ans;
}

LL modPow(LL x,LL n,LL mod){
    if (n==0) return 1;
    LL res=modPow( multi(x,x,mod)%mod,n/2,mod);
    if (n&1) res=multi(res,x,mod)%mod;
    return res;
}
int main()
{
    int T;
    LL n,k,A,ans;
    scanf("%d",&T);
    //cin>>T;
    while (T--){
        //cin>>n>>k;
        scanf("%lld%lld",&n,&k);
        ans=0;
        for (int i=0;i<n;i++){
            //cin>>A;
            scanf("%lld",&A);
            ans+=modPow(A,k,MOD);
            ans%=MOD;
        }
        printf("%lld\n",ans);
        //cout<<ans<<endl;
    }
    return 0;
}
