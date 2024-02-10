#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(v) v.begin(),v.end()
#define ff first
#define ss second 
#define pyes cout << "Yes" << "\n"
#define pno cout << "No" << "\n"
#define rev(a) a.rbegin(),a.rend()

ll power(ll a,ll p){
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
    while(s.size()<63){
        s.pb('0');
    }
//    reverse(all(s));
    return s;
}
 ll getnum(string s){
    ll a=0;
    
    for(ll i=0;i<s.size();i++){
        a+=((s[i]-'0')*(power(2,i)));
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

bool isposs(ll a,ll b,ll c,ll m){
    ll v1=(b-m)*(b-m);
    ll v2=4*(a*c);
    if(v2>v1) return true;
    return false;
}
ll getslp(ll a,ll b,ll c,vector<ll>& slope){
    ll n=slope.size();
    ll l=0,h=n-1;
    
    while(l<=h){
        ll m=(l+h)/2;
        bool r=isposs(a,b,c,slope[m]);
       
        if(r){
            return slope[m];
        }
        else{
            if((b-slope[m])<=0){
                h=m-1;
            }
            else{
               
                l=m+1;
            }
        }
    }
    return 1e10;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll> slope(n);
    ll minm=1e10,maxm=(-1)*(1e10);
    bool neg=false;
    for(ll i=0;i<n;i++){
        cin>>slope[i];
        if(slope[i]>=0){
            minm=min(minm,slope[i]);
        }
        else{
            neg=true;
            maxm=max(maxm,slope[i]);
        }
    }
    sort(all(slope));
    
    while(m--){
        ll a,b,c;
        cin>>a>>b>>c;
        
        if((b*b)<(4*(a*c))){
            
            if(minm!=1e10){
            bool r=isposs(a,b,c,minm);
            if(r){
                pyes;
                cout<<minm<<"\n";
                continue;
            }
        }
        if(neg){
             bool r1=isposs(a,b,c,maxm);
            if(r1){
                pyes;
                cout<<maxm<<"\n";
                continue;
            }
        }
        pno;
        }
        else{
            
            ll a1=getslp(a,b,c,slope);
            if(a1!=1e10){
                pyes;
                cout<<a1<<"\n";
            }
            else{
                pno;
            }
        }
        
        
        
    }
}
 



	 
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	ll t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}