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

void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    vector<ll> isprime(n+1,1),primes;
    isprime[1]=0;
    for(int i=2;i<=n;i++){
        if(isprime[i]){
            for(ll j=i;j*i<=n;j++){
                isprime[i*j]=0;
            }
        }
    }
    primes.pb(3);
    primes.pb(4);
    for(int i=5;i<=n;i++){
        if(isprime[i]) primes.pb(i);
    }
    ll m=primes.size();
    ll j1=0;
    while(j1<n&&v[j1]==0) j1++;
    ll i=0;
    while(i<m){
        if(n%primes[i]==0){
            ll sz=n/primes[i];
            bool flag=true;
            ll j=j1;
            while(j<n){
                if(!v[j]){
                    
                    flag=false;
                }
                j+=(sz);
            }
            if(flag){
                pyes;
                return;
            }
        }
        i++;
    }
    pno;
    
}
 
 
 
 
	 
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	solve();
	return 0;
}