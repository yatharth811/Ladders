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
    rep(i,0,n){cin >> a[i];}


    // DP
    // vector<vector<ll>> dp(n+1, vector<ll>(n+1, -1e15));

    // rep(i,0,n+1){
    //     dp[i][0] = 0;
    // }

    // rep(i,1,n+1){
    //     rep(j,1,i+1){
    //         if (dp[i-1][j-1] + a[i] >= 0){
    //             dp[i][j] = max(dp[i-1][j-1] + a[i], dp[i-1][j]);
    //         }
    //         else{
    //             dp[i][j] = dp[i-1][j];
    //         }
    //     }
    // }

    // ll idx = -1;
    // rep(i,0,n+1){
    //     if (dp[n][i] >= 0) idx = max(idx, i);
    // }

    // cout << idx << endl;

    // Greedy
    priority_queue<ll, vi, greater<ll>> pq;
    ll sum = 0, cnt = 0;
    for (auto x: a){
        if (x >= 0){
            sum += x;
            cnt++;
        }
        else{
            if (sum + x < 0){
                if (!pq.empty() && pq.top() < x){
                    auto y = pq.top();
                    pq.pop();
                    sum = sum - y + x; 
                    pq.push(x);
                }
            }
            else{
                if (cnt){
                    pq.push(x);
                    cnt++;
                    sum += x;
                }
            }
        }
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
