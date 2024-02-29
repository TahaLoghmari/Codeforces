#include <bits/stdc++.h>
using namespace std;
#define IWillWinTCPC cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0);
#define ll long long 
#define Take(x) for ( auto & d : x ) cin >> d ; 
#define No cout << "No" << endl  
#define Yes cout << "Yes" << endl  
#define Sort(x) sort( x.begin() , x.end() ) ;
#define RSort(x) sort( x.begin() , x.end() ) ; reverse ( x.begin() , x.end() ) ; 
#define MOD 1e9 + 7 
#define Sum(A) accumulate( A.begin() , A.end() , (int)0 ) 
#define MAX LONG_LONG_MAX 
#define MIN LONG_LONG_MIN 
#define endl '\n' 
#define isSorted(x) is_sorted(A.begin(),A.end())
#define Unique(x) x.erase(unique(x.begin(),x.end()),x.end());
class Solution
{
public:
ll countBits(ll number) {
    if (number <= 0) {
        return 0;
    }
    ll bits = (ll)(log2(number)) + 1;
    return bits;
}
void solve()
{
    int n , x ; cin >> n ; 
    map<ll,ll> Occ ; 
    for ( int i = 0 ; i < n ; ++i ){ cin >> x ; Occ[countBits(x)]++; }
    ll Count = 0 ; 
    for ( auto & d : Occ ) Count += d.second*(d.second-1)/2 ; 
    cout << Count << endl ; 
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
