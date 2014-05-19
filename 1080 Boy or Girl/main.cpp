#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[1111];
    while (cin>>s){
        int n=strlen(s);
        if (n&1) cout<<"CHAT WITH HER!"<<endl;
        else cout<<"IGNORE HIM!"<<endl;
    }
    return 0;
}
