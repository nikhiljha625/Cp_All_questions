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
        return a.first>b.first;
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
    string s;
    string t;
    cin>>s>>t;
    //cout<<(char)toupper('a')<<"\n";
    unordered_map<char,ll> f1;
    unordered_map<ll,ll> f2;
    for(ll i=0;i<t.size();i++){
        f1[t[i]]++;
    }
    ll k=0,n=0;
    for(ll i=0;i<s.size();i++){
        if(f1.count(s[i])&&f1[s[i]]>0){
            f1[s[i]]--;
            f2[i]++;
            k++;
        }
        
    }
    for(ll i=0;i<s.size();i++){
        if(!f2[i]){
            char ch=toupper(s[i]);
            if(ch==s[i]){
                ch=tolower(s[i]);
            }
            if(f1[ch]>0){
                n++;
                f1[ch]--;
            }
            
        }
    }
    cout<<k<<" "<<n<<"\n";


}
 



	 
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	solve();
	return 0;
}