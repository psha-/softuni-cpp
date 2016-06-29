#include <iostream>
#include "gamescene.h"
#include "gameenvironment.h"
#include "gamecharacter.h"
#include "charactercontroller.h"

using namespace std;

namespace game {
    void printCharacterJumpData(const CharacterController& controller)
    {
        cout << "Maximum jump height of "
             << controller.getGameCharacter()->getName() << ": "
             << controller.calculateObjectMaxJumpHeight() << " meters" << endl;

        cout << "Time of jump of "
             << controller.getGameCharacter()->getName() << ": "
             << controller.calculateAirborneTime() << " seconds" << endl;

        cout << "Can "
             << controller.getGameCharacter()->getName()
             << " jump at 50cm? : "
             << boolalpha << controller.canObjectJumpAtHeight(0.5f) << endl;

        cout << endl;
    }
}

int main()
{
    GameScene level1 = GameScene(new GameEnvironment(1, "Earth", 9.81));
    level1.addObject(new GameCharacter(2, "Luke Skywalker", 75, 250));
    level1.addObject(new GameCharacter(3, "Darth Vader", 89, 250));

    CharacterController skywalkerController(&level1, static_cast<GameCharacter*>(level1.getObjectById(2)));
    CharacterController vaderController(&level1, static_cast<GameCharacter*>(level1.getObjectById(3)));

    skywalkerController.jump();
    vaderController.jump();

    game::printCharacterJumpData(skywalkerController);
    game::printCharacterJumpData(vaderController);

    return 0;
}

