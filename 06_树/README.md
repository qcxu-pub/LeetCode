# 1.树&递归

```
分支数最多是2，为二叉树。
满二叉树：最后一层都是满的。
完全二叉树：只有最后一层的最右边可以缺一些点，剩余的都是满的。序号满足父子2倍关系（跟堆那边是一样的）。

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
```

- [226. 翻转二叉树 (easy)](https://leetcode-cn.com/problems/invert-binary-tree/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/06_树/226invertTree.cpp)

- [98. 验证二叉搜索树 (median)](https://leetcode-cn.com/problems/validate-binary-search-tree/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/06_树/98isValidBST.cpp)

- [1245. 树的直径 (median)](https://leetcode-cn.com/problems/tree-diameter/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/06_树/1245treeDiameter.cpp)

- [236. 二叉树的最近公共祖先 (median)](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/06_树/236lowestCommonAncestor.cpp)

- [235. 二叉搜索树的最近公共祖先 (easy)](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/06_树/235lowestCommonAncestor.cpp)

- [114. 二叉树展开为链表 (median)](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/06_树/114flatten.cpp)

- [124. 二叉树中的最大路径和 (hard)](https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/06_树/124maxPathSum.cpp)


# 2.二叉树的信息统计：递归在树上的应用

- [104. 二叉树的最大深度 (easy)](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/06_树/104maxDepth.cpp)

- [111. 二叉树的最小深度 (easy)](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/06_树/111minDepth.cpp)


# 3.树的遍历和序列化

```
前序遍历：根-左子树-右子树
中序遍历：左子树-根-右子树
后序遍历：左子树-右子树-根
层次序遍历：一层一层来

深度优先遍历：递归。先序、中序、后序
广度优先遍历：队列。层次序
```

- [94. 二叉树的中序遍历 (easy)](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/06_树/94inorderTraversal.cpp)

- [589. N 叉树的前序遍历 (easy)](https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/06_树/589preorder.cpp)

- [429. N叉树的层序遍历 (median)](https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/06_树/429levelOrder.cpp)

- [105. 从前序与中序遍历序列构造二叉树 (median)](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) | [solution](https://github.com/qcxu-pub/LeetCode/blob/master/06_树/105buildTree.cpp)

- [106. 从中序与后序遍历序列构造二叉树 (median)](https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/06_树/106buildTree.cpp)

- [297. 二叉树的序列化与反序列化 (hard)](https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/06_树/279Codec.cpp)

- [101. 对称二叉树 (easy)](https://leetcode-cn.com/problems/symmetric-tree/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/06_树/101isSymmetric.cpp)

- [剑指 Offer 36. 二叉搜索树与双向链表 (median)](https://leetcode.cn/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/06_树/36treeToDoublyList.cpp)

# 4.二叉搜索树

```
二叉搜索树(binary search tree, BST) 是满足如下性质的二叉树：
1.根的key >= 它左子树中的所有结点的key
2.根的key <= 它右子树中的所有结点的key
所以，二叉搜索树的中序遍历必然是个有序序列

二叉搜素树的建立：两个保护结点，一个key是正无穷，另一个key是负无穷

二叉搜索树的查找：找val是否存在，从根节点可以开始递归查找
1.若当前结点key==val，则找到
2.若当前key>val，则递归左子树 
3.若当前key<val，则递归右子树

二叉搜索树的插入：
1.先查找到要插入的位置，若存在则放弃插入（或把val对应的结点计数+1）
2.若不存在则直接插入

二叉搜索树求前驱/后继：
1.前驱就是找小于val的最大结点，在val为根的左子树一路往右走到底；如果没有左子树，那就在走之前走过点中的一个
2.后继就是找大于val的最小结点，在val为根的右子树一路往左走到底；如果没有右子树，那就在之前走过点中的一个
所以先查找val

二叉搜索树的删除：基于查找+求后继实现
删除就说明，该点在二叉搜索树里是存在的。所以后继是通过相同结点的右子树一路往左找到的。所以后继点最多只有一颗右子树
1.把后继删了直接替代待删除的地方
2.把子树跟父亲相连

查找/插入/求前驱后继/删除，时间复杂度都是O(logN)。特殊情况下（树变成了长长的链），是O(N)，这个时候需要平衡二叉树
```


- [701. 二叉搜索树中的插入操作 (median)](https://leetcode-cn.com/problems/insert-into-a-binary-search-tree/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/06_树/701insertIntoBST.cpp)

- [面试题 04.06. 后继者 (median)](https://leetcode-cn.com/problems/successor-lcci/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/06_树/0406inorderSuccessor.cpp)

- [450. 删除二叉搜索树中的节点 (median)](https://leetcode-cn.com/problems/delete-node-in-a-bst/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/06_树/450deleteNode.cpp)

- [538. 把二叉搜索树转换为累加树 (median)](https://leetcode-cn.com/problems/convert-bst-to-greater-tree/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/06_树/538convertBST.cpp)

- [230. 二叉搜索树中第K小的元素 (median)](https://leetcode.cn/problems/kth-smallest-element-in-a-bst/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/06_树/230kthSmallest.cpp)

- [776. 拆分二叉搜索树 (median)](https://leetcode.cn/problems/split-bst/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/06_树/776splitBST.cpp)

# 5.Trie树

```
由 结点 和 带有字符的边 构成的树形结构。边是字母，叶子结点/中间部分结点是单词。前缀相同的字符串在同一子树中
优点：最大限度地减少无谓的字符串比较，查询效率比哈希表高。用空间换时间，利用字符串的公共前缀降低查询时间开销
应用：搜索提示自动补全
```

- [208. 实现 Trie (前缀树) (median)](https://leetcode-cn.com/problems/implement-trie-prefix-tree/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/06_树/208Trie.cpp)

- [212. 单词搜索 II (hard)](https://leetcode-cn.com/problems/word-search-ii/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/06_树/212findWords.cpp)

- [79. 单词搜索 (median)](https://leetcode-cn.com/problems/word-search/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/06_树/79exist.cpp)

- [440. 字典序的第K小数字 (hard)](https://leetcode.cn/problems/k-th-smallest-in-lexicographical-order/) |  [solution](https://github.com/qcxu-pub/LeetCode/blob/master/06_树/440findKthNumber.cpp)