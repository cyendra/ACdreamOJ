#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn=55;
int n,m,T,K,B;
int cnt[maxn][maxn];
int sum[maxn][maxn];
int dis[maxn][maxn];
int f[maxn][maxn][6][6];
int dp(int t,int p,int c,int l){
    if (t>T) return 0;
    if (f[t][p][c][l]!=-1) return f[t][p][c][l];
    int res=0;
    for (int np=1;np<=n;np++){
        if (dis[p][np]!=-1){//&&t+dis[p][np]<=T
            int nt=t+dis[p][np];
            int nl=min(5,l+dis[p][np]);
            res=max(res,dp(nt,np,c,nl)+cnt[p][t]);
            if (l==5&&c<B){
                res=max(res,dp(nt,np,c+1,min(5,dis[p][np]))+sum[p][t]);
            }
        }
    }
    f[t][p][c][l]=res;
    return res;
}
int main()
{
    int TTT;
    cin>>TTT;
    while (TTT--){
        cin>>n>>m>>T>>K>>B;
        memset(f,-1,sizeof(f));
        memset(dis,-1,sizeof(dis));
        memset(sum,0,sizeof(sum));
        memset(cnt,0,sizeof(cnt));
        for (int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            dis[u][v]=dis[v][u]=w;
        }
        for (int i=1;i<=n;i++){
            dis[i][i]=1;
        }
        for (int i=1;i<=K;i++){
            int t,p,c;
            cin>>t>>p>>c;
            cnt[p][t]+=c;
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (dis[i][j]!=-1){
                    for (int k=0;k<=T;k++){
                        sum[i][k]+=cnt[j][k];
                    }
                }
            }
        }
        int ans=0;
        for (int i=1;i<=n;i++){
            ans=max(ans,dp(1,i,0,5));
        }
        cout<<ans<<endl;
    }
    return 0;
}
