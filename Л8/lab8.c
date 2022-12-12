#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct node
{
	int data;
	int N;
	struct node* left;
	struct node* right;
}Node;


void rotate_l(Node ** h) {
	Node *x;
	int k = (*h)->N;
	
	if ((*h)->right == NULL)
	{
		return;
	}
	
	x=(*h)->right;
	(*h)->right=x->left;
	x->left=*h;
	(*h)=x;
	(*h)->N=k;
	
	(*h)->left->N = 1;
	
	if ((*h)->left->left != NULL)
	{
		(*h)->left->N += (*h)->left->left->N;
		
	}	
	
	if ((*h)->left->right != NULL)
	{
		(*h)->left->N += (*h)->left->right->N;
		
	}
return;
}

void rotate_r(Node ** h) {
	Node *x;
	int k = (*h)->N;
	
	if ((*h)->left == NULL)
	{
		return;
	}
	
	x=(*h)->left;
	(*h)->left=x->right;
	x->right=*h;
	(*h)=x;
	(*h)->N=k;
	
	(*h)->right->N = 1;
	
	if ((*h)->right->right != NULL)
	{
		(*h)->right->N += (*h)->right->right->N;
		
	}	
	
	if ((*h)->right->left != NULL)
	{
		(*h)->right->N += (*h)->right->left->N;
		
	}
	return;
}

void InsertR(Node ** Root, int key) {
	if (*Root == NULL) {
	(*Root) = (Node*)malloc(sizeof(Node));
	(*Root)->data = key;
	(*Root)->left = NULL;
	(*Root)->right = NULL;
	(*Root)->N = 1;
	return;
	}
	else {
		
		if (key >= (*Root)->data) {
			(*Root)->N++;
			InsertR(&((*Root)->right), key);
			rotate_l(Root);	
		}
		else {
			(*Root)->N++;
			InsertR(&((*Root)->left), key);
			rotate_r(Root);
		}
	}
}


void Print(Node *Root)  
{
	if (Root == NULL) return;
	else
	{
		printf("%d (%d)\n",Root->data, Root->N);
		Print(Root->left);
		
		Print(Root->right);
	}
}

struct Node *Join (Node *a, Node *b) {
	if (b == NULL) return a;
	if (a == NULL) return b;
	InsertR(&b,a->data);
	b->left = Join(a->left, b->left);
	b->right = Join(a->right, b->right);
	free(a);
	return b;
}

int main() {
	system("chcp 1251");
	Node* root = NULL;
	Node* root_help = NULL;
	Node *root_new = NULL;
	int n, a, i;

	printf("Введите кол-во элементов: ");
	scanf("%d", &n);
	printf("\nВставка в корень\n");
	printf("\nИсходное 1 BST:\n");
	for (i = 0; i < n; i++)
	{
		a = rand() % 20 + 1;
		printf("%d ", a);
		InsertR(&root, a);
	}

	printf("\nИсходное 2 BST:\n");
	for (i = 0; i < n; i++)
	{
		a = rand() % 20 + 1;
		printf("%d ", a);
		InsertR(&root_help, a);
	}
	printf("\n");
	printf("\n");
	Print(root);
	printf("\n\n");
	Print(root_help);
	
	printf("\nОперация объединения двух BST-деревьев:\n");
	root_new = Join(root, root_help);

	Print(root_new);
	return 0;
}
