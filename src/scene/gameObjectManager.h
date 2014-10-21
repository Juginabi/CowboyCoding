#include "../commonTypeDefs.h"
#include "gameObject.h"
#include "component.h"

class gameObjectManager {
public:
    ///
    /// \brief Get instance of this singleton class
    /// \return Shared pointer of this class
    ///
    static gameObjectManager *getInstance();

    ///
    /// \brief Create gameObject with name and component list as parameter
    /// \param GameObject name as std::string
    /// \param Component-list as std::string ie. "gocVisualSphere, gocAI, gocTransform"
    ///
    void createGameObject(go_type_name _GOName, goc_type_name _GOCList);

    ///
    /// \brief Create GameObject using template database of ready made GOs
    /// \param Template GameObject name
    ///
    void createGameObject(go_type_name _GOName);

    ///
    /// \brief Clear all GameObjects from the database
    ///
    void clearGameObjects();

    ///
    /// \brief Get GameObject pointer from GameObjectMap
    /// \param GameObject name
    ///
    void getGameObjectByName(go_type_name _GOName);

    ///
    /// \brief Get GameObject pointer from GameObjectMap
    /// \param GameObject Id as unsigned long int
    ///
    void getGameObjectById(go_type_id _GOId);

protected:
    gameObjectManager() {}; // Prevent construction
    gameObjectManager(const gameObjectManager&); // Prevent construction by copying
    gameObjectManager& operator=(const gameObjectManager&); // Prevent assignment
    ~gameObjectManager(); // Prevent unwanted destruction
private:
    static gameObjectManager *goManager_;

    static bool goManagerFlag_;

    // Map containing all created gameObjects
    GameObject_map gameObjectMap_;

    go_type_id nextFreeId_;
};
