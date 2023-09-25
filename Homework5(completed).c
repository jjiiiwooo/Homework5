#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
	//만약 오른쪽 링크가 스레드이면 TRUE
	int is_rightthread; 
}TreeNode;

TreeNode n1 = { 4, NULL,NULL,1 };
TreeNode n2 = { 5, NULL,NULL,1 };
TreeNode n3 = { 3, &n1,&n2,0 };
TreeNode n4 = { 6, NULL,NULL,1 };
TreeNode n5 = { 2, &n3, &n4,0 };
TreeNode n6 = { 10, NULL,NULL,1 };
TreeNode n7 = { 11, NULL,NULL,1 };
TreeNode n8 = { 9, &n6, &n7,0 };
TreeNode n9 = { 8, NULL,NULL,1};
TreeNode n10 = { 7, &n9,&n8,0,};
TreeNode n11 = { 1, &n5 ,&n10,0};
TreeNode* exp = &n11;


//중위 후속자 반환
TreeNode * find_successor(TreeNode* p)
{
	//q는 p의 오른쪽 포인터 
	TreeNode* q = p->right;
	//만약 오른쪽 포인터가 NULL이거나 스레드이면 오른쪽 포인터를 반환
	if (q == NULL || p->is_rightthread == TRUE)
		return q;
	//만약 오른쪽 자식이면 다시 가장 왼쪽 노드로 이동
	while (q->left != NULL) q = q->left;
	return q;
}

//스레드 중위 순회 
void Thread_inorder(TreeNode* t)
{
	TreeNode* q;
	q = t;
	while (q->left) q = q->left; //가장 왼쪽 노드로 이동
	do {
		printf(" %d", q->data); //데이터 출력
		q = find_successor(q); //후속자 함수 호출
	} while (q); //NULL이 아니면 
}



//부모 노드 출력
TreeNode* Parent(TreeNode* child)
{
	TreeNode* parent;

	if (child->right != NULL)
		parent = find_successor(child)->left;
	else
		parent = find_successor(child)->left->left;

	return parent;
}

int main(void)
{
	n1.right = &n3;
	n2.right = &n5;
	n4.right = &n11;
	n6.right = &n8;
	n9.right = &n10;
	n7.right = NULL;

	printf("1.중위 순회 결과\n");
	Thread_inorder(exp);
	printf("\n");

	printf("2. Node 4의 부모: %d\n", Parent(&n1)->data);
	printf("3. Node 5의 부모: %d\n", Parent(&n2)->data);
	printf("4. Node 6의 부모: %d\n", Parent(&n4)->data);

	return 0;
	
}
