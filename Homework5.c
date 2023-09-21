#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
	int is_thread;
}TreeNode;

TreeNode n1 = { 4, NULL,NULL,1 };
TreeNode n2 = { 5, NULL,NULL,1 };
TreeNode n3 = { 3, &n1,&n2,0};
TreeNode n4 = { 6, NULL,NULL,1 };
TreeNode n5 = { 2, &n3, &n4,0 };
TreeNode n6 = { 10, NULL,NULL,1 };
TreeNode n7 = { 11, NULL,NULL,1 };
TreeNode n8 = { 9, &n6, &n7,0 };
TreeNode n9 = { 8, NULL,NULL,1 };
TreeNode n10 = { 7, &n9,&n8,0 };
TreeNode n11 = { 1, &n5 ,&n10,0 };
TreeNode* exp = &n11;

TreeNode* find_successor(TreeNode* p)
{
	TreeNode* q = p->right;
	if (q == NULL || p->is_thread == TRUE)
	{
		return 1;
	}
	while (q->left != NULL) q = q->left;
	return q;
}

void Thread_inorder(TreeNode* t)
{
	TreeNode* q;

	q = t;
	while (q->left) q = q->left;
	do {
		printf(" %d", q->data);
		q = find_successor(q);
	} while (q);
}

TreeNode* Parent(TreeNode* child)
{
	TreeNode* parent;
	TreeNode* temp;

	if (child == NULL || child->is_thread == TRUE)
	{
		parent = find_successor(child);
	}
	else
	{
		temp = find_successor(child);
		parent = temp->left;
	}
 
	printf("%d", parent->data);
	return parent;
}

int main(void)
{
	n1.right = &n3;
	n2.right = &n5;
	n4.right = &n11;
	n6.right = &n8;
	
	printf("1.중위 순회 결과\n");
	thread_inorder(exp);
	printf("\n");
	parent(&n1);
	parent(&n2);
	parent(&n4);

	printf("2.Node 4의 부모: %d\n", Parent(&n1));
	printf("3.Node 5의 부모: %d\n", Parent(&n5));
	printf("4.Node 6의 부모:%d\n", Parent(&n4));

}