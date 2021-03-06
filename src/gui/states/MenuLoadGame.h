/*
    Copyright (c) 2013-2014, Patrick Hillert <silent@gmx.biz>

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

#ifndef MENULOADGAME_H
#define MENULOADGAME_H

#include "gui/interface/AbstractState.h"
#include "gui/states/MenuLoadGame.h"
#include "gui/Menu2D.h"

class StateMachine;

/**
 * @brief Class which holds the state LoadGame. The user can load a previously
 * saved game from one of three game slots.
 *
 * @note To run() a state, first enter() the state.
 */
class MenuLoadGame : public AbstractState {
public:
    /**
     * @brief Creates a new menu LoadGame State object.
     */
    MenuLoadGame();

    /**
     * @brief Enters the state for the first time. This will setup all the state related stuff.
     * @note To run() the current state, first enter() it.
     */
    void enter() override;

    /**
     * @brief Runs the current state and does all the work.
     * @return AbstractState* the state which should be run after this state.
     * A nullptr if the game should be exited.
     */
    AbstractState* run() override;

    /**
     * @brief Exits the current state and cleans up all allocated resources.
     * @note This is the last method to call, before the object is deleted.
     */
    void exit() override;

    /**
     * @brief Draws something state related stuff on the screen.
     */
    void draw();

    /**
     * @brief This method is called if the user chose the back button.
     */
    void onMenuBack();

private:
    //! Reference to the StateMachine.
    StateMachine& fsm;

    //! Internal GameMode states.
    enum States {
        KEEP_CURRENT,

        LOAD_SLOT_A,
        LOAD_SLOT_B,
        LOAD_SLOT_C,
        MENU_MAIN
    };

    //! The next State for the StateMachine to enter.
    States m_nextState;

    //! Shared pointer for better garbage handling.
    Menu2DPtr menu;
};

#endif // MENULOADGAME_H