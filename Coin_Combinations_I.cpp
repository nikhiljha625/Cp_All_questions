#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
 
 
int main() {
   fast_io;
   ll t,n,m,x,i,j,k,q;
   //cin >> t;
   t = 1;
   
   while(t--)
   {
        cin >> n >> x;
        vector<int> v(n);
        for(auto &it:v) cin>>it;
        vector<ll> dp(x+1);
        dp[0]=1;
        for(ll i=1;i<=x;i++){
            for(int j=0;j<n;j++){
                if(i>=v[j]){
                    dp[i]+=(dp[i-v[j]]);
                    dp[i]=dp[i]%mod;
                }
            }
        }
        cout<<dp[x]<<"\n";
        
   }
   return 0;
}