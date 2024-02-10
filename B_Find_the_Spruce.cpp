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
    while(s.size()<32){
        s.pb('0');
    }
//    reverse(all(s));
    return s;
}
 ll getnum(string s){
    ll a=0;
    reverse(all(s));
    for(ll i=0;i<s.size();i++){
        a+=((s[i]-'0')*(power(10,i)));
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

ll func(ll i,ll j1,ll j2,ll n,ll m,vector<vector<char>>& v,vector<vector<ll>>& p){
    if(i>=n) return 0;
    if(j1<0||j2>=m) return 0;
    
    ll len=p[i][j2];

//    cout<<i<<" "<<j1<<" "<<j2<<"\n";
    if(j1>0) len-=p[i][j1-1];
    ll x;
    if(len==(j2-j1+1)) return 1+func(i+1,j1-1,j2+1,n,m,v,p);
    else return 0;
    
}
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<char>> v(n,vector<char> (m));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    vector<vector<ll>> p(n,vector<ll> (m));
    
    for(ll i=0;i<n;i++){
        p[i][0]=(v[i][0]=='*'?1:0);
        for(ll j=1;j<m;j++){
            if(v[i][j]=='*') p[i][j]=1+p[i][j-1];
            else p[i][j]=p[i][j-1];
        }
    }

    ll ans=0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(v[i][j]=='*'){
                ans+=func(i,j,j,n,m,v,p);
            }
        }
    }
    cout<<ans<<"\n";
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