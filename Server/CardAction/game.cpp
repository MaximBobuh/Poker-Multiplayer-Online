#include "game.h"
#include "gameimpl.h"

Game::Game()
{

}

Game::~Game()
{

}

//-----------------------------------

void Game::run()
{
    while(1) //edit
    {
        pimpl->nextStep();
    }
}
