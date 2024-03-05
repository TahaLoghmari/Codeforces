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
/* 
ASK WHY???!!! DOES IT MATTER IF.... ??!! ARE WE SUPPOSED TO DO LIKE HE SAID???!! DOES IT MATTER THAT THE SUBPROBLEMS ARE SEPERATED ? AM I SUPPOSED TO FIND THE OPTIMAL WAY BY MYSELF ? WHY DID HE GAVE ME SUCH CONSTRAINT ? CONSIDER ELIMINATING SOME CASSES OR EXCESS ELEMENTS 
*/
/* 
STAY ORGANIZED , DON'T RUSH , DON'T THINK ABOUT A SOLUTION THAT's BASED ON LUCK , DON'T CHECK WRONG ANSWERS 
CONSIDER REVERSE THINKING , THINKING BACKWARDS  
*/
class Solution
{
public:
void solve()
{
    ll n , k ; cin >> n >> k ; 
    vector<ll> A ; 
    for ( int i = 1 ; i <= sqrt(n) ; ++i ) 
    {
        if ( n % i == 0 ) 
        {
            if ( i == 1 ) 
            {
                A.push_back(n*(n+1)/2);
                A.push_back(1);
                continue;
            }
            ll Sum = 0  ;
            ll Start = 1 ; 
            while ( Start <= n ) 
            {
                Sum += Start ; 
                Start += i ; 
            }
            A.push_back(Sum);
            if ( (n/i) != i ) 
            {
                ll Sum2 = 0  ;
                ll Start2 = 1 ; 
                while ( Start2 <= n ) 
                {
                    Sum2 += Start2 ; 
                    Start2 += (n/i) ; 
                }
                A.push_back(Sum2);
            }
        }
    }
    Sort(A);
    for ( int i = 0 ; i < A.size() ; ++i ) cout << A[i] << " " ; 
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
