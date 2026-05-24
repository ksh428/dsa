	// Code here
	vector<int>ans;
	if(!root) return ans;
	queue<Node*>q;
	q.push(root);
	int f=1;
	while(!q.empty()){
	   vector<int>temp;
	    int n=q.size();
	    while(n--){
	        Node* curr=q.front();
	        q.pop();
	        temp.push_back(curr->data);
	        if(curr->left) q.push(cur->left);
	        if(curr->right) q.push(curr->right);
	    }
	    if(!f&1) reverse(temp.begin(),temp.end());
	    for(int x:temp) ans.push_back(x);
	    f=!f;
	}
	return ans;
