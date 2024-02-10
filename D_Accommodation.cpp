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


void solve(){
    ll n,m;
    cin>>n>>m;
    vector<string> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    vector<ll> total(n);
    for(ll i=0;i<n;i++){
        for(auto it: v[i]){
            if(it=='1') total[i]++;
        }
        
    }
    ll minm=0,maxm=0;
    ll req2=m/4;
    for(ll i=0;i<n;i++){
        ll c1=0,c2=0,j=0;
        while(j<m){
            if(v[i][j]=='1'){
                
                if(c1<req2){
                    if(j+1<m&&v[i][j+1]=='1'){
                        c1++;
                        j+=2;
                    }
                    else{
                        j++;
                    }
                }
                else{
                    j++;
                }
            }
            else{
                j++;
            }
        }
        
       minm+=(total[i]-c1);
        j=0;
        while(j<m){
            if(v[i][j]=='1'&&j+1<m&&v[i][j+1]=='0'){
                if(c2<req2){
                    c2++;
                    j+=2;
                }
                else{
                    j++;
                }
                
            }
            else if(v[i][j]=='0'&&j+1<m){
                if(c2<req2){
                    c2++;
                    j+=2;
                }
                else{
                    j++;
                }
            }
            else{
                j++;
            }
        }
        c2=req2-c2;
        maxm+=(total[i]-c2);
  //      cout<<total[i]<<" "<<minm<<"  1: "<<c1<<" 2: "<<c2<<"\n";
    }
    cout<<minm<<" "<<maxm<<"\n";
}
 



	 
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	solve();
	return 0;
}