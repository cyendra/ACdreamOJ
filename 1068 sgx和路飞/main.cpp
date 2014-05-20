#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
const int maxn=300;

LL f[maxn][maxn];
int digit[11];
LL L,R;
int S;

LL dp(int pos,int pre,bool limit){
    if (pos==-1) return pre==S;
    if (!limit&&f[pos][pre]!=-1) return f[pos][pre];
    LL res=0;
    int ed=limit?digit[pos]:9;
    for (int i=0;i<=ed;i++) res+=dp(pos-1,pre+i,limit&&i==ed);
    if (!limit) return f[pos][pre]=res;
    return res;
}

LL solve(LL n){
    int len=0;
    while (n){
        digit[len++]=n%10;
        n/=10;
    }
    return dp(len-1,0,1);
}

bool C(LL x, LL y){
    return (solve(y)-solve(x-1))>=1;
}

LL gao(){
    LL res=0;
    LL l=L,r=R;
    while (l<=r){
        LL mid=(l+r)/2;
        if (C(L,mid)){
            r=mid-1;
            res=mid;
        }
        else{
            l=mid+1;
        }
    }
    return res;
}

int main()
{
    while (cin>>L>>R>>S){
        memset(f,-1,sizeof(f));
        cout<<gao()<<endl;
    }
    return 0;
}
