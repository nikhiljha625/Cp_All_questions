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
ll cntways(ll i,ll x,vector<vector<ll>>& dp,vector<ll>& v){
    if(x<0) return 1e9;
    if(x==0) return 0;
    if(i<0) return 1e9;
    
    if(dp[i][x-1]!=-1) return dp[i][x-1];
    
    ll a=cntways(i,x-v[i],dp,v)+1;
    ll b=cntways(i-1,x,dp,v);
    
    dp[i][x-1]=min(a,b);
    return dp[i][x-1];
    
}
ll mincoins(ll x,vector<ll>& dp,vector<ll>& v){
    if(x<0) return 1e9;
    if(x==0) return 0;
    if(dp[x]!=-1) return dp[x];
    ll a=1e9;
    for(ll i=0;i<v.size();i++){
        a=min(a,mincoins(x-v[i],dp,v));
    }
    if(a==1e9) return dp[x]=a;
    else return dp[x]=1+a;
}
void solve(){
    ll n,x;
    cin>>n>>x;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    ll sz=1e6;
    vector<ll> dp(sz+1,-1);
 //   vector<vector<ll>> dp(n,vector<ll> (sz,-1));
    ll a=mincoins(x,dp,v);
    if(a==1e9) cout<<"-1\n";
    else cout<<a<<"\n";
}
 
 
 
 
	 
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	solve();
	return 0;
}