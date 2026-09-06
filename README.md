# UnrealVoxelSim.Items.Api

Header-only generic item contracts: `ICreator`, `IMover`, `ItemComponent`, and `StackComponent`.

`CreateItem` attaches the item marker and world position, without stack data. `MoveItem` requires an existing position;
it does not extract an item from containment. Failed operations leave no partial creation or movement.

`StackComponent::Size` represents a positive unit count on an initialized stack. Non-stackable items omit the component.
Subtype domains own stack initialization, mutation, limits, and exhaustion behavior; this API defines no item catalog.

All capabilities are synchronous and confined to the owning simulation thread. Returned query containers are owned
snapshots. Entity references are non-owning and scoped to one registry; they are not persistent save identities.
Components are public read contracts; composition grants mutation authority only to the owning domain.

## Build validation

Use a Visual Studio developer environment with CMake, Ninja, and `VCPKG_ROOT` available:

```powershell
cmake --preset windows-msvc-debug
cmake --build --preset windows-msvc-debug
cmake --preset windows-msvc-release
cmake --build --preset windows-msvc-release
```

The default build compiles each public header in isolation and verifies that interfaces remain abstract with virtual
destructors. This module contains no runtime implementation or behavioral tests yet. Linux Clang presets are also provided.
