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

#define SIEVE 
constexpr int N = 1E7 + 5;  
int is_prime[N];
vector<int> primes;
int spf[N];
void sieve() {
    for(int i = 1; i < N; i++) {
        spf[i] = i;
    }
    for(int i = 2; i < N; i++) {
        if (is_prime[i] == 0) {
            primes.push_back(i);
            for(auto j = 1ll * i * i ; j < N ; j += i){
                is_prime[j] = 1;
                if (spf[j] == j) spf[j] = i;
            }
        }
        is_prime[i] ^= 1;
    }
}
set<int> factorise(int n){  // O(logN) , works till n ranging 1e7.
    set<int> ans;
    while(n != 1){
        ans.insert(spf[n]);
        n = n / spf[n];
    }
    return ans;     // ans vector is always sorted.
}


void solve(){
    int a, b;
    cin >> a >> b;
    int d = b - a;
    if (d == 1) {
        cout << -1 << '\n';
        return;
    }
    if (__gcd(a, b) != 1) {
        cout << "0\n";
        return;
    }
    auto F = factorise(d);
    int ans = 1e8;
    for (auto z : F) {
        int m = b % z;
        ans = min(ans, z - m);
    }
    cout << ans << '\n';
}


int main() {
    FAST;
    ll t=1;
    cin >> t;
    sieve();
    while(t--){
        solve();
    }
    return 0;
}
