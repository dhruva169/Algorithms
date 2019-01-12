#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef set<int> si; 
typedef map<string, int> msi;

#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define testcases(t) int t;cin>>t;while(t--)
#define leadzero(a) __builtin_clz(a) // count leading zeroes 
#define trailzero(a) __builtin_ctz(a) // count trailing zeroes

#define rep(i,a,b)	for(ll i=a;i<b;i++)
#define TRvi(c, it)	for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define	TRvii(c, it)	for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it)	for (msi::iterator it = (c).begin(); it != (c).end(); it++)

#define INF 2000000000
#define MEMSET_INF 127
#define MEMSET_HALF_INF 63
//memset(dist, MEMSET_INF, sizeof dist); 	 useful to initialize shortest path distances 
//memset(dp_memo, -1, sizeof dp_memo); 		 useful to initialize DP memoization table 
//memset(arr, 0, sizeof arr); 				 useful to clear array of integer

#define	endl		'\n'
#define all(a)      (a).begin(),(a).end()
#define sz(x)       (ll) x.size()
#define hell        1000000007


int binarysearch(ll a[], ll l, ll r, ll x){
	if(r>=1){
		ll mid = l+(r-1)/2;
		if(a[mid]==x){
			return mid;
		}
		if(a[mid]>x){
			return binarysearch(a,1,mid-1,x);
		}
		return binarysearch(a,mid+1,r,x);
	}
	return -1;
}

int main()
{
	fastio;
	
	ll n,key;
	cin>>n>>key;
	ll a[n];
	rep(i,0,n){
		cin>>a[i];
	}
	sort(a,a+n);
	ll result = binarysearch(a,0,n-1,key);
	cout<<result<<endl;

	return 0;
}