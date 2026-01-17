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
#define mn_ele min_element
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
ll n, x;
vll v, prf, suf;
ll mx;
ll t;

void solve(){
    in n >> x;
    rs(v, n);
    rs(prf, n);
    rs(suf, n);
    
    rep(i, n) in v[i];
    
    prf[0] = 1;
    rep1(i, 1, n - 1) (v[i] >= v[i - 1]) ? prf[i] = prf[i - 1] + 1 : prf[i] = 1;
    
    suf[n - 1] = 1;
    rrep1(i, n - 2, 0) (v[i] <= v[i + 1]) ? suf[i] = suf[i + 1] + 1 : suf[i] = 1;
    
    mx = 1;
    
    rep(i, n){
        if(i == 0) ( (v[i] <= v[i + 1]) || (v[i] * x <= v[i + 1]) ) ? t = suf[i + 1] + 1 : 1;
        else if(i == n - 1) ( (v[i] >= v[i - 1]) || (x * v[i] >= v[i - 1]) ) ? t = prf[i - 1] + 1 : t = 1;
        else ( (v[i] >= v[i - 1] && v[i] <= v[i + 1]) || (x * v[i] >= v[i - 1] && x * v[i] <= v[i + 1]) ) ? t = prf[i - 1] + suf[i + 1] + 1 : t = 1;
        
        mx = max(mx, t);
    }
    
    out(mx);
}

int main(){
    FastIO(); 
    
    T = 1;
    in T;
    while(T--) solve();
}
