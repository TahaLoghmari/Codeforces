#include <bits/stdc++.h>
using namespace std;
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

void solve() {
    int n ; cin >> n ; 
    vector<pair<int,int>> Operations ; 
    for ( int i = 0 ; i < n ; ++i ) 
    for ( int j = 0 ; j < n ; ++j ) {
        char x ; cin >> x ; 
        if ( x == '1' ) Operations.push_back({i,j});
    }
    vector<set<int>> M(n) ; 
    for ( int i = 0 ; i < n ; ++i ) M[i].insert(i+1);
    for ( int i = 0 ; i < Operations.size() ; ++i ) 
    for ( auto & E : M[Operations[i].first] ) M[Operations[i].second].insert(E);
    for ( int i = 0 ; i < n ; ++i ) {
        cout << M[i].size() << " " ; 
        for ( auto & E : M[i] ) cout << E << " " ; 
        cout << endl ; 
    }
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
