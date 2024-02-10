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



// ll power(int a,int p){
//     if(p==0) return 1;
//     ll x=power(a,p/2);
//     if(p%2){
//         return (ll)x*x*a;
//     }
//     return x*x;
// }
// ll GCD(ll a,ll b){
//     ll minm=min(a,b);
//     ll maxm=max(a,b);
//     if(maxm%minm==0){
//         return minm;
//     }
//     return GCD(minm,maxm%minm);
// }
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


// ll fact(ll i){
//     if(i==0){
//         return 1;
        
//     }
//     return i*(fact(i-1));
// }

//*******************************************************************************************************************************************


void solve(){
    
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    for(auto &it:v){
        cin>>it;
    }
    vector<ll> top(k+1,-1),left(k+1,-1),rt(k+1,-1),dn(k+1,-1);
    map<ll,ll> mp;
    ll prev=-1;
    for(int i=0;i<n;i++){
        if(top[v[i]]==-1){
            auto it=mp.upper_bound(v[i]);
            if(it==mp.end()){
                top[v[i]]=i;
                left[v[i]]=i;
            }
            else{
                top[v[i]]=it->second;
                left[v[i]]=it->second;
            }
            if(v[i]>prev){
                mp[v[i]]=i;
                prev=v[i];
            }
        }
    }

    mp.clear();
    prev=-1;
    for(int i=n-1;i>=0;i--){
        if(dn[v[i]]==-1){
            auto it=mp.upper_bound(v[i]);
            if(it==mp.end()){
                dn[v[i]]=i;
                rt[v[i]]=i;
            }
            else{
                dn[v[i]]=it->second;
                rt[v[i]]=it->second;
            }
            if(v[i]>prev){
                mp[v[i]]=i;
                prev=v[i];
            }
        }
    }
    vector<ll> ans(k+1);
    for(ll i=1;i<=k;i++){
        if(top[i]==-1) ans[i]=0;
        else{
            ll len=dn[i]-top[i]+1;
            ll brd=rt[i]-left[i]+1;
            ans[i]=len+brd;
        }
    }
    for(int i=1;i<=k;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";

   
}


int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
    cin>>t;
    while(t--){
        solve();
    }
	
	return 0;
}