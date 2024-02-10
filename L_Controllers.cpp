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




bool isposs(ll a,ll b,ll cntp,ll cntn){
    if(a*cntp==b*cntn) return true;
    if(a*cntp>b*cntn){
        int l=1,h=cntp;
        while(l<=h){
            ll m=(l+h)/2;
            ll left=cntp-m;
            if(a*m==b*(cntn-left)) return true;
            else{
                if(a*m>b*(cntn-left)) h=m-1;
                else l=m+1;
            }
        }
        return false;
    }
    else{
        int l=1,h=cntn;
        while(l<=h){
            ll m=(l+h)/2;
            ll left=cntn-m;
            if(b*m==a*(cntp-left)) return true;
            else{
                if(b*m>a*(cntp-left)) h=m-1;
                else l=m+1;
            }
        }
        return false;
    }
}

	 
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int n;
	cin>>n;
	string s;
    cin>>s;
    ll cntp=0;
    for(ll i=0;i<n;i++){
        if(s[i]=='+') cntp++;
    }
    ll cntn=n-cntp;
    ll q;
    cin>>q;
    while(q--){
        ll a,b;
        cin>>a>>b;
        if(cntn==cntp) pyes;
        else{
            if(cntp==0||cntn==0){
                pno;
                continue;
            }
            ll maxm=max(a,b);
            ll minm=min(a,b);
            bool r;
            if(cntp>cntn){
                r=isposs(minm,maxm,cntp,cntn);
            }
            else{
                r=isposs(maxm,minm,cntp,cntn);
            }
            
            if(r) pyes;
            else pno;
        }
    }
	return 0;
}