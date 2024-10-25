#include "scanner.h"
#include "utils.h"
#include<omp.h>

bool DEBUG = true;

int main(int argc, char* argv[])
{
    char expr[] = "(P -> Q) v ~P";
    rmspc(expr);
    printf("%s\n", expr);

    TokenStack* stack = NULL;
    Token* token;
    for(int i = 0; i < strlen(expr); i++)
    {
        token = scanToken(expr[i]);
        stack = push(stack, token);

        //setDepth(token, &depth);
    }

    int depth = 0;

    for(TokenStack* p = stack; p != NULL; p = p->next)
    {
        //setDepth(p, p->token->depth);
        if (p->token->type == TOKEN_LEFT_PAREN)
        {
            depth--;
        }
        if (p->token->type == TOKEN_RIGHT_PAREN)
        {
            depth++;
        }
        p->token->depth = depth;

    }

    printStack(stack);
    printf("end\n");
    return 0;
}