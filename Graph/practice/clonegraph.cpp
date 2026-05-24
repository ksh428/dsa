
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    void dfs(Node* curr,Node* newnode,vector<Node *>& visited)
    {
        //Node* copy = new Node(node->val);
        visited[newnode->val] = newnode;
        for(auto ele: curr->neighbors)
        {
            if(visited[ele->val] == NULL)
            {
                Node *newnode1 = new Node(ele->val);
                (newnode->neighbors).push_back(newnode1);
                dfs(ele,newnode1,visited);
            }
            else
                (newnode->neighbors).push_back(visited[ele->val]);
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;

        vector<Node *> visited(1000,NULL);
        Node* copy = new Node(node->val);
        visited[node->val] = copy;
        //Iterate for all neighbors
        for(auto curr: node->neighbors)
        {
            if(visited[curr->val] == NULL)
            {
                Node *newnode = new Node(curr->val);//make new copied node
                (copy->neighbors).push_back(newnode);
                dfs(curr,newnode,visited);
            }
            else
                (copy->neighbors).push_back(visited[curr->val]);
        }
        return copy;
    }
};


static int fastio = []() {
    //#define endl '\n'
    std::ios::sync_with_stdio(false);
    //std::cin.tie(NULL);
    //std::cout.tie(0);
    return 0;
}();
