#include <bits/stdc++.h>
using namespace std;
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

void solve(){
    ll n;
    cin>>n;
    vector<ll> a1(n),a2(n),pmin(n),smax(n);
    for(ll i=0;i<n;i++){
        cin>>a1[i];
    }
    for(ll i=0;i<n;i++){
        cin>>a2[i];
    }
    ll i=0,j=n-1;
    while(i<=j){
        bool f1=false,f2=false;
        if(a1[i]==a2[i]){
            f1=true;
            i++;
        }
        if(a1[j]==a2[j]){
            
            f2=true;
            j--;
        }
        if(!f1&&!f2) break;
        
    }
    i--;
    
    j++;
    while(i>=0||j<n){
        
        if(i>=0&&a2[i]<=a2[i+1]) i--;
        
        else if(j<n&&a2[j]>=a2[j-1]){
            
            j++;
        }
        else break;
    }
    cout<<i+2<<" "<<j<<"\n";
    // ll l=i,r=j;
    // pmin[j]=a1[j];
    // j--;
    // while(j>=0){
    //     pmin[j]=min(pmin[j+1],a1[j]);
    //     j--;
    // }
    // smax[i]=a1[i];
    // i++;
    // while(i<n){
    //     smax[i]=max(smax[i-1],a1[i]);
    //     i++;
    // }
    // while(l>=0||r<n){
    //     if(l>=0){
    //         if(a2[])
    //     }
    // }
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