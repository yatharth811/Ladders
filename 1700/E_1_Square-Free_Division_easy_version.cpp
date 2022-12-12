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

ll lgb(ll a,ll b){
    return log2(a) / log2(b);
}

ll bpw(ll a,ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}


ll m[10000001];
vector<bool> a(1e7+1, true);
void precompute(){
    ll N = 1e7;
    rep(i,1,N+1){m[i] = 1;}
    rep(i,2,N+1){
        if (a[i]){
            for (ll j = 2*i; j <= N; j+=i){
                a[j] = false;
                // ll l = 0, r = lgb(j, i) + 1;
                // while(r-l > 1){
                //     ll mid = l + (r-l)/2;
                //     if (j % bpw(i, mid) == 0){
                //         l = mid;
                //     }
                //     else{
                //         r = mid;
                //     }
                // }

                // if (l&1){
                //     if (m[j] == 0){
                //         m[j] = i;
                //     }
                //     else{
                //         m[j] *= i;
                //     }
                // }
                // else{
                //     if (m[j] == 0){
                //         m[j] = 1;
                //     }
                // }

            }
            // m[i] = i;
        }
    }

}

void solve(){
    ll n, k;
    cin >> n >> k;

}


int main() {
    FAST;
    ll t=1;
    cin >> t;
    precompute();

    while(t--){
        solve();
    }
    return 0;
}
