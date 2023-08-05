//https://cses.fi/problemset/submit/1640/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>>ar;
    for(int i = 1;i<=n;i++)
    {
        int x;cin>>x;
        ar.push_back({x,i});
    }
    sort(ar.begin(),ar.end());
    int l = 0;
    int r = n-1;
    while (1)
    {
        if(l == r) break;
        if(ar[l].first + ar[r].first == k)
        {
            cout<<ar[r].second<<" "<<ar[l].second ;
            return 0;
        }
        else if(ar[l].first + ar[r].first > k)
        {
            r--;
        }
        else if(ar[l].first + ar[r].first < k)
        {
            l++;
        }
        
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
    
}
/*
4 8
2 7 5 1

out: 2 4
*/