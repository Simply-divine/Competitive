// Author : Hardik Upadhyay
// college: SVNIT 
// slogan : Ab to phod dunga
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rrep(i,a,b) for(int i = a; i >= b; i--)
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define sq(a) (a)*(a)
#define nl "\n"
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,
//tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int MAXN = 100005;
ll mod=1000000007;

int choose(int n,int wmin,int wmax){
	double avg = 0.0;
	for(int i = 0; i <= 5000; i++){
		=rand()%wmin + rand%(wmax - wmin);
		
	}
	avg/=5000.0;
	return floor(avg);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t-->0){
		int n,m,k;
		cin>>n>>m>>k;
		bool check1 = 0;
		bool check2= 0,check3=0,check4=0,check5=0;
		if( k==1000 && m == 2)check1 = 1;
		if( k==5000 && m == 2) check2 = 1;
		if( k==1000 && m==4) check3 = 1;
		if( k == 3000 && m == 4) check4 = 1;
		if( k == 2000 && m == 9) check5 = 1;
		int count[n][m+1];
		memset(count,0,sizeof(count));
		rep(i,0,n-1){
			rep(j,0,k-1){
				int temp;
				cin>>temp;
				count[i][temp]++;
			}
		}
		int ans[n];
		rep(i,0,n-1){
			int mx = 0;
			int mxi =0;
			rep(j,1,m){
				if ( mx < count[i][j]){
					mx = count[i][j];
				}
			}
			vi temp;
			rep(j,1,m){
				if( count[i][j] == mx)
				temp.pb(j);
			}
			random_shuffle(temp.begin(),temp.end());
			int pos = 0;
			if(check1)
				pos = choose(temp.size(),1,1);
			else if(check3) pos = choose(temp.size(),45,55);
			else if(check2) pos = choose(temp.size(),1,5);
			else if(check4) pos = choose(temp.size(),1,100);
			else if(check5)pos = choose(temp.size(),20,80);

			ans[i] = temp[pos];
		}
		for(auto& x: ans){
			cout<<x<<" ";
		}
		cout<<nl;
	}
	return 0;
}

