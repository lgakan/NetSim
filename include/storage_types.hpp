//
// Created by ACER on 15.12.2021.
//

#ifndef NETSIM_STORAGE_TYPES_HPP
#define NETSIM_STORAGE_TYPES_HPP

#include <iterator>
#include <list>
#include "package.hpp"
#include "memory"


class IPackageStockpile{
public:
    using const_iterator = std::list<Package>::const_iterator;

    virtual void push(Package&& aPackage) = 0;
    virtual bool empty() const = 0;
    virtual size_type size() const = 0;

    virtual const_iterator begin() = 0;
    virtual const_iterator cbegin() const = 0;
    virtual const_iterator end() = 0;
    virtual const_iterator cend() const = 0;

    virtual ~IPackageStockpile() {};
};

enum class PackageQueueType{
    FIFO = 0,
    LIFO = 1
};

class IPackageQueue : public IPackageStockpile{
public:
    virtual Package pop() = 0;
    virtual PackageQueueType get_queue_type() const = 0;
    virtual ~IPackageQueue() {};
};

class PackageQueue : public  IPackageQueue{
public:
    PackageQueue(PackageQueueType queue_type) : type_of_queue_(queue_type) {};
    PackageQueue(const PackageQueue&) {};

    void push(Package&& aPackage) {list_of_products_.emplace_back(std::move(aPackage));}
    bool empty() const {return list_of_products_.empty();}
    size_type size() const {return list_of_products_.size();}

    const_iterator begin() {return list_of_products_.begin();}
    const_iterator cbegin() const { return list_of_products_.cbegin();}
    const_iterator end() {return list_of_products_.end();}
    const_iterator cend() const {return list_of_products_.cend();}

    Package pop();
    PackageQueueType get_queue_type() const {return type_of_queue_;}

    ~PackageQueue() {};
private:
    std::list<Package> list_of_products_;
    PackageQueueType type_of_queue_;
};
//std::unique_ptr<IPackageStockpile> ptr = std::make_unique<PackageQueue>(PackageQueueType::LIFO);

#endif //NETSIM_STORAGE_TYPES_HPP
