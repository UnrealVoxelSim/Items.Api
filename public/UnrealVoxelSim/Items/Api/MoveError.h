#pragma once

namespace UnrealVoxelSim::Items::Api
{
	enum class MoveError
	{
		EntityNotAlive,
		EntityDestroying,
		NotItem,
		MissingPosition,
	};
}
