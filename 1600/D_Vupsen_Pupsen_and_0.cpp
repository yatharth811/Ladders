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
    vector<pi> a;
    rep(i,0,n){
        ll x; cin >> x; 
        a.push_back({x, i}); 
    }

    if (n%2){
        sort(a.begin(), a.end());
        vi b(n);
        for (ll i = 0; i < n-3; i+=2){
           b[a[i].second] = a[i+1].first;
           b[a[i+1].second] = -a[i].first;
        }

        ll e1 = a[n-3].first, e2 = a[n-2].first, e3 = a[n-1].first;
        ll i1 = a[n-3].second, i2 = a[n-2].second, i3 = a[n-1].second;
        
        if (e1 == e2 && e2 == e3){
            b[i1] = 1;
            b[i2] = 1;
            b[i3] = -2;
        }
        else if (e1 == e2 && e2!=e3){
            b[i1] = e3;
            b[i2] = e3;
            b[i3] = -2*e1;
        }
        else if (e1 != e2 && e2==e3){
            b[i1] = -2*e2;
            b[i2] = e1;
            b[i3] = e1;
        }
        else{
            b[i1] = e2-e3;
            b[i2] = e3-e1;
            b[i3] = e1-e2;
        }
        
        for (auto x: b){
            cout << x << " ";
        }
        cout << endl;

    }
    else{
        for (ll i = 0; i < n; i+=2){
            cout << a[i+1].first << " " << -a[i].first << endl;
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
