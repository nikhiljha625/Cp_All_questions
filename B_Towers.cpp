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
ll mod=1e9+7;
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
 
 
 
 
ll fact(ll i){
    if(i==0){
        return 1;
        
    }
    return i*(fact(i-1));
}
 
//*******************************************************************************************************************************************

void solve(){
    ll n,k;
    cin>>n>>k;
    
    vector<pair<ll,ll>> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i].first;
        v[i].second=i;
    }
    sort(all(v));
    vector<pair<ll,ll>> ans;
    
        ll i=0,j=n-1;
        while(k>0&&i<=j){
            if(i+1<n&&v[i].ff>v[i+1].ff) i++;
            if(j>0&&v[j].ff<v[j-1].ff) j--;
            ll d1=v[j].ff-v[i].ff;
            if(d1<=1) break;
            else{
//              cout<<i<<" **"<<j<<"\n";
                ans.pb({v[j].ss,v[i].ss});
                k--;
                v[i].ff++;
                v[j].ff--;
            //    cout<<v[i].ff<<"  */*/"<<v[j].ff<<"\n";
            }
        }
     //   cout<<i<<" "<<j<<"\n";
        if(i+1<n&&v[i].ff>v[i+1].ff) i++;
        if(j>0&&v[j]<v[j-1]) j--;
     //   cout<<i<<" "<<j<<"\n";
        if(i>=j){
            cout<<"0 ";
        }
        else{
            cout<<v[j].ff-v[i].ff<<" ";
        }
        cout<<ans.size()<<"\n";
        for(auto it:ans){
            cout<<it.ff+1<<" "<<it.ss+1<<"\n";
        }
    
    
}
 
 
 
 
	 
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	solve();
	return 0;
}