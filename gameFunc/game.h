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

    void finaliseRound();
    void prepareNewRound();
    bool playerMakesMove(int playerNum);
    bool hasRoundEnded();
    bool hasGameEnded();
    void finaliseGame();
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

#endif // AzulGame