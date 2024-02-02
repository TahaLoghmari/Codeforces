#include <bits/stdc++.h>
using namespace std ;
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
/* 
ASK WHY???!!! DOES IT MATTER IF.... ??!! ARE WE SUPPOSED TO DO LIKE HE SAID???!! DOES IT MATTER THAT THE SUBPROBLEMS ARE SEPERATED ? AM I SUPPOSED TO FIND THE OPTIMAL WAY BY MYSELF ? WHY DID HE GAVE ME SUCH CONSTRAINT ? CONSIDER ELIMINATING SOME CASSES OR EXCESS ELEMENTS 
*/
/* 
STAY ORGANIZED , DON'T RUSH , DON'T THINK ABOUT A SOLUTION THAT's BASED ON LUCK , DON'T CHECK WRONG ANSWERS  
*/

void solve() 
{
    int n , l1 , r1 ; cin >> n ; 
    vector<pair<int,int>> A(n) ; 
    for ( int i = 0 ; i < n ; ++i ) 
    {
        cin >> l1 >> r1 ; 
        A[i] = { l1 , r1 } ; 
    }    
    int l = 0 , r = 1e9 , k ; 
    while ( l <= r ) 
    {
        k = ( l + r ) / 2 ;
        int right = 0 , left = 0 ;  
        bool CanWe = true ; 
        for ( int i = 0 ; i < n ; ++i ) 
        {
            right = min( A[i].second , right + k ) ; 
            left = max ( A[i].first , left - k ) ; 
            if ( right < left ) CanWe = false ;             
        }
        if ( !CanWe ) l = k + 1 ; 
        else r = k - 1 ; 
    }
    cout << l << endl ; 
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
