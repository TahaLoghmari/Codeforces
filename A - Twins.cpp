#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set> 
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h>
#define ll long long 
#define FIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
 
int main() 
{
  FIO ;
	int n ,x;
	cin >> n ;
	int arr[n];
	for ( int i = 0 ; i < n  ; ++i )
	{
		cin >> x ;
		arr[i] = x ;
	}
	sort(arr, arr+n) ;
	int MinCoins = 0 ;
	int Sum1= 0 ;
	if (n == 1 )
	{ 
		cout << "1" ;
	}
	else
	{
		for ( int i = n - 1 ; i > 0 ; i-- )
		{
			int Sum2 = 0 ;
			Sum1 +=  arr[i] ;
			MinCoins ++ ;
			for ( int j = 0 ; j < i ; j++ )
			{
				Sum2 += arr[j] ;
			}
			if ( Sum1 == Sum2)
			{
				MinCoins++ ;
				break;
			}
			else if ( Sum1 > Sum2 )
			{
				break ;
			}
		}
		cout << MinCoins ;
	}
  return 0;
	
}
