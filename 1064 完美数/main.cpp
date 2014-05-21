#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn=1111;
int n;
int f[11][4];
int digit[11];
int new_s(int s,int d){
    if (d==3) return s|1;
    if (d==8) return s|2;
    return s;
}
int dp(int pos,int s,bool limit){
    if (pos==-1) return s==1||s==2;
    if (!limit&&f[pos][s]!=-1) return f[pos][s];
    int res=0;
    int ed=limit?digit[pos]:9;
    for (int i=0;i<=ed;i++) res+=dp(pos-1,new_s(s,i),limit&&i==ed);
    if (!limit) f[pos][s]=res;
    return res;
}
int cal(int x){
    int cnt=0;
    while (x){
        digit[cnt++]=x%10;
        x/=10;
    }
    return dp(cnt-1,0,1);
}
int main()
{
    int T;
    cin>>T;
    memset(f,-1,sizeof(f));
    while (T--){
        int l,r;
        cin>>l>>r;
        cout<<cal(r)-cal(l-1)<<endl;
    }
    return 0;
}
