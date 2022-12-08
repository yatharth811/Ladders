#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;

#define FAST ios::sync_with_stdio(0), cin.tie(0)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define per(i,a,b) for(ll i=a;i>b;i--)
#define endl '\n'

const ll MAX = INT_MAX;
const ll MIN = INT_MIN;
const ll MOD = 1e9 + 7;

ll ceil(ll a, ll b) {
    return (a + b - 1) / b; 
}



void solve(){
    ll n, m;
    cin >> n >> m;
    vi a(n), pre(n, 0);
    rep(i,0,n){cin >> a[i]; }

    map<ll,ll> mp;
    map<ll,ll> pm;

    pre[0] = a[0];
    mp[a[0]] = 1;
    rep(i,1,n){
        pre[i] = pre[i-1] + a[i];
        mp[pre[i]] = 1;
        pm[pre[i]] = -1;
    }

    rep(i,0,n){
        if (pm[pre[i]]==-1){
            pm[pre[i]] = i;
        }
    }

    vi ans;
    ll sum = pre.back();

    while(m--){
        ll x;
        cin >> x;


        if (sum > 0){

        }
        else{
            if (mp[x]!=-1){
                ans.push_back(pm[x]);
            }
            else{
                ans.push_back(-1);
            }
        }

    
    }

    for (auto g: ans){
        cout << g << " ";
    }
    cout << endl;

}


int main() {
    FAST;
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
