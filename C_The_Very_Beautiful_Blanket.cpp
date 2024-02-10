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
ll findnextp(ll c){
    string s=conv(c);
    int cnt=0,idx;
    for(ll i=0;i<2;i++){
        
        if(s[i]=='1'){
            cnt++;
            s[i]='0';
        }
    }
    if(cnt!=0){
    for(ll i=2;i<64;i++){
        if(s[i]=='1'){
            s[i]='0';
        }
        else{
            s[i]='1';
            break;
        }
    }
    }
    ll n1=getnum(s);
    return n1;
}

void solve(){
    ll n,m;
    cin>>n>>m;

    ll v[n][m];
    int cnt=0;
    for(ll i=0;i<n;i+=2){
        cnt=1024*(i/2);
        for(ll j=0;j<m;j+=2){
            v[i][j]=cnt;
            if(j+1<m){
                v[i][j+1]=cnt+1;
            }
            if(i+1<n){
                v[i+1][j]=cnt+2;
            }
            if(i+1<n&&j+1<m){
                v[i+1][j+1]=cnt+3;
            }
            cnt+=4;
        }
    // //   cout<<cnt<<"*/*\n";
    //    ll a=findnextp(cnt);
    // //   cout<<a<<"**-*/\n";
    //     cnt=a;
    }
    cout<<n*m<<"\n";
   
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
//    cout<<"\n";
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