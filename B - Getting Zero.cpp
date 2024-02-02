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
    for ( int i = 0 ; i < n ; ++i ) 
    {
        if ( A[i] == 0 )
        {
            cout << 0 << endl ; continue;
        } 
        int Count = 0 ; 
        int Min = MAX ; 
        for ( int j = A[i] ; j < A[i] + 20 ; j++ ) 
        {
            int Choice1 = (int)(log2(lcm(32768,j)/j) + Count);
            int Choice2 = (int)(32768 - j) + Count ; 
            Min = min ( Min , min ( Choice1 , Choice2 ) ) ;
            Count++; 
        } 
        cout << Min << endl ; 
    }
 
}       
signed main() 
{
    #ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    #endif
    TCPC ;   
    int t = 1 ; 
    // cin >> t ; 
    while ( t-- ) solve();
    return 0;
}
