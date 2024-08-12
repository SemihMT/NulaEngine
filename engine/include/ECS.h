#include "Entity.h"
#include "Component.h"
namespace nula
{
    //This is the class we use that will manage all the entities, their components and the systems
    class ECS final
    {
        public:
        ECS() = default;
        ~ECS() = default;
        
        void CreateEntity();
        void AddComponent(Entity e, Component c);
        private:

    };
} // namespace nula
