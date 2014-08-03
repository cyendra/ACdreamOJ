#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;
const int maxn=1111;
const int MOD=1e9+7;
int n;
char s[maxn][maxn];
int main() {
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        scanf("%s",s[i]+1);
    }
    LL ans=0;
    for (int i=1; i<=n; i++) {
        LL last1=0;
        LL sum1=0;
        LL last2=0;
        LL sum2=0;
        for (int j=1; j<=n; j++) {
            sum1=(last1*10%MOD+j*(s[i][j]-'0')%MOD)%MOD;
            last1=sum1;
            ans=(ans+sum1)%MOD;
            sum2=(last2*10%MOD+j*(s[j][i]-'0')%MOD)%MOD;
            last2=sum2;
            ans=(ans+sum2)%MOD;
        }
    }
    printf("%d\n",(int)ans);

    return 0;
}
