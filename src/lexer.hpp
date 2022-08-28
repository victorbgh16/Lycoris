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

            IF,
            ELIF,
            ELSE,
            RETURN,
            CONTINUE,
            BREAK,
            FOR,
            IN,
            WHILE,

            IMPORT,
            AS,
            FROM,

            DEF,
        };
    } // namespace lex
} // namespace lyc

#endif //LYCORIS_LEXER_HPP