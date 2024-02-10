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

ll fact(ll i){
    if(i==0){
        return 1;
        
    }
    return (i%mod*(fact(i-1))%mod)%mod;
}

//*******************************************************************************************************************************************

ll findmax(vector<vector<ll>>& pre,ll l,ll& n,ll i){
    ll low=l,h=n-1;
    // if(l!=0) return -500;
    
    while(low<=h){
        ll m=(low+h)/2;
        ll len=m-l+1;
        ll val=pre[m][i];
        // cout<<m<<"*\n";
        if(l>0) val-=pre[l-1][i];
        // cout<<val<<" "<<len<<"**\n";
        if(val==len){
            if(m==n-1){
                return m;
            }
            else{
                ll val2=pre[m+1][i];
                if(l>0) val2-=pre[l-1][i];
                // cout<<val2<<"*-*-\n";
                if(val2!=(len+1)) return m;
                else low=m+1;
            }
        }
        else{
            h=m-1;
        }
    }
    
    return h;
}
void solve(){
    
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(auto &it:v){
        cin>>it;
    }
    vector<vector<ll>> pre(n,vector<ll> (64));
    for(int i=62;i>=0;i--){
        ll q=1;
        ll mask=q<<i;
        for(int j=0;j<n;j++){
            ll s1=v[j]&mask;
            if(s1==0){
                if(j==0){
                    pre[j][i]=0;
                }
                else{
                    pre[j][i]=pre[j-1][i];
                }
            }
            else{
                if(j==0){
                    pre[j][i]=1;
                }
                else{
                    pre[j][i]=pre[j-1][i]+1;
                }
            }
        }
    }
   
    ll q;
    cin>>q;
    while(q--){
        ll l,x;
        cin>>l>>x;
        ll ans=-2;
        ll a1=0,idx=-2;
        vector<pair<ll,ll>> temp;
        for(ll i=62;i>=0;i--){
            ll q=1;
            ll mask=(q<<i);
            // cout<<mask<<"** "<<i<<"\n";
            ll s1=v[l-1]&mask;
            if(s1==0) continue;
            // cout<<mask<<"**"<<l<<"**\n";
            ll r=findmax(pre,l-1,n,i);
            // cout<<r<<" "<<l<<"\n";
            if(mask>=x){
                ans=max(ans,r);
            }
            else{
                temp.pb({r,mask});
            }
            // cout<<ans<<" "<<r<<" "<<l<<"\n";
        }
        sort(all(temp),greater<pair<ll,ll>>());
        ll val=0;
        for(int i=0;i<temp.size();i++){
            val+=temp[i].second;
            if(val>=x){
                idx=temp[i].first;
                break;
            }
        }
        ans=max(ans,idx);
        cout<<ans+1<<" ";
        // if(ans!=-2){
        //     cout<<ans+1<<" ";
        // }
        // else if(a1>=x){
        //     cout<<idx+1<<" ";
        // }
        // else cout<<"-1 ";
        
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