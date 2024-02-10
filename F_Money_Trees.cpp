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

bool isposs(ll m,vector<ll>& hp,vector<ll>& fp,ll &k,ll& n){
    if(m>n) return false;
    if(m==0) return true;
    ll val=1e15;
    for(int i=0;i<n;i++){
        if(hp[i]>=m){
            ll a1=fp[i+m-1];
            if(i>0) a1-=fp[i-1];
            val=min(val,a1);
            if(val<=k) return true;
        }
    }
    return false;
}
void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> f(n),h(n);
    for(auto &it:f){
        cin>>it;
    }
    for(auto &it:h){
        cin>>it;
    }
    vector<ll> hp(n),fp(n);
    for(int i=0;i<n;i++){
        if(i==0){
            fp[i]=f[i];
        }
        else{
            fp[i]=fp[i-1]+f[i];
        }
        if(i<n-1){
            if(h[i]%h[i+1]==0){
                hp[i]=1;
            }
            else{
                hp[i]=0;
            }
        }
    }
    hp[n-1]=1;
    for(int i=n-2;i>=0;i--){
        if(hp[i]==0){
            hp[i]=1;
        }
        else{
            hp[i]=hp[i+1]+1;
        }
    }
    // cout<<hp[0]<<"**\n";
    // ll len=0;
    // for(ll i=0;i<n;i++){
    //     ll l1=hp[i];
    //     ll a1=fp[i+l1-1];
    //     if(i>0) a1-=fp[i-1];
    //     if(a1<=k){
    //         len=max(len,l1);
    //     }
    // }
    // cout<<len<<"\n";
    ll l=0,high=n;
    while(l<=high){
        ll m=(l+high)/2;
        // cout<<m<<"**\n";
        if(!isposs(m,hp,fp,k,n)){
            high=m-1;
        }
        else{
            if(!isposs(m+1,hp,fp,k,n)){
                cout<<m<<"\n";
                return;
            }
            else l=m+1;
        }
    }
    cout<<"0\n";
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