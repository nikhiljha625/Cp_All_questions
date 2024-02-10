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

void solve(){
    ll n,k;
    cin>>n>>k;
    ll v[n][n];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    ll cnt=0;
    ll i=0;
    ll j=n-1;
    while(i<=j){
        ll s1=0,s2=n-1;
        while(s1<n&&s2>=0){
            if(i==j&&s1>=s2) break; 
            if(v[i][s1]!=v[j][s2]) cnt++;
            
            s1++;
            s2--;
        }
     //   cout<<cnt<<"\n";
        i++;
        j--;
    }
  //  cout<<cnt<<"\n";
    ll rem=k-cnt;
    if(rem<0){
        pno;
        return;
    }
    if(rem%2==0){
        pyes;
        return;
    }
    else{
        if(n%2){
            pyes;
        }
        else{
            pno;
        }
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