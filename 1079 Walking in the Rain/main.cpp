#include <iostream>

using namespace std;
const int maxn=11111;

int a[maxn];
int n;

int main()
{
    while (cin>>n){
        for (int i=1;i<=n;i++) cin>>a[i];
        int ans=min(a[1],a[n]);
        for (int i=1;i<n;i++){
            ans=min(ans,max(a[i],a[i+1]));
        }
        cout<<ans<<endl;
    }
    return 0;
}
