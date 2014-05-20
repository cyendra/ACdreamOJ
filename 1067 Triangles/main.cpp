#include <iostream>

using namespace std;
typedef long long LL;
LL n;
int main()
{
    while (cin>>n){
        LL len=(n-1-(n+1)/2);
        LL ans=n*(n-1)*(n-2)/6-n*len*(len+1)/2;
        cout<<ans<<endl;
    }
    return 0;
}
