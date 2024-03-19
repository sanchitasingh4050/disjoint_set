#include <iostream>
using namespace std;
#include<vector>
class DisjointSet {
    vector<int> rank, parent,size;
public:
    //CONSTRUCTOR
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n+1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i]=1;
        }
    }
    // TO FIND ULTIMATE PARENT 
    int FindUpar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = FindUpar(parent[node]);
    }

    void UnionByRank(int u, int v) {
        int ulp_u = FindUpar(u);
        int ulp_v = FindUpar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void UnionBySize(int u, int v){
        int ulp_u = FindUpar(u);
        int ulp_v = FindUpar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] <size[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (size[ulp_v] < size[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
int main() {
    DisjointSet ds(7);
    ds.UnionBySize(1,2);
    ds.UnionBySize(2,3);
    ds.UnionBySize(4,5);
    ds.UnionBySize(6,7);
    ds.UnionBySize(5,6);
    ds.UnionBySize(3,7);
    // IF ULTIMATE PARENT OF U AND V ARE THE SAME THEY BELONG TO THE SAME COMPONENT
      if(ds.FindUpar(3)==ds.FindUpar(7)){
         cout<<"They belong to the same component"<<endl;
     }
     else{
         cout<<"They don't belong to the same component";
     }
     
    return 0;
}