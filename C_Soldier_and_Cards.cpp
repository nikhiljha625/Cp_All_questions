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
    ll n;
    cin>>n;
    ll k1;
    cin>>k1;
    queue<ll> f1;
    queue<ll> f2;
    vector<ll> a(k1);
    map<pair<vector<ll>,vector<ll>>,int> mp;
    for(ll i=0;i<k1;i++){
        cin>>a[i];
        f1.push(a[i]);
    } 
    ll k2;
    cin>>k2;
    vector<ll> b(k2);
    for(ll i=0;i<k2;i++){
        cin>>b[i];
        f2.push(b[i]);
    } 
    mp[{a,b}]=1;
    ll cnt=1;
    while(!f1.empty()&&!f2.empty()){
        if(cnt>1){
            vector<ll> t1,t2;
            ll sz1=f1.size();
            ll sz2=f2.size();
            ll i=0;
            while(i<sz1){
                ll x=f1.front();
                t1.pb(x);
                f1.pop();
                f1.push(x);
                i++;
            }
            i=0;
            while(i<sz2){
                ll x=f2.front();
                t2.pb(x);
                f2.pop();
                f2.push(x);
                i++;
            }
            if(mp.count({t1,t2})){
                cout<<"-1\n";
                 return;
            }
            else{
                mp[{t1,t2}]=1;
            }
            // if(t1==a&&t2==b){
            //     cout<<"-1\n";
            //     return;
            // }
        }
        ll a1=f1.front();
        f1.pop();
        ll a2=f2.front();
        f2.pop();
        
        if(a1>a2){
            f1.push(a2);
            f1.push(a1);
        }
        else{
            f2.push(a1);
            f2.push(a2);
        }
        if(f1.empty()){
            cout<<cnt<<" "<<"2\n";
        }
        if(f2.empty()){
            cout<<cnt<<" "<<"1\n";
        }

        cnt++;
    }


}



	 
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
	// int t;
	// cin>>t;
	// while(t--){
	//     solve();
	// }
	return 0;
}