#include<bits/stdc++.h>
using namespace std;
const int N =60;
const int M = 1001;
const int MOD = 1e7;
int dp[N][M];
int coin[N],limit[N];
int main()
{
    int t,tst = 0;
    cin>>t;
    while (t--)
    {
        int n,k;cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            cin>>coin[i];
        }
        for(int i=1;i<=n;i++)
        {
            cin>>limit[i];
        }
        for(int i=0;i<=n;i++)
        { 
        for(int target = 0;target<=k;target++)
        {
            dp[i][target] = 0;
        }
        }
        //handle base case
        dp[0][0] = 1;
        for(int i=1;i<=n;i++)
        {
            for(int target=0;target<=k;target++)
            {
                dp[i][target] =dp[i-1][target];
                for(int j=1;j<=limit[i];j++)
                {
                  if(target < j*coin[i])
                  {
                   break;  
                  }
                  int ret = dp[i-1][target - j*coin[i]];
                  dp[i][target] = (dp[i][target] + ret) % MOD;
                   
                }
                
            }
        } 
        cout<<"case "<<++tst<<":"<<dp[n][k]<<endl;

    }
    return 0;
}
/*
2
3 5
1 2 5 3 2 1
4 20
1 2 3 4 8 4 2 1
*/