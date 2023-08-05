//https://cses.fi/problemset/result/6650878/
#include<bits/stdc++.h>
using namespace std;
long long int dp[1000005];
long long int num[105];
const long long int mod = 1e7;

int main()
{
    int n,k;
    cin>>n>>k;
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int i=1;i<=n;i++)cin>>num[i];
    for(int i=1;i<=k;i++)
    {
        int sum = 0;
        for(int j=1;j<=n;j++)
        {
            if(i - num[j] >= 0)
            {
            sum += dp[i-num[j]];
            }
        }
        dp[i] = sum%mod;
    }
    cout<<dp[k];
    return 0;
}
/*
3 9
2 3 5

out:8
*/