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
#define pyes cout << "Yes" << "\n"
#define pno cout << "No" << "\n"
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

ll mod=998244353;

// ll fact(ll i){
//     if(i==0){
//         return 1;
        
//     }
//     return (i%mod*(fact(i-1))%mod)%mod;
// }

//*******************************************************************************************************************************************


void solve(){
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n),b(n);
    for(auto &it:a) cin>>it;
    for(auto &it:b) cin>>it;
    vector<pair<ll,ll>> v(n);
    for(int i=0;i<n;i++){
        v[i]={a[i],i};
    }

    sort(all(v));
    sort(all(b));
    map<ll,ll> mp,mp1;
    for(auto it:b) mp[it]++;
    
    ll minm=0,maxm=0;
    ll idx=-1;
    for(int i=0;i<n;i++){
        // cout<<v[i].first<<" "<<minm<<"\n";
        if(mp.lower_bound(v[i].first)!=mp.end()){
            minm++;
            ll it=mp.lower_bound(v[i].first)->first;
            mp[it]--;
            mp1[it]++;
            if(mp[it]==0) mp.erase(it);
        }
        else{
            idx=i;
            break;
        }
    }
    minm=(n-minm);

    // for(int i=0;i<n;i++){
    //     if(v[i].first>b[i]) minm++;
    // }
    for(int i=0;i<n;i++){
        if(v[n-1-i].first>b[i]) maxm++;
    }
    // cout<<minm<<" "<<maxm<<"\n";
    vector<ll> ans(n,-1);
    if(x>=minm&&x<=maxm){
        pyes;
        ll i=idx;
        x-=minm;
        while(i<n){
            ll a1=mp.begin()->first;
            mp[mp.begin()->first]--;
            if(mp[mp.begin()->first]==0) mp.erase(mp.begin()->first);
            ans[v[i].second]=a1;
            i++;
        }
        i=0;
        while(i<idx){
            if(x>0){
                auto it=mp.begin();
                if(it->first<v[i].first){
                
                    minm--;
                    // ll itr=mp.lower_bound(v[i].first)->first;
                    mp1[it->first]--;
                    // mp1[it]++;
                    if(mp1[it->first]==0) mp1.erase(it->first);
                    ans[v[i].second]=it->first;
                }
                
            }
            else{
                ans[v[i].second]=mp1.lower_bound(v[i].first)->first;
            }
            i++;
        }
        // ll c1=minm;
        //
        // ll i=0;
        // while(c1--&&i<n){
        //     ans[v[i].second]=b[i];
        //     i++;
        // }
        // ll j1=i;
        // x-=minm;
        // ll j=0;
        // while(x--&&i<n){
        //     ans[v[j].second]=b[i];
        //     i++;
        // }
        // while (i<n)
        // {
        //     /* code */
        //     ans[v[j1].second]=b[i];
        //     i++;
        // }
        
       if(x==0){
         for(auto it:ans) cout<<it<<" ";
        cout<<"\n";
       }
       else pno;
    }
    else pno;
    
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