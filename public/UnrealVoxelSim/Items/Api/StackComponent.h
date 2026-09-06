#pragma once

#include <cstddef>

namespace UnrealVoxelSim::Items::Api
{
	// Shared representation only. The item's subtype domain owns mutation and stack limits.
	// Present stacks represent positive unit counts; non-stackable items omit this component.
	struct StackComponent final
	{
		std::size_t Size;
	};
}
