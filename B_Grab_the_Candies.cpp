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
    vector<ll> v(n);
    ll sume=0,sumo=0;
    for(ll i=0;i<n;i++){
        cin>>v[i];
        if(v[i]%2) sumo+=v[i];
        else sume+=v[i];
        
    }
    if(sume>sumo) pyes;
    else pno;
    



}

void fun(){
    set<string> s1;
    string temp;
    temp="NIKHIL";
    s1.insert(temp);
    temp="KUMAR";
    s1.insert(temp);
    temp="JHA";
    s1.insert(temp);
    set<string> s2;
    for(auto &it:s1){
        string p=it;
        p.pb(temp[0]);
        s2.insert(p);

    }
    for(auto it:s2){
        cout<<it<<"\n";
    }

}



	 
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fun();
	// int t;
	// cin>>t;
	// while(t--){
	//     solve();
	// }
	return 0;
}