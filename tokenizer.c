#include "tokenizer.h"
#include <stdio.h>
#include <string.h>
#include "error.h"

#define STR_COMP(word,word2) if(strcmp(word,word2) == 0)
token determine_token(const char* word){
    token result;
    STR_COMP(word,"if"){
        result.data.key_word = IF;
        result.type = KEY_WORD;
        return result;
    }
    STR_COMP(word,"equal"){
        result.data.key_word = EQUAL;
        result.type = KEY_WORD;
        return result;
    }
    STR_COMP(word,"not"){
        result.data.key_word = NOT;
        result.type = KEY_WORD;
        return result;
    }
    STR_COMP(word,"declare"){
        result.data.key_word = DECLARE;
        result.type = KEY_WORD;
        return result;
    }
    STR_COMP(word,"let"){
        result.data.key_word = LET;
        result.type = KEY_WORD;
        return result;
    }
    STR_COMP(word,"end"){
        result.data.key_word = END;
        result.type = KEY_WORD;
        return result;

    }
    STR_COMP(word,"return"){
        result.data.key_word = RETURN;
        result.type = KEY_WORD;
        return result;
    }
    STR_COMP(word,"add"){
        result.data.key_word = ADD;
        result.type = KEY_WORD;
        return result;
    }

    STR_COMP(word,"subtract"){
        result.data.key_word = SUB;
        result.type = KEY_WORD;
        return result;
    }

    STR_COMP(word,"multiply"){
        result.data.key_word = MULTIPLY;
        result.type = KEY_WORD;
        return result;
    }

    STR_COMP(word,"divide"){
        result.data.key_word = DIVIDE;
        result.type = KEY_WORD;
        return result;
    }
    STR_COMP(word,"define"){
        result.data.key_word = DIVIDE;
        result.type = KEY_WORD;
        return result;
    }
    STR_COMP(word,"integer"){
        result.data.key_word = INTEGER;
        result.type = KEY_WORD;
        return result;
    }
    STR_COMP(word,"string"){
        result.data.key_word = STRING;
        result.type = KEY_WORD;
        return result;
    }
    switch(word[0]){
        case '0':
        case '1':
        case '2':
        case '3':
        case '5':
        case '6':
        case '7':
        case '9':
            result.data.literal.type = INT;
            strcpy(result.data.literal.buff,word);
            result.type = LITERAL;
            return result;
        case '"':
            result.data.literal.type = STR;
            strcpy(result.data.literal.buff,word);
            result.type = LITERAL;
            return result;
    }
    result.type = SYMBOL;
    strcpy(result.data.symbol.buff,word);

    return result;
}


vector get_tokens(const char* path){
    FILE* file =  fopen(path,"r");
    ERR_ASSERT(file != NULL,"null file");
    char c;
    int string_mode = 0;
    int other_mode;
    char str[MAX_LITERAL_SIZE];
    char str_o[MAX_SYMBOL_SIZE];
    int string_mode_counter = 0;
    int other_mode_counter = 0;
    vector tokens = create_vector(token,10);
    while((c = fgetc(file)) != EOF){
        if(string_mode){
            if(c == '"'){
                str[string_mode_counter] = '\0';
                printf("token: %s\n",str);
                push_vector(token,&tokens,determine_token(str));
                string_mode = 0;
                string_mode_counter = 0;
                continue;
            }
            str[string_mode_counter] = c;
            string_mode_counter++;
            continue;
        }
        if(c == '"') {
            string_mode = 1;
            continue;
        }
        if(c != ' ' && c != '\n' && c != EOF && c != '\t') {
            other_mode =1;
        }
        if(other_mode){
            if(c == ' ' || c == '\n' || c == EOF || c == '\t'){
                str_o[other_mode_counter] = '\0';
                printf("token: %s\n",str_o);
                push_vector(token,&tokens,determine_token(str_o));
                other_mode = 0;
                other_mode_counter = 0;
                continue;
            }
            str_o[other_mode_counter] = c;
            other_mode_counter++;
            continue;
        }


    }
    fclose(file);
    return tokens;
}


