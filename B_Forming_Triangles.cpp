// #include<iostream>
// #include<cstring>
// #include<vector>
// using namespace std;
// using LL = long long;
 
// int main(){
 
//     cin.tie(0);
//     cout.tie(0);
//     ios::sync_with_stdio(0);
 
//     auto C2 = [&](int x){
//         return 1LL * x * (x - 1) / 2;
//     };
 
//     auto C3 = [&](int x){
//         return 1LL * x * (x - 1) * (x - 2) / 6;
//     };
 
//     int T;
//     cin >> T;
//     while(T--){
//         int n;
//         cin >> n;
//         vector<int> cnt(n + 1);
//         for(int i = 1; i <= n; i++){
//             int x;
//             cin >> x;
//             cnt[x] += 1;
//         }
//         LL ans = 0;
//         int s = 0;
//         for(int i = 0; i <= n; i++){
//             ans += C3(cnt[i]) + C2(cnt[i]) * s;
//             s += cnt[i];
//         }
//         cout << ans << '\n';
//     }
 
// }

#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;
long long zero = 0;

int binexp(int a, int b, int mod)
{
    int prod = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            prod = (prod * 1LL * a) % mod;
        }
        b = b >> 1;
        a = (a * 1LL * a) % mod;
    }
    return prod;
}

void solve()
{
    int n;
    cin>>n;

    vector<int> vect;
    for(int i = 0; i<n; i++)
    {
        int x;
        cin>>x;
        vect.push_back(x);
    }

    map<int,int> map1;
    for(int i = 0; i<n; i++)
    {
        map1[vect[i]]++;
    }   

    int tillct = 0;
    int answer = 0;
    for(auto it:map1)
    {
        int ele = it.first;
        int ct = it.second;

        if(ct >= 2)
        {
            int n1 = ct;
            n1 *= ct-1;
            n1 /= 2;
            int n2 = n1;
            n2 *= tillct;
            answer += n2;
        }
        if(ct >= 3)
        {
            int n3 = ct;
            n3 *= ct-1;
            n3 *= ct-2;
            n3 /= 6;
            answer += n3;
        }

        tillct += ct;
    }
    cout<<answer<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;

    while (tt--)
    {
        solve();
    }
}