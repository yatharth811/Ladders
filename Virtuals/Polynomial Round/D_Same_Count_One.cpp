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

ll finder(set<pair<ll, ll>> &vec, ll key){
    auto it = std::find_if(vec.begin(), vec.end(),
                        [&key](const std::pair<int, double>& elem) {
                            return elem.first == key;
                        });
    return it != vec.end() ? it->second : -1;
}

void solve(){
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));

    ll cnt = 0;
    vi counts;
    rep(i,0,n){
        ll tes = 0;
        rep(j,0,m){
            cin >> a[i][j];
            cnt += a[i][j];
            tes += a[i][j];
        }
        counts.push_back(tes);
    }

    if (cnt%n){
        cout << "-1" << endl;
    }
    else{

        rep(i,0,n){
            if (counts[i] > (cnt/n)){
                
            }
        }

    }

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
