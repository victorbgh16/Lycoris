// Created by Victor Berghausen on 28.08.2022.

#ifndef LYCORIS_LEXER_HPP
#define LYCORIS_LEXER_HPP

#include <vector>
#include <string>

enum TokenType {
    // Data types
    TOK_INT, // integer
    TOK_FLT, // float
    TOK_DBL,// double
    TOK_CHAR, // character
    TOK_STR, // string
    TOK_BOOl, // boolean

    TOK_IDEN, // identifier

    // Keywords
    TOK_ENUM, // enumeration
    TOK_IMPORT, // import
    TOK_FROM, // from (from x import sth)
    TOK_AS, // as (import x as y)
    TOK_STRUCT, // structure
    TOK_FN, // function
    TOK_RETURN, // return
    TOK_IF, // if
    TOK_ELIF, // else if
    TOK_ELSE, // else
    TOK_FOR, // for
    TOK_IN, // in
    TOK_CONTINUE, // continue
    TOK_BREAK, // break
    TOK_TRUE, // true
    TOK_FALSE, // false

    // Operators
    TOK_ASSN, // assignment
    // Arithmetic
    TOK_ADD, // +
    TOK_SUB, // -
    TOK_MUL, // *
    TOK_DIV, // /
    TOK_MOD, // %
    // Arithmetic assignment
    TOK_ADD_ASSN, // +=
    TOK_SUB_ASSN, // -=
    TOK_MUL_ASSN, // *=
    TOK_DIV_ASSN, // /=
    TOK_MOD_ASSN, // %=
    // power
    TOK_POW, // **
    // Unary
    TOK_UADD, // +expression
    TOK_USUB, // -expression
    // Logic
    TOK_AND, // &&
    TOK_OR, // ||
    TOK_NOT, // !
    TOK_EQ, // ==
    TOK_LT, // <
    TOK_GT, // >
    TOK_LE, // <=
    TOK_GE, // >=
    TOK_NE, // !=
    // Bitwise
    TOK_BAND, // bitwise AND / &
    TOK_BOR, // bitwise OR / |
    TOK_BNOT, // bitwise NOT / ~
    TOK_BXOR, // bitwise XOR / ^
    // Bitwise assignment
    TOK_BAND_ASSN, // &=
    TOK_BOR_ASSN, // |=
    TOK_BNOT_ASSN, // ~=
    TOK_BXOR_ASSN, // ^=
    // Misc.
    TOK_LSHIFT, // <<
    TOK_RSHIFT, // >>
    TOK_LSHIFT_ASSN, // <<=
    TOK_RSHIFT_ASSN, // >>=
    // Conditional ( ? : )
    TOK_QUEST, // ?
    TOK_COL, // :

    // Varargs
    TOK_TDOT, // ...

    // Separators
    TOK_DOT, // .
    TOK_COMMA, // ,
    TOK_AT, // @
    TOK_SPC, // space
    TOK_TAB, // tab
    TOK_NEWL, // \n
    TOK_COLS, // Semicolon
    //Parenthesis, Braces, Brackets
    TOK_LPAREN, // (
    TOK_RPAREN, // )
    TOK_LBRACE, // {
    TOK_RBRACE, // }
    TOK_LBRACK, // [
    TOK_RBRACK, // ]

    TOK_INVALID, // invalid

    _TOK_LAST,
};

#endif //LYCORIS_LEXER_HPP
