#pragma once
#include <vector>
#include <cstddef> // for size_t

/**
 * @brief A queue that returns random item on pop.
 *
 */
template <class T>
class RandomQueue
{
private:
    std::vector<T> queue;

public:
    RandomQueue(){}

    RandomQueue(std::vector<T> queue)
    {      
        this->queue = queue;
    }

    ~RandomQueue() {}

    T PopItem()
    {
        int index = rand() % queue.size();
        T item = queue[index];
        queue.erase(queue.begin() + index);
        return item;
    }

    void PushItem(T item)
    {
        queue.push_back(item);
    }

    bool IsEmpty()
    {
        return queue.empty();
    }

    size_t GetSize()
    {
        return queue.size();
    }
};
