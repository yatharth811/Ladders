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

ll smans(vector<ll> &a){
    sort(a.begin(), a.end());
    ll n = a.size();

    ll res = 0;
    rep(i,0,n){
        // how many bigger than me?
        auto x = n - (upper_bound(begin(a), end(a), a[i]) - begin(a));
        auto y = (lower_bound(begin(a), end(a), a[i])-begin(a));

        res += (+y*a[i] - x*a[i]);
    }

    // cout << res << endl;.
    return res;

}

ll mans(vector<pi> &a){
    vi x, y;

    for (auto [p, q]: a){
        x.push_back(p);
        y.push_back(q);
    }


    return smans(x) + smans(y);
}

void solve(){
    ll n, m;
    cin >> n >> m;

    ll maxi = -1;
    vector<pi> colors[100001];
    rep(i,0,n){
        rep(j,0,m){
            ll x;
            cin >> x;
            colors[x].push_back({i+1,j+1});
            maxi = max(x, maxi);
        }
    }

    ll ans = 0;
    rep(i,1,maxi+1){
        ans += mans(colors[i]);
    }

    cout << ans << endl;

}


int main() {
    FAST;
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
