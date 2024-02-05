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
    int n ; cin >> n ; 
    vector<int> A(n) ; Take(A); 
    if ( n == 1 ) {cout << A[0] << endl ; return ; }
    int Max = *max_element(A.begin()+1,A.end()) , BestL = 0 , BestR = 0 ;
    for ( int i = 0 ; i < n ; ++i ) {
        if ( A[i] == Max ){
            if ( i != n - 1 && A[i-1] < A[(i+1)]) BestR = i - 1 ;
            else if ( i == n - 1 && A[i-1] > A[0] ) BestR = i - 1 ; 
            else if ( i == 1 && i != n - 1 && A[i-1] > A[i+1] ) BestR = i - 1 ;  
            else if ( i == n - 1 ) BestR = i ;
            else BestR = i - 1 ; 
            break; 
        }  
    } 
    BestL = BestR ; 
    for ( int i = BestR - 1 ; i >= 0 ; --i ) 
    if ( i != 0 && A[i] >= A[0] ) BestL = i  ; 
    else break ; 
    for ( int i = BestR + 1 ; i < n ; ++i ) cout << A[i] << " " ; 
    for ( int i = BestR ; i >= BestL ; --i ) cout << A[i] << " " ;
    for ( int i = 0 ; i < BestL ; ++i ) cout << A[i] << " " ;  
    cout << endl ; 
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
