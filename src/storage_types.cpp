#include "storage_types.hpp"

Package PackageQueue::pop()
{
    Package x;
    switch (type_of_queue_)
    {
        case PackageQueueType::LIFO:
            x = std::move(list_of_products_.back());
            list_of_products_.pop_back();
            break;

        case PackageQueueType::FIFO:
            x = std::move(list_of_products_.front());
            list_of_products_.pop_front();
            break;
        default:
            throw;
    }
    return x;
}
