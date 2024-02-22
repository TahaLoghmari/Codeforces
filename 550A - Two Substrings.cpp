#include <bits/stdc++.h>
using namespace std;
#define IWillWinTCPC cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0);
#define ll long long 
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
#define isSorted(x) is_sorted(A.begin(),A.end())
#define Unique(x) x.erase(unique(x.begin(),x.end()),x.end());
void solve()
{
    string s ; cin >> s ; 
    bool FoundAB = false , FoundBA = false ; 
    int B = 0, A = 0 ; 
    for ( int i = 0 ; i < s.size() ; ++i ) 
        if ( s[i] == 'A' && s[i+1] == 'B' ) 
        {
            FoundAB = true ;
            B = i + 1 ;
            break;
        }
    for ( int i = 0 ; i < s.size() ; ++i ) 
        if ( s[i] == 'B' && s[i+1] == 'A' ) 
        {
            FoundBA = true ; 
            A = i + 1 ; 
            break;
        }
    if ( FoundAB ) 
    {
        for ( int i = B + 1 ; i < s.size() ; ++i ) if ( s[i] == 'B' && s[i+1] == 'A' ) { Yes; return ; }
    }
    if ( FoundBA )
    {
        for ( int i = A + 1 ; i < s.size() ; ++i ) if ( s[i] == 'A' && s[i+1] == 'B' ) { Yes; return ; }
    }
    No;
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
    // cin >> t ; 
    while ( t-- ) solve();
    return 0;
}
