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

#define pll pair<ll, ll>
#define vll vector<ll>

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
ll n, k;
vll v;
ll tmp1, tmp2;
string s;

void solve(){
    in n >> k >> s;
    v.assign(2, 0);
    
    rep(i, s.size()){
        if(s[i] == '0') v[0]++;
        else v[1]++;
    }
    
    if(k == 1){
        if(n % 2){
            if( ( (v[0] == n/2) && (v[1] == ((n/2) + 1) ) ) || ( (v[1] == n/2) && (v[0] == ((n/2) + 1) ) )  ){
                Yes;
            }
            else No;
        }
        else{
            ( (v[0] == n/2) && (v[1] == n/2) ) ? Yes : No;
        }
    }
    else if(k == (n - 1)){
        ( (v[0] >= 1) && (v[1] >= 1) ) ? Yes : No;
    }
    else{
        tmp1 = k;
        tmp1 = n - k;
        
        ( (v[0] == tmp1) && (v[1] == tmp2) ) || ( (v[1] == tmp1) && (v[0] == tmp2) ) ? Yes : No;
    }
}

int main(){
    FastIO(); 
    
    t = 1;
    in t;
    while(t--) solve();
}
