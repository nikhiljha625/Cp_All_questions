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


void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> des(n),sz(m);
    for(ll i=0;i<n;i++){
        cin>>des[i];
    }
    for(ll i=0;i<m;i++){
        cin>>sz[i];
    }
    ll cnt=0;
    sort(all(des));
    sort(all(sz));
    ll low=0,high=m-1;
    

    for(ll i=0;i<n;i++){
        ll f1=des[i]-k,f2=des[i]+k;
        ll l=low,h=high;
        ll idx=-1;
        while(l<=h){
            ll m=(l+h)/2;
            if(sz[m]>f2){
                h=m-1;
            }
            else if(sz[m]<f1){
                l=m+1;
            }
            else{
                if(m==low){
                    idx=m;
                    cnt++;
                    break;
                }
                if(sz[m-1]>=f1&&sz[m-1]<=f2){
                    h=m-1;
                }
                else{
                    idx=m;
                    cnt++;
                    break;
                }
            }
        }
        if(idx!=-1) low=idx+1;
  //      cout<<idx<<"\n";
    }
    cout<<cnt<<"\n";
}
 



	 
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	
    solve();

	return 0;
}