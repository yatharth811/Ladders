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
    ll n;
    cin >> n;
    vi a(n);
    ll m[150002] = {0};
    rep(i,0,n){cin >> a[i]; m[a[i]]++;}
    sort(a.rbegin(), a.rend());
    for (auto x: a){
        // cout << x << " ";
        if (m[x+1] == 0){
            m[x+1]++;
            m[x]--;
            // cout << "YES: " << x << " " << m[x] << " " << m[x+1] << endl;
        }
        else if (m[x] > 1 && x!=1){
            m[x]--;
            m[x-1]++;
        }
    }
    // cout << endl;

    ll cnt = 0;
    rep(i,1,150002){
        cnt += (m[i] ? 1 : 0);
        // cout << m[i] << endl;
    }

    cout << cnt << endl;

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
