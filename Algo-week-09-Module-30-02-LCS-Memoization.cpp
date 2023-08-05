#include<bits/stdc++.h>
using namespace std;
const int N = 3003;
/*
-state:LCS(i,j)  -> Length of longest  common subsequence
                    between string s[i....n] and t[j...m]

-recurance :LCS(i,j) = 1 + LCS(i+1,j+1) if s[i] == t[j]
                      else max{LCS(i+1,j),LCS(i,j+1)}

- base:
LCS(i,m) = 0
-LCS(n,j) = 0                                          

*/
int n,m;
int dp[N][N];
string s,t;
int LCS(int i,int j)
{
    //base case:
    if(i==n || j==m) return 0;
    //2.if result is already calculated return it
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    //3.calculate result from smaller sub--problem
    if(s[i] == t[j])
    {
        int ans = 1 + LCS(i+1,j+1);
        dp[i][j] = ans;
        return ans;
    }

    int ans = max(LCS(i+1,j),LCS(i,j+1));
    dp[i][j] = ans;
    return ans;

}
int main()
{
   
    cin>>s>>t;
     n = s.size();
     m = t.size();
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            dp[i][j]= -1;
        }
    }
    cout<<LCS(0,0)<<endl;//0,0 bolte ist and 2nd string er modde(0 teke n tomo character er modde) LCM koto ?

    return 0;
}
/*
axyb
abyxb

=>axb  (3)

ayc
aby

=>ay(2)


aaaaa
aaaaa

out:5
*/