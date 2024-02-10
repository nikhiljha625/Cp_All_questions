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
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    ll sum=0,i=0,st=0;
    vector<pair<int,int>> ans;
    ll curr_sum=0;
    while (i<n)
    {
        sum=v[i];
        if(sum==0){
            ll j=i;
            while(j<n&&v[j]==0){
                j++;
            }   
            ans.pb({i,j-1});
            i=j;
            
        }
        else{
            ll len=0;
            ll j=i+1;
            while(j<n&&v[j]==0){
                j++;
                len++;
            }
            if(j==n){
                cout<<"-1\n";
                return;

            }
            if(v[j]==sum&&len%2){
                ans.pb({i,i});
                ans.pb({i+1,j});
            }
            else if(v[j]==sum&&len%2==0){
                
                ans.pb({i,j});
                
            }
            if(v[j]+sum==0&&len%2){
                ans.pb({i,j});
            }
            else if(v[j]+sum==0&&len%2==0){
                
                ans.pb({i,i+len});
                ans.pb({j,j});
            }
            sum=0;
            i=j+1;
        }
    }
    if(sum!=-0){
        cout<<"-1\n";
    }
    else{
        cout<<ans.size()<<"\n";
        for(auto i:ans){
            cout<<i.first+1<<" "<<i.second+1<<"\n";
        }
        
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