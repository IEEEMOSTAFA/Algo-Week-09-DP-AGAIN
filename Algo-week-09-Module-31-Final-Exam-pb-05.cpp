//https://cses.fi/problemset/task/1745
#include<bits/stdc++.h>
using namespace std;
long long int nums[1001];
vector<set<long long int>>dp;

int main()
{
 long long  int n;cin>>n;
for(long long int  i=1;i<=n;i++)
cin>>nums[i];
dp.resize(n+1);

dp[1].insert(nums[1]);
for(long long int i=2;i<=n;i++)
{
    dp[i].insert(nums[i]);
    for(auto j : dp[i-1])
    {
        dp[i].insert(j);
        dp[i].insert(j+nums[i]);
         
    }
}
cout<<dp[n].size()<<endl;
for(auto i:dp[n])
cout<<i<<" ";
return 0;
}
/*
4
4 2 5 2

*/