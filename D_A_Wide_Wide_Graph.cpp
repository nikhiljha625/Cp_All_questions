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

ll power(ll a,ll p){
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

void dfs(int i,int d,vector<bool>& visited,int& u,vector<int> adj[],int& maxm){
    if(visited[i]) return;
    visited[i]=1;
    if(d>maxm){
        maxm=d;
        u=i;
    }
    for(auto it:adj[i]){
        dfs(it,1+d,visited,u,adj,maxm);
    }
}
void bfs(int i,vector<ll>& dis1,vector<int> adj[]){
    int n=dis1.size();
    queue<pair<int,int>> q;
    vector<bool> visit(n);
    visit[i]=true;
    q.push({i,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int n1=it.first;
        int d=it.second;
        dis1[n1]=d;
        for(auto itr:adj[n1]){
            if(!visit[itr]){
                visit[itr]=1;
                q.push({itr,1+d});
            }
        }
    }
}

void solve(){
    ll n;
    cin>>n;
    vector<int> adj[n+1];
    int temp=n;
    while(temp--){
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    vector<bool> visited(n+1);
    int u=1;
    int maxm=0;
    dfs(1,0,visited,u,adj,maxm);
    
    int v=u;
    visited.clear();
    visited.resize(n+1);
    int m1=0;
    dfs(u,0,visited,v,adj,m1);
    vector<ll> dis1(n+1),dis2(n+1);
    
    bfs(u,dis1,adj);
    bfs(v,dis2,adj);
    
    vector<ll> dis(n+1);
    for(ll i=1;i<=n;i++){
        dis[i]=max(dis1[i],dis2[i]);
    }
    sort(all(dis));
    for(ll k=1;k<=n;k++){
        auto it=lower_bound(all(dis),k)-dis.begin()-1;
        if(it==n) cout<<it<<" ";
        else cout<<it+1<<" ";
      
    }


}
 



	 
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	solve();
	return 0;
}