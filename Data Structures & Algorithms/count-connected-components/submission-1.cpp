class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(parent[x] == x){
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void Union(int u, int v){
        int parent_u = find(u);
        int parent_v = find(v);

        if(parent_u == parent_v){
            return;
        }

        if(rank[parent_u] > rank[parent_v]){
            parent[parent_v] = parent_u;
        }
        if(rank[parent_u] < rank[parent_v]){
            parent[parent_u] = parent_v;
        }
        if(rank[parent_u] == rank[parent_v]){
            parent[parent_u] = parent_v;
            rank[parent_v]++;
        }
    }

    /*
    step samjho isko karne ka,
    1. rank aur parent ka arry banao,
    2. pehle sare component ko alag alag consider karo, for loop laga k
    3. fir dono ko parent ko find karo  agar parent same, then component-- kro but agar joint nhi h toh joint karo

    Rule of joint as per rank
    4. jiska rank kam hai usme join karna hai tumhe taki ek hi side bda na ho

    5. end me jitna component bache use return kar do..

    */


    int countComponents(int n, vector<vector<int>>& edges) {
        int component = n;
        parent.resize(n);
        rank.resize(n, 0);

        for(int i=0; i<n; i++){
            parent[i] = i;
        }

        for(auto& edge : edges){
            
            if(find(edge[0]) != find(edge[1])){
                component--;
                Union(edge[0], edge[1]);
            }
        }
        return component;
    }
};
