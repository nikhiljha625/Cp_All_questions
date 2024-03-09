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
    
    ll i=63;
    ll idx=62;
    while(i>=0){
        ll mask=(long long)(1LL<<i);
        // // cout<<mask<<"\n";
        // if(mask==2){
        //     cout<<m<<"--\n";
        //     cout<<(mask&m)<<"\n";
        // }
        if((mask&m)==mask){
            // cout<<"mask--"<<mask<<"\n";
            if((mask&n)==0){
                // cout<<"mask--"<<mask<<"\n";
                cout<<"-1\n";
                return;
            }
        }
        i--;
    }
    i=0;
    ll cnt=0;
    vector<ll> ans;
    ans.pb(m);
    while(i<63){
        ll mask=(long long)(1LL<<i);
        if((mask&n)==mask){
            if((mask&m)==0){
                cnt++;
                m=m+mask;
                ans.pb(m);
            }
        }
        if(mask==n) break;
        i++;
    }
    cout<<cnt<<"\n";
    reverse(all(ans));
    for(auto it:ans) cout<<it<<" ";
    cout<<"\n";
    // ll cnt=0;
    // vector<ll> ans;
    // ans.pb(n);
    // while(idx>=0){
    //     ll mask=(long long )(1LL<<idx);
    //     if(mask>n){
    //         idx--;
    //         continue;
    //     }
    //     if(mask==n){
    //         cout<<"-1\n";
    //         return;
    //     }
    //     cout<<n<<" "<<mask<<"**\n";
    //     ll a1=mask;
    //     ll a2=mask^n;
    //     cnt++;
    //     if(a1==m||a2==m){
    //         ans.pb(m);
    //         break;
    //     }
    //     else{
    //         ans.pb(a2);
    //     }
    //     n=a2;
    //     idx--;
    // }
    // cout<<cnt<<"\n";
    // for(auto it:ans) cout<<it<<" ";

    // cout<<"\n";
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