#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=11111;
char s[maxn];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--){
        scanf("%s",s);
        int ans=0;
        int cnt=0;
        int len=strlen(s);
        for (int i=0;i<len;i++){
            if (s[i]=='A') ans=max(ans,++cnt);
            else cnt=0;
        }
        for (int i=0;i<=ans;i++) s[i]='A';
        s[ans+1]=0;
        printf("%s\n",s);
    }
    return 0;
}
