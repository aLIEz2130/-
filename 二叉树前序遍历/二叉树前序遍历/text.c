#define _CRT_SECURE_NO_WARNINGS 1
//前序遍历
//1.空树  return
//2.一个结点 printf（root->value）
//3.只有根+左子树 printf（root->value）; preorder(root->left);
//4.只有根+右子树
//5.有根+左子树+右子树
typedef struct Node{
	int value;
	struct Node *left;//
	struct Node *right;//
};
void PreorderTraversal(Node *root){
	if (root == NULL){  //空树
		return;
	}
	printf("%d ", root -> value);
	PreorderTraversal(root -> left);
	PreorderTraversal(root -> right);
}

//中序遍历
void INorder(Node *root){
	//左子树 根 右子树
	if (root == NULL){
		return;
	}
	INorder(root -> left);
	printf("%d ", root -> value);
	INorder(root -> right);
}
//求结点个数
//1.通过遍历的方式，（前/中/后)每次经过一个非空结点，计算count++
int size；
void Size(Node *root){
	if (root == NULL){
		return;
	}
	size++;
	Size(root->left);
	Size(root->right);
}
//2.递推的方式
int Size2(Node *root){
	if (root == NULL){
		return 0;
	}
	int left = Size2(root->left);
	int right = Size2(root->right);
	return left + right + 1;
}
//求叶子结点
int   LeafSize(Node *root){
// 找递推
//已知左子树叶子结点个数 left
//右子树结点个数 right
//整棵树叶子结点？
//中止结点
//空树 retuen 0，一个结点的树 return 1;
if (root == NULL) {return 0;}
if (root->left == NULL&&root-> == NULL){return 1;}
int left = LeafSize(root->left);
int right = LeafSize (root->right);
return left + right;
}

//求二叉树的高度
//递推  终止条件
int GetHeight(Node *root){
	if (root==NULL){
		return 0;
	}
	int left = GetHeight(root->left);
	int right = generic(root->right);
	return (left > right:left:right)+1;
}//求K层结点个数
int GetKLevelSize(Node *root, int k){
	if (root == NULL){
		return 0;
	}
	if (k == 1){ //隐含条件是，root！=NULL
		return 1;
	}
	return GetKLevelSize(root->left, k - 1) + GetKLevelSize(root->right, k - 1);
}
//二叉树结点中所有value都不重复
//找结点的value是v的结点
//如果找到了，返回v所在的结点地址
//如果没找到，返回NULL
//Find返回NULL意味着没找到，返回非NULL意味着找到了
//先确定根结点->左子树是否包含->右子树是否包含
//如果根结点就是，不需要再去左右子树查找了
//如果右子树找到了，不需要去右子树查找了
Node *Find(Node *root, int v){
	if (root == NULL){
		return NULL;
	}
	if (root->value == v){
		return root;
	}
	Node *result = Find(root->left, v);
	if (result ！= NULL){
		//左子树找到了
		return result;
	}
	//如果左子树没找到,去右子树找
	result = Find(root->right, v);
	if (result != NULL){
		return result;
	}
	else {
		return NULL;
	}
}


bool isMirror(struct TreeNode *p, struct TreeNode *q){
	if (p == NULL&&q == NULL){
		return true;
	}if (p == NULL || q == NULL){
		return false;
	}return p->val==q->val&&
}