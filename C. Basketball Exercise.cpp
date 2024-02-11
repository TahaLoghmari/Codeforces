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
#define ll long long 
/* 
ASK WHY???!!! DOES IT MATTER IF.... ??!! ARE WE SUPPOSED TO DO LIKE HE SAID???!! DOES IT MATTER THAT THE SUBPROBLEMS ARE SEPERATED ? AM I SUPPOSED TO FIND THE OPTIMAL WAY BY MYSELF ? WHY DID HE GAVE ME SUCH CONSTRAINT ? CONSIDER ELIMINATING SOME CASSES OR EXCESS ELEMENTS 
*/
/* 
STAY ORGANIZED , DON'T RUSH , DON'T THINK ABOUT A SOLUTION THAT's BASED ON LUCK , DON'T CHECK WRONG ANSWERS  
*/
/* IF YOU'RE ASKED FOR MIN OR MAX WHAT WILL YOU DO??? --->>> BINARY SEARCH ON ANSWERS ( MOST OF THE TIME )*/ 
ll BestTeam( vector<vector<ll>>& BothTeams, vector<vector<ll>>& DP , ll i , int Row , int n ) 
{
    if ( i > n ) return 0;
    if ( DP[Row][i] != 0 ) 
    {
        return DP[Row][i];
    }
        ll First = BothTeams[(Row+1)%2][i] + BestTeam( BothTeams , DP , i + 1 , (Row+1)%2 ,  n );
        ll Second = BothTeams[(Row+1)%2][i] + BestTeam( BothTeams , DP , i + 2 , (Row+1)%2 , n );
    return DP[Row][i] = max ( First , Second ) ; 
}
void solve()
{
    int n ; cin >> n ; 
    vector<vector<ll>> BothTeams(2,vector<ll>(n,0)) ; Take(BothTeams[0]) ; Take(BothTeams[1]);
    vector<vector<ll>> DP(2,vector<ll>(n,0));
    ll FirstChoice = BestTeam( BothTeams , DP , 0 , 0 , n - 1 ) ;
    ll SecondChoice = BestTeam( BothTeams , DP , 0 , 1 , n - 1 ) ;
    cout << max ( FirstChoice , SecondChoice ) << endl ; 
}
int main() 
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
