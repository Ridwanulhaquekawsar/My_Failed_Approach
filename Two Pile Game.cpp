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
#define pb push_back
#define ppb pop_back
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
ll n;
vll a, b;
ll mn;
ll tmp;
ll smn, smx;
ll mx;
ll a_mn;
ll ans

void solve(){
    in n;
    rs(a, n);
    rs(b, n);
    
    rep(i, n){
        in a[i];
    }
    
    rep(i, n){
        in b[i];
    }
    
    a_mn = min(a[0], b[0]);
    
    rep(i, n-1){
        mn = min(a[i], b[i]);
        mx = max(a[i], b[i]);
        
        smn = min(a[i+1], b[i+1]);
        smx = max(a[i+1], b[i+1]);
        
        /*if(smn >= mn) mn = smn;
        else{
            if(smx >= mn) mn = smx;
            else{
                No;
                return;
            }
        }*/
        
        if(smn >= a_mn){
            a_mn = smn;
            
            if(smx >= mx){
                ans = i;
                break;
            }
        }
        else{           
            if(smx >= a_mn) a_mn = smx;
            else{
                No;
                return;
            }
        } 
    }
    
    
    //if(tmp == a[n-1]){
        //a[n-1] <= b[n-1] ? Yes : No;
    //}
    //else{
        //b[n-1] <= a[n-1] ? Yes : No;
    //}//
    
    
}

int main(){
    FastIO(); 
    
    T = 1;
    in T;
    while(T--) solve();
}


~~~★~~~★~~~★~~~★~~~★~~~


Another Way:


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
#define pb push_back
#define ppb pop_back
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
vll a, b;
vector<bool>prf;
ll n;

void solve(){
    in n;
    rs(a, n);
    rs(b, n);
    as(prf, n, 1);
    
    rep(i, n){
        in a[i];
    }
    
    rep(i, n){
        in b[i];
    }
    
    rep(i, n){
        if(a[i] > b[i]) swap(a[i], b[i]);
    }
    
    /* rep(i, n){ cout << a[i] << " "; }
    cout << nl << nl;
    
    rep(i, n){ cout << b[i] << " "; }
    cout << nl << nl; */
    
    rrep(i, n-1){
        if(prf[i+1]){
            if(b[i] > b[i+1]) prf[i] = 0;
        }
        else prf[i] = 0;
    }
    
    //rep(i, n){cout << prf[i] << " ";}
    //cout << nl;
    
    rep(i, n-1){
        if(prf[i]){
            Yes;
            return;
        }
    
        if(a[i] > a[i+1]){
            No;
            return;
        }
    }
    
    Yes;
}

int main(){
    FastIO(); 
    
    T = 1;
    in T;
    while(T--) solve();
}
