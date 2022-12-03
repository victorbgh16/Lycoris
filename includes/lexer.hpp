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

        class Tok {
            TokType val;

        public:
            Tok(const int &tok);

            inline bool isData() const {
                return val == INT || val == FLT || val == CHAR || val == STR || val == IDEN || val == VOID ||
                       val == TRUE || val == FALSE || val == NIL || val == ANY || val == TYPE || val == I1 ||
                       val == I8 || val == I16 || val == I32 || val == I64 || val == U8 || val == U16 ||
                       val == U32 || val == U64 || val == F32 || val == F64;
            }

            inline bool isLiteral() const {
                return val == INT || val == FLT || val == CHAR || val == STR;
            }

            inline bool isOper() const {
                return val >= ASSN && val <= RBRACK;
            }

            inline bool isUnaryPre() const {
                return val == UADD || val == USUB || val == UAND || val == UMUL || val == INCX || val == DECX ||
                       val == LNOT || val == BNOT;
            }

            inline bool isUnaryPost() const {
                return val == XINC || val == XDEC;
            }

            inline bool isComparison() const {
                return val == EQ || val == LT || val == GT || val == LE || val == GE || val == NE;
            }

            inline bool isAssign() const {
                return val == ASSN || val == ADD_ASSN || val == SUB_ASSN || val == MUL_ASSN || val == DIV_ASSN ||
                       val == MOD_ASSN || val == BAND_ASSN || val == BOR_ASSN || val == BNOT_ASSN || val == BXOR_ASSN ||
                       val == LSHIFT_ASSN || val == RSHIFT_ASSN;
            }

            inline bool isValid() const {
                return val != INVALID && val != FEOF;
            }

            inline const char *cStr() const {
                return TokStrs[val];
            }

            inline std::string str() const {
                return TokStrs[val];
            }

            const char *getOperCStr() const;
            const char *getUnaryNoCharCstr() const;

            inline bool operator==(const Tok &other) const {
                return val == other.val;
            }

            inline TokType getVal() const {
                return val;
            }

            inline void setVal(const TokType &v) {
                val == v;
            }

            inline bool isType(const TokType &other) const {
                return val == other;
            }
        };

        struct Data {
            std::string_view s;
            int64_t i;
            long double f;

            bool cmp(const Data &other, const TokType type) const;
        };

        class Lexeme {
            
        };

    } // namespace lex
} // namespace lyc

#endif //LYCORIS_LEXER_HPP