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
//     return (i%mod*(fact(i-1))%mod)%mod;
// }

//*******************************************************************************************************************************************

void dfs(ll st,ll t,ll par,vector<set<ll>> adj,vector<ll>& time,vector<ll>& sz_cycle,ll& flag){
    if(flag>0) return; 
    cout<<st<<"*\n";
    time[st]=t;

    for(auto i:adj[st]){
            if(i==par) continue;
            if(time[i]==-1){
                dfs(i,t+1,st,adj,time,sz_cycle,flag);
            }
            else{
                if(sz_cycle[i]!=-1){
                    flag=sz_cycle[i];
                    return;
                }
                sz_cycle[i]=time[st]-time[i]+1;
                flag=sz_cycle[i];
                return;
            }
        }
    return;
}
// ll bfs(ll st,vector<ll> adj[],vector<ll>& time,vector<ll>& sz_cycle){
//     queue<pair<ll,ll>> q;
//     q.push({st,-1});
//     ll t=1;
//     // time[st]=1;
//     while(!q.empty()){
//         auto it=q.front();
//         cout<<it.first<<"* "<<it.second<<"\n";
//         q.pop();
//         time[it.first]=t++;
//         for(auto i:adj[it.first]){
//             if(i==it.second) continue;
//             if(time[i]==-1){
//                 // time[i]=1+time[it.first];
//                 q.push({i,it.first});
//             }
//             else{
//                 if(sz_cycle[i]!=-1) return sz_cycle[i];
//                 sz_cycle[i]=time[it.first]-time[i]+1;
//                 return sz_cycle[i];
//             }
//         }
//     }
//     return -1;
// }


void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    for(auto &it:v) cin>>it;
    if(k==1){
        for(int i=1;i<=n;i++){
            if(v[i-1]!=i){
                pno;
                return;
            }
        }
        pyes;
        return;
    }
    vector<set<ll>> adj(n+1);
    for(int i=1;i<=n;i++){
        if(i==v[i-1]) continue;
        adj[i].insert(v[i-1]);
        adj[v[i-1]].insert(i);
    }
    vector<ll> time(n+1,-1);
    vector<ll> sz_cycle(n+1,-1);
    
    for(int i=1;i<=n;i++){
        if(time[i]==-1){
            ll sz=-1;
            dfs(i,1,-1,adj,time,sz_cycle,sz);
            
            // ll sz=bfs(i,adj,time,sz_cycle);
            cout<<i<<" "<<sz<<"\n";
            if(sz!=k&&sz!=-1){
                pno;
                return;
            }
        }
    }
    pyes;
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