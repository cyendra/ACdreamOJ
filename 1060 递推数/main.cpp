#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const int mod[4]={240,183120,222222224,1000000007};
int MOD;
struct Matrix{
    LL a[2][2];
    void clear(){
        memset(a,0,sizeof(a));
    }
    void base1(){
        a[0][0]=3;
        a[0][1]=1;
        a[1][0]=1;
        a[1][1]=0;
    }
    void base2(){
        a[0][0]=1;
        a[0][1]=0;
        a[1][0]=0;
        a[1][1]=1;
    }
    Matrix operator*(const Matrix &b) const{
        Matrix tmp;
        tmp.clear();
        for (int i=0;i<2;i++){
            for (int j=0;j<2;j++){
                for (int k=0;k<2;k++){
                    tmp.a[i][j]+=a[i][k]*b.a[k][j];
                    tmp.a[i][j]%=MOD;
                }
            }
        }
        return tmp;
    }
    friend LL pow(Matrix&x,LL n);
};

LL pow(Matrix& x,LL n){
    Matrix res;
    res.base2();
    while (n){
        if (n&1) res=res*x;
        x=x*x;
        n>>=1;
    }
    return res.a[0][0];
}

LL solve(LL x){
    for (int i=0;i<4;i++){
        Matrix m;
        m.base1();
        MOD = mod[i];
        if (x>0){
            x=pow(m,x-1);
        }
        else x=0;
    }
    return x;
}
int main()
{
    int T;
    LL n;
    cin>>T;
    while (T--){
        cin>>n;
        cout<<solve(n)<<endl;
    }
    return 0;
}
