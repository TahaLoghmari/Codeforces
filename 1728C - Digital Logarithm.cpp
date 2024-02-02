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
    int n , Count = 0 ; cin >> n ; 
    vector<int> A(n) , B(n) ; Take(A) ; Take(B) ;
    map<int,int> OccA , OccB ; 
    for ( int i = 0 ; i < n ; ++i ) OccA[A[i]]++;
    for ( int i = 0 ; i < n ; ++i ) OccB[B[i]]++;
    for ( int i = 0 ; i < n ; ++i ) {
        if ( A[i] >= 10 && OccB[A[i]] == 0 ){
            Count++;
            string s = to_string(A[i]);
            A[i] = s.size() ; 
        }
        OccB[A[i]]--;
    }
    OccA.clear() ; 
    for ( int i = 0 ; i < n ; ++i ) OccA[A[i]]++;
    for ( int i = 0 ; i < n ; ++i ) {
        if ( B[i] >= 10 && OccA[B[i]] == 0 ) {
            Count++;
            string s = to_string(B[i]);
            B[i] = s.size() ;
        }
        OccA[B[i]]--;
    }
    for ( int i = 0 ; i < n ; ++i ) {
        if ( A[i] >= 10 ) A[i] = 1 ; 
        if ( B[i] >= 10 ) B[i] = 1 ; 
    }
    OccB.clear();
    for ( int i = 0 ; i < n ; ++i ) OccB[B[i]]++;
    OccA.clear() ; 
    for ( int i = 0 ; i < n ; ++i ) OccA[A[i]]++;
    for ( int i = 9 ; i >= 1 ; --i ) {
        if ( OccA[i] > OccB[i] ) {
            Count += OccA[i] - OccB[i] ; 
            OccA[1] += OccA[i] - OccB[i] ; 
        }
        else if ( OccA[i] < OccB[i] ){
            Count += OccB[i] - OccA[i] ; 
            OccB[1] += OccB[i] - OccA[i] ;
        }
    }
    cout << Count << endl ; 
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
