#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn=100005;
vector<int>fac[maxn];
vector< pair<int,int> >pos[maxn];
int cnt[maxn];
int ans[maxn];
int num[maxn];
int n,m;

void init(){
    for (int i=0;i<maxn;i++){
        pos[i].clear();
        cnt[i]=0;
        ans[i]=-1;
    }
}
int solve(int x){
    int res=0;
    for (int i=0;i<fac[x].size();i++){
        res+=cnt[fac[x][i]];// 能整除x的数的个数
    }
    return res;
}
int main()
{
    for (int i=1;i<maxn;i++) fac[i].clear();
    for (int i=1;i<maxn;i++){
        for (int j=i;j<maxn;j+=i){
            fac[j].push_back(i);// i是j的因子
        }
    }
    //while (cin>>n){
    while (~scanf("%d",&n)){
        init();
        for (int i=1;i<=n;i++) scanf("%d",&num[i]); //cin>>num[i];
        //cin>>m;
        scanf("%d",&m);
        for (int i=0;i<m;i++){
            int l,r,x;
            //cin>>l>>r>>x;
            scanf("%d%d%d",&l,&r,&x);
            pos[l-1].push_back(make_pair(x,i));
            pos[r].push_back(make_pair(x,i));
        }
        for (int i=0;i<=n;i++){
            cnt[num[i]]++;
            for (int j=0;j<pos[i].size();j++){
                int x=pos[i][j].first;
                int idx=pos[i][j].second;
                int c=solve(x);
                if (ans[idx]==-1) ans[idx]=c;
                else ans[idx]=c-ans[idx];
            }
        }
        for (int i=0;i<m;i++) printf("%d\n",ans[i]); //cout<<ans[i]<<endl;
    }
    return 0;
}
