#ifndef TOKENIZER_H
#define TOKENIZER_H
#include "vector.h"
#define MAX_LITERAL_SIZE 256
#define MAX_SYMBOL_SIZE 256
typedef enum token_type token_type;
typedef struct token token;
typedef struct literal literal;
typedef struct symbol symbol;
typedef enum key_word key_word;
typedef enum symbol_type symbol_type;
typedef enum literal_type literal_type;

enum symbol_type{
    VARIABLE,
    FUNCTION,
    STRUCT
};

struct symbol{
    char buff[MAX_SYMBOL_SIZE];
    symbol_type type;
};

enum token_type{
    KEY_WORD,
    LITERAL,
    SYMBOL,
};
enum key_word{
    IF,
    EQUAL,
    NOT,
    DECLARE,
    LET,
    END,
    RETURN,
    ADD,
    SUB,
    DIVIDE,
    MULTIPLY,
    DEFINE,
    INTEGER,
    STRING,
};

enum literal_type{
    INT,
    STR,
};
struct literal{
    char buff[MAX_LITERAL_SIZE];
    literal_type type;
};

union _token{
    key_word key_word;
    literal literal;
    symbol symbol;
};

struct token{
    union _token data;
    token_type type;
};

vector get_tokens(const char* path);
#endif
