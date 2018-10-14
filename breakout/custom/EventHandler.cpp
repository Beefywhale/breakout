#include "EventHandler.hpp"

void EventHandler::addEvent(std::function<void()> event) {
    eventQueue.push(event);
}

std::function<void()> EventHandler::pollEvents() {
    std::function<void()> event = eventQueue.front();
    eventQueue.pop();
    return event;
}
