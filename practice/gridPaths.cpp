#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define SQ(a) (a)*(a)
#define DEBUG printf("hello\n")
#define nl "\n";

using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
	tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
int n;
int vis[10][10];
//vector<pair<int,int>> path;

bool isValid(int x,int y){
	if(x>=0&&x<n&&y>=0&&y<n)return true;
	return false;
}
int cnt;
int vis_cnt=0;
void solve(int n,int x,int y,char notToGo){
	if(x==n-1&&y==n-1){
		if(vis_cnt==n*n)
			cnt++;	
	}
	else{
		if(y==0){
			if(isValid(x-1,y)&&isValid(x+1,y)&&!vis[x-1][y]&&!vis[x+1][y]){
				return;
			}
		}
		if(y==n-1){
			if(isValid(x-1,y)&&isValid(x+1,y)&&!vis[x-1][y]&&!vis[x+1][y]){
				return;
			}
		}
		if(x==0){
			if(isValid(x,y+1)&&isValid(x,y-1)&&!vis[x][y+1]&&!vis[x][y-1]){
				return;
			}		
		}
		if(x==n-1){
			if(isValid(x,y+1)&&isValid(x,y-1)&&!vis[x][y+1]&&!vis[x][y-1]){
				return;
			}	
		}
		if(isValid(x-1,y)&&notToGo!='L'){
			if(!vis[x-1][y]){
				vis[x-1][y] = 1;
				vis_cnt++;
			//	path.PB(MP(x-1,y));
				solve(n,x-1,y,'R');
			//	path.pop_back();
				vis[x-1][y] = 0;
				vis_cnt--;
			}
			else{
				if(isValid(x,y-1)&&isValid(x,y+1)&&!vis[x][y-1]&&!vis[x][y+1]){
					return;
				}
			}
		}
		if(isValid(x+1,y)&&notToGo!='R'){
			if(!vis[x+1][y]){
				vis[x+1][y] = 1;
				vis_cnt++;
			//	path.PB(MP(x+1,y));
				solve(n,x+1,y,'L');
			//	path.pop_back();
				vis[x+1][y] = 0;
				vis_cnt--;
			}
			else{
				if(isValid(x,y-1)&&isValid(x,y+1)&&!vis[x][y-1]&&!vis[x][y+1]){
					return;
				}

			}
		}
		if(isValid(x,y+1)&&notToGo!='D'){
			if(!vis[x][y+1]){
				vis[x][y+1] = 1;
	//			path.PB(MP(x,y+1));
				vis_cnt++;
				solve(n,x,y+1,'U');
	//			path.pop_back();
				vis[x][y+1] = 0;
				vis_cnt--;
			}
			else{
				if(isValid(x-1,y)&&isValid(x+1,y)&&!vis[x-1][y]&&!vis[x+1][y]){
					return;
				}
			}

		}
		if(isValid(x,y-1)&&notToGo!='U'){
			if(!vis[x][y-1]){
				vis[x][y-1] = 1;
				vis_cnt++;
	//			path.PB(MP(x,y-1));
				solve(n,x,y-1,'D');
	//			path.pop_back();
				vis[x][y-1] = 0;
				vis_cnt--;
			}else{
				if(isValid(x-1,y)&&isValid(x+1,y)&&!vis[x-1][y]&&!vis[x+1][y]){
					return;
				}

			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	time_t start,end;
	cin>>n;
	time(&start);
	for(int i = 0; i < 10;i++){
		for(int j=0; j< 10;j++){
			vis[i][j] = 0;
		}
	}
	cnt=0;
	vis_cnt=1;
	vis[0][0]=1;
	solve(n,0,0,'D');
	time(&end);
	cout<<"The number of paths are "<<2*cnt<<nl;
	cout<<"Time taken "<<(end-start)<<nl;	
	return 0;
}




