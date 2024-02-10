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
bool isposs(int n,vector<ll>& s){
    ll i=0,j=s.size()-1;
    while(i<j){
        if(s[i]*s[j]==n){
            if(s[j]%s[i]==0) return false;
            return true;
        }
        else if(s[i]*s[j]>n) j--;
        else i++;
    }
    return false;
}
void solve(){
    ll n;
    cin>>n;
    vector<ll> s;
    vector<ll> isprime(n+1,1),primes;
    isprime[1]=0;
    for(int i=2;i<=n;i++){
        if(isprime[i]){
            for(ll j=i;j*i<=n;j++){
                isprime[i*j]=0;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(isprime[i]) primes.pb(i);
    }
    ll m=primes.size();
    
    for(ll i=0;i<m;i++){
        ll c=primes[i];
        ll temp=c;
        
        while(c<=n){
            s.pb(c);
            
            c=c*temp;
        }
    }
    cout<<s.size()<<"\n";
    for(auto it:s){
        cout<<it<<" ";
    }
}
 
 
 
 
	 
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	solve();
	return 0;
}