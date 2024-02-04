#include <bits/stdc++.h>
#define TCPC cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0);
using namespace std;
#define int long long 
#define Take(x) for ( auto & d : x ) cin >> d ; 
#define Show(x) for ( auto & d : x ) cout << d << " " ; 
#define No cout << "No" << endl  
#define Yes cout << "Yes" << endl  
#define Sort(x) sort( x.begin() , x.end() ) ;
#define RSort(x) sort( x.begin() , x.end() ) ; reverse ( x.begin() , x.end() ) ; 
#define MOD 998244353
#define Summ( A , Start ) accumulate( A.begin() , A.end() , (int)Start ) 
 
 
void solve()
{
    int n , Count = 0 ; cin >> n ; 
    vector<int> A(n) , B , C ; Take(A);
    for ( int i = 0 ; i < n ; ++i ) {
        if ( A[i] < ( i + 1 ) ) {
            B.push_back(A[i]);C.push_back(i+1);
        }
    }
    Sort(B);
    for ( int i = 0 ; i < C.size() ; ++i ) Count += B.size() - (upper_bound( B.begin() , B.end() , C[i] ) - B.begin()) ; 
    cout << Count << endl ; 
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
