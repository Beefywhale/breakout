#include "EventHandler.hpp"

void EventHandler::addEvent(Event* event) {
    eventQueue.push(event);
}

Event* EventHandler::pollEvents() {
    Event* event = eventQueue.front();
    eventQueue.pop();
    return event;
}
