#include <cstdint>
#include <limits>
namespace nula
{
    // Entities are simple identifiers
    using Entity = uint32_t;
    const Entity INVALID_ENTITY = std::numeric_limits<Entity>::max();
}