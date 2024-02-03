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
    int n , m , Total = 0 , l = 0 ; cin >> n ; cin >> m ; 
    vector<int> K(n) , C(m) ; Take(K); Take(C) ; RSort(K);
    for ( int i = 0 ; i < n ; ++i ) {
        if ( C[K[i]-1] < C[l] ) Total += C[K[i]-1] ; 
        else{
            Total += C[l] ; 
            if ( l != m - 1 ) l++;  
        }
    }
    cout << Total << endl ; 
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
    return 0;
}
