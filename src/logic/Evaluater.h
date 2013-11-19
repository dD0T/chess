#ifndef EVALUATER_H
#define EVALUATER_H

#include "GameState.h"

class Evaluater {
public:
    virtual int getMaterialWorth(PlayerColor player, ChessBoardPtr board);

};

using EvaluaterPtr = std::shared_ptr<Evaluater>;

#endif // EVALUATER_H