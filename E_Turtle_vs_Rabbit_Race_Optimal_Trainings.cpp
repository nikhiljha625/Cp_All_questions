#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<ll> v(n+1);
        v[0]=0;
        for(int i=1;i<=n;i++){
            cin>>v[i];
        }

        vector<ll> pf(n+1);
        pf[0]=0;
        pf[1]=v[1];
        for(int i=2;i<=n;i++)
        {
            pf[i]=pf[i-1]+v[i];
        }

        ll q;
        cin>>q;

        while(q--)
        {
            int l,u;
            cin>>l>>u;
            // vector<ll> pf(n+1);
            // for(int i=0;i<=n;i++){
            //     pf[i]=pf[i];
            // }
            // for(int i=l;i<=n;i++)
            // {
            //     pf[i]=pf[i]-pf[l-1];
            // }
            // cout<<u<<"***\n";

            int idx = lower_bound(pf.begin()+l,pf.end(),u+pf[l-1])-pf.begin();
            // for(auto it:pf) cout<<it<<" ";
            // cout<<"\n";
            // cout<<idx<<"***** ";
            // cout<<idx<<" ";
            if(idx>n){
                cout<<n<<" ";
                continue;
            }
            int k1 = pf[idx]-pf[l-1];
            // cout<<k1<<"--\n";
            int s1=0;
            int s2=0;
            int u1 = u;

            if(u1>=k1){
                ll a1=(u1*(u1+1))/2;
                ll rem=u1-k1;
                ll a2=((rem)*(rem+1))/2;
                s1=(a1-a2);
            }
            else{
                ll a1=((u1)*(u1+1))/2;
                ll rem=k1-u1-1;
                ll a2=((rem)*(rem+1))/2;
                s1=(a1-a2);
            }
            // cout<<s1<<"\n";
            if((idx-1)>=l)
            {
                int k2 = pf[idx-1]-pf[l-1];
                int u2=u;

                if(u2>=k2){
                ll a1=(u2*(u2+1))/2;
                ll rem=u2-k2;
                ll a2=((rem)*(rem+1))/2;
                s2=(a1-a2);
            }
            else{
                ll a1=((u2)*(u2+1))/2;
                ll rem=k2-u2-1;
                ll a2=((rem)*(rem+1))/2;
                s2=(a1-a2);
            }
            }
            else{
                cout<<idx<<" ";
                continue;
            }

            if(s1>s2)
            {
                cout<<idx<<" ";
            }
            else
            {
                cout<<idx-1<<" ";
            }
        } 
        cout<<endl;
    }
}