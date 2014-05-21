#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn=410000;

struct Node;
Node *cur,*nil,*root;

struct Node{
    Node* ch[2];
    int v;
    void clear(){
        ch[0]=ch[1]=nil;
        v=0;
    }
};
Node nodePool[maxn];

Node* newNode(){
    cur->clear();
    return cur++;
}
void prepare(){
    cur=nodePool;
    nil=newNode();
    root=newNode();
}
void insert(int x){
    int bit=0;
    int s;
    Node* rt=root;
    for (int i=29;i>=0;i--){
        bit=1<<i;
        if (x&bit) s=1;
        else s=0;
        if (rt->ch[s]==nil){
            rt->ch[s]=newNode();
        }
        rt=rt->ch[s];
    }
    rt->v=x;
}
int findMax(int x){
    int bit=0;
    int s;
    Node* rt=root;
    for (int i=29;i>=0;i--){
        bit=1<<i;
        if (x&bit) s=1;
        else s=0;
        if (rt->ch[s^1]!=nil) rt=rt->ch[s^1];
        else rt=rt->ch[s];
    }
    return rt->v;
}
int findMin(int x){
    int bit=0;
    int s;
    Node* rt=root;
    for (int i=29;i>=0;i--){
        bit=1<<i;
        if (x&bit) s=1;
        else s=0;
        if (rt->ch[s]!=nil) rt=rt->ch[s];
        else rt=rt->ch[s^1];
    }
    return rt->v;
}
int n;
int main()
{
    int T;
    char s[11];
    int cmd;
    //cin>>T;
    scanf("%d",&T);
    while (T--){
        prepare();
        //cin>>n;
        scanf("%d",&n);
        for (int i=0;i<n;i++){
            //cin>>s>>cmd;
            scanf("%s%d",s,&cmd);
            if (s[0]=='i') insert(cmd);
            else if (s[2]=='i'){
                int ans=findMin(cmd)^cmd;
                //cout<<(ans^cmd)<<endl;
                printf("%d\n",ans);
            }
            else if (s[2]=='a'){
                int ans=findMax(cmd)^cmd;
                //cout<<(ans^cmd)<<endl;
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
