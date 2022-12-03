#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;

#define rep(i,a,b) for(ll i=a;i<b;i++)
#define per(i,a,b) for(ll i=a;i>b;i--)

void solve(){
    ll n, p;
    cin >> n >> p;
    string s;
    cin >> s;

    vi v;
    ll cost = 0;
    for (auto x: s){
        v.push_back(26 - (x-'A'));
        cost += 26 - (x-'A');
    }

    sort(v.begin(), v.end());
    ll ans = 0;
    for (auto x: v){
        if (cost - x  <= p) break;
        else {
            cost -= x;
            ans++;
        }
    }

    cout << ans << endl;

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
