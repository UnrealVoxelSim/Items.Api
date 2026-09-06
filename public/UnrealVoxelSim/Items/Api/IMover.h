#pragma once

#include <expected>
#include "UnrealVoxelSim/Ecs/Api/EntityId.h"
#include "UnrealVoxelSim/Items/Api/MoveError.h"
#include "UnrealVoxelSim/Spatial/Api/Position.h"

namespace UnrealVoxelSim::Items::Api
{
	// Synchronous, simulation-thread-affine capability. Implementations add no implicit locking.
	class IMover
	{
	public:
		virtual ~IMover() = default;

		// Updates an item's existing PositionComponent; never extracts it from containment.
		// Failure leaves the item unchanged.
		[[nodiscard]] virtual std::expected<void, MoveError> MoveItem(Ecs::Api::EntityId entity,
																	  const Spatial::Api::Position& position) = 0;
	};
}
