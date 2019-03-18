#include <stdio.h>
#include <string.h>
struct Node
{
    Node *lchild;
    Node *rchild;
    int c;
} Tree[100];
int loc;
Node *creat()
{
    Tree[loc].lchild = Tree[loc].rchild = NULL;
    return &Tree[loc++];
}
char str1[25], str2[25];
int size1, size2;
char *str; //当前正在保存的字符串
int *size; //当前正在保存字符串的个数
void postOder(Node *T)
{
    if (T->lchild != NULL)
        postOder(T->lchild);
    if (T->rchild != NULL)
        postOder(T->rchild);
    str[(*size)++] = T->c + '0';
}
void inOder(Node *T)
{
    if (T->lchild != NULL)
        inOder(T->lchild);
    str[(*size)++] = T->c + '0';
    if (T->rchild != NULL)
        inOder(T->rchild);
}
Node *insert(Node *T, int x)
{
    if (T == NULL)
    {
        T = creat();
        T->c = x;
        return T;
    }
    else if (x < T->c)
        T->lchild = insert(T->lchild, x);
    else if (x > T->c)
        T->rchild = insert(T->rchild, x);
    return T;
}
int main()
{
    int n;
    char tmp[12];
    while (scanf("%d", &n) != EOF && n != 0)
    {
        loc = 0;
        Node *T = NULL;
        scanf("%s", tmp);
        for (int i = 0; tmp[i] != 0; i++)
        {
            T = insert(T, tmp[i] - '0');
        }
        size1 = 0;
        str = str1;
        size = &size1;
        postOder(T);
        inOder(T);
        str1[size1] = 0;
        while (n-- != 0)
        {
            scanf("%s", tmp);
            Node *T2 = NULL;
            for (int i = 0; tmp[i] != 0; i++)
                T2 = insert(T2, tmp[i] - '0');
            size2 = 0;
            str = str2;
            size = &size2;
            postOder(T2);
            inOder(T2);
            str2[size2] = 0;
            puts(strcmp(str1, str2) == 0 ? "YES" : "NO");
        }
    }

    return 0;
}