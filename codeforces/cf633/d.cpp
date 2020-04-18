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
#define rrep(i,a,b) for(int i = a ; i >= b; i--)
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

//Number theory library
ll add(ll a,ll b,ll mod){
	return (a%mod+b%mod)%mod;
}
ll sub(ll a,ll b,ll mod){
	return (a%mod-b%mod+mod)%mod;
}
ll mul(ll a,ll b,ll mod){
	return ((a%mod)*(b%mod))%mod;
}

ll power(ll a, ll b,ll mod){
	ll ans = 1;
		while(b>0){
			if(b%2==1)ans=mul(ans,a,mod);
			a = mul(a,a,mod);
			b/=2;
		}
		return ans;
}

int gcd,x,y;
void extendedEuclid(int A,int B){
	if(B==0){
		gcd = A;
		x = 1;
		y = 0;
	}
	else{
		extendedEuclid(B,A%B);
		int temp = x;
		x = y;
		y = temp - (A/B)*y;
	}
}
ll modularInverse(ll A,ll M){
	extendedEuclid(A,M);
	return (x%M+M)%M;
}
//if M is prime 
//Fermat's theorem mod-1 ==> A^(M-2)
ll modularInversePrime(ll A,ll M){
	return power(A,M-2,M);
}
ll div(ll a,ll b,ll mod){
	return ((a%mod)*(modularInverse(b,mod)%mod))%mod;
}

//string library
vi prefix_function(string s){
	int n = s.length();
	vector<int> p(n);
	p[0] = 0;
	for(int i = 1; i < n; i++){
		int j = p[i - 1];
		while ( j > 0  && s[i]!=s[j]){
			j = p[j - 1];            // if current j is not the solution 	
		}
		if ( s[i] == s[j] ){
			j++;
		}
		p[i] = j;
	}
	return p; 
}

void reverse(string& s){
	reverse(s.begin(),s.end());
}

// tree library
struct node {
	int data;
	struct node *left;
	struct node *right;
};
struct node * newNode(int element){
	struct node * temp = (node *)malloc(sizeof(node *));
	temp->data = element;
	temp->left = temp->right = NULL;
	return temp;
}
int maxDepth(struct node * v){
	if(v == NULL){
		return 0;
	}
	else {
		int ldepth = maxDepth(v->left);
		int rdepth = maxDepth(v->right);
		return max(ldepth,rdepth)+1;
	}
}

//BST library
void preorder(struct node * root,int q){
	if(root){
		printf("%d ",root->data);
		preorder(root->left,q);
		preorder(root->right,q);
	}
}
void postorder(struct node *root){
	if(root){
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}
void inorder(struct node *root){
	if(root){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
struct node * insert(struct node *root,int data){
	if(root == NULL){
		return newNode(data);
	}
	else {
		if(data <= root->data){
			root->left = insert(root->left,data);
		}
		else {
			root->right = insert(root->right,data);
		}
	}
	return root;
}
struct node *lca(ll x,ll y,struct node *root){
	if(root->data < x && root->data < y){
		return lca(x,y,root->right);	
	}
	else if( root->data > x && root->data > y){
	 return lca(x,y,root->left);
	}	 
	return root;
}

// union-set library
vector<ii> pset(1000);
void initSet(int _size){pset.resize(_size);rep(i,0,_size-1) pset[i] = {i,1};}
int findSet(int i){ return pset[i].F == i? i : (pset[i].F = findSet(pset[i].F));}
int sizeOfSet(int i){ return pset[findSet(i)].S;}
void unionSet(int i,int j) { if(sizeOfSet(i) < sizeOfSet(j)) swap(i,j);pset[findSet(i)].F = pset[findSet(j)].F;}
bool isSameSet(int i,int j) { return findSet(i) == findSet(j);}
int numberOfSets(){int cnt=0;rep(i,0,pset.size()-1) if(pset[i].F == i)cnt++;return cnt;}

// segment-tree library
// segment tree is stored like heap array
#define RANGE_SUM 0
#define RANGE_MIN 1
#define RANGE_MAX 2
vi segment_tree;

void init_segment_tree(int N) {
	// if original array is of size N
	// the required segment_tree array length is 2*(2^(floor(log2(N)) + 1));
	int length = (int)(2*pow(2.0,floor( ( log((double)N)/log(2.0) ) + 1) ) );
	segment_tree.resize(length,0);	
}

void build_segment_tree(int code, int A[], int node, int b,int e){
	if( b == e) { 
		if( code == RANGE_SUM) segment_tree[node] = A[b];
		else segment_tree[node] = b;
	}
	else{
		// recursively compute the values in left and right subtree
		int leftIdx = 2*node,rightIdx = 2*node + 1;
		build_segment_tree(code,A,leftIdx,b, ( b + e)/2);
		build_segment_tree(code,A,rightIdx, ( b+e)/2+1,e);
		int lContent = segment_tree[leftIdx],rContent = segment_tree[rightIdx];
		if(code == RANGE_SUM) segment_tree[node] = lContent + rContent;
		else{
			int lValue = A[lContent];
			int rValue = A[rContent];
			if(code == RANGE_MIN) segment_tree[node] = (lValue < rValue)? lContent: rContent;
			else segment_tree[node] = (lValue > rValue)? lContent: rContent;
		}
	}
}

int query(int code,int A[], int node,int b,int e,int i,int j){
	if( i > e || j < b) return -1;
	if( b >= i && e <= j) return segment_tree[node];
	
	int p1 = query(code,A, 2*node, b, (b + e)/2, i,j);
	int p2 = query(code, A, 2*node+1, (b+e)/2+1, e, i,j);
	if( p1 == -1) return p2;
	if( p2 == -1) return p1;
	if(code == RANGE_SUM) return p1 + p2;
	else if ( code == RANGE_MIN) return (A[p1] < A[p2])? p1 : p2;
	else return (A[p1]>A[p2])? p1: p2;
}

void update(int code,int A[],int pos,int new_val,int node,int b, int e){
	if(b==e){
		segment_tree[node] = new_val;
	}
	else{
		int mid = (b + e)/2;
		if(pos <= mid){
			update(code,A,pos,new_val,2*node,b,mid);
		}	
		else update(code,A,pos,new_val,2*node + 1,mid + 1,e);
		int lContent = segment_tree[2*node];
		int rContent = segment_tree[2*node+1];
		if(code==RANGE_SUM) segment_tree[node] = lContent + rContent;
		else if(code == RANGE_MIN) segment_tree[node] = ( A[lContent] < A[rContent] )? lContent: rContent; 
		else segment_tree[node] = ( A[lContent] > A[rContent] )? lContent: rContent; 
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	return 0;
}
