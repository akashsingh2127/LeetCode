#include <bits/stdc++.h>
using namespace std;

/*
Approach:
1. Build the directed graph using the given invocations.
2. Perform a DFS starting from method k to mark all suspicious methods.
3. Traverse every invocation and check whether any non-suspicious method invokes a suspicious method.
4. If such an invocation exists, removing suspicious methods would break the project, so return all methods.
5. Otherwise, return only the non-suspicious methods.

Time Complexity: O(V + E)
where V = number of methods and E = number of invocations.

Space Complexity: O(V + E)
Adjacency list takes O(V + E), infected array takes O(V),
and the DFS recursion stack is O(V) in the worst case.
*/

class Solution
{
public:

// classic dfs code very simple
    void dfs(vector<vector<int>> &graph, int node, vector<bool> &infected)
    {
        infected[node] = true;

        for (int neighbour : graph[node])
        {
            if (!infected[neighbour])
            {
                dfs(graph, neighbour, infected);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>> &invocations)
    {

        // Build adjacency list ( most important part )
        vector<vector<int>> graph(n);
        for (auto &edge : invocations){  // this is an easy way of building adjacency list if the no of col r less
            graph[edge[0]].push_back(edge[1]);
        }

        // Mark all suspicious methods
        vector<bool> infected(n, false);
        dfs(graph, k, infected); // call dfs function

        // now time to check if any safe method invokes a suspicious method.. if it does then then and there we will return every nodes and if not the only non-suspicious methods will be returned.
        int flag = 0;
        for (auto &edge : invocations)
        {
            int u = edge[0];
            int v = edge[1];

            if (!infected[u] && infected[v])
            {
                flag = 1;
                break;
            }
        }

        vector<int> ans;

        if (flag)
        {
            // Cannot remove suspicious methods
            for (int i = 0; i < n; i++)
                ans.push_back(i);
        }
        else
        {
            // Return only non-suspicious methods
            for (int i = 0; i < n; i++)
            {
                if (!infected[i])
                    ans.push_back(i);
            }
        }

        return ans;
    }
};

int main()
{

    int n = 5;
    int k = 1;

    vector<vector<int>> invocations = {
        {1, 2},
        {2, 3},
        {4, 2}};

    Solution obj;

    vector<int> ans = obj.remainingMethods(n, k, invocations);

    cout << "Remaining Methods : ";

    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}

/*Remember one thing firstly i am initialixing every node in infected as false( no suspicious)  after dfs all the suspicious methods will be marked as true then using the another for loop i am checking for the non suspicious methods which is marked as (false)........ and using the (infected vector) itself u can check for the flag*/