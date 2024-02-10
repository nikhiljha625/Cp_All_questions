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


ll nb,ns,nc,pb1,ps,pc;
ll fb,fs,fc;
ll r;

bool isposs(ll m){
   
    ll f1=m*fb;
    ll f2=m*fs;
    ll f3=m*fc;
    ll req1=max((ll)0,f1-nb);
    ll req2=max((ll)0,f2-ns);
    ll req3=max((ll)0,f3-nc);
    ll v1=req1*pb1+req2*ps+req3*pc;
    return r>=v1;
}
void solve(){
    string s;
    cin>>s;
    fb=0,fs=0,fc=0;
    
    
    cin>>nb>>ns>>nc>>pb1>>ps>>pc;
    
    cin>>r;
    for(ll i=0;i<s.size();i++){
        if(s[i]=='B') fb++;
        else if(s[i]=='S') fs++;
        else fc++;
    }
    
    ll l=0,h=1e15;
    while(l<=h){
        ll m=(l+h)/2;
        bool a1=isposs(m);
        if(!a1){
            h=m-1;
        }
        else{
            bool a2=isposs(m+1);
            if(!a2){
                cout<<m<<"\n";
                return;
            }
            else{
                l=m+1;
            }
        }

    }
}
 



	 
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	solve();
	return 0;
}