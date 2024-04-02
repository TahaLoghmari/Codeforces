#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define IWillWinTCPC cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0);
#define ll long long 
#define Take(x) for ( auto & d : x ) cin >> d ; 
#define No cout << "NO" << endl  
#define Yes cout << "YES" << endl  
#define CB(x) 64 - __builtin_clzll(x) 
#define Sort(x) sort( x.begin() , x.end() ) ;
#define RSort(x) sort( x.begin() , x.end() ) ; reverse ( x.begin() , x.end() ) ; 
#define MOD (ll)(1e9+7)
#define BS(A,x) binary_search(A.begin(),A.end(),x)
#define INF LONG_LONG_MAX 
#define Sum(A) accumulate( A.begin() , A.end() , (ll)0 ) 
#define Max(A) (ll)(*max_element(A.begin(),A.end()))
#define Min(A) (ll)(*min_element(A.begin(),A.end()))
#define endl '\n' 
#define All(x) x.begin(),x.end()
#define isSorted(x) is_sorted(A.begin(),A.end())
#define Unique(x) x.erase(unique(x.begin(),x.end()),x.end());
#define Inverse(x) (((1ll<<CB(x))-1)^x)
#define CountOnes(x) __builtin_popcountll(x)
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
/* 
ASK WHY???!!! DOES IT MATTER IF.... ??!! ARE WE SUPPOSED TO DO LIKE HE SAID???!! DOES IT MATTER THAT THE SUBPROBLEMS ARE SEPERATED ? AM I SUPPOSED TO FIND THE OPTIMAL WAY BY MYSELF ? WHY DID HE GAVE ME SUCH CONSTRAINT ? CONSIDER ELIMINATING SOME CASSES OR EXCESS ELEMENTS 
*/
/* 
STAY ORGANIZED , DON'T RUSH , DON'T THINK ABOUT A SOLUTION THAT's BASED ON LUCK , DON'T CHECK WRONG ANSWERS 
CONSIDER REVERSE THINKING , THINKING BACKWARDS  
READ THE PROBLEM CAREFULLY , DONT RUSH 
m = l + (r - l) / 2;
BITWISE:
- WHEN YOU HAVE A BITWISE PROBLEM ON NUMBERS ALWAYS LOOK AT THE NUMBERS IN TERM OF DIGITS SO YOU CAN NOTICE SOMETHING OR COME UP WITH AN OBSERVATION
IF YOU HAVE A NUMBER THAT HAVE SQRT ITS MODULO BY 4 CAN BE ONLY 0 OR 1 
IF IT'S A SOLUTION THAT NORMALLY REQUIRES O(n*n) , FIRSTLY TRY TO THINK ABOUT THE BRUTE FORCE
SOLUTION AND TRY TO OPTIMIZE IT , CONSIDER THINKING BACKWARDS 
IF YOU HAVE TWO THINGS YOU ARE CONSIDERING TO ITERATE ON THEM OR DO SOMETHING ON THEM , CONSIDER ITERATING ON ONLY ONE OF THEM AND GET THE OTHER ONE IN ANOTHER WAY 
*/
class Solution 
{
public:
int n ; 
vector<vector<string>> Graph ; 
vector<bool> Vis ; 
void dfs( int Pos ) 
{
    Vis[Pos] = true ; 
    for ( int i = 0 ; i < Graph[Pos].size() ; ++i ) 
    {
        string t = Graph[Pos][i] ; 
        for ( int j = 0 ; j < t.size() ; ++j ) if ( !Vis[t[j]-'a'] ) dfs(t[j]-'a');
    }
}
void solve()
{
    cin >> n ; 
    Graph.resize(26);
    Vis.resize(26);
    vector<string> Stock ; 
    for ( int i = 0 ; i < n ; ++i ) 
    {
        string s ; cin >> s ;
        Stock.push_back(s);
        for ( int b = 0 ; b < s.size() ; ++b ) Graph[(s[b]-'a')].push_back(s);
    }
    ll Count = 0 ; 
    for ( int i = 0 ; i < 26 ; ++i ) 
    {
        if ( !Vis[i] && Graph[i].size() != 0 )  
        {
            Count++;
            dfs(i);
        }
    }
    cout << Count << endl ; 
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
