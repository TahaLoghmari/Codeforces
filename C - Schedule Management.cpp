#include <bits/stdc++.h>
using namespace std;
#define IWillWinTCPC cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0);
#define int long long 
#define Take(x) for ( auto & d : x ) cin >> d ; 
#define No cout << "No" << endl  
#define Yes cout << "Yes" << endl  
#define Sort(x) sort( x.begin() , x.end() ) ;
#define RSort(x) sort( x.begin() , x.end() ) ; reverse ( x.begin() , x.end() ) ; 
#define MOD (int)( 1e9 + 7 ) 
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
    int n , m ; cin >> n >> m ; 
    vector<int> A(m) , Tasks(n) ; Take(A); 
    for ( int i = 0 ; i < m ; ++i ) Tasks[A[i]-1]++;
    int TotalTasks = Sum(Tasks) , l = 1 , r = m * 2 ; 
    while ( l <= r ) 
    {
        int x = ( l + r ) / 2 , Help = 0 , WorkDone = 0 ;
        for ( int i = 0 ; i < n ; ++i ) 
        {
            if ( x >= Tasks[i] ) 
            {
                WorkDone += Tasks[i];
                Help += ( x - Tasks[i] ) / 2;
            } 
            else WorkDone += x;
        }
        if ( WorkDone + Help >= m ) r = x - 1 ; 
        else l = x + 1 ; 
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
