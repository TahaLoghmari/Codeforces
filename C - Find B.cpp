#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define int long long 
typedef pair<int,pair<int,int>> tup;
typedef pair<int,int> pi;
#define endl "\n"
#define all(x) x.begin(), x.end()
#define sortt(x) sort(all(x))
#define unq(vt)  vt.erase(unique(all(vt)), vt.end())
#define rev(x)   reverse (all(x)) 
class Solution {
public:
     int n ;
     
     void solve(){
          int q ;
          cin >> n ;
          cin >> q ;
 
          vector<int>a(n) , pref ( n + 2 , 0 ) , cteofone ( n + 2 , 0);
          for(auto &d : a )  cin>>d; 
          
          for( int i =  1 ; i <= n ; i++ )
          {
               pref[i] += pref[i-1] + a[i-1];
               if ( a[i-1] == 1) cteofone[i]++;
          }
          for( int i =  1 ; i <= n ; i++ )
          {
               
               cteofone[i]+=cteofone[i-1];
          }
          for ( int i =  0 ; i < q ; i++ )
          {
               int l , r ;
               cin >> l >> r ;
               int sum = pref[r] - pref[l-1];
               int cte = cteofone[r] - cteofone[l-1];
               int w7id = sum /*- ( r-l + 1 )*/;
               int mizelou = sum  ;
               int communw7id = min( w7id , cte) ;
               mizelou += -communw7id - ( r - l + 1 );
               if ( mizelou < 0 || r == l  )  cout << "No" << endl;
               
               else cout << "Yes" <<endl;
          }      
     }
     
};
 
signed main() {
     SPEED;
     #ifndef ONLINE_JUDGE
          freopen("Input.txt", "r", stdin);
          freopen("Output.txt", "w", stdout);
          freopen("err.txt", "w", stderr);
     #endif
     int t = 1;
     cin >> t;
     while (t--){
          Solution sol;  
          sol.solve();
     } 
     return 0;
}
