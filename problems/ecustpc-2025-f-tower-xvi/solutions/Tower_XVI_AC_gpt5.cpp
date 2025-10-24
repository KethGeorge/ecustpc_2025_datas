#include <bits/stdc++.h>
using namespace std;
const int MOD = 9;

// -------- 10x10矩阵基本操作 --------
struct Mat {
    int a[10][10];
    Mat(bool ident=false){
        memset(a,0,sizeof(a));
        if(ident) for(int i=0;i<10;i++) a[i][i]=1;
    }
};

Mat operator*(const Mat& A, const Mat& B){
    Mat C;
    for(int i=0;i<10;i++)
        for(int k=0;k<10;k++) if(A.a[i][k])
            for(int j=0;j<10;j++)
                C.a[i][j]=(C.a[i][j]+A.a[i][k]*B.a[k][j])%MOD;
    return C;
}
Mat operator+(const Mat& A,const Mat& B){
    Mat C;
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            C.a[i][j]=(A.a[i][j]+B.a[i][j])%MOD;
    return C;
}

// -------- 同时求 A^k 和 sum_{i=0}^{k-1}A^i --------
pair<Mat,Mat> pow_sum(Mat A,long long k){
    if(k==0) return {Mat(true), Mat()};     // (I,0)
    if(k==1) return {A, Mat(true)};         // (A,I)
    if(k%2==0){
        auto [P,S]=pow_sum(A,k/2);
        Mat P2 = P*P;
        Mat S2 = S + P*S;
        return {P2,S2};
    }else{
        auto [P,S]=pow_sum(A,k-1);
        Mat Pn = P*A;
        Mat Sn = S + P;
        return {Pn,Sn};
    }
}

// -------- 构造转移矩阵 --------
Mat buildA(){
    Mat A;
    for(int d=0;d<=9;d++){
        int sq=d*d;
        A.a[sq%10][d]++;
        if(sq>=10) A.a[sq/10][d]++;
    }
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++) A.a[i][j]%=MOD;
    return A;
}

// -------- 主函数：求 sum_{t=0}^{m}(A^t * v0) --------
int solve(long long n,long long m){
    Mat A = buildA();
    auto [P,S] = pow_sum(A, m+1);  // 得到 A^{m+1}, S_{m+1}=I+A+...+A^{m}
    // 初始频次向量 v0
    int v[10]={0};
    if(n==0) v[0]=1;
    while(n>0){ v[n%10]++; n/=10; }

    // u = S * v
    int u[10]={0};
    for(int i=0;i<10;i++){
        long long sum=0;
        for(int j=0;j<10;j++) sum += 1LL*S.a[i][j]*v[j];
        u[i]=sum%MOD;
    }

    long long ans=0;
    for(int d=0;d<10;d++) ans += 1LL*d*u[d];
    return ans%MOD;
}

// -------- main --------
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        long long n,m;
        cin >> n >> m;
        cout << solve(n,m) << "\n";
    }
    return 0;
}
