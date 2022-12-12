#include <bits/stdc++.h>

// #include <boost/random.hpp>
// #include <boost/nondet_random.hpp>

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vi primes;

void precompute(){
    ll j = 2;

    while(primes.size() < 500){
        bool f = true;

        for (ll i = 2; i*i <= j; i++){
            if ((j % i) == 0){
                f = false;
                break;
            }
        }

        if (f) primes.push_back(j);

        j++;
    }
}

void solve(){
    ll n;
    cin >> n;
    map<ll, ll> m;
    vi a(n);
    rep(i,0,n){cin >> a[i]; m[a[i]]++;}

    // boost::random::random_device rand_dev;
    // boost::random::mt19937 generator(rand_dev());
    // boost::random::uniform_int_distribution<> distr(0, n-1);

    if (m.size() < n){
        cout << "YES" << endl;
    }
    else{
        for (auto x: primes){
            ll cnt = 0;
            for (auto y: a){
                cnt += ((y%x) == 0);
                if (cnt > 1){
                    cout << "YES" << endl;
                    return;
                }
            }
        }

        rep(_,0,300){
            ll i = uniform_int_distribution<ll>(0, n-1)(rng);
            ll j = uniform_int_distribution<ll>(0, n-1)(rng);

            if (i!=j){
                if (__gcd(a[i], a[j]) > 1){
                    cout << "YES" << endl;
                    return;
                }
            }
        }


        cout << "NO" << endl;
    }

    

}


int main() {
    FAST;
    ll t=1;
    cin >> t;
    // precompute first 100 numbers

    precompute();

    while(t--){
        solve();
    }
    return 0;
}
