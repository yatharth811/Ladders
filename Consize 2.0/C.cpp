#include<bits/stdc++.h>
using namespace std;using ll = long long int;using vi = vector<ll>;
#define endl '\n'
void solve(){ll n;cin>>n;map<tuple<ll,ll,ll>,ll>m;while(n--){ll a,b,c;cin>>a>>b>>c;m[{a,b,c}]++;}ll ans=0;for(auto[_, x]:m){ans+=(x*(x-1))/2;}cout<<ans<<endl;}int main(){ios::sync_with_stdio(0), cin.tie(0);ll t;cin>>t;while(t--){solve();}return 0;}