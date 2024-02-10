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

ll isposs(int k,vector<ll>& temp,vector<ll>& v,ll &s,ll &n){
    if(k>n) return 0;
    ll sum=0;
    for(ll i=0;i<n;i++){
        ll p=v[i]+(i+1)*k;
        temp.pb(p);
    }
    sort(all(temp));
    for(ll i=0;i<k;i++){
        sum+=temp[i];
    }
    temp.clear();
    if(sum>s) return 0;
    return sum;
}
void solve(){
    ll n,s;
    cin>>n>>s;
    vector<ll> v(n),temp;
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    ll l=0,h=n;
    while(l<=h){
        ll m=(l+h)/2;
        
        if(m==0){
            l=m+1;
            continue;
        
        }
        int r=isposs(m,temp,v,s,n);
        if(r==0){
            h=m-1;
        }
        else{
            int r1=isposs(m+1,temp,v,s,n);
            if(r1==0){
                cout<<m<<" "<<r<<"\n";
                return;
            }
            else{
                l=m+1;
            }
        }
    }
    cout<<"0 0\n";
}
 



	 
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	
    solve();

	return 0;
}