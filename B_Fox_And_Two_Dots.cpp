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
vector<pair<int,int>> drn={{1,0},{-1,0},{0,1},{0,-1}};
bool isvalid(int i,int j,ll& n,ll& m){
    return i>=0&&i<n&&j>=0&&j<m;
}
bool cycle;
void dfs(int i,int j,int par,vector<vector<int>>& visited,vector<vector<int>>& v,int ip,int jp,ll& n,ll& m){
    if(visited[i][j]){
        cycle=true;
        return;
    }
    
 //   
    visited[i][j]=1;
    for(auto it:drn){
        int i1=i+it.ff;
        int j1=j+it.ss;
        
        if(isvalid(i1,j1,n,m)){
           
            if(par==-1&&v[i1][j1]==v[i][j]){

                dfs(i1,j1,v[i][j],visited,v,i,j,n,m);
            }
            else{
                 
                int a1=v[i1][j1];
                if(a1==par&&!(i1==ip&&j1==jp)&&v[i1][j1]==v[i][j]){
                   
                    dfs(i1,j1,a1,visited,v,i,j,n,m);
                }
        
    }
                
            }
        }
    
    v[i][j]=-1;
}

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int> (m));
    cycle=false;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            char c;
            cin>>c;
            v[i][j]=c-65;
        }
    }
    vector<vector<int>> visited(n,vector<int> (m));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(!visited[i][j]){
            //    cout<<i<<" *****"<<j<<"\n";
                dfs(i,j,-1,visited,v,-1,-1,n,m);
            }
            if(cycle){
            //    cout<<i<<" "<<j<<"\n";
                pyes;
                return;
            }
        }
    }
    pno;
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//	int t;
//	cin>>t;
	//while(t--){
	    solve();
//	}
	return 0;
}