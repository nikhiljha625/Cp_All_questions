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

ll fact(ll i){
    if(i==0){
        return 1;
        
    }
    return (i%mod*(fact(i-1))%mod)%mod;
}

//*******************************************************************************************************************************************

void dfs(int i,vector<ll>& cnt,vector<ll>& val,vector<ll> adj[],ll par,vector<ll>& v){
    int c=0;
    cnt[i]=1;
    for(auto it:adj[i]){
        if(it!=par){
            dfs(it,cnt,val,adj,i,v);
            cnt[i]+=cnt[it];
            val[i]+=val[it]+(v[i]^v[it])*cnt[it];
           
        }
    }
}
void dfs1(int i,vector<ll>& cnt,vector<ll>& val,vector<ll> adj[],ll par,vector<ll>& ans,vector<ll>& v,ll& n){
    
    for(auto it:adj[i]){
        if(it!=par){
            ll v1=val[i];
            ll v2=val[it];
            val[i]-=val[it];
            val[i]-=((v[i]^v[it])*cnt[it]);
            val[it]+=val[i];
            val[it]+=((v[i]^v[it])*(n-cnt[it]));
            ans[it]=val[it];
            // val[i]-=val[it];
            // val[i]-=((v[i]^v[it])*cnt[it]);
            // val[it]+=val[i];
            // val[it]+=((v[i]^v[it])*(n-cnt[it]));
            // ans[it]=val[it];
            dfs1(it,cnt,val,adj,i,ans,v,n);
            
            // val[it]-=(val[i]+(v[i]^v[it])*(n-cnt[i]));
            val[it]-=val[i];
            val[it]-=((v[i]^v[it])*(n-cnt[it]));
            val[i]+=val[it];
            val[i]+=((v[i]^v[it])*cnt[it]);
        }
    }
}

void solve(){
    
    ll n,m;
    cin>>n>>m;
    ll val=n/m;
    n-=(val*m);
    if(n==0){
        cout<<"0\n";
        return;
    }
    // cout<<n<<"\n";
    ll g1=GCD(n,m);
    n/=g1;
    m/=g1;
    ll mask=1;
    ll i=0;
    while(mask<=m){
        ll v1=mask&m;
        if(v1){
          
            break;
        }
        i++;
        mask=mask<<1;
    }
    if((m&(m-1))==0){
        cout<<i*g1<<"\n";
    }
    else cout<<"-1\n";
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