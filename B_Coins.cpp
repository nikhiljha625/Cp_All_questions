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
    if(minm==0) return maxm;
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


void solve(){
    string s;
    map<ll,ll> m;
    ll i=0;
    
    while(i<3){
        cin>>s;
        
        if(s[1]=='>'){
            m[s[0]-'A']++;
        }
        else m[s[2]-'A']++;
        i++;
    }
    if(m[0]==1&&m[1]==1&&m[2]==1){
        cout<<"Impossible\n";
        return;
    }
    
    if(m[0]==2){
        if(m[1]==1){
            cout<<"CBA\n";
        }
        else{
            cout<<"BCA\n";
        }
    }
    else if(m[1]==2){
        if(m[0]==1){
            cout<<"CAB\n";
        }
        else{
            cout<<"ACB\n";
        }
    }
    else{
        if(m[1]==1){
            cout<<"ABC\n";
        }
        else{
            cout<<"BAC\n";
        }
    }
}
 



	 
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	solve();
	return 0;
}