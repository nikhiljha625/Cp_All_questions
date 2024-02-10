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

ll mod=998244353;

// ll fact(ll i){
//     if(i==0){
//         return 1;
        
//     }
//     return (i%mod*(fact(i-1))%mod)%mod;
// }

//*******************************************************************************************************************************************

pair<ll,ll> OtherEnd(int i,vector<ll> adj[],ll& n,unordered_map<ll,ll,custom_hash>& mp){
    
    // return {-1,-1};
    vector<ll> visited(n+1);
    queue<pair<ll,ll>> q;
    ll dis=-1,idx;
    q.push({i,0});
    visited[i]=1;
    
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        // cout<<it.first<<"**\n";
        if(mp.count(it.first)){
            
            if(dis<it.second){
                idx=it.first;
                // cout<<it.first<<"----\n";
                dis=it.second;
            }
        }
        for(auto itr:adj[it.first]){
            if(!visited[itr]){
                visited[itr]=1;
                q.push({itr,it.second+1});
            }
        }
        
    }
    return {idx,dis};
}
void solve(){
    
    ll n,k;
    cin>>n>>k;
    vector<ll> lablledIndices(k);
    for(auto &it:lablledIndices) cin>>it;
    unordered_map<ll,ll,custom_hash> mp;
    for(auto it:lablledIndices) mp[it]++;
    vector<ll> adj[n+1];
    ll edges=n-1;
    while(edges--){
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    if(k==1){
        cout<<"0\n";
        return;
    }
    // for(int i=1;i<=n;i++){
    //     cout<<adj[i].size()<<" ";
    //     for(auto it:adj[i]){
    //         cout<<it<<" ";
    //     }
    //     cout<<"\n";
    // }
    auto it=OtherEnd(lablledIndices[0],adj,n,mp);
    // cout<<it.first<<"-*-\n";
    auto ans=OtherEnd(it.first,adj,n,mp);
    ll a1=ans.second;
    ll c1=a1/2;
    if(a1%2){
        c1++;
    }
    cout<<c1<<"\n";    
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