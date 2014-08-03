#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn=5111111;
int a[maxn];
int n;
int partition(int A[],int p,int r) {
    int x = A[r];
    int i = p-1;
    for (int j=p;j<r;j++) {
        if (A[j] >= x) {
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}
int randomizedPartition(int A[],int p,int r) {
    int i = rand() % (r-p+1) + p;
    swap(A[r],A[i]);
    return partition(A,p,r);
}
int randomizedSelect(int A[],int p,int r,int i) {
    if (p==r) return A[p];
    int q = randomizedPartition(A,p,r);
    int k = q-p+1;
    if (i==k) return A[q];
    else if (i<k) return randomizedSelect(A,p,q-1,i);
    else return randomizedSelect(A,q+1,r,i-k);
}

int main()
{
    int k;
    while (~scanf("%d%d",&n,&k))
    {
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        int ans=randomizedSelect(a,1,n,k);
        printf("%d\n",ans);
    }
    return 0;
}
