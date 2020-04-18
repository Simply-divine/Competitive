#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define SQ(a) (a)*(a)
#define DEBUG printf("hello\n")
#define nl "\n"
#define INF std::numeric_limits<int>::max()
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
ll mod=1000000009;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//knapsack problem
	// given a set of weights determine all the weights that you can get through those weights
	int n;//number of weights
	cin>>n;
	int weights[n+1];
	REP(i,1,n)cin>>weights[i];
	//find the maximum sum using that weights
	int sum=0;
	REP(i,1,n){
		sum+=weights[i];
	}
	//approach 1 simple 
	bool possible[n+1][sum+1];
	REP(i,1,n)REP(j,1,sum)possible[i][j] = false;
	possible[0][0] = true;
	cout<<"hello"<<possible[0][0]<<nl;
	REP(i,1,n){
		REP(j,0,sum){	
			cout<<possible[i][j]<<nl;
			if(j - weights[i]>=0) possible[i][j] |= possible[i-1][j-weights[i]];
			possible[i][j] |=possible[i-1][j];
			cout<<possible[i][j]<<nl;
		}
	}
	REP(i,0,sum){
		if(possible[n][i])
			cout<<i<<" ";
	}
	cout<<nl;
	// to find all the weights between 0 and sum that are possible using these weights, we will use a boolean array
	/*
	bool possible[sum+1];
	REP(i,0,sum){possible[i] = false;}
	possible[0] = true; //we can make sum=0 using none of the weights
	REP(i,1,n){
			for(int j = sum;j>=0;j--)
				if(possible[j])possible[j+weights[i]]=true;
	}
	REP(i,0,sum){
		if(possible[i]){
			cout<<i<<" ";
		}
	}
	*/
	return 0;
}




