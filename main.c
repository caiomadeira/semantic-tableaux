#include "utils.h"

#define MAX_ATOMIC 64

typedef struct TreeNode {
    char* expr;
    struct TreeNode* prev;
    struct TreeNode* next;

} TreeNode;

void printTree(TreeNode* root)
{
    if (root == NULL) return;
    printf("  %s\n", root->expr);
    //if (root->prev != NULL)
       // printf("\t|\n");
    printTree(root->prev);
}

TreeNode* newNode(char* expr)
{
    TreeNode* new = (TreeNode*)malloc(sizeof(TreeNode));
    if (new != NULL)
    {
        new->expr = (char*)malloc((strlen(expr) + 1)*sizeof(char));
        if (new->expr != NULL)
            strcpy(new->expr, expr);
        new->prev = NULL;
        new->next = NULL;
        return new;
    }
    return NULL;
}

TreeNode* pushToTree(TreeNode* node, char* expr)
{
    if (node == NULL) // Se a arvore esta vazia
        return newNode(expr); // Cria o nodo raiz
    else 
    {
        if (strlen(expr) < strlen(node->expr))
        {
            node->prev = pushToTree(node->prev, expr);
        } else { 
            node->next = pushToTree(node->next, expr);
        }
    }
    return node;
}

bool isAtomic(char c)
{
    if (c >= 'A' && c <= 'Z')
        return true;
    return false;
}

void checkParenthesis(char* expr)
{
    int* parenthesisIndex = (int*)malloc(strlen*(sizeof(char) + 1);

    for(int i=0; i<strlen(expr); i++)
    {
        if (expr[i] == '(')
        {
            parenthesisIndex[i] = i;
        } else if (expr[i] == )
        {
            parenthesisIndex[i]
        }
        
    }
}

void analyseExpr(char* expr)
{
    int * atomicForms = (int*)malloc(MAX_ATOMIC*sizeof(int));
    int j = 0;;
    for(int i=0; i<strlen(expr); i++)
    {
        // if (isAtomic(expr[i]) == true)
        // {
        //     printf("Is Atomic: %c\n", expr[i]);
        //     atomicForms[j] = expr[i];
        //     j++;
        // } 
        
    }
}

char* operation(TreeNode** node, char* expr)
{

}

int main(int argc, char* argv[])
{
    char expr[] = "(A v B)";
    //char expr2[] = "~(P<=>Q)";
    //char expr3[] = "~P^Q";

    analyseExpr(expr);

    //TreeNode* root = NULL;
    //root = pushToTree(root, expr);
    //root = pushToTree(root, expr2);
    //root = pushToTree(root, expr3);

    //printTree(root);

    return 0;
}