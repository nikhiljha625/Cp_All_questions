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

ll mod=1e9+7;
//code for custom hashing: no collision :all will be O[1] operation

// for pairs:
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(pair<uint64_t,uint64_t> x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x.first + FIXED_RANDOM)^(splitmix64(x.second + FIXED_RANDOM) >> 1);
	}
};

// for long long:
// struct custom_hash {
//     static uint64_t splitmix64(uint64_t x) {
//         // http://xorshift.di.unimi.it/splitmix64.c
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }

//     size_t operator()(uint64_t x) const {
//         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
// };


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
    string s;
    cin>>s;
    string b;
    cin>>b;
    ll k;
    cin>>k;
    ll cnt=0;
    ll n=s.size();
    unordered_map<pair<ll,ll>,ll,custom_hash> mp;
    for(ll i=0;i<n;i++){
    //    cout<<i<<"\n";
        vector<ll> freq(26);
        ll hash=0,p=31;
        ll hash1=0,p1=29;
        ll pow1=1,pow2=1;
        for(ll j=i;j<n;j++){
            freq[s[j]-'a']++;
            hash=(hash+(s[j]-'a'+1)*pow1)%mod;
            hash1=(hash1+(s[j]-'a'+1)*pow2)%mod;
            pow1=(pow1*p)%mod;
            pow2=(pow2*p1)%mod;
            ll f=0;
            for(ll q=0;q<26;q++){

                if(freq[q]>0&&b[q]=='0'){
                    f+=freq[q];
                }
                
            }
            if(f<=k){
                
                if(!mp.count({hash,hash1})){
                    cnt++;
                    mp[{hash,hash1}]++;
                }
            }
            else break;
        }
        //cout<<i<<" "<<cnt<<"/*/\n";
    }
    cout<<cnt<<"\n";
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	// int t;
	// cin>>t;
    solve();
	// while(t--){
	    
	// }
	return 0;
}