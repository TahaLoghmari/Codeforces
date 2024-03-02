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
void solve()
{
    int n , k ; cin >> n >> k ; 
    string s ; cin >> s ; 
    ll l = 0 , r = 0 , HowManyB = 0 , HowManyA = 0 , Max = MIN ;
    while ( r < n ) 
    {
        HowManyB += s[r] =='b' ; 
        while ( HowManyB - k > 0 && l < r ) 
        {
            HowManyB -= s[l] == 'b' ; 
            l++;
        }
        Max = max( Max , r - l + 1 ) ;
        r++;
    }
    l = 0 ; r = 0 ; 
    while ( r < n ) 
    {
        HowManyA += s[r] =='a' ; 
        while ( HowManyA - k > 0 && l < r ) 
        {
            HowManyA -= s[l] == 'a' ; 
            l++;
            
        }
        Max = max( Max , r - l + 1 ) ;
        r++;
    }
    cout << ( Max == MIN ? n : Max ) << endl ; 
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
