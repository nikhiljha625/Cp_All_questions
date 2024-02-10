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

void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    if(n==1){
        cout<<v[0]<<"\n";
        return;
    }
    vector<ll> ans(n);
    if(v[0]==n){
        int idx;
        for(int i=1;i<n;i++){
            if(v[i]==(n-1)){
                idx=i;
                break;
            }
        }
        if(idx==1){
            for(int i=1;i<n;i++) ans[i-1]=v[i];
            ans[n-1]=v[0];
        }
        else if(idx==n-1){
            ans[0]=v[idx];
            for(int i=0;i<n-1;i++){
                ans[i+1]=v[i];
            }
        }
        else{
            ll j=0;
            for(int i=idx;i<n;i++){
                ans[j++]=v[i];
            }
            if(idx-1>=0&&j<n){
                ans[j++]=v[idx-1];
            }
            for(int i=0;i<idx-1;i++){
                if(j<n){
                    ans[j++]=v[i];
                }
                
            }
        }

    }
    else{
        int idx;
        for(int i=0;i<n;i++){
            if(v[i]==n){
                idx=i;
                break;
            }
        }
        if(idx==n-1){
            while(idx>=0&&v[idx]>=v[0]) idx--;
            int j=0;
            for(int i=n-1;i>idx;i--){
                if(j<n){
                    ans[j++]=v[i];
                }
            }
            int i=0;
            while(j<n&&i<=idx){
                ans[j++]=v[i++];
            }
        }
        else{
            int j=0;
            for(int i=idx;i<n;i++){
                if(j<n){
                    ans[j++]=v[i];
                }
            }
            if(idx-1>=0&&j<n){
                ans[j++]=v[idx-1];
            }
            int k=idx-2;
            while(k>=0&&v[k]>=v[0]){
                k--;
            }
        //    cout<<k<<"\n";
            for(int i=idx-2;i>k;i--){
                if(j<n){
                    ans[j++]=v[i];
                }
            }
            int i=0;
            while(j<n&&i<=k) ans[j++]=v[i++];
        }
    }
    for(auto it:ans) cout<<it<<" ";
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