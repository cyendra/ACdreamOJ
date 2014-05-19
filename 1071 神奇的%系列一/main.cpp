#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=101000;
int v[maxn];
int a[maxn];
int p[maxn];
int n;
int main()
{
    while (~scanf("%d",&n)){
        memset(v,0,sizeof(v));
        for (int i=0;i<n;i++) {
            scanf("%d",&a[i]);
            v[a[i]]++;
        }
        sort(a,a+n);
        for (int i=0;i<n;i++){
            if (i+1<n&&a[i+1]==a[i]) continue;
            p[a[i]]=i;
        }
        long long ans=0;
        for (int i=0;i<n;i++){
            if (a[i]==1) continue;
            long long cnt=0;
            for (int j=a[i]*2;j<=a[n-1];j+=a[i]){
                cnt+=v[j];
            }
            cnt=n-1-cnt-p[a[i]];
            ans+=cnt;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
