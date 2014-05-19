#include <iostream>
#include <cstring>
using namespace std;
const int MOD=1e9+7;
typedef long long LL;
struct Matrix{
    int n,m;
    LL a[2][2];
    void clear(){
        n=m=0;
        memset(a,0,sizeof(a));
    }
    void base1(){
        n=m=2;
        a[0][0]=3;
        a[0][1]=1;
        a[1][0]=1;
        a[1][1]=0;
    }
    void base2(){
        n=1;
        m=2;
        a[0][0]=1;
        a[0][1]=0;
    }
    Matrix operator+(const Matrix &b) const{
        Matrix tmp;
        tmp.n=n;
        tmp.m=m;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                tmp.a[i][j]=a[i][j]+b.a[i][j];
                tmp.a%=MOD;
            }
        }
        return tmp;
    }
    Matrix operator*(const Matrix &b) const{
        Matrix tmp;
        tmp.clear();
        tmp.n=n;
        tmp.m=b.m;
        for (int i=0;i<n;i++){
            for (int j=0;j<b.m;j++){
                for (int k=0;k<m;k++){
                    tmp.a[i][j]+=a[i][k]*b.a[k][j];
                    tmp.a[i][j]%=MOD;
                }
            }
        }
        return tmp;
    }
};

LL modPow(Matrix x,LL n){
    if (n==0) return 1;
    LL res=modPow(x*x,n/2);
    if (n&1) res=res*x;
    return res;
}

int main()
{

    return 0;
}
