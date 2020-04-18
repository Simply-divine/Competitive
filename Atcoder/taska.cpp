#include <bits/stdc++.h>
using namespace std;
bool sortinrev(const pair< int,int > &a,const pair< int,int > &b)
{
    return (a.first>b.first);
}
int main()
{
    ios_base::sync_with_stdio(false);
    // For getting input from input.txt file 
    freopen("d_quite_big.in", "r", stdin); 
    // Printing the Output to output.txt file 
    freopen("d_outpur.out","w",stdout);
    cin.tie(NULL);
    cout.tie(NULL);
    int slices_required=0;
    cin>>slices_required;
    int diff_pizzas=0;
    cin>>diff_pizzas;
    vector< pair< int,int > > slices;
    for(int i=0,temp;i<diff_pizzas;i++){
        cin>>temp;
        slices.push_back(make_pair(temp,i));
    }
    sort(slices.begin(),slices.end(),sortinrev);
    vector<int> order;
    for(int i=0;i<diff_pizzas and slices_required>0;i++){
        if(slices_required>=slices[i].first){
            slices_required-=slices[i].first;
            order.push_back(slices[i].second);
        }
    }
    cout<<order.size()<<"\n";
    for(int i=order.size()-1;i>=0;i--) cout<<order[i]<<" ";
    return 0;
}

