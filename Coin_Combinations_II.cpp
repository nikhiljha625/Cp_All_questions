#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define ff first
#define ss second
#define pyes cout << "Yes" \
                  << "\n"
#define pno cout << "No" \
                 << "\n"
#define rev(a) a.rbegin(), a.rend()
ll mod = 1e9 + 7;
ll power(int a, int p)
{
    if (p == 0)
        return 1;
    ll x = power(a, p / 2);
    if (p % 2)
    {
        return (ll)x * x * a;
    }
    return x * x;
}
ll GCD(ll a, ll b)
{
    ll minm = min(a, b);
    ll maxm = max(a, b);
    if (maxm % minm == 0)
    {
        return minm;
    }
    return GCD(minm, maxm % minm);
}
void swap(ll &a, ll &b)
{
    ll c = a;
    a = b;
    b = c;
}
bool cmp(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.first < b.first;
}

ll fact(ll i)
{
    if (i == 0)
    {
        return 1;
    }
    return i * (fact(i - 1));
}

//*******************************************************************************************************************************************
// ll cntways(ll i,ll x,vector<vector<ll>>& dp,vector<ll>& v){
//     if(x<0) return 0;
//     if(x==0) return 1;
//     if(i<0) return 0;

//     if(dp[i][x]!=-1) return dp[i][x];

//     ll a=cntways(i,x-v[i],dp,v);
//     ll b=cntways(i-1,x,dp,v);

//     dp[i][x]=(a%mod+b%mod)%mod;
//     return dp[i][x];

// }

void solve()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<ll> dp(x + 1);
    dp[0]=1;

    for(int i=0;i<n;i++){
        for(ll w=1;w<=x;w++){
            if(w>=v[i]){
                dp[w]=(dp[w]%mod+dp[w-v[i]]%mod)%mod;
            }
        }
    }
    // for(int i=0;i<=x;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    cout<<dp[x];
}

int main()
{
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}