#include <glm/vec3.hpp>
namespace nula
{
    struct Component{};
    struct Renderable final : public Component
    {};

    struct Transform final : public Component
    {
       glm::vec3 position;
       glm::vec3 rotation;
       glm::vec3 scale;
    };

}