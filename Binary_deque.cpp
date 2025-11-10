#include<bits/stdc++.h>
using namespace std;
#define FastIO() ios::sync_with_stdio(0),cin.tie(0)
using ll = long long int;
#define nl '\n'

ll t,n,s,sum,x,left_dis,right_dis,cnt;
deque<ll>dq;

void solve(){
    cin>>n>>s;
    dq.clear();
    
    sum=0;
    
    for(int i=0; i<n; i++){
        cin>>x;
        sum+=x;
        
        dq.push_back(x);
    }
    
    if(sum==s) cout<<0<<nl;
    else if(sum<s) cout<<"-1"<<nl;
    else{
        cnt=0;
    
        while(sum>s){
            auto it=find(dq.begin(),dq.end(),1);
            auto rit=find(dq.rbegin(),dq.rend(),1);
        
            left_dis=distance(dq.begin(),it)+1;
            right_dis=distance(dq.rbegin(),rit)+1;
            
            
            if(left_dis<=right_dis){
                while(left_dis--){
                    cnt++;
                    
                    if(dq.front()==1){
                        sum-=1;
                        
                        dq.pop_front();
                        break;
                    }
                    else dq.pop_front();    
                }
            }
            else{
                while(right_dis--){
                    cnt++;
                    
                    if(dq.back()==1){
                        sum-=1;
                        
                        dq.pop_back();
                        break;
                    }
                    else dq.pop_back();    
                }
            }
        }
        
        
        cout<<cnt<<nl;
    }
}

int main(){
    FastIO(); cin>>t; while(t--) solve();
}

Note: 
  • My code is failed cause i choosed nearest possible element alternating the contigous element from end so this the wrong from my end cause if i choose nearest then the nerest all removal is extra operation if other end contain contigous element 🙂🧑‍💻
  • My code is not made best decision here, cause variable size sliding window has made best decision here 😎🧑‍💻



Correct Approach:
      • 👇

#include<bits/stdc++.h>
using namespace std;
#define FastIO() ios::sync_with_stdio(0),cin.tie(0)
using ll = long long int;
#define nl '\n'

ll t,n,s,sum,l,mx;
vector<ll>a;

void solve(){
    cin>>n>>s;
    a.resize(n);
    
    sum=0;
    
    for(int i=0; i<n; i++){
        cin>>a[i];
        sum+=a[i];
    }
    
    if(sum==s) cout<<0<<nl;
    else if(sum<s) cout<<"-1"<<nl;
    else{
        l=0;
        mx=-1;
        sum=0;
        
        for(int r=0; r<n; r++){
            sum+=a[r];
            
            while(sum>s) sum-=a[l++];
            
            if(sum==s) mx=max(mx,r-l+1);
        }
        
        cout<<n-mx<<nl;
    }
}

int main(){
    FastIO(); cin>>t; while(t--) solve();
}
