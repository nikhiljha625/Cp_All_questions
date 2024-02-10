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
ll mod=1e9+7;
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
 
 
 
 
ll fact(ll i){
    if(i==0){
        return 1;
        
    }
    return i*(fact(i-1));
}
 
//*******************************************************************************************************************************************

void solve(){
    ll n,p;
    cin>>n>>p;
    vector<ll> v(n);
    for(ll i=1;i<n;i++){
        v[i]=n-i;
    }
    ll curr=1;
    vector<pair<ll,ll>> ans;
    for(ll i=1;i<n;i++){
        if(curr+v[i]<=(2*n+p)){
            for(ll j=i+1;j<=n;j++){
                ans.pb({i,j});
            }
            curr+=(v[i]);
        }
        else{
            ll j=i+1;
            while(curr<=(2*n+p)&&j<=n){
                ans.pb({i,j});
                j++;
                curr++;
            }
        }
    }
    for(auto it:ans){
        cout<<it.ff<<" "<<it.ss<<"\n";
    }
    
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