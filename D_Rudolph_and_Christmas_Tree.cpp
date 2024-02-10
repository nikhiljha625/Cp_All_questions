#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unrolong double-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC optimize("Ofast")
#define ll long long
#define pb push_back
#define along double(v) v.begin(),v.end()
#define ff first
#define ss second 
#define pyes cout << "YES" << "\n"
#define pno cout << "NO" << "\n"
#define rev(a) a.rbegin(),a.rend()


//code for custom hashing: no colong doubleision :along double wilong double be O[1] operation

 // for pairs:
// struct custom_hash {
// 	static uint64_t splitmix64(uint64_t x) {
// 		// http://xorshift.di.unimi.it/splitmix64.c
// 		x += 0x9e3779b97f4a7c15;
// 		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
// 		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
// 		return x ^ (x >> 31);
// 	}

// 	size_t operator()(pair<uint64_t,uint64_t> x) const {
// 		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
// 		return splitmix64(x.first + FIXED_RANDOM)^(splitmix64(x.second + FIXED_RANDOM) >> 1);
// 	}
// };

// for long long:
/*struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};



long double power(int a,int p){
    if(p==0) return 1;
    long double x=power(a,p/2);
    if(p%2){
        return (long double)x*x*a;
    }
    return x*x;
}
long double GCD(long double a,long double b){
    long double minm=min(a,b);
    long double maxm=max(a,b);
    if(maxm%minm==0){
        return minm;
    }
    return GCD(minm,maxm%minm);
}
void swap(long double& a,long double& b){
    long double c=a;
    a=b;
    b=c;
}
bool cmp(pair<long double,long double>& a,pair<long double,long double>& b){
        return a.first<b.first;
}

bool isperfect(long double a){
    long double x=sqrt(a);
    if(x*x==a){
        return true;
    }
    return false;
}
string conv(long double a){
    string s;
    while(a>0){
        long double d=a%2;
        s.pb(d+'0');
        a/=2;
    }
    while(s.size()<32){
        s.pb('0');
    }
//    reverse(along double(s));
    return s;
}
 long double getnum(string s){
    long double a=0;
    reverse(along double(s));
    for(long double i=0;i<s.size();i++){
        a+=((s[i]-'0')*(power(10,i)));
    }
    return a;
}


long double fact(long double i){
    if(i==0){
        return 1;
        
    }
    return i*(fact(i-1));
}
*/
//*******************************************************************************************************************************************

void solve(){
    long double n,base,ht;
    cin>>n>>base>>ht;
    vector<long double> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    long double last=1e10;
    long double ans=0;
    for(int i=n-1;i>=0;i--){
        long double x=((0.500000)*(base)*(ht));
        if(v[i]+ht<=last){
            ans+=x;
            last=v[i];
        }
        else{
            long double h1=v[i]+ht-last;
            long double y=((0.500000)*(base)*(h1*h1))/ht;
            ans+=(x-y);
            last=v[i];
        }
    }
    cout<<fixed<<setprecision(9)<<ans<<"\n";
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