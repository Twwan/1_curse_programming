#include <iostream>


using namespace std;


struct node {
    int data;
    int len;
    node *left, *right;
};

node *tree = NULL;

void rotate_r(node **t) {
    node *x;
    x = (*t)->left;
    (*t)->left = x->right;
    x->right = *t;
    *t = x;
}

void rotate_l(node **t) {
    node *x;
    x = (*t)->right;
    (*t)->right = x->left;
    x->left = *t;
    *t = x;
}

void insert_head(node **t, int key) {
    if ((*t) == NULL) {
        (*t) = new node;
        (*t)->data = key;
        (*t)->left = (*t)->right = NULL;
        (*t)->len = 1;
        return;
    } else {
        (*t)->len++;
        if (key >= (*t)->data) {
            insert_head(&(*t)->right, key);
            rotate_l(&(*t));
        } else {
            insert_head(&(*t)->left, key);
            rotate_r(&(*t));
        }
    }
}

void insert(int key, node **t) {
    if ((*t) == NULL) {
        (*t) = new node;
        (*t)->data = key;
        (*t)->left = (*t)->right = NULL;
        (*t)->len = 1;
        return;
    }
    (*t)->len++;
    if (key >= (*t)->data) insert(key, &(*t)->right);
    else insert(key, &(*t)->left);
}

void print(node *t) {
    if (t == NULL) return;
    else {
        print(t->left);
        cout << t->len << "|" << t->data << endl;
    }
    print(t->right);
}

node *join(node **a, node **b) {
    if ((*b) == NULL) return (*a);
    if ((*a) == NULL) return (*b);
    insert_head(&(*b), (*a)->data);
    (*b)->left = join(&(*a)->left, &(*b)->left);
    (*b)->right = join(&(*a)->right, &(*b)->right);
    delete (*a);
    return (*b);
}

node *search(node **t, int key) {
    if ((*t) == NULL) return NULL;
    if (key == (*t)->data) return (*t);
    else if (key >= (*t)->data) return search(&(*t)->right, key);
    else return search(&(*t)->left, key);
}

void delete_branch(int key, node **t) {
    int z = (*t)->data;
    if (key == z) {
        node *r = (*t);
        (*t) = join(&(*t)->left, &(*t)->right);
        delete r;
        return;
    }
    if (key < z) delete_branch(key, &(*t)->left);
    else delete_branch(key, &(*t)->right);
}

void mass_print(int *mass, int len) {
    cout << "Набор чисел выглядит следующим образом: " << endl;
    for (int i = 0; i < len; i++) cout << mass[i] << "\t";
    cout << endl;
}

void mass_gen_and_print(int *mass, int len) {
    for (int i = 0; i < len; i++) mass[i] = rand() % 100;
    mass_print(mass, len);
}


int main() {
    system("chcp 65001");
    srand(time(NULL));

    //Генерация массива чисел
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    int *mass = new int[50];
    mass_gen_and_print(mass, n);

    //Создание дерева
    int i;
    for (i = 0; i < n; i++) insert(mass[i], &tree);
    cout << "Дерево:" << endl;
    print(tree);

    //Вставка в корень
    int b;
    cout << "Введите новое число:";
    cin >> b;
    mass[i] = b;
    i++;
    insert_head(&tree, b);
    mass_print(mass, i);
    cout << "Измененное дерево:" << endl;
    print(tree);

    //Удаления элемента
    int del_data;
    cout << "Введите значения удаляемого элемента: ";
    cin >> del_data;
    if (search(&tree, del_data) == NULL) cout << "Такого элемента не существует";
    else delete_branch(del_data, &tree);
    print(tree);


    return 0;
}
