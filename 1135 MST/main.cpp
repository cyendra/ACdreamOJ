#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxm=111111;
typedef pair<int,int> PII;
int n,m;
struct EDGES {
    int x,y;
    PII w;
    bool operator<(const EDGES& rhs) const {
        return w<rhs.w;
    }
} a[maxm];

int pa[maxm];
void makeset(int n) {
    for (int i=0; i<=n; i++) pa[i]=i;
}
int findset(int x) {
    if (x!=pa[x]) pa[x]=findset(pa[x]);
    return pa[x];
}
void unionset(int x,int y) {
    x=findset(x);
    y=findset(y);
    if (x!=y) pa[x]=y;
}

int main() {
    while (~scanf("%d%d",&n,&m)) {
        makeset(n);
        for (int i=0; i<m; i++) {
            int x,y,l,c;
            scanf("%d%d%d%d",&x,&y,&l,&c);
            a[i].x=x;
            a[i].y=y;
            a[i].w=make_pair(l,c);
        }
        sort(a,a+m);
        int len=0,cost=0;
        int cnt=0;
        for (int i=0; i<m; i++) {
            if (findset(a[i].x)==findset(a[i].y)) continue;
            unionset(a[i].x,a[i].y);
            len+=a[i].w.first;
            cost+=a[i].w.second;
            cnt++;
        }
        if (cnt!=n-1) printf("-1 -1\n");
        else printf("%d %d\n",len,cost);
    }
    return 0;
}
