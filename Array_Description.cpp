#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("Ofast")
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define ff second
#define ss second
#define pyes cout << "YES" \
                  << "\n"
#define pno cout << "NO" \
                 << "\n"
#define rev(a) a.rbegin(), a.rend()

// Important header files
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>
// #include <functional> // for less
// #include <iostream>
// using namespace __gnu_pbds;
// using namespace std;

// // Declaring ordered_set
// typedef tree<ll, null_type, less<ll>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     ordered_set;


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;


// code for custom hashing: no collision :all will be O[1] operation

// for pairs:
// struct custom_hash {
// 	static uint64_t splitmix64(uint64_t x) {
// 		// http://xorshift.di.unimi.it/splitmix64.c
// 		x += 0x9e3779b97f4a7c15;
// 		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
// 		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
// 		return x ^ (x >> 31);
// 	}

// 	size_t operator()(pair<uint64_t,uint64_t> x) const {
// 		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
// 		return splitmix64(x.second + FIXED_RANDOM)^(splitmix64(x.second + FIXED_RANDOM) >> 1);
// 	}
// };

// for long long:
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// ll power(ll a,ll p){
//     if(p==0) return 1;
//     ll x=power(a,p/2);
//     if(p%2){
//         return (ll)x*x*a;
//     }
//     return x*x;
// }
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
// void swap(ll& a,ll& b){
//     ll c=a;
//     a=b;
//     b=c;
// }
// bool cmp(pair<ll,ll>& a,pair<ll,ll>& b){
//         return a.second<b.second;
// }

// bool isperfect(ll a){
//     ll x=sqrt(a);
//     if(x*x==a){
//         return true;
//     }
//     return false;
// }
// string conv(ll a){
//     string s;
//     while(a>0){
//         ll d=a%2;
//         s.pb(d+'0');
//         a/=2;
//     }
//     while(s.size()<32){
//         s.pb('0');
//     }
// //    reverse(all(s));
//     return s;
// }
//  ll getnum(string s){
//     ll a=0;
//     reverse(all(s));
//     for(ll i=0;i<s.size();i++){
//         a+=((s[i]-'0')*(power(10,i)));
//     }
//     return a;
// }

ll mod = 1e9+7;

// ll fact(ll i){
//     if(i==0){
//         return 1;

//     }
//     return (i%mod*(fact(i-1))%mod)%mod;
// }

//*******************************************************************************************************************************************

int maxmarray(int i,int prev,int& n,int& m,vector<vector<int>>& dp,vector<int>& v){
    // cout<<i<<" "<<prev<<"\n";
    if(i>=n) return 1;
    if(v[i]>0){
        if(prev==0) return maxmarray(i+1,v[i],n,m,dp,v)%mod;
        else{
            int diff = abs(prev-v[i]);
            if(diff>1) return 0;
            else return maxmarray(i+1,v[i],n,m,dp,v)%mod;
        }
    }
    else{
        int ways=0;
        if(prev==0){
            for(int j=1;j<=m;j++){
                ways+=(maxmarray(i+1,j,n,m,dp,v))%mod;
            }
        }
        else if(prev==1){
            ways+=(maxmarray(i+1,prev+1,n,m,dp,v))%mod;
            ways+=(maxmarray(i+1,prev,n,m,dp,v))%mod;
        }
        else if(prev==m){
            ways+=(maxmarray(i+1,prev-1,n,m,dp,v))%mod;
            ways+=(maxmarray(i+1,prev,n,m,dp,v))%mod;
        }
        else{
            ways+=(maxmarray(i+1,prev-1,n,m,dp,v))%mod;
            // if(i==1) cout<<ways<<"--\n";
            ways+=(maxmarray(i+1,prev+1,n,m,dp,v))%mod;
            // if(i==1) cout<<ways<<"*--*\n";
            ways+=(maxmarray(i+1,prev,n,m,dp,v))%mod;
            // if(i==1) cout<<ways<<"-*-\n";
        }
        return dp[i][prev]=ways%mod;
    }

    
}
 
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(auto &it:v) cin>>it;
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    for(int i=1;i<=m;i++) dp[n][i]=1;
    for(int i=n-1;i>=0;i--){
        if(i==n-1){
            if(v[i]==0){
                prev=0;
                for(int j=1;j<=m;j++){
                    dp[i][prev]+=(dp[i+1][j])%mod;
                }
            }
            else{
                prev=v[i];
                dp[i][prev]=dp[i+1][prev];
            }
        }
        else{
            
        }
    }
    // int ans=maxmarray(0,0,n,m,dp,v);
    cout<<ans<<"\n";
}
 





int main()
{
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }

    return 0;
}