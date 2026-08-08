## Scripting: To Be Determined

Scripting is not yet locked in. The current leaning is toward Lua for gameplay scripting due to its simplicity, small footprint, and status as the industry standard for game scripting. Python is also being considered for tooling or editor scripting since it is already familiar.

This decision is deferred until the core engine systems are in place. The architecture is designed so that scripting can be added later without major refactoring. The ECS, scheduler, and asset manager do not depend on the scripting layer.