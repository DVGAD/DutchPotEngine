### Scheduler: Single-Threaded with Fixed and Variable Updates

DutchPot uses a custom scheduler that controls which systems run and how often. This was designed from the start rather than added later because performance and control are core goals.
The scheduler distinguishes between two types of updates:

**Variable Update** runs as fast as the display allows and receives a delta_time value indicating how much time has passed since the last frame. The `RenderSystem`, `InputSystem`, and `AnimationSystem` run on variable update because they need to respond to the actual frame rate of the monitor.

**Fixed Update** runs at a strict, unchanging interval (typically 60Hz) regardless of the display refresh rate. The PhysicsSystem and simulation logic run on fixed update to ensure deterministic and stable behavior. If the game is rendering at 30fps the fixed update runs twice in one frame to catch up. If the game is rendering at 144fps the fixed update skips frames as needed.

The scheduler is single-threaded with a strict execution order. Systems run in sequence on one CPU core. This was chosen over a multi-threaded scheduler because multi-threading an ECS introduces significant complexity around race conditions and component access synchronization. The scheduler's interface is designed so that multi-threading could be added later without major architectural changes.
Not all systems run every frame. The scheduler allows systems to be registered with different frequencies or to run only when triggered. This avoids the wasteful pattern of running every system every frame regardless of whether it has work to do.