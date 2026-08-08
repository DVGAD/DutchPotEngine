## Core Architectural Decisions

### System Communication: State Components vs Events

DutchPot uses two different communication patterns depending on the type of information being communicated.

**State Components for Gameplay Logic**
For gameplay communication between systems DutchPot uses state components rather than traditional event callbacks. When something happens in one system, that system writes state data onto the relevant entity, and other systems read that state when they process the entity during their own update phase.
For example when the `PhysicsSystem` detects that an entity has landed on the ground, it adds a `JustLanded` component to that entity. Later in the frame the `AnimationSystem` sees that component and switches to the landing animation. 
The AudioSystem sees it and plays a landing sound. 
At the end of the frame a cleanup system removes the `JustLanded` component.
This approach was chosen over immediate event callbacks for several reasons. 
State components keep systems isolated, so no system ever runs code inside another system's update loop. This prevents the call stack from becoming deeply nested and avoids issues with modifying entity data while a system is iterating through it. State components are also more performant because the systems are already iterating through the relevant entities, so checking for an additional component is essentially free in a cache-friendly ECS like `EnTT`.

**Events for Engine-Level Concerns**
For engine-level communication that does not fit the state component model, a simple event system is used. This includes things like window resize events, input events for editor shortcuts, and scene transition events. These are rare, one-off occurrences where the listening system does not normally iterate over the entity in question, making state components less appropriate.