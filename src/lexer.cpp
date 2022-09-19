// Created by Victor Berghausen on 28.08.2022.

#include "lexer.hpp"

#include <charconv>

namespace lyc {
    namespace lex {
        const char *TokStrs[_LAST] = {
                "INT",
                "FLT",
                "CHAR",
                "STR",
                "IDEN",

                // Keywords
                "let",
                "def",
                "if",
                "elif",
                "else",
                "for",
                "in",
                "while",
                "return",
                "continue",
                "break",
                "void",
                "true",
                "false",
                "nil",
                "any",
                "type",
                "i1",
                "i8",
                "i16",
                "132",
                "i64",
                "u8",
                "u16",
                "u32",
                "u64",
                "f32",
                "f64",
                "or",
                "static",
                "const",
                "volatile",
                "defer",
                "extern",
                "comptime",
                "global",
                "inline",
                "struct",
                "enum",

                // Operators
                "=",
                // Arithmetic
                "+",
                "-",
                "*",
                "/",
                "%",
                "+=",
                "-=",
                "*=",
                "/=",
                "%=",
                // Post/Pre Inc/Dec
                "x++",
                "++x",
                "x--",
                "--x",
                // Unary
                "u+",
                "u-",
                "u&",
                "u*",
                // Logic
                "&&",
                "||",
                "!",
                // Comparison
                "==",
                "<",
                ">",
                "<=",
                ">=",
                "!=",
                // Bitwise
                "&",
                "|",
                "~",
                "^",
                "&=",
                "|=",
                "~=",
                "^=",
                // Others
                "<<",
                ">>",
                "<<=",
                ">>=",

                "[]",
                "()",
                "{}",

                // Varargs
                "x...",
                "...x",

                // Separators
                ".",
                "?",
                ":",
                ",",
                "@",
                "SPC",
                "TAB",
                "NEWL",
                ";",
                "->",
                // Parenthesis, Braces, Brackets
                "(",
                ")",
                "{",
                "}",
                "[",
                "]",

                "<FEOF>",
                "<INVALID>"
        };

        std::string view_backslash(std::string_view data);

        Tok::Tok(const int &tok) : val((TokType)tok) {}

        const char *Tok::getUnaryNoCharCstr() const {
            switch(val) {
                case XINC:
                case INCX: return "++";
                case XDEC:
                case DECX: return "--";
                case UADD: return "+";
                case USUB: return "-";
                case UAND: return "&";
                case UMUL: return "*";
                case LNOT: return "!";
                case BNOT: return "~";
                default: break;
            }
            return "";
        }

        const char *Tok::getOperCStr() const {

        }
    }
}