#pragma once
#include "Macro.h"
#include <list>
GG_NAMESPACE_BEGIN
class GameRole;
class GameController
{
public:
    static GameController &getInstance()
    {
        return smInstance;
    }
    static GameController smInstance;
    std::list<GameRole*> mGameRoles;
    ~GameController();
private:
    GameController();
};
GG_NAMESPACE_END
