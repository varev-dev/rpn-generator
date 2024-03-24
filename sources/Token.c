//
// Created by varev on 20.03.2024.
//
#include <malloc.h>
#include <string.h>
#include "../includes/Token.h"

char significance(const char* operand) {
    switch (*operand) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case 'N':
            return 3;
        default:
            return 0;
    }
}

Token* init_token_with_value(Type type, const char *value) {
    Token* token = (Token*) malloc(sizeof(Token));
    token->type = type;
    token->value = malloc(sizeof(char) * 2);
    token->value[0] = *value;
    token->value[1] = '\0';
    return token;
}

Token* init_token(Type type) {
    Token* token = (Token*) malloc(sizeof(Token));
    token->type = type;
    size_t size = (type == OPERAND ? OPERAND_SIZE : NUMBER_SIZE);
    token->value = malloc((size + 1) * sizeof(char));
    token->value[size] = '\0';
    return token;
}

void append_to_token(Token* token, const char *value) {
    size_t length = strlen(token->value);

    if (length == NUMBER_SIZE)
        return;

    token->value[length] = *value;
    token->value[length+1] = '\0';
}

void delete_token(Token* token) {
    /*char* value = token->value;
    token->value = NULL;
    free(value);*/
    free(token);
}