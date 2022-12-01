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

bool isPower(ll x, ll y)
{
    if (x == 1)
        return (y == 1);

    ll pow = 1;
    while (pow < y)
        pow *= x;

    return (pow == y);
}


bool check(ll x, ll y, ll a, ll b){
    // x -> power of a
    // y -> kb + 1
    if (isPower(a, x) && (y%b == 1)) return true;
    return false;
}

void solve(){
    ll n, a, b;
    cin >> n >> a >> b;
    unordered_map <ll,bool> m;
    m.reserve(1024);
    m.max_load_factor(0.25);
    queue<ll> q;
    q.push(n);
    while(!q.empty()){
        ll x = q.front();
        // cout << x << endl;
        m[x] = true;
        q.pop();

        if (x == 1 || x%b == 1){
            cout << "Yes" << endl;
            return;
        }

        if (x%a == 0 && !m[x/a]){
            q.push(x/a);
        }

        while(x > 0 && (x%a)!=0){
            x -= b;
        }

        if (x > 0 && !m[x]) q.push(x);

    }


    cout << "No" << endl;
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