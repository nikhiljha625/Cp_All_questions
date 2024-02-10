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
ll mod;
ll power(ll a,ll p){
    if(p==0) return 1;
    ll x=power(a,p/2);
    if(p%2){
        return ((x%mod*x%mod)%mod*a%mod)%mod;
    }
    return (x%mod*x%mod)%mod;
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
 
 
 
 
ll fact(ll i){
    if(i==0){
        return 1;
        
    }
    return i*(fact(i-1));
}
 
//*******************************************************************************************************************************************

void solve(){
    ll n,m;
    cin>>n>>m;
    mod=m;
    ll v1=power(3,n);
    if(v1%m==0) cout<<m-1<<"\n";
    else{
        cout<<(v1-1)%m<<"\n";
    }
    
}
 
 
 
 
	 
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	solve();
	return 0;
}