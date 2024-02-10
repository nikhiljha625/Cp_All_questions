#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(ll i = 0; i<n; i++){
        cin >> v[i];
    }

    ll maxm = *max_element(v.begin(), v.end());
    ll maxi=sqrt(maxm);
    vector<bool> prime(maxi+1, true);

    for(ll p =2; p*p <=maxi; p++){
        if(prime[p] == true){
            for(ll i = p*p; i<=maxi; i+=p){
                prime[i] = false;
            }
        }
    }
    set<ll> primeN;
    for(ll p = 2; p<=maxi; p++){
        if(prime[p]){
            primeN.insert(p);
        }
    }

    for(ll i = 0; i<v.size(); i++){
        ll a1=sqrt(v[i]);
        if((a1*a1)!=v[i]){
            cout << "NO" << endl;
            continue;
        }
        if(primeN.find(a1)!=primeN.end()){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}