#include <queue>
#include "Event.h"


class EventHandler {
public:
    void addEvent(Event event);
    bool pollEvents(Event event);

private:
    std::queue<Event> eventQueue;
};