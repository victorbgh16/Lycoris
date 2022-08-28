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
    TOK_STR, // string

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

};

#endif //LYCORIS_LEXER_HPP
