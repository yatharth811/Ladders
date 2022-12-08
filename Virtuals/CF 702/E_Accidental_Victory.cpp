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
    vector<pi> x;
    rep(i,0,n){cin >> a[i]; x.push_back({a[i], i});}
    sort(begin(x), end(x));

    vi pre(n), ans;
    pre[0] = x[0].first;
    rep(i,1,n){
        pre[i] = pre[i-1] + x[i].first;
    }

    per(i,n-2,-1){
        if (pre[i] >= x[i+1].first){
            ans.push_back(x[i].second);
        }
        else{
            break;
        }
    }

    ans.push_back(x[n-1].second);

    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (auto g: ans){
        cout << g+1 << " ";
    }
    cout <<endl;





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
