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

void bubbleSort(vi &arr, int n, vector<pi>&ans, ll offset)
{
    int i, j;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                ans.push_back({j+1+offset, j+2+offset});
            }
        }

    }

}


void bsort(vector<pi> &arr, int n, vector<pi>&ans)
{
    int i, j;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (arr[j].first > arr[j + 1].first){
                swap(arr[j], arr[j + 1]);
                ans.push_back({j+1, j+2});
            }
        }

    }

    // cout << "DEBG" << endl;
    // for (auto [x, _]: arr){
    //     cout << x << " ";
    // }
    // cout << endl;

}

void solve(){
    ll n;
    cin >> n;
    vector<pi> a(n), ans;
    vi ma, mb;

    rep(i,0,n){
        ll x;
        cin >> x;
        a[i] = {x, -1};
        ma.push_back(x);
    }

    rep(i,0,n){
        ll x;
        cin >> x;
        a[i].second = x;
        mb.push_back(x);
    }


    bsort(a, n, ans);

    rep(i,0,n-1){
        ll p = a[i].first, q = a[i+1].first, r = a[i].second, s = a[i+1].second;


        if (r > s && p!=q){
            cout << -1 << endl;
            return;
        }

    }

    // bubbleSort(ma, n, ans, 0);

    ll i = 0, j = 1;
    vi window;
    window.push_back(a[i].second);
    vi main;
    while(j < n){
        // cout << "TEST: " << a[j].first << endl;
        if (a[j].first == a[i].first){
            window.push_back(a[j++].second);
        }
        else{
            // call bubble sort on window and clear it
            // cout << "WINDOW" << endl;
            // for (auto x: window){
            //     cout << x << " ";
            // }
            // cout << endl;
            bubbleSort(window, window.size(), ans, i);
            for (auto x: window){
                main.push_back(x);
            }
            window.clear();
            i = j++;
            window.push_back(a[i].second);
            // cout << "WINDOW" << endl;
            // for (auto x: window){
            //     cout << x << " ";
            // }
            // cout << endl;
        }
    }

    bubbleSort(window, window.size(), ans, i);
    for (auto x: window){
        main.push_back(x);
    }

    if (!is_sorted(main.begin(), main.end())){
        cout << -1 << endl;
        return;
    }

    cout << ans.size() << endl;
    for (auto [x,y]: ans){
        cout << x << " "  << y << endl;
    }


    // cout << "TBA" << endl;

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
