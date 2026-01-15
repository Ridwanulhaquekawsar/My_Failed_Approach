#include<bits/stdc++.h>
using namespace std;
#define FastIO() ios::sync_with_stdio(0),cin.tie(0)
using ll = long long int;
#define nl '\n'

#define out(x) cout << (x) << nl
#define in cin >>

#define pinf LLONG_MAX
#define ninf LLONG_MIN

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define Yes cout << "Yes\n"
#define No cout << "No\n"

#define f first
#define sc second
#define fr front()
#define bc back()
#define bg begin()
#define ed end()
#define pu push
#define po pop
#define pf push_front
#define pb push_back
#define pob pop_back()
#define pof pop_front()
#define emp emplace
#define clr clear()
#define wh while
#define emp_fr emplace_front
#define emp_bc emplace_back
#define sz(x) (ll)x.size()

#define rs(v, n) (v).resize(n)
#define as(v, sz, val) (v).assign(sz, val)

#define pll pair<ll, ll>
#define vll vector<ll>
#define vvll vector< vector<ll> >
#define vpll vector<pll>
#define S string

#define St set<ll>
#define Ms multiset<ll>
#define Mp map<ll, ll>
#define Ump unordered_map<ll, ll>
#define Q queue<ll>
#define Dq deque<ll>

#define rep(i, n) for(ll i = 0; i < n; i++)
#define rrep(i, n) for(ll i = n - 1; i >= 0; i--)
#define rep1(i, a, b) for(ll i = a; i <= b; i++)
#define rrep1(i, b, a) for(ll i = b; i >= a; i--)

bool isPrime(ll n){

    if(n == 1) return 0;  
    else if(n == 2) return 1;  
    else if(n % 2 == 0) return 0;  
  
    for(ll i = 3; i <= n/i; i += 2){  
        if(n % i == 0) return 0;  
    }  
  
    return 1;

}

/*
ll lcm(ll a, ll b) {
    return (a / __gcd(a, b)) * b;
}
*/

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
*/

ll T;
ll l, w, r, g, b;
ll le_w, e_w, c_lw, c_l;
ll la_w;

void solve(){
    in l >> w >> r >> g >> b;
    
    if(w > l) swap(l, w);
    e_w = 0;  
  
    if(r == w) e_w++;  
    if(g == w) e_w++;  
    if(b == w) e_w++;  
  
    le_w = 0;  
  
    if(r < w) le_w++;  
    if(g < w) le_w++;  
    if(b < w) le_w++;  
  
    c_l = 0;  
    c_lw = 0;  
  
    if(r >= l && r < l+w) c_l++;  
    if(r >= l+w) c_lw++;  
  
    if(g >= l && g < l+w) c_l++;  
    if(g >= l+w) c_lw++;  
  
    if(b >= l && b < l+w) c_l++;  
    if(b >= l+w) c_lw++;  
  
    la_w = 0;  
  
    if(r >= w) la_w++;  
    if(g >= w) la_w++;  
    if(b >= w) la_w++;  
  
  
    if(e_w == 2) out(4);  
    else if(le_w == 2) ( (2 * min({r, g, b}) == w) || (2 * min({r, g, b}) == l) ) ? out(5) : out(6);
    else if(le_w == 1) (c_lw == 1) ? out(5) : out(6);  
    else if(la_w == 3) (c_l >= 1 && c_lw >= 1) ? out(4) : out(5);
}

int main(){
    FastIO();

    T = 1;  
    in T;  
    while(T--) solve();
}
