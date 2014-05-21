#include <iostream>

using namespace std;
const int maxn=51111;
const int lim=44723;
int f[maxn];
void prepare(){
    f[0]=1;
    f[1]=2;
    for (int i=2;f[i-1]<2000000000;i++){
        f[i]=f[i-1]+2*(i-1);
    }
}
int main()
{
    prepare();
    int T,x;
    cin>>T;
    while (T--){
        cin>>x;
        if (x==0) cout<<1<<endl;
        else cout<<lower_bound(f,f+lim,x)-f<<endl;
    }
    return 0;
}
