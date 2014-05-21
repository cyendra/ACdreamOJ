#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn=55;
const int dir[4][2]={ {1,0},{0,1},{-1,0},{0,-1} };
int n,m;

char s[maxn][maxn];
int a[maxn][maxn];
int b[maxn][maxn];
int zero[maxn][maxn]={};
int num;
struct Point{
    int x,y;
    Point(){}
    Point(int a,int b){x=a;y=b;}
};
bool check(int x,int y){
    queue<Point>que;
    que.push(Point(x,y));
    b[x][y]=0;
    while (!que.empty()){
        Point t=que.front();
        que.pop();
        for (int i=0;i<4;i++){
            int dx=t.x+dir[i][0];
            int dy=t.y+dir[i][1];
            if (b[dx][dy]){
                que.push(Point(dx,dy));
                b[dx][dy]=0;
            }
        }
    }
    if (memcmp(zero,b,sizeof(b))) return false;
    return true;
}

int solve(){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (a[i][j]){
                memcpy(b,a,sizeof(a));
                b[i][j]=0;
                int x,y;
                for (int d=0;d<4;d++){
                    x=i+dir[d][0];
                    y=j+dir[d][1];
                    if (b[x][y]) break;
                }
                if (!check(x,y)) return 1;
            }
        }
    }
    return 2;
}
int main()
{
    while (cin>>n>>m){
        for (int i=1;i<=n;i++) cin>>(s[i]+1);
        memset(a,0,sizeof(a));
        num=0;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                if (s[i][j]=='#'){
                    a[i][j]=1;
                    num++;
                }
            }
        }
        if (num<=2) cout<<-1<<endl;
        else cout<<solve()<<endl;
    }
    return 0;
}
