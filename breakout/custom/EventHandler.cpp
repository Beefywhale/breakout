#include "EventHandler.h"

void EventHandler::addEvent(Event* event) {
    eventQueue.push(event);
}

Event* EventHandler::pollEvents() {
    Event* event = eventQueue.front();
    printf(std::to_string(eventQueue.front()->collision->tile->getPosition().x).c_str());
    eventQueue.pop();
    return event;
}