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

    // sum array -> sum[i] = a[i] + a[i+1]
    vi sum(n+1, 0);
    vi a(n+1);
    if (n&1){

        ll as = 0, minus = 1;
        rep(i,1,n){
            cout << "? " << i << " " << i + 1 << endl;
            cin >> sum[i];
            as += minus * sum[i];
            minus = minus * -1;
        }
        // a1 - an = x;
        // a1 + an = y;
        ll temp;
        cout  << "? " << 1 << " " << n << endl;
        cin >> temp;

        a[1] = (as + temp) >> 1;
        a[n] = (temp - as) >> 1;

        rep(i,2,n){
            a[i] = sum[i-1] - a[i-1];
        }

    }
    else{
        ll as = 0, minus = 1;
        rep(i,1,n-1){
            cout << "? " << i << " " << i + 1 << endl;
            cin >> sum[i];
            as += minus * sum[i];
            minus = minus * -1;
        }

        cout << "? " << 1 << " " << n - 1 << endl;
        ll x;
        cin >> x;
        as += x;

        a[1] = (as) >> 1;
        rep(i,2,n){
            a[i] = sum[i-1] - a[i-1];
        }

        ll temp;
        cout  << "? " << 1 << " " << n << endl;
        cin >> temp;
        a[n] = temp - a[1];

    }

    cout << "! ";
    rep(i,1,n+1){
        cout << a[i] << " ";
    } 
    cout << endl;
}


int main() {
    // FAST;
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
