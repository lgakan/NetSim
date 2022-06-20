//
// Created by ACER on 15.12.2021.
//

#ifndef NETSIM_PACKAGE_HPP
#define NETSIM_PACKAGE_HPP

#include "types.hpp"
#include <set>
#include <utility>

class Package{
public:
    Package();
    Package(ElementID id) : id_(id) {}
    Package(const Package& package) : id_(package.get_id()) {};
    Package(Package&& aPackage) = default;

    Package& operator = (Package&&) = default;
    ElementID get_id() const { return id_; }
    ~Package();
private:
    ElementID id_;
    static std::set<ElementID> assigned_IDs_;
    static std::set<ElementID> freed_IDs_;
};
#endif //NETSIM_PACKAGE_HPP



