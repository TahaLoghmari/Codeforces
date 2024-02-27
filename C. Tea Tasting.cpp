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
class Solution
{
public: 
vector<ll> A , B ; 
int n ; 
void solve()
{
    cin >> n ; 
    A.resize(n); B.resize(n) ; Take(A) ; Take(B) ;
    vector<ll> Prefix = B  , Result(n+1) , Rest(n+1) ; 
    for ( int i = 1 ; i < n ; ++i ) Prefix[i] += Prefix[i-1] ; 
    for ( int i = 0 ; i < n ; ++i ) 
    {
        int Where = upper_bound(Prefix.begin(),Prefix.end(),A[i]+( i ? Prefix[i-1] : 0 ) ) - Prefix.begin() ; 
        Result[i] += 1 ; 
        Result[Where] += - 1 ;
        ll Restt =  A[i] - ( Where ? Prefix[Where-1] : 0 ) + ( i ? Prefix[i-1] : 0 ) ;
        Rest[Where] += Restt;
    }
    for ( int i = 1 ; i < n ; ++i ) Result[i] += Result[i-1] ; 
    for ( int i = 0 ; i < n ; ++i ) Result[i] = B[i] * Result[i] + Rest[i] ; 
    for ( int i = 0 ; i < n ; ++i ) cout << Result[i] << " " ;
    cout << endl; 
}
};
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
    while ( t-- ){ Solution Sol ; Sol.solve(); } 
    return 0;
}
