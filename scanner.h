#ifndef tableaux_scanner_h
#define tableaux_scanner_h

#include "utils.h"

typedef enum {

    // Single-Character Token
    TOKEN_ATOMIC,
    TOKEN_DISJUNCTION, 
    TOKEN_CONJUNCTION,
    TOKEN_NEGATION,
    TOKEN_RIGHT_PAREN,
    TOKEN_LEFT_PAREN,

    // Two or more character Token
    TOKEN_IMPLICATION,
    TOKEN_BICONDITIONAL,

    // Non listed token
    TOKEN_NONE

} TokenType;

typedef struct {
    char raw;
    int depth;
    TokenType type;
} Token;

struct TokenStack {
    int size;
    Token* token;
    struct TokenStack *next;
};

typedef struct TokenStack TokenStack;

void setDepth(Token* token, int* depth);
void printStack(TokenStack* top);
TokenStack* push(TokenStack* top, Token* token);
Token* makeToken(char c, TokenType type);
Token* scanToken(char c);

#endif