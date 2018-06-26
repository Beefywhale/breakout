#include <queue>
#include "Event.h"


class EventHandler {
public:
    EventHandler() {}

    void addEvent(Event* event);
    Event* pollEvents();
    bool isEmpty() { return eventQueue.empty(); }
    std::queue<Event*> getQueue() { return eventQueue; }

private:
    std::queue<Event*> eventQueue;
};