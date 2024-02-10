#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("Ofast")
#define ll long long
#define pb push_back
#define all(v) v.begin(),v.end()
#define ff second
#define ss second 
#define pyes cout << "YES" << "\n"
#define pno cout << "NO" << "\n"
#define rev(a) a.rbegin(),a.rend()

// Important header files   
#include <ext/pb_ds/assoc_container.hpp> // Common file  
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional> // for less  
#include <iostream>  
using namespace __gnu_pbds;  
using namespace std;  
  
// Declaring ordered_set 
typedef tree<ll, null_type, less<ll>, rb_tree_tag,  
            tree_order_statistics_node_update>  
    ordered_set;  
  
  

//code for custom hashing: no collision :all will be O[1] operation

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
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
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
ll GCD(ll a,ll b){
    ll minm=min(a,b);
    ll maxm=max(a,b);
    if(maxm%minm==0){
        return minm;
    }
    return GCD(minm,maxm%minm);
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

ll mod=998244353;

// ll fact(ll i){
//     if(i==0){
//         return 1;
        
//     }
//     return (i%mod*(fact(i-1))%mod)%mod;
// }

//*******************************************************************************************************************************************

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll> v(n),p(m);
    for(auto &it:v) cin>>it;
    for(auto &it:p) cin>>it;
    sort(all(v));
    sort(all(p));
    reverse(all(p));
    ll i=0,j=m-1;
    ll alt=true;
    ll i1=0,j1=n-1;
    ll ans=0;
    while(i1<=j1){
        
        ll a1=abs(v[i1]-p[i]);
        ll a2=abs(v[i1]-p[j]);
        ll m1=max(a1,a2);
        ll b1=abs(v[j1]-p[i]);
        ll b2=abs(v[j1]-p[j]);
        ll q1=max(b1,b2);
        ll maxm=max(m1,q1);
        if(maxm==m1){
            ans+=(m1);
            if(m1==a1){
                i++;
            }
            else j--;
            i1++;
        }
        else{
            ans+=(q1);
            if(q1==b1){
                i++;
            }
            else j--;
            j1--;
        }
        // ans+=(a1+a2);
        // i1++;
        // j1--;
        // i++;
        // j--;

    }
    // if(i1==j1){
    //     ll a1=abs(v[j1]-p[i]);
    //     ll a2=abs(v[j1]-p[j]);
    //     ll m1=max(a1,a2);
    //     ans+=(m1);
    // }
    cout<<ans<<"\n";
    
}


int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	ll t;
    cin>>t;
    while(t--){
        solve();
    }
	
	return 0;
}