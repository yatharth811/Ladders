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
    ll n, k;
    cin >> n >> k;
    vi a(k), t(k);
    vi temp(n+1, INT_MAX);
    vi isAC(n+1, -1);
    rep(i,0,k){cin >> a[i];}
    rep(i,0,k){cin >> t[i]; isAC[a[i]] = t[i];}

    priority_queue<ll, vector<ll>, greater<ll>> pq1, pq2;
    rep(i,1,n+1){
        if (isAC[i]==-1){
            if (!pq1.empty()){
                temp[i] = pq1.top() + i;
            }
        }
        else{
            pq1.push(isAC[i] - i);
            temp[i] = pq1.top() + i;
        }
    }

    per(i,n,0){
        if (isAC[i]==-1){
            if (!pq2.empty()){
                temp[i] = min(pq2.top() - i, temp[i]);
            }
        }
        else{
            pq2.push(isAC[i] + i);
            temp[i] = min(temp[i], pq2.top() - i);
        }
    }

    rep(i,1,n+1){
        cout << temp[i] << " ";
    }
    cout << endl;




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
