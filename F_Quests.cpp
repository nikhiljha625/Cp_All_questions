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


bool isposs(ll m,vector<ll>& v,ll& c,ll& d,ll& n,vector<ll>& temp){

    ll a1=d/(m+1);
    ll c1=d%(m+1);
    c1--;
    ll val=temp[m]*a1;
    if(c1>=0){
        val+=temp[c1];
    }
    
    return val>=c;
}

void solve(){
    ll n,c,d;
    cin>>n>>c>>d;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    sort(all(v),greater<int> ());
    vector<ll> temp(d+1);
    temp[0]=v[0];
    ll i=1;
    while(i<min(n,d+1)){
        temp[i]=temp[i-1]+v[i];

        i++;
    }
    
    while(i<=d){
        temp[i]=temp[i-1];
        i++;
    }


    ll sum=0;
    for(ll i=0;i<min(n,d);i++){
        sum+=v[i];
    }
    if(sum>=c){
        cout<<"Infinity\n";
        return;
    }
    if(v[0]*d<c){
        cout<<"Impossible\n";
        return;
    }
    ll a1=1e5;
    ll l=0,h=d;
    while(l<=h){
        ll m=(l+h);
        bool r=isposs(m,v,c,d,n,temp);
        
        if(!r){
            h=m-1;
        }
        else{
            bool r1=isposs(m+1,v,c,d,n,temp);
            if(!r1){
                cout<<m<<"\n";
                return;
            }
            l=m+1;
        }
    }
    cout<<"Impossible\n";
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