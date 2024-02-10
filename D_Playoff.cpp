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




 



	 
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int n;
	cin>>n;
    string s;
    cin>>s;
    ll cnt1=0;
    for(ll i=0;i<n;i++){
        if(s[i]=='1') cnt1++;
    }
	ll total=power(2,n);
    ll temp=cnt1;
    pair<ll,ll> ans{0,0};
    for(ll i=1;i<total;i++){
        ll left=i-1;
        ll j=0;
        if(left<cnt1) continue;
  //      cout<<i<<"*\n";
        while(j<n){
            if(left<cnt1) break;
            if(s[j]=='1'){
                left--;
                left/=2;
                cnt1--;
            }
            
            j++;
        }
        if(left>=cnt1){
            ans.first=i;
            break;
        }
        cnt1=temp;
    }
    cnt1=n-temp;
    for(ll i=total;i>=1;i--){
        ll rt=total-i;;
        ll j=n-1;
        if(rt<cnt1) continue;
        
        while(j>=0){
            if(rt<cnt1) break;
            if(s[j]=='0'){
                rt--;
                rt/=2;
                cnt1--;
            }
            j--;
        }
        if(rt>=cnt1){
            ans.second=i;
            break;
        }
        cnt1=n-temp;

    }
    if(ans.first==0) cout<<ans.second<<"\n";
    else if(ans.second==0) cout<<ans.first<<"\n";
    else{
        for(ll i=ans.first;i<=ans.second;i++){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
	return 0;
    
}