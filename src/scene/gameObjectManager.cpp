#include "gameObjectManager.h"

bool gameObjectManager::goManagerFlag_ = false;
gameObjectManager gameObjectManager::goManager_ = NULL;

gameObjectManager::getInstance() {
    if (goManagerFlag_) {
        return goManager_;
    } else {
        /// TODO return gameObjectManager pointer
    }
}
