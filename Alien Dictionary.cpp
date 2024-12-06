class Solution{
private:

    void dfs(int node, vector<int> &visited, stack<int> &st, vector<int> adj[]){
        visited[node] = 1;
        for(auto it : adj[node]){
            if(!visited[it]){
                dfs(it, visited, st, adj);
            }
        }
        
        st.push(node);
    }    

public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K];
        for(int i = 0; i < N-1; i++){
            string s1 = dict[i];
            string s2 = dict[i + 1];
            
            int m = min(s1.size(), s2.size());
            for(int j = 0; j < m; j++){
                if(s1[j] != s2[j]){
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }
        stack<int> st;
        vector<int> visited(K, 0);
        for(int i = 0; i < K; i++){
            if(!visited[i]){
                dfs(i, visited, st, adj);
            }
        }
        
        string ans = "";
        while(!st.empty()){
            int chracter = st.top();
            st.pop();
            ans = ans + char(chracter + 'a');
        }
        return ans;
    }
};
