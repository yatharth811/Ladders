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


void solve () {
    ll n;
    string s, t;
    cin >> n >> s >> t;
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'W') v.push_back({i, 0});
        if (t[i] == 'W') v.push_back({i, 1});
    }
    bool ans = true;
    for (int i = 1; i < (int) v.size(); i++) {
        auto m = (v[i].first - v[i - 1].first) % 2;
        if (v[i].second == v[i - 1].second) {
            if (m % 2 == 0) ans = false;
        } else {
            if (m % 2 == 1) ans = false;
        }
    }
    cout << (ans ? "YES\n" : "NO\n");
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
