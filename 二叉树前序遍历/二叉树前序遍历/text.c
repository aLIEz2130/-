#define _CRT_SECURE_NO_WARNINGS 1
//ǰ�����
//1.����  return
//2.һ����� printf��root->value��
//3.ֻ�и�+������ printf��root->value��; preorder(root->left);
//4.ֻ�и�+������
//5.�и�+������+������
typedef struct Node{
	int value;
	struct Node *left;//
	struct Node *right;//
};
void PreorderTraversal(Node *root){
	if (root == NULL){  //����
		return;
	}
	printf("%d ", root -> value);
	PreorderTraversal(root -> left);
	PreorderTraversal(root -> right);
}

//�������
void INorder(Node *root){
	//������ �� ������
	if (root == NULL){
		return;
	}
	INorder(root -> left);
	printf("%d ", root -> value);
	INorder(root -> right);
}
//�������
//1.ͨ�������ķ�ʽ����ǰ/��/��)ÿ�ξ���һ���ǿս�㣬����count++
int size��
void Size(Node *root){
	if (root == NULL){
		return;
	}
	size++;
	Size(root->left);
	Size(root->right);
}
//2.���Ƶķ�ʽ
int Size2(Node *root){
	if (root == NULL){
		return 0;
	}
	int left = Size2(root->left);
	int right = Size2(root->right);
	return left + right + 1;
}
//��Ҷ�ӽ��
int   LeafSize(Node *root){
// �ҵ���
//��֪������Ҷ�ӽ����� left
//������������ right
//������Ҷ�ӽ�㣿
//��ֹ���
//���� retuen 0��һ�������� return 1;
if (root == NULL) {return 0;}
if (root->left == NULL&&root-> == NULL){return 1;}
int left = LeafSize(root->left);
int right = LeafSize (root->right);
return left + right;
}

//��������ĸ߶�
//����  ��ֹ����
int GetHeight(Node *root){
	if (root==NULL){
		return 0;
	}
	int left = GetHeight(root->left);
	int right = generic(root->right);
	return (left > right:left:right)+1;
}//��K�������
int GetKLevelSize(Node *root, int k){
	if (root == NULL){
		return 0;
	}
	if (k == 1){ //���������ǣ�root��=NULL
		return 1;
	}
	return GetKLevelSize(root->left, k - 1) + GetKLevelSize(root->right, k - 1);
}
//���������������value�����ظ�
//�ҽ���value��v�Ľ��
//����ҵ��ˣ�����v���ڵĽ���ַ
//���û�ҵ�������NULL
//Find����NULL��ζ��û�ҵ������ط�NULL��ζ���ҵ���
//��ȷ�������->�������Ƿ����->�������Ƿ����
//����������ǣ�����Ҫ��ȥ��������������
//����������ҵ��ˣ�����Ҫȥ������������
Node *Find(Node *root, int v){
	if (root == NULL){
		return NULL;
	}
	if (root->value == v){
		return root;
	}
	Node *result = Find(root->left, v);
	if (result ��= NULL){
		//�������ҵ���
		return result;
	}
	//���������û�ҵ�,ȥ��������
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