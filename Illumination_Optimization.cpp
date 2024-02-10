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

ll power(ll a,ll p){
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
    ll m,r,n;
    cin>>m>>r>>n;
    vector<pair<ll,ll>> v(n);
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        ll le=max((ll)0,x-r);
        ll re=min(m,x+r);
        v[i]={le,re};
    }
    ll cnt=0;
    bool flag=true;
    ll prev=0;
    ll i=0;
    while(i<n){
        
        ll j=i;
        ll c1=0;
        ll temp=prev;
        while(j<n&&v[j].ff<=prev){
            c1++;
            temp=v[j].ss;
            j++;
        }
        prev=temp;
        if(c1==0){
            flag=false;
            break;
        }
        
        i=j;
        cnt+=(c1-1);
        if(prev==m){
            cnt+=(n-j);
        }
        

        // else{
        //     if(v[i].ss<=prev) cnt++;
        //     else{
        //         if(v[i].ff>prev){
        //             flag=false;
        //             break;
        //         }
        //         prev=v[i].ss;
        //     }
        //     if(i==n-1&&v[i].ss<m){
        //         flag=false;
        //         break;
        //     }
        // }
        

    }
    if(!flag) cout<<"IMPOSSIBLE\n";
    else cout<<n-cnt<<"\n";
}
	 
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	ll t;
	cin>>t;
	for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
	    solve();
	}
	return 0;
}