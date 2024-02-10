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

void binfun(ll i,ll& n,vector<ll>& v,vector<ll>& ans,vector<ll>& psum,vector<ll>& a){
    
//    ll l=i,h=n-1;

    // while(l<=h){
    //     ll m=(l+h)/2;
    //     ll s=psum[m];
    //     if(i>0){
    //         s-=psum[i-1];
    //     }
    //     if(s<=a[i]){
    //         l=m+1;
    //         if(l>h) idx=m;
    //     }
    //     else{
    //         if(m==i){
    //             break;
    //         }
    //         int s1=psum[m-1];
    //         if(i>0){
    //             s1-=psum[i-1];
    //         }
    //         if(s1<=a[i]){
    //             idx=m-1;
    //             break;
    //         }
    //         else{
    //             h=m-1;
    //         }
    //     }
    // }
    ll ch=a[i];
    if(i>0) ch+=psum[i-1];
    ll idx=upper_bound(all(psum),ch)-psum.begin();
    if(idx>0) v[idx-1]++;
    if(i>0) v[i-1]--;

    if(idx<n){
        ll s1=0;
        if(idx>0) s1+=psum[idx-1];
        if(i>0) s1-=psum[i-1];
        ll curr=a[i]-s1;
        ans[idx]+=curr;
    }
    // v[idx]++;
    // if(i>0) v[i-1]--;
    // if(idx+1<n){
    //     ll curr=psum[idx];
    //     if(i>0) curr-=psum[i-1];
    //     ll y=a[i]-curr;
        
    //     ans[idx+1]+=y;
    // }
    
}

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> psum(n),v(n),ans(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll i=0;i<n;i++){
        cin>>b[i];
        if(i==0){
            psum[0]=b[0];
        }
        else{
            psum[i]=psum[i-1]+b[i];
        }
    }
    for(ll i=n-1;i>=0;i--){
        binfun(i,n,v,ans,psum,a);
    }
    for(ll i=n-2;i>=0;i--){
        v[i]+=v[i+1];
    }
    for(ll i=0;i<n;i++){
        ans[i]+=(v[i]*b[i]);
    }
    for(auto &x: ans){
        cout<<x<<" ";
    }
    cout<<"\n";
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