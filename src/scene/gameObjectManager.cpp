#include "gameObjectManager.h"

bool gameObjectManager::goManagerFlag_ = false;
gameObjectManager *gameObjectManager::goManager_ = 0;

gameObjectManager* gameObjectManager::getInstance() {
    if (!goManagerFlag_) {
        // First time query of this class. Let us create new instance
        goManager_= new gameObjectManager();
        goManagerFlag_ = !goManagerFlag_;
    }
    return goManager_;
}
