#include <bits/stdc++.h>
using namespace std;
#define IWillWinTCPC cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0); 
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
#define pb push_back 
/* 
ASK WHY???!!! DOES IT MATTER IF.... ??!! ARE WE SUPPOSED TO DO LIKE HE SAID???!! DOES IT MATTER THAT THE SUBPROBLEMS ARE SEPERATED ? AM I SUPPOSED TO FIND THE OPTIMAL WAY BY MYSELF ? WHY DID HE GAVE ME SUCH CONSTRAINT ? CONSIDER ELIMINATING SOME CASSES OR EXCESS ELEMENTS 
*/
/* 
STAY ORGANIZED , DON'T RUSH , DON'T THINK ABOUT A SOLUTION THAT's BASED ON LUCK , DON'T CHECK WRONG ANSWERS  
*/
int n ; 
vector<int> A; 
vector<vector<int>> DP( 5 , vector<int>( 105 , -1 ) ) ; 
int Best ( int i , int prev ) 
{
    if ( i == n ) return 0 ; 
    if ( i && DP[prev][i] != -1 ) return DP[prev][i] ; 
    if ( i && A[i] == prev || A[i] == 0 ) DP[prev][i] = 1 + Best ( i + 1 , 0 ) ; 
    else if ( A[i] == 3 ) 
    {
        int FirstChoice = ( i && prev == 1 ? 1 : 0 ) + Best( i + 1 , 1 ) ; 
        int SecondChoice = ( i && prev == 2 ? 1 : 0 ) + Best( i + 1 , 2 ) ; 
        DP[prev][i] = min( FirstChoice , SecondChoice ) ; 
    }
    else DP[prev][i] = Best( i + 1 , A[i] ) ; 
    return DP[prev][i] ; 
}
void solve()
{
    cin >> n ; 
    A.resize(n) ; Take(A) ; 
    int Result = Best ( 0 , A[0] ) ; 
    cout << Result << endl ; 
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
