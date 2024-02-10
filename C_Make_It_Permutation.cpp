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


void solve(){
    ll n,c,d;
    cin>>n>>c>>d;
    
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    
    sort(all(v));
    vector<ll> p;
    ll cost=0;
    p.pb(v[0]);
    for(ll i=1;i<n;i++){
        if(v[i]==v[i-1]){
            cost+=c;
        }
        else{
            p.pb(v[i]);
        }
    }

    ll m=p.size();
    // ll ans=m*c+d;
    // for(ll i=0;i<m;i++){
    //     ll rem=m-1-i,add=p[i]-(i+1);
    //     ans=min(ans,rem*c+add*d);
    // }
    // cout<<cost+ans<<"\n";


    
    ll cnt=1;
    ll i=0;
    vector<ll> ins(m+1);
    for(ll i=m-1;i>0;i--){
        if(p[i]==(p[i-1]+1)){
            ins[i]=ins[i+1];
        }
        else{
            ll len=p[i]-p[i-1]-1;
            ins[i]=ins[i+1]+(len*d);
        }
        //cout<<ins[i]<<" **";
    }
    if(p[0]!=1){
        ins[0]=ins[1]+(p[0]-2)*d;
    }
    else{
        ins[0]=ins[1];
    }
    // for(auto it:ins){
    //     cout<<it<<"\n";
    // }
    while(i<m){
        if(p[i]!=cnt){
            if(cnt==1){
                cost+=d;
                cnt++;
            }
            else{
                ll len=m-i;
                ll len2=p[i]-(cnt-1)-1;
               // cout<<len<<" **"<<ins[i]<<"\n";
                if((len*c)<=ins[i]){
                    cost+=len*c;
                    break;
                }
                else{
                //    cout<<len2*d<<"**/\n";

                    cost+=(len2*d);
                //    cout<<cost<<"\n";
                    cnt=p[i];
                }
            }
        }
        else{
            i++;
            cnt++;
        }
    }
    cost=min(n*c+d,cost);
    cout<<cost<<"\n"; 
    

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