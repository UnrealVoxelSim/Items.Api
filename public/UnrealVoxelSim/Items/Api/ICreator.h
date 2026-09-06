#pragma once

#include <expected>
#include "UnrealVoxelSim/Ecs/Api/EntityId.h"
#include "UnrealVoxelSim/Items/Api/CreateError.h"
#include "UnrealVoxelSim/Spatial/Api/Position.h"

namespace UnrealVoxelSim::Items::Api
{
	// Synchronous, simulation-thread-affine capability. Implementations add no implicit locking.
	class ICreator
	{
	public:
		virtual ~ICreator() = default;

		// Creates an entity with ItemComponent and PositionComponent, without StackComponent.
		// Failure leaves no partially initialized entity.
		[[nodiscard]] virtual std::expected<Ecs::Api::EntityId, CreateError>
		CreateItem(const Spatial::Api::Position& position) = 0;
	};
}
