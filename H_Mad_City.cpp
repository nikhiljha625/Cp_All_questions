#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("Ofast")
#define ll long long
#define pb push_back
#define all(v) v.begin(),v.end()
#define ff first
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
// 		return splitmix64(x.first + FIXED_RANDOM)^(splitmix64(x.second + FIXED_RANDOM) >> 1);
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



ll power(int a,int p){
    if(p==0) return 1;
    ll x=power(a,p/2);
    if(p%2){
        return (ll)x*x*a;
    }
    return x*x;
}
ll GCD(ll a,ll b){
    ll minm=min(a,b);
    ll maxm=max(a,b);
    if(maxm%minm==0){
        return minm;
    }
    return GCD(minm,maxm%minm);
}
void swap(ll& a,ll& b){
    ll c=a;
    a=b;
    b=c;
}
bool cmp(pair<ll,ll>& a,pair<ll,ll>& b){
        return a.first<b.first;
}

bool isperfect(ll a){
    ll x=sqrt(a);
    if(x*x==a){
        return true;
    }
    return false;
}
string conv(ll a){
    string s;
    while(a>0){
        ll d=a%2;
        s.pb(d+'0');
        a/=2;
    }
    while(s.size()<32){
        s.pb('0');
    }
//    reverse(all(s));
    return s;
}
 ll getnum(string s){
    ll a=0;
    reverse(all(s));
    for(ll i=0;i<s.size();i++){
        a+=((s[i]-'0')*(power(10,i)));
    }
    return a;
}


ll fact(ll i){
    if(i==0){
        return 1;
        
    }
    return i*(fact(i-1));
}

//*******************************************************************************************************************************************
void dfs(int i,int p,vector<int>& visited,vector<int> adj[],ll& b,int& flag){
    
    if(visited[i]){
        // cout<<i<<"\n";
        if(flag==-1) flag=i;
        return;
    }
    // cout<<i<<"*\n";
    visited[i]=1;
    for(auto it:adj[i]){
            if(it!=p){
                dfs(it,i,visited,adj,b,flag);
                
            }
        }
}
int bfs(int st,vector<int> adj[],int dst,int m){
    vector<int> visited(m);
    queue<pair<int,int>> q;
    q.push({st,0});
    visited[st]=1;
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        if(it.first==dst) return it.second;
        for(auto itr:adj[it.first]){
            if(!visited[itr]){
                visited[itr]=1;
                q.push({itr,it.second+1});
                
            }
        }
    }
    return -1;
}
void solve(){
    ll n,a,b;
    cin>>n>>a>>b;
    vector<int> adj[n+1];
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    if(a==b){
        pno;
        return;
    }
    
    // for(int i=1;i<=n;i++){
    //     cout<<i<<" :";
    //     for(auto it:adj[i]){
    //         cout<<it<<" ";
    //     }
    //     cout<<"\n";
    // }
    vector<int> visited(n+1);
    int flag=-1;
    dfs(b,-1,visited,adj,b,flag);
    // cout<<flag<<"**\n";
    int c1=bfs(b,adj,flag,n+1);
    int c2=bfs(a,adj,flag,n+1);
    if(c1<c2) pyes;
    else pno;
    // if(flag) pyes;
    // else{
    //     flag=false;
    //     visited.resize(n+1);
    //     dfs(b,-1,visited,adj,b,flag);
    //     if(!flag) pyes;
    //     else pno;
    // }
    // while(!q.empty()){
    //     auto v=q.front();
    //     q.pop();
    //     int a1=v.first;
    //     int p1=v.second;
    //     // cout<<a1<<"**\n";
    //     if(a1==b&&p1!=-1){
    //         pyes;
    //         return;
    //     }
    //     visited[a1]=1;
    //     visited[b]=0;
    //     for(auto it:adj[a1]){
    //         if(it!=p1){
    //             if(!visited[it]) q.push({it,a1});
                
    //         }
    //     }
    // }
    // pno;
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