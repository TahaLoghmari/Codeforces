#include <bits/stdc++.h>
using namespace std;
#define TCPC cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0);
#define int long long 
#define Take(x) for ( auto & d : x ) cin >> d ; 
#define No cout << "no" << endl  
#define Yes cout << "yes" << endl  
#define Sort(x) sort( x.begin() , x.end() ) ;
#define RSort(x) sort( x.begin() , x.end() ) ; reverse ( x.begin() , x.end() ) ; 
#define MOD 998244353
#define Sum(A) accumulate( A.begin() , A.end() , (int)0 ) 
#define MAX LONG_LONG_MAX 
#define MIN LONG_LONG_MIN 
#define endl '\n' 
 
void solve()    
{
    int n ; cin >> n ; 
    vector<int> A(n) ; Take(A) ; 
    int Min = 0 ,  Max = (int)1e9 ; 
    for ( int i =  0 ; i < n - 1 ; ++i ) 
    {
        if ( A[i] > A[i+1] ) 
        {
            Min = max ( Min , (int)(( A[i] + A[i+1] + 1 ) / 2) ) ; 
        }
        if ( A[i] < A[i+1] ) 
        {
            Max = min ( Max , (int)(( A[i] + A[i+1] ) / 2) ) ; 
        }
    }
    if ( Min <= Max ) cout << Min << endl ; 
    else cout << -1 << endl ;
}       
signed main() 
{
    #ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    #endif
    TCPC ;   
    int t = 1 ; 
    cin >> t ; 
    while ( t-- ) solve();
    return 0 ;
}
