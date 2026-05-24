
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> redGraph[n], greenGraph[n];

    // Forming the graph by red edges.
    for (vector<int> edge: redEdges)
    {
        redGraph[edge[0]].push_back(edge[1]);
    }

    // Forming the graph by green edges.
    for (vector<int> edge: blueEdges)
    {
        greenGraph[edge[0]].push_back(edge[1]);
    }

    vector<vector<int>> visited(n, vector<int>(2, 0));

    vector<vector<int>> pathLength(n, vector<int>(2, 1e9));

    queue<vector<int>> q;

    // Pushing in node with label zero, taking last edge to be red.
    q.push({0, 0});
    visited[0][0] = 1;
    pathLength[0][0] = 0;

    // Pushing in node with label zero, taking last edge to be green.
    q.push({0, 1});
    visited[0][1] = 1;
    pathLength[0][1] = 0;

    // Finding shortest path for each node till we have unprocessed nodes in the queue.
    while (!q.empty())
    {

        vector<int> cur = q.front();
        q.pop();

        // Checking if last edge in path to node cur[0], if red or green.
        if (cur[1] == 1)
        {
            // If last edge is green, then we should next traverse through the red edges.
            for (int next: redGraph[cur[0]])
            {
                if (visited[next][0] == 0)
                {

                    q.push({next, 0});
                    visited[next][0] = 1;
                    pathLength[next][0] = pathLength[cur[0]][1] + 1;
                }

            }

        }
        else
        {
            // If last edge is red, then we should next traverse through the green edges.
            for (int next: greenGraph[cur[0]])
            {
                if (visited[next][1] == 0)
                {

                    q.push({next, 1});
                    visited[next][1] = 1;
                    pathLength[next][1] = pathLength[cur[0]][0] + 1;
                }

            }

        }

    }

    // Vector to store the shortest alternating path for each node.
    vector<int> shortestPathLength(n);

    for (int i = 0; i < n; i++)
    {
        // Storing only the shortest path to node i, via red and green edge.
        shortestPathLength[i] = min(pathLength[i][0], pathLength[i][1]);

        if (shortestPathLength[i] == 1e9)
        {
            shortestPathLength[i] = -1;
        }

    }

    // Returning the shortest alternating path for each node.
    return shortestPathLength;
    }
};
