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
            switch(val) {
                case ASSN: return "__assn__";
                // Arithmetic
                case ADD: return "__add__";
                case SUB: return "__sub__";
                case MUL: return "__mul__";
                case DIV: return "__div__";
                case MOD: return "__mod__";
                case ADD_ASSN: return "__add_assn__";
                case SUB_ASSN: return "__sub_assn__";
                case MUL_ASSN: return "__mul_assn__";
                case DIV_ASSN: return "__div_assn__";
                case MOD_ASSN: return "__mod_assn__";
                // Post/Pre Inc/Dec
                case XINC: return "__xinc__";
                case INCX: return "__incx__";
                case XDEC: return "__xdec__";
                case DECX: return "__decx__";
                // Unary
                case UADD: return "__uadd__";
                case USUB: return "__usub__";
                // Logic
                case LAND: return "__logand__";
                case LOR: return "__logor__";
                case LNOT: return "__lognot__";
                // Comparison
                case EQ: return "__eq__";
                case LT: return "__lt__";
                case GT: return "__gt__";
                case LE: return "__le__";
                case GE: return "__ge__";
                case NE: return "__ne__";
                // Bitwise
                case BAND: return "__band__";
                case BOR: return "__bor__";
                case BNOT: return "__bnot__";
                case BXOR: return "__bxor__";
                case BAND_ASSN: return "__band_assn__";
                case BOR_ASSN: return "__bor_assn__";
                case BNOT_ASSN: return "__bnot_assn__";
                case BXOR_ASSN: return "__bxor_assn__";
                // Others
                case LSHIFT: return "__lshift__";
                case RSHIFT: return "__rshift__";
                case LSHIFT_ASSN: return "__lshift_assn__";
                case RSHIFT_ASSN: return "__rshift_assn__";
                case SUBS: return "__subscr__";
                default: break;
            }
            return "";
        }

        bool Data::cmp(const Data &other, const TokType type) const {

            switch(type) {
                case STR:
                case IDEN: return s == other.s;
                case INT: return i == other.i;
                case FLT: return f == other.f;
                default: break;
            }
            return false;
        }

    }
}