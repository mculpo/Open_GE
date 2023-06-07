#ifndef __ENTITYMANAGER_H__
#define __ENTITYMANAGER_H__

#include <Entity/Entity.h>
#include <Core/Singleton.h>
#include <Core/tspch.h>

namespace openge {

	class Entity;

	class EntityManager : public Singleton<EntityManager> {
	private:
		std::unordered_map<std::string, ref<Entity>> m_entities;

	public:
		EntityManager() {};
		~EntityManager() {};


		template<typename EntityType>
		void addEntity(ref<EntityType> entity) {
			static_assert(std::is_base_of<Entity, EntityType>::value, "EntityType must derive from Entity.");

			ref<Entity> _entity = std::static_pointer_cast<Entity>(entity);
			std::string sizeString = std::to_string(m_entities.size());
			m_entities[_entity->getTag() + sizeString] = _entity;
		}

		template<typename EntityType>
		std::vector<ref<EntityType>> findGameObjects()
		{
			static_assert(std::is_base_of<Entity, EntityType>::value, "EntityType must derive from Component<T>.");

			std::vector<ref<EntityType>> entities;

			for (const auto& entity : m_entities)
			{
				ref<EntityType> _ent = std::static_pointer_cast<EntityType>(entity.second);
				if (_ent)
				{
					entities.push_back(_ent);
				}
			}

			return entities;
		}

		template<typename EntityType>
		std::vector<ref<EntityType>> findGameObjectsByTag(const std::string& tag)
		{
			static_assert(std::is_base_of<Entity, EntityType>::value, "EntityType must derive from Entity.");
			std::vector<ref<EntityType>> entities;

			for (const auto& entity : m_entities) {
				if (entity.second->getTag() == tag) {
					ref<EntityType> _entity = std::static_pointer_cast<EntityType>(entity.second);
					if (_entity) {
						entities.push_back(_entity);
					}
				}
			}
			return entities;
		}

		void removeEntity(const std::string& tag) {
			m_entities.erase(tag);
		}

		template<typename EntityType>
		ref<EntityType> findEntityByTag(const std::string& tag) {

			static_assert(std::is_base_of<Entity, EntityType>::value, "EntityType must derive from Entity.");

			for (const auto& entity : m_entities) {
				if (entity.second->getTag() == tag) {
					return std::static_pointer_cast<EntityType>(entity.second);
				}
			}
			return nullptr;
		}
	};

} // namespace openge

#endif

