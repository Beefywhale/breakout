#pragma once
#include <queue>
#include <functional>

class EventHandler {
public:
    EventHandler() {}

    void addEvent(std::function<void()> event);
    std::function<void()> pollEvents();
    bool isEmpty() { return eventQueue.empty(); }
    std::queue<std::function<void()>> getQueue() { return eventQueue; }

private:
    std::queue<std::function<void()>> eventQueue;
};
