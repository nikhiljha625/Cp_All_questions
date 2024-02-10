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
vector<pair<ll,ll>> drn{{1,0},{-1,0},{0,1},{0,-1}};
bool isvalid(int i,int j,ll& n,ll& m){
    return i>=0&&i<n&&j>=0&&j<m;
}
void dfs(ll i,ll j,vector<vector<ll>>& v,vector<vector<ll>>& visited,ll& maxm,ll& n,ll& m){
    if(visited[i][j]) return;
 //   cout<<i<<" "<<j<<"\n";
    visited[i][j]=1;
    maxm+=v[i][j];
    for(auto it:drn){
        ll i1=i+it.ff;
        ll j1=j+it.ss;
        if(isvalid(i1,j1,n,m)&&v[i1][j1]) dfs(i1,j1,v,visited,maxm,n,m);
    }

}
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> v(n,vector<ll> (m));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    vector<vector<ll>> visited(n,vector<ll> (m));
    ll ans=0;
    
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(!visited[i][j]&&v[i][j]){
                ll maxm=0;
                dfs(i,j,v,visited,maxm,n,m);
                ans=max(ans,maxm);
                
            //    cout<<maxm<<" "<<i<<" "<<j<<"\n";
            }
        }
    }
    cout<<ans<<"\n";
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