#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

#include <Entity/Entity.h>
#include <Core/tspch.h>

namespace openge {

    class GameObject : public Entity {
      
    public:
        GameObject();
        GameObject(std::uint64_t id, const std::string& name, const std::string& tag);
        ~GameObject();
    };
}

#endif // __GAME_OBJECT_H__
