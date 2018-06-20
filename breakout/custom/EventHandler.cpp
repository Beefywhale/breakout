#include "EventHandler.h"


void EventHandler::addEvent(Event event) {
    eventQueue.push(event);
}

bool EventHandler::pollEvents(Event event) {
    if (eventQueue.empty()) {
        return false;
    } else {
        //event = eventQueue.front();
        eventQueue.pop();
        return true;
    }
}