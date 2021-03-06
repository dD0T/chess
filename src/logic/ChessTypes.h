/*
    Copyright (c) 2013-2014, Max Stark <max.stark88@googlemail.com>

    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice,
    this list of conditions and the following disclaimer.

    2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.

    3. Neither the name of the copyright holder nor the names of its
    contributors may be used to endorse or promote products derived from
    this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.
*/
#ifndef CHESSTYPES_H
#define CHESSTYPES_H

#include <stdint.h>
#include <limits.h>
#include <vector>
#include <string>
#include <sstream>
#include <memory>
#include <cassert>
#include "misc/helper.h"

/* Collection of some useful definitions and chess-types */

const int NUM_FIELDS = 64;
const int NUM_FILES = 8;
const int NUM_RANKS = 8;
const int NUM_PLAYERS = 2;
const int NUM_PIECETYPES = 6;

enum Field {
    A1, B1, C1, D1, E1, F1, G1, H1,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A8, B8, C8, D8, E8, F8, G8, H8,
    ERR
};

enum File {
    A = 0, B, C, D, E, F, G, H, NoFile
};

enum Rank {
    One = 0, Two, Three, Four, Five, Six, Seven, Eight, NoRank
};

enum PieceType {
    King, Queen, Bishop, Knight, Rook, Pawn, AllPieces, NoType
};
enum PlayerColor {
    White, Black, NoPlayer
};

using Score = int;
// Provide MAX_SCORE/MIN_SCORE to ensure that both are negatable to reach each other
const Score MAX_SCORE = std::numeric_limits<Score>::max();
const Score MIN_SCORE = -std::numeric_limits<Score>::max();
// Provide a WIN_SCORE/LOOSE_SCORE to ensure that results with it are preferred to MAX_SCORE/MIN_SCORE
const Score WIN_SCORE = std::numeric_limits<Score>::max() - 1;
const Score LOOSE_SCORE = -std::numeric_limits<Score>::max() + 1;
const Score WIN_SCORE_THRESHOLD = WIN_SCORE - 100000; //! Threshold above which a score is considered a certain victory.

//! Toggles player color between white and black
inline PlayerColor togglePlayerColor(PlayerColor color) {
    assert(White == 0 && Black == 1);
    return static_cast<PlayerColor>(static_cast<int>(color) ^ 0x1);
}

//! Returns the Rank of the given Field
inline Rank rankFor(Field field) {
    return static_cast<Rank>(static_cast<int>(field) / 8);
}

//! Returns the File of the given Field
inline File fileFor(Field field) {
    return static_cast<File>(static_cast<int>(field) % 8);
}

//! Returns the Field identified by Rank and File
inline Field fieldFor(File file, Rank rank) {
    return static_cast< Field>(file + rank * 8);
}

//! Flips the Rank of the given Field
inline Field flipHorizontal(Field field) {
    return fieldFor(fileFor(field), static_cast<Rank>(Eight - rankFor(field)));
}

inline Rank nextRank(Rank rank) {
    return static_cast<Rank>(rank + 1);
}

inline Rank prevRank(Rank rank) {
    return static_cast<Rank>(rank - 1);
}

inline File nextFile(File file) {
    return static_cast<File>(file + 1);
}

inline File prevFile(File file) {
    return static_cast<File>(file - 1);
}

inline Field nextField(Field field) {
    return static_cast<Field>(field + 1);
}

inline Field prevField(Field field) {
    return static_cast<Field>(field - 1);
}

using BitBoard = uint64_t;
using Hash = uint64_t;

struct Piece {
    PlayerColor player;
    PieceType   type;

    Piece()
        : player(NoPlayer), type(NoType) {}
    Piece(PlayerColor player, PieceType pieceType)
        : player(player), type(pieceType) {}

    bool operator==(const Piece& other) const;
};

namespace std {
    std::ostream& operator <<(std::ostream& stream, const PlayerColor c);
    std::ostream& operator <<(std::ostream& stream, const Piece p);
    std::ostream& operator <<(std::ostream& stream, const Field f);
    std::ostream& operator <<(std::ostream& stream, const Rank r);
    std::ostream& operator <<(std::ostream& stream, const File f);
}


#endif // CHESSTYPES_H
