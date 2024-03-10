#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_pbds;
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
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
class Solution 
{
public:
void solve()
{
    int n ; cin >> n ; 
    vector<ll> A(n) ; Take(A) ; 
    string s ; cin >> s ; 
    int q ; cin >> q ; 
    ll Zeros = 0 , Ones = 0 ; 
    for ( int i = 0 ; i < n ; ++i ) 
    {
        if ( s[i] == '0' ) Zeros^= A[i];
        if ( s[i] == '1' ) Ones ^= A[i] ; 
    }
    for ( int i = 1 ; i < n ; ++i ) A[i] ^= A[i-1] ; 
    for ( int i = 0 ; i < q ; ++i ) 
    {
        int O ; cin >> O ; 
        if ( O == 2 ) 
        {
            int Bit ; cin >> Bit ; 
            if ( Bit == 0 ) cout << Zeros << " " ; 
            else cout << Ones << " " ; 
        }
        else
        {
            int l , r ; cin >> l >> r ; 
            l--; r-- ; 
            Zeros ^= A[r] ^ ( l == 0 ? 0 : A[l-1]) ; 
            Ones ^= A[r] ^ ( l == 0 ? 0 : A[l-1]) ; 
        }
    }
    cout << endl ; 
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
