class Solution {
    
    bool topoSort(int node, vector<int> adj[],  vector<int> &visited,  vector<int> &pathVis, stack<int> &st) {
        visited[node] = 1;
        pathVis[node] = 1;

        for(auto it : adj[node]) {
            if(!visited[it]) {
                if(topoSort(it, adj, visited, pathVis, st)) return true;
            } else {
                if(pathVis[it]) {
                    return true;
                }
            }
        }

        st.push(node);
        pathVis[node] = 0;
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // adj list 
        vector<int> adj[numCourses];

        vector<int> visited(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        for(auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }
        stack<int> st;
        for(int i = 0; i < numCourses; i++) {
            if(!visited[i]) {
                // if we find cycle at any point it means we cannot schedule the course
                // so we return empty array
                if(topoSort(i, adj, visited, pathVis, st)) return {};
            }
        }
        
        if(st.size() != numCourses) return {};
        vector<int> result;
        while(!st.empty()) {
            auto it = st.top();
            st.pop();
            result.push_back(it);
        }
        return result;
    }
};
