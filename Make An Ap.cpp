#include<bits/stdc++.h>
using namespace std;
#define FastIO() ios::sync_with_stdio(0),cin.tie(0)
using ll = long long int;
#define nl '\n'

#define out(x) cout << (x) << nl
#define in cin >>

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define Yes cout << "Yes\n"
#define No cout << "No\n"

#define f first
#define s second
#define pb push_back

#define rs(v, n) (v).resize(n)
#define as(v, sz, val) (v).assign(sz, val)

#define pll pair<ll, ll>
#define vll vector<ll>

#define St set<ll>
#define Ml multiset<ll>
#define Mp map<ll, ll>
#define Ump unordered_map<ll, ll>

#define rep(i, n) for(ll i = 0; i < n; i++)
#define rrep(i, n) for(ll i = n - 1; i >= 0; i--)
#define rep1(i, a, b) for(ll i = a; i <= b; i++)
#define rrep1(i, b, a) for(ll i = b; i >= a; i--)

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
*/

ll t;
ll mx;
ll n, mn;
vll v;
ll tmp;
St st;

void solve(){
    in n;
    rs(v, n);
    st.clear();
    
    mx = LLONG_MIN;
    
    rep(i, n){
        in v[i];
        mx = max(mx, v[i]);
    }
    
    mn = LLONG_MAX;
    
    rep(i, n - 1){
        
        mn = min(mn, abs(v[i] - v[i + 1]) );
    }
    
    rep1(i, 1, (ll)sqrt(n)){
    
        if(v[n - 1] % i == 0) st.insert(i);
    }
    
    if(mn <= *st.rbegin()) tmp = (mx + mn - 1 - v[0])/mn;
    else{
        tmp = (mx + *st.rbegin() - 1 - v[0])/(*st.rbegin());
    }
    
    out(tmp - n);
}

int main(){
    FastIO(); 
    
    t = 1;
    in t;
    while(t--) solve();
}
