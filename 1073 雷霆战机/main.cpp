#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1111;
int n;
int a[11];
int exp[maxn];
int main()
{
    while (cin>>n){
        for (int i=1;i<=4;i++) cin>>a[i];
        for (int i=1;i<=n;i++) cin>>exp[i];
        sort(exp+1,exp+1+n);
        int res=0,idx=1;
        for (int i=1;i<=n&&idx<=4;i++){
            int ch=1;
            for (int j=1;j<=n;j++){
                if (exp[j]==-1) continue;
                ch=j;
                if (res+exp[j]>=a[idx]) break;
            }
            res+=exp[ch];
            exp[ch]=-1;
            if (res>=a[idx]){
                idx++;
                res=0;
            }
        }
        if (idx<=4){
            cout<<"NO"<<endl;
        }
        else{
            int ans=0;
            for (int i=1;i<=n;i++){
                if (exp[i]==-1) continue;
                ans+=exp[i];
            }
            cout<<"YES "<<ans<<endl;
        }
    }
    return 0;
}
