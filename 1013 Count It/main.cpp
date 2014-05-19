#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
char s[1111];
int n;
int main()
{
    while (cin>>n){
        cin>>s;
        int len=strlen(s);
        int ans=0;
        for (int i=0;i<len;i++) if (s[i]=='L') ans++;
        cout<<n-strlen(s)+ans<<" "<<ans<<endl;
    }
    return 0;
}
