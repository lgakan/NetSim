#include "package.hpp"

std::set<ElementID> Package::assigned_IDs_;
std::set<ElementID> Package::freed_IDs_;

Package::Package(){
    if(freed_IDs_.empty()){
        if(assigned_IDs_.empty()) {
            id_ = 1;
        }
        else {
            id_ = *assigned_IDs_.end() + 1;
        }
        assigned_IDs_.insert(id_);
    }
    else {
        id_ = *freed_IDs_.begin();
        freed_IDs_.erase(id_);
    }
}

Package::~Package() {
    freed_IDs_.insert(id_);
    assigned_IDs_.erase(id_);
}

//Package& Package::operator = (Package&& aPackage) {
//    assigned_IDs_.erase(assigned_IDs_.end());
//    freed_IDs_.insert(id_);
//    id_ = aPackage.id_;
//    return *this;
//}
