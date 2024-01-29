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
/* 
ASK WHY???!!! DOES IT MATTER IF.... ??!! ARE WE SUPPOSED TO DO LIKE HE SAID???!! DOES IT MATTER THAT THE SUBPROBLEMS ARE SEPERATED ? AM I SUPPOSED TO FIND THE OPTIMAL WAY BY MYSELF ? WHY DID HE GAVE ME SUCH CONSTRAINT ? CONSIDER ELIMINATING SOME CASSES OR EXCESS ELEMENTS 
*/
/* 
Stay Organized , DON'T RUSH , DON'T THINK ABOUT A SOLUTION THAT's BASED ON LUCK , DON'T CHECK WRONG ANSWERS  
*/
 
void solve() 
{
    int n , q , IndexOfMaxElement = 0 ; cin >> n >> q ; 
    vector<int> A(n) ; Take(A) ; 
    for ( int i = 0 ; i < n ; ++i ) 
    {
        if ( A[i] == n ){ IndexOfMaxElement = i ; break ;} 
    }
    map<int,vector<int>> Wins ; 
    map<int,int> TotalWins ;  
    int Previous = A[0] , WhichRound = 0 , TotalRoundTillMax = IndexOfMaxElement - 1 > 0 ? IndexOfMaxElement - 1 : 0 ; 
    for ( int i = 0 ; i < IndexOfMaxElement - 1 ; ++i ) 
    {
        int Now = max(Previous,A[i+1]) ; 
        TotalWins[Now]++;
        Wins[Now].push_back(WhichRound);
        WhichRound++;
        Previous = Now ; 
    }
    for ( int i = 0 ; i < q ; ++i ) 
    {
        int P , R ; cin >> P >> R ; 
        if ( A[P-1] == n ) 
        {
            if ( R <= TotalRoundTillMax ) cout << 0 << endl ; 
            else cout << R - TotalRoundTillMax << endl ; 
        }
        else
        {
            if ( ( P - 1 ) > IndexOfMaxElement ) cout << 0 << endl ; 
            else
            {
                if ( R >= TotalRoundTillMax ) cout << TotalWins[A[P-1]] << endl ;
                else
                {
                    auto Where = lower_bound(Wins[A[P-1]].begin(),Wins[A[P-1]].end(),(R-1));
                    if ( Where == Wins[A[P-1]].end() ) 
                    {
                        cout << TotalWins[A[P-1]] << endl ; 
                    }
                    else
                    {
                        // cout << (Where - Wins[A[P-1]].begin())+1 << endl ; 
                        if ( *(Where) > ( R - 1 ) ) 
                        {
                            if ( Where-1 == Wins[A[P-1]].begin() ) 
                            {
                                cout << 0 << endl ; 
                            }
                            else
                            {
                                cout << (Where - 1 ) - Wins[A[P-1]].begin()+1 << endl ; 
                            }
                        }
                        else if ( *(Where) == ( R - 1 ) ) 
                        {
                            cout << (Where - Wins[A[P-1]].begin())+1 << endl ;
                        }
                    }
                    // if ( R - 1 > Track[A[P-1]] ) cout << TotalWins[A[P-1]] << endl;
                    // else cout << Wins[A[P-1]][R-1] << endl ;
                }
            }
        }
    }
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
