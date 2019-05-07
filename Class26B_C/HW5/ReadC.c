#include "ReadC.h"

char read_c_char(READ_C* read_c) {
    int ch    = fgetc(read_c->fptr);
    int index = ftell(read_c->fptr);
    if (ch == EOF) {
        //printf("  ch[%d] = EOF\n", index);
        read_c->eof = 1;
    } else if (ch == '\n') {
        read_c->line_number ++;
    } else if (ch >= 28 && ch <= 126) {
        //printf("  ch[%d] = '%c'\n", index, ch);
    } else {
        //printf("  ch[%d] = %d\n", index, (int)ch);
    }
    return ch;
}

void undo_read_c_char(READ_C* read_c, char ch) {
    if (ch == '\n') {
        read_c->line_number --;
    }
    fseek(read_c->fptr, -1, SEEK_CUR);
}

void skip_c_chars(READ_C* read_c) {
    const char* skip_chars = " \t\n\r~!@#$%^&*()_+`-=[]\\{}|;:,.<>?";
    int done = 0;
    char ch;
    while (!done && !read_c->eof) {
        ch = read_c_char(read_c);
        done = 1;
        for (int i = 0; skip_chars[i] != '\0'; i ++) {
            if (ch == skip_chars[i]) {
                done = 0;
                break;
            }
        }
    }
    undo_read_c_char(read_c, ch);
}

void read_c_double_quote(READ_C* read_c) {
    char ch = read_c_char(read_c);
    if (ch == '\"') {
        int done = 0;
        while (! done) {
            ch = read_c_char(read_c);
            if (ch == '\"') {
                done = 1;
            }
        }
    } else {
        undo_read_c_char(read_c, ch);
    }
}

void read_c_single_quote(READ_C* read_c) {
    char ch = read_c_char(read_c);
    if (ch == '\'') {
        int done = 0;
        while (! done) {
            ch = read_c_char(read_c);
            if (ch == '\'') {
                done = 1;
            }
        }
    } else {
        undo_read_c_char(read_c, ch);
    }
}

void read_c_single_line_comment(READ_C* read_c) {
    char ch = read_c_char(read_c);
    if (ch == '/') {
        ch = read_c_char(read_c);
        if (ch == '/') {
            int done = 0;
            while (! done) {
                ch = read_c_char(read_c);
                if (ch == '\n') {
                    done = 1;
                }
            }
        } else {
            undo_read_c_char(read_c, ch);
            undo_read_c_char(read_c, '/');
        }
    } else {
        undo_read_c_char(read_c, ch);
    }
}

void read_c_multi_line_comment(READ_C* read_c) {
    char ch = read_c_char(read_c);
    if (ch == '/') {
        ch = read_c_char(read_c);
        if (ch == '*') {
            int done = 0;
            while (! done) {
                ch = read_c_char(read_c);
                char ch2 = read_c_char(read_c);
                if ((ch == '*') && (ch2 == '/')) {
                    done = 1;
                } else {
                    undo_read_c_char(read_c, ch2);
                }
            }
        } else {
            undo_read_c_char(read_c, ch);
            undo_read_c_char(read_c, '/');
        }
    } else {
        undo_read_c_char(read_c, ch);
    }
}

void read_c_number(READ_C* read_c) {
    char ch = read_c_char(read_c);
    if ((ch >= '0' && ch <= '9') ||
        ch == '-' ||
        ch == '.') {
        int done = 0;
        while (! done) {
            ch = read_c_char(read_c);
            if ((ch >= '0' && ch <= '9') ||
                ch == '-' ||
                ch == '.' ||
                ch == 'e') {
                // do nothing
            } else {
                done = 1;
            }
        }
        undo_read_c_char(read_c, ch);
    } else {
        undo_read_c_char(read_c, ch);
    }
}

void read_c_identifier(READ_C* read_c) {
    char identifier[MAX_C_IDENTIFIER_LENGTH];
    identifier[0] = '\0';
    int identifier_length = 0;
    char ch = read_c_char(read_c);
    if ((ch >= 'a' && ch <= 'z') ||
        (ch >= 'A' && ch <= 'Z') ||
        ch == '_') {
        identifier[identifier_length] = ch;
        identifier[identifier_length + 1] = '\0';
        identifier_length ++;
        int done = 0;
        while (! done) {
            ch = read_c_char(read_c);
            if ((ch >= 'a' && ch <= 'z') ||
                (ch >= 'A' && ch <= 'Z') ||
                (ch >= '0' && ch <= '9') ||
                ch == '_') {
                identifier[identifier_length] = ch;
                identifier[identifier_length + 1] = '\0';
                identifier_length ++;
            } else {
                done = 1;
            }
        }
        undo_read_c_char(read_c, ch);
        if (identifier[0] != '\0') {
            bst_insert(&(read_c->identifiers), identifier, read_c->line_number);
        }
    } else {
        undo_read_c_char(read_c, ch);
    }
}

BST_NODE* read_c_identifiers(char* filename) {
    READ_C read_c;
    read_c.identifiers = NULL;
    read_c.fptr        = fopen(filename, "r");
    if (read_c.fptr == NULL) {
        printf("Error opening \"%s\"\n", filename);
        exit(-1);
    }
    read_c.line_number = 1;
    read_c.eof         = 0;
    while (! read_c.eof) {
        skip_c_chars(&read_c);
        read_c_double_quote(&read_c);
        read_c_single_quote(&read_c);
        read_c_single_line_comment(&read_c);
        read_c_multi_line_comment(&read_c);
        read_c_number(&read_c);
        read_c_identifier(&read_c);
    }
    fclose(read_c.fptr);
    return read_c.identifiers;
}

