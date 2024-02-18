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
#define ll long long 
struct YeahCard 
{
    int l , r ;
    char Type1 , Type2 ; 
};
 
void solve()
{
    int n ; cin >> n ; 
    char TS ; cin >> TS ; 
    vector<char> TypeOfCards = {'C', 'D', 'H','S'};
    map<char,deque<int>> Cards;
    vector<YeahCard> Rounds ; 
    for ( int i = 0 ; i < 2*n ; ++i ) 
    {
        string s ; cin >> s ; 
        Cards[s[1]].push_back((s[0]-'0'));
    }
    for ( auto & d : Cards )
    {
        if ( d.first == TS ) continue;
        Sort(d.second);
        while ( d.second.size() > 1 ) 
        {
            Rounds.push_back({d.second.front(),d.second.back(),d.first,d.first});
            d.second.pop_back() ; d.second.pop_front();
        }
    }
    for ( auto & d : Cards ) 
    {
        if ( d.first == TS ) 
        {
            Sort(d.second);
            while ( d.second.size() != 0 ) 
            {
                for ( auto & i : TypeOfCards ) 
                {
                    if ( i == TS ) continue;
                    if ( Cards[i].size() != 0 ) 
                    {
                        if ( d.second.size() == 0 ) 
                        {
                            cout << "IMPOSSIBLE" << endl ; return ; 
                        }
                        Rounds.push_back({d.second[0],Cards[i].front(),d.first,i});
                        d.second.pop_front();
                        Cards[i].pop_front();
                    }
                }
                while ( Cards[TS].size() > 1 ) 
                {
                    Rounds.push_back({Cards[TS].front(),Cards[TS].back(),TS,TS});
                    Cards[TS].pop_back();
                    Cards[TS].pop_front();
                }
                break;
            }
        }
    }
    for ( auto & d : Cards ) 
    {
        if ( d.second.size() != 0 ) 
        {
            cout << "IMPOSSIBLE" << endl ; return ; 
        }
    }
    for ( int i = 0 ; i < Rounds.size() ; ++i ) 
    {
        if ( Rounds[i].Type1 == Rounds[i].Type2 ) 
        {
            cout << min(Rounds[i].l , Rounds[i].r ) << Rounds[i].Type1 << " " << max(Rounds[i].l , Rounds[i].r ) << Rounds[i].Type1 << endl;
        }
        else
        {
            if ( Rounds[i].Type1 == TS ) 
            {
                cout << Rounds[i].r << Rounds[i].Type2 << " " << Rounds[i].l << Rounds[i].Type1 <<endl ; 
            }
            else
            {
                cout << Rounds[i].l << Rounds[i].Type1 << " " << Rounds[i].r << Rounds[i].Type2 <<endl ; 
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
