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
#define isSorted(x) is_sorted(A.begin(),A.end())
/* 
ASK WHY???!!! DOES IT MATTER IF.... ??!! ARE WE SUPPOSED TO DO LIKE HE SAID???!! DOES IT MATTER THAT THE SUBPROBLEMS ARE SEPERATED ? AM I SUPPOSED TO FIND THE OPTIMAL WAY BY MYSELF ? WHY DID HE GAVE ME SUCH CONSTRAINT ? CONSIDER ELIMINATING SOME CASSES OR EXCESS ELEMENTS 
*/
/* 
STAY ORGANIZED , DON'T RUSH , DON'T THINK ABOUT A SOLUTION THAT's BASED ON LUCK , DON'T CHECK WRONG ANSWERS  
*/

void solve()
{
    int m , s , Sum1 = 0 , Sum2 = 0 ; cin >> m >> s ; 
    string MinResult = "" , MaxResult = "" ; 
    int CopyS = s , KeepInMind = 0 ; 
    for ( int i = 0 ; i < m ; ++i ) {
        for ( int j = i == 0 && m != 1 ? 1 : 0 ; j <= 9 ; ++j ) {
            int Left = 9 * (m - ( i + 1 ) ); 
            if ( (CopyS - j - KeepInMind) > Left ) continue;
            else{
                MinResult += to_string(j);
                KeepInMind += j ; 
                break;
            } 
        }
    }
    int CopyS2 = s , KeepInMind2 = 0 ; 
    for ( int i = 0 ; i < m ; ++i ) {
        for ( int j = 9 ; j >= 0 ; --j ) {
            int Left = 9 * (m - ( i + 1 ) ); 
            if ( (CopyS2 - j - KeepInMind2) > Left ) continue;
            else if ( KeepInMind2 + j <= CopyS2 ){
                MaxResult += to_string(j);
                KeepInMind2 += j ; 
                break;
            } 
        }
    }
    for ( int i = 0 ; i < MinResult.size() ; ++i ) {
        Sum1 += MinResult[i] - '0' ; Sum2 += MaxResult[i] - '0' ;
    }
    if ( Sum1 != s || Sum2 != s ) cout << -1 << " " << -1 << endl ; 
    else cout << MinResult << " " << MaxResult << endl ; 
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
