// Created by Victor Berghausen on 28.08.2022.
// credit to https://www.github.com/scribe-lang/scribe for a lot of this code

#ifndef LYCORIS_LEXER_HPP
#define LYCORIS_LEXER_HPP

#include <cstddef>
#include <vector>
#include <string>

namespace lyc {
    namespace lex {
        enum TokType {
            INT,
            FLT,

            CHAR,
            STR,
            IDEN,

            // Keywords
            LET,
            DEF,
            IF,
            ELIF,
            ELSE,
            FOR,
            IN,
            WHILE,
            RETURN,
            CONTINUE,
            BREAK,
            VOID,
            TRUE,
            FALSE,
            NIL,
            ANY,  // type: any
            TYPE, // type: type
            I1,
            I8,
            I16,
            I32,
            I64,
            U8,
            U16,
            U32,
            U64,
            F32,
            F64,
            OR,
            STATIC,
            CONST,
            VOLATILE,
            DEFER,
            EXTERN,
            COMPTIME, // maybe?
            GLOBAL,
            INLINE, // maybe?
            STRUCT,
            ENUM,

            // Operators
            ASSN,
            // Arithmetic
            ADD,
            SUB,
            MUL,
            DIV,
            MOD,
            ADD_ASSN,
            SUB_ASSN,
            MUL_ASSN,
            DIV_ASSN,
            MOD_ASSN,
            // Post/Pre Inc/Dec
            XINC,
            INCX,
            XDEC,
            DECX,
            // Unary
            UADD,
            USUB,
            UAND, // address of
            UMUL, // dereference
            // Logic
            LAND,
            LOR,
            LNOT,
            // Comparison
            EQ,
            LT,
            GT,
            LE,
            GE,
            NE,
            // Bitwise
            BAND,
            BOR,
            BNOT,
            BXOR,
            BAND_ASSN,
            BOR_ASSN,
            BNOT_ASSN,
            BXOR_ASSN,
            // Others
            LSHIFT,
            RSHIFT,
            LSHIFT_ASSN,
            RSHIFT_ASSN,

            SUBS, // idk what this is

            FNCALL, // function call and struct template specialization
            STCALL, // instantiate structs

            // Varargs
            PreVA,
            PostVA,

            // Separators
            DOT,
            QUEST,
            COL,
            COMMA,
            AT,
            SPC,
            TAB,
            NEWL,
            COLS, // Semi colon
            ARROW, // maybe?
            // Parenthesis, Braces, Brackets
            LPAREN,
            RPAREN,
            LBRACE,
            RBRACE,
            LBRACK,
            RBRACK,

            FEOF,
            INVALID,

            _LAST,
        };

        extern const char *TokStrs[_LAST];


    } // namespace lex
} // namespace lyc

#endif //LYCORIS_LEXER_HPP