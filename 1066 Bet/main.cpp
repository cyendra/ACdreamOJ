#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    double sum,p;
    double money;
    int n;
    while (cin>>n){
        sum=0;
        for (int i=0;i<n;i++){
            cin>>p;
            sum+=1.0/p;
        }
        cin>>money;
        printf("%0.2f\n",money/sum);
    }
    return 0;
}
