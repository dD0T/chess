#ifndef ABSTRACTGAMEOBSERVER_H
#define ABSTRACTGAMEOBSERVER_H

#include <memory>
#include <chrono>

#include "../GameState.h"
#include "core/GameConfiguration.h"

class AbstractGameObserver {
public:
	virtual ~AbstractGameObserver() { /* Nothing */ }

    virtual void onGameStart(GameState /*state*/, GameConfiguration /*config*/ ) { /* Nothing */ }
	virtual void onTurnStart(PlayerColor /*who*/ ) { /* Nothing */ }
    virtual void onTurnEnd(PlayerColor /*who*/, Turn /*turn*/, GameState /*newState*/) { /* Nothing */ }
	virtual void onTurnTimeout(PlayerColor /*who*/, std::chrono::seconds /*timeout*/ ) { /* Nothing */ }
    virtual void onGameOver(GameState /*state*/, PlayerColor /*winner*/) { /* Nothing */ }
};

using AbstractGameObserverPtr = std::shared_ptr<AbstractGameObserver>;

#endif // ABSTRACTGAMEOBSERVER_H
