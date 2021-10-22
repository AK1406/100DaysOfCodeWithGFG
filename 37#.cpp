class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
    vector<int> temp(1e6, -1), ans;
    queue<pair<Node*, int>> q;
    q.push({root, (int)5e5});
    while (!q.empty()) {
        auto x = q.front(); q.pop();
        if (temp[x.second] == -1)temp[x.second] = x.first->data;
        if (x.first->left)q.push({x.first->left, x.second - 1});
        if (x.first->right)q.push({x.first->right, x.second + 1});
    }
    for (int i = 0; i < (int)1e6; i++)if (temp[i] != -1)ans.push_back(temp[i]);
    return ans;
    }

};
