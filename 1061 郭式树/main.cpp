#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long LL;
LL a,b;
LL lim=-9223372036854775808LL;
int main()
{
    int T;
    //cin.sync_with_stdio(false);
    //cin>>T;
    scanf("%d",&T);
    while (T--){
        //cin>>a>>b;
        scanf("%lld%lld",&a,&b);
        LL ans=b-a;
        if (ans<0) ans=-ans;
        if (ans==lim) printf("9223372036854775808\n");//cout<<"9223372036854775808"<<endl;
        else printf("%lld\n",ans); //cout<<ans<<endl;
    }
    return 0;
}
