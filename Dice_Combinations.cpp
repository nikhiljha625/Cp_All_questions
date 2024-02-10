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
ll cntways(ll n,vector<ll>& dp){
    if(n<0) return 0;
    if(n==0) return 1;
    if(dp[n]!=-1) return dp[n];
    dp[n]=0;
    for(ll i=1;i<=6;i++){
        dp[n]=(dp[n]%mod+cntways(n-i,dp)%mod)%mod;
    }
    return dp[n]%mod;
}

void solve(){
    ll n;
    cin>>n;
    vector<ll> dp(n+1,-1);
    ll x=cntways(n,dp);
    cout<<x%mod<<"\n";
}
 



	 
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	solve();
	return 0;
}