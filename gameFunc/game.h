#ifndef AzulGame
#define AzulGame

#include "Factories.h"
#include "Centre.h"
#include "Player.h"
#include "BoxLid.h"
#include "TileBag.h"

#define FACTORIES_NUM 5

class Game {
public:

    Game();
    Game(std::string playerName1, std::string playerName2, int seed);
    ~Game();

    // copy constructor
    Game(Game& other);

    // Called after round ends, moves tiles and calculates points
    void finaliseRound();

    // Prepares for a new round after finalise round is called
    void prepareNewRound();

    // Gets the input of the player and validates their move
    bool playerMakesMove(int playerNum);

    // Ends the round when the centre factory is empty
    bool hasRoundEnded();

    // Ends the round when a line has been completed on the wall
    bool hasGameEnded();

    // Called after the game has ended and calculated the score and winner
    void finaliseGame();

    // Called after a loaded game has ended. Does not calculate bonus points
    void finaliseLoadedGame();


    factoriesPtr getFactories();
    centrePtr getCentre();
    playerPtr getPlayer1();
    playerPtr getPlayer2();
    lidPtr getLid();
    bagPtr getBag();

private:
    Factories *factories;
    Centre *centre;
    Player *player1;
    Player *player2;
    Lid *lid;
    Bag *bag;
};

#endif // Azul Game