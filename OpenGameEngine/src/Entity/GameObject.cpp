#include "GameObject.h"

namespace openge {
    GameObject::GameObject() : Entity(0, "", "") {}
    GameObject::GameObject(std::uint64_t id, const std::string& name, const std::string& tag)
        : Entity(id, name, tag)
    {
    }
    GameObject::~GameObject()
    {
    }
}

