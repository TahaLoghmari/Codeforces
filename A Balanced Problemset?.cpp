#include <bits/stdc++.h>
using namespace std ;
#define IWillWinTCPC cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0);
#define int long long 
#define Take(x) for ( auto & d : x ) cin >> d ; 
#define No cout << "No" << endl  
#define Yes cout << "Yes" << endl  
#define Sort(x) sort( x.begin() , x.end() ) ;
#define RSort(x) sort( x.begin() , x.end() ) ; reverse ( x.begin() , x.end() ) ; 
#define MOD 998244353
#define Sum(A) accumulate( A.begin() , A.end() , (int)0 ) 
#define MAX LONG_LONG_MAX 
#define MIN LONG_LONG_MIN 
#define endl '\n' 

void solve() 
{
    int x , n ; cin >> x >> n ; 
    int Res = 1 ; 
    for ( int d = 1 ; d * d <= x ; ++d ) 
    {
        if ( x % d == 0 ) 
        {
            int Left = x - ( d * n ) ; 
            if ( Left >= 0 && Left % d == 0 ) Res = max ( Res , d ) ;
        }
        if ( ( x / d ) != d ) 
        {
            int NewD = x / d ; 
            int Left = x - ( NewD * n ) ; 
            if ( Left >= 0 && Left % NewD == 0 ) Res = max ( Res , NewD ) ;  
        }
    }
    cout << Res << endl ; 
}  
signed main() 
{
    #ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    #endif
    IWillWinTCPC ;   
    cout<<fixed<<setprecision(14);
    int t = 1 ; 
    cin >> t ; 
    while ( t-- ) solve();
    return 0;
}
