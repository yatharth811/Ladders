#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using vi = vector<ll>;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define per(i,a,b) for(ll i=a;i>b;i--)
#define endl '\n'
void solve(){set<ll> x;ll z = 1;rep(i,0,9){x.insert(5*z);z*=10;}z = 10;rep(i,1,10){x.insert(z);z*=10;}ll n,m;cin>>n>>m;vi a(n),b(m);map<ll,ll>mp;rep(i,0,n){cin>>a[i];mp[a[i]]++;}rep(i,0,m){cin>>b[i];}for(auto el:b){if(x.find(el)==x.end()){if (x.upper_bound(el)==x.end()){cout<<"NO"<<endl;return;}else{ll r=*x.upper_bound(el);if(mp[r]>0){mp[r]--;}else{cout<<"NO"<<endl;return;}}}else{if(mp[el]>0){mp[el]--;}else{cout<<"NO"<<endl;return;}}}cout<<"YES"<<endl;}int main(){ios::sync_with_stdio(0), cin.tie(0);ll t;cin>>t;while(t--){solve();}return 0;}
