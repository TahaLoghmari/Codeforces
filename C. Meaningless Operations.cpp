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
ll inver ( ll x , ll Bits ) 
{
    return ((1ll<<Bits)-1)^x;
}
ll countBits(ll number) {
    if (number <= 0) return 0;
    ll bits = (ll)(log2(number)) + 1;
    return bits;
}
void solve()
{
   int q ; cin >> q ; 
   for ( int i = 0 ; i < q ; ++i ) 
   {
        int x ; cin >> x ; 
        ll Bits = countBits(x) ;
        ll Inverse = inver( x , Bits ) ;
        if ( Inverse != 0 ) 
        {
            ll XORR =  x ^ Inverse ; 
            ll ANDD = x & Inverse ; 
            ll GCDD = __gcd(XORR,ANDD) ;
            cout << GCDD << endl ; 
        } 
        else
        {
            bool Enter = false ; 
            int Max = 1 ; 
            for ( int i = 2 ; i <= sqrt(x) ; ++i ) 
            {
                if ( x % i == 0 ) 
                {
                    Max = max( Max , max( i , x/i ) )  ;
                }
            }
            cout << Max << endl ; 
        }
   } 
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
    // cin >> t ; 
    while ( t-- ){ Solution Sol ; Sol.solve(); } 
    return 0;
}
