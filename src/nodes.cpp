#include "nodes.hpp"

void ReceiverPreferences::add_receiver(IPackageReceiver* r) {
    preferences_.insert(std::pair<IPackageReceiver*, double>(r, 1));

    auto n = double(preferences_.size());
    for (auto& p : preferences_) {
        p.second = 1/n;
    }
}

void ReceiverPreferences::remove_receiver(IPackageReceiver* r) {
    preferences_.erase(r);

    auto n = double(preferences_.size());
    for (auto& p : preferences_) {
        p.second = 1/n;
    }
}

IPackageReceiver* ReceiverPreferences::choose_receiver() {
    double pg = pg_();
    double lower_bound = 0;

    for (const auto& p : preferences_) {
        if (lower_bound == 0) {
            if (pg >= lower_bound && pg <= p.second) {
                return p.first;
            }
        }
        if (lower_bound < pg && pg <= lower_bound + p.second) {
            return p.first;
        }
        lower_bound += p.second;
    }
    return nullptr;
}

void PackageSender::send_package() {
    std::optional<Package>& buffer = get_sending_buffer();
    if (buffer) {
        IPackageReceiver* s = receiver_preferences_.choose_receiver();
        s->receive_package(std::move(*buffer));
        buffer_.reset();
    }
}

void Ramp::deliver_goods(Time t) {
    Time time = t - 1;
    if (time % get_delivery_interval() == 0) {
        push_package(Package());
    }
}

void Worker::do_work(Time t) {
    if (!processing_buffer_) {
        starting_time_ = t - 1;
        processing_buffer_.emplace(ptr_->pop());
    }
    if (starting_time_ + time_offset_ == t) {
        push_package(std::move(*processing_buffer_));
        processing_buffer_.reset();
    }
}

void Worker::receive_package(Package&& p) {
    ptr_->push(std::move(p));
}

void Storehouse::receive_package(Package&& p) {
    ptr_->push(std::move(p));
}
