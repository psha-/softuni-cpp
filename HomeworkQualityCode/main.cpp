#include <iostream>
#include "gamescene.h"
#include "gameenvironment.h"
#include "gamecharacter.h"
#include "charactercontroller.h"

// This is to serve as game framework demo.
//
// All framework interfaces defined in .h files.
// - GameScene is like a level.
// - GameObject is a base class and
// abstraction of something that can be placed in a scene
// - RigidBody is a subclass of GameObject and delas with the game physics.
// - The "controller" is a high level class that the framework user uses directly
// to controll the game objects.
//
// Note: character jump is defined as force (Newtons).
// I think it will be easier when a player is controlling the objects to think in terms of forces.

using namespace std;

namespace game {
    void printCharacterJumpData(const CharacterController& controller)
    {
        cout << "Maximum jump height of "
             << controller.getGameCharacter()->getName() << ": "
             << controller.calculateJumpHeight() << " meters" << endl;

        cout << "Time of jump of "
             << controller.getGameCharacter()->getName() << ": "
             << controller.calculateAirborneTime() << " seconds" << endl;

        cout << "Can "
             << controller.getGameCharacter()->getName()
             << " jump at 50cm? : "
             << boolalpha << controller.canJumpAtHeight(0.5f) << endl;

        cout << endl;
    }
}

int main()
{
    GameScene level1 = GameScene(new GameEnvironment(1, "Earth", 9.81));
    // My preference is jump force (in Newtons) instead of jump velocity (km/h). It's cleaner like this.
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

