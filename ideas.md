# Project ideas

Implement binding based event handling:

```c++
class Player {
  Player() {
    subscribe_to(Event::Jump, { on_event: on_jump, startup: jump_startup });
  }
  
  EventResult on_jump(genv::event &raw_event) {
    // handle jump
    return EventResult()
      .debug("player jumped!")
      .request_render();
  }
  
  EventResult jump_startup() {
    // load resources
    if (!resource) {
      return EventResult().error("Couldn't load resource");
    } else {
      return EventResult().debug("Loaded player jump resources");
    }
  }
  
  override void render(Canvas &canvas) {
    this->image.draw_at(this->position);
  }
}
```
