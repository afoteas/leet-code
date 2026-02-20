# Binary Trees

## Overview
Hierarchical data structure where each node has at most two children (left and right).

## Definition
```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
```

## Tree Traversals

### 1. Inorder (Left → Root → Right)
```cpp
void inorder(TreeNode* root) {
    if (root == nullptr) return;
    
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Iterative
vector<int> inorderIterative(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    TreeNode* curr = root;
    
    while (curr != nullptr || !st.empty()) {
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        result.push_back(curr->val);
        curr = curr->right;
    }
    
    return result;
}
```

### 2. Preorder (Root → Left → Right)
```cpp
void preorder(TreeNode* root) {
    if (root == nullptr) return;
    
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Iterative
vector<int> preorderIterative(TreeNode* root) {
    vector<int> result;
    if (root == nullptr) return result;
    
    stack<TreeNode*> st;
    st.push(root);
    
    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        result.push_back(node->val);
        
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
    
    return result;
}
```

### 3. Postorder (Left → Right → Root)
```cpp
void postorder(TreeNode* root) {
    if (root == nullptr) return;
    
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}
```

### 4. Level-Order (BFS)
```cpp
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (root == nullptr) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> level;
        
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        
        result.push_back(level);
    }
    
    return result;
}
```

## Common Operations

### Maximum Depth
```cpp
int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
```

### Minimum Depth
```cpp
int minDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr) return 1 + minDepth(root->right);
    if (root->right == nullptr) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}
```

### Diameter of Tree
```cpp
int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    
    function<int(TreeNode*)> height = [&](TreeNode* node) {
        if (node == nullptr) return 0;
        
        int left = height(node->left);
        int right = height(node->right);
        
        diameter = max(diameter, left + right);
        
        return 1 + max(left, right);
    };
    
    height(root);
    return diameter;
}
```

### Path Sum
```cpp
bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) return false;
    
    if (root->left == nullptr && root->right == nullptr) {
        return root->val == targetSum;
    }
    
    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
}
```

## Binary Search Tree (BST)

### Properties
- Left subtree values < root value
- Right subtree values > root value
- Both subtrees are also BSTs

### Validate BST
```cpp
bool isValidBST(TreeNode* root, long minVal = LONG_MIN, long maxVal = LONG_MAX) {
    if (root == nullptr) return true;
    
    if (root->val <= minVal || root->val >= maxVal) {
        return false;
    }
    
    return isValidBST(root->left, minVal, root->val) &&
           isValidBST(root->right, root->val, maxVal);
}
```

### Search in BST
```cpp
TreeNode* searchBST(TreeNode* root, int val) {
    if (root == nullptr || root->val == val) {
        return root;
    }
    
    if (val < root->val) {
        return searchBST(root->left, val);
    } else {
        return searchBST(root->right, val);
    }
}
```

### Insert into BST
```cpp
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }
    
    return root;
}
```

### Lowest Common Ancestor (BST)
```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (p->val < root->val && q->val < root->val) {
        return lowestCommonAncestor(root->left, p, q);
    }
    if (p->val > root->val && q->val > root->val) {
        return lowestCommonAncestor(root->right, p, q);
    }
    return root;
}
```

## Common Patterns

### Recursion Template
```cpp
int solve(TreeNode* root) {
    // Base case
    if (root == nullptr) return 0;
    
    // Recursive calls
    int left = solve(root->left);
    int right = solve(root->right);
    
    // Process current node
    return /* combine left, right, and root */;
}
```

### Divide and Conquer
- Solve for left subtree
- Solve for right subtree
- Combine results

## Common Problems
- Maximum Depth (LeetCode #104)
- Same Tree (LeetCode #100)
- Invert Binary Tree (LeetCode #226)
- Symmetric Tree (LeetCode #101)
- Validate BST (LeetCode #98)
- Lowest Common Ancestor (LeetCode #236)
- Binary Tree Level Order Traversal (LeetCode #102)
- Serialize and Deserialize Binary Tree (LeetCode #297)

## Time Complexities

| Operation | Binary Tree | BST (balanced) | BST (worst) |
|-----------|-------------|----------------|-------------|
| Search | O(n) | O(log n) | O(n) |
| Insert | O(n) | O(log n) | O(n) |
| Delete | O(n) | O(log n) | O(n) |
| Traversal | O(n) | O(n) | O(n) |

## Tips
- Always check for nullptr
- Recursion is natural for trees
- Use helper functions with additional parameters
- Level-order uses queue (BFS)
- Inorder traversal of BST gives sorted order
- Consider both recursive and iterative solutions

[← Back to README](README.md)
