#include "scanner.h"

bool isAtomic(char c)
{
    if (c >= 'A' && c <= 'Z')
        return true;
    return false;
}

void setDepth(Token* token, int* depth)
{
    if (token->type == TOKEN_LEFT_PAREN) // '('
    {
        (*depth)++; 
        printf("Increased depth: %d\n", *depth); // Verificando incremento
    }
    else if (token->type == TOKEN_RIGHT_PAREN) //')'
    {
        (*depth)--;
        printf("Decreased depth: %d\n", *depth); // Verificando decremento
    }

}

void printStack(TokenStack* top)
{
    TokenStack* p;
    for(p = top; p != NULL; p = p->next)
        printf("Stack[size:%d]: Token: [char: '%c', depth: %d]\n", p->size, p->token->raw, p->token->depth);
}

TokenStack* push(TokenStack* top, Token* token)
{
    TokenStack* new = (TokenStack*)malloc(sizeof(TokenStack));
    if (new != NULL)
    {
        new->token = token;
        new->next = top;
        new->size = (top == NULL) ? 0: top->size + 1;
        return new;
    }
    return NULL;
}

Token* makeToken(char c, TokenType type)
{
    Token* token = (Token*)malloc(sizeof(Token));
    if (token != NULL)
    {
        token->raw = c;
        token->type = type;
        token->depth = 0;
        return token;
    }
    return NULL;
}

Token* scanToken(char c)
{
    if (isAtomic(c)) return makeToken(c, TOKEN_ATOMIC);
    switch(c)
    {
        case 'v': return makeToken(c, TOKEN_DISJUNCTION);
        case '^': return makeToken(c, TOKEN_CONJUNCTION);
        case '~': return makeToken(c, TOKEN_NEGATION);
        case '(': return makeToken(c, TOKEN_LEFT_PAREN);
        case ')': return makeToken(c, TOKEN_RIGHT_PAREN);
    }
    return makeToken(c, TOKEN_NONE);
}
