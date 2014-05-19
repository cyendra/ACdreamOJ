#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    char s[11111];
    while (cin>>s){
        int len=strlen(s);
        int ans=0;
        for (int i=0;i<len;i++) {
            if (isdigit(s[i])) ans+=s[i]-'0';
        }
        cout<<ans<<endl;
    }
    return 0;
}
