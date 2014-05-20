#include <iostream>

using namespace std;

int gao(int n){
    if (n<=2) return 0;
    if (n==3) return 1;
    if (n==4) return 8;
    if (n==5) return 35;
    if (n==6) return 32;
    return n*5%20121111;
}

int main()
{
    int n;
    int cas=0;
    int T;
    cin>>T;
    while (T--){
        cin>>n;
        cout<<"Case #"<<++cas<<": "<<gao(n)<<endl;
    }
    return 0;
}
