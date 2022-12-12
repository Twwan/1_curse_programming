// В текстовом файле расположено произвольное количество чисел.
// Считать числа из файла в однонаправленный линейный список.
// Преобразовать список, повторив в списке все нечетные числа.
// На экран вывести исходный и преобразованный списки.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}
node;

//
node* cnode(int data)
{
    node* nnode = (node*)malloc(sizeof(node));
    nnode->data = data;
    nnode->next = NULL;
    return nnode;
}

//
node* add_tail(node* root, int data)
{
    if (root == NULL)
        root = cnode(data);
    else
        root->next = add_tail(root->next, data);

    return root;
}

//
node* modify(node* root)
{
    if (root == NULL) return NULL;

    if (root->data%2) {
        node* temp = root->next;
        root->next = cnode(root->data);
        root->next->next = temp;
 
        root->next->next = modify(root->next->next);
    }
    else
        root->next = modify(root->next);

    return root;
}

//
void out(node* root)
{
    while (root != NULL) {
        printf("%d ", root->data);
        root = root->next;
    }
    printf("\n");
}

//
int main()
{
    node* root = NULL;
    freopen("l1.txt", "r", stdin);
    int n;

    while (scanf("%d", &n) != EOF)
        root = add_tail(root, n);

    out(root);
    root = modify(root);
    out(root);

    return 0;
}