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
    ll v[2][n];
    if(n%2==0){
        ll j=2*n;
        ll i=1;
        ll idx=n-1;
        v[0][0]=j;
        j--;
        
        while(idx>0){
            if(idx%2) v[1][idx]=j;
            else v[0][idx]=j;
            j--;
            idx--;
        }
        idx=0;
        while(idx<n){
            if(idx%2) v[0][idx]=i;
            else v[1][idx]=i;
            i++;
            idx++;
        }
        // bool minm=false;
        // while(idx<n&&i<=j){
        //     if(!minm){
        //         v[idx][0]=j;
        //         j--;
        //         v[n-1-idx][1]=j;
        //         j--;
        //         minm=true;
        //         idx++;
        //     }
        //     else{
        //         v[idx][0]=i;
        //         i++;
        //         v[idx-1][1]=i;
        //         i++;
        //         idx++;
        //         minm=false;
        //     }
            
        // }
    }
    for(ll i=0;i<2;i++){
        for(ll j=0;j<n;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
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