#include "factory.hpp"

enum class NodeColor { UNVISITED, VISITED, VERIFIED };

bool has_reachable_storehouse(const PackageSender* sender, std::map<const PackageSender*, NodeColor>& node_colors) {
    if (node_colors.at(sender) == NodeColor::VERIFIED) {
        return true;
    }
    node_colors.at(sender) = NodeColor::VISITED;

    if (sender->receiver_preferences_.get_preferences().empty()) {
        throw std::logic_error("Receivers not defined");
    }

    bool different_receiver_than_itself = false;
    for (const auto& receiver : sender->receiver_preferences_) {
        if (receiver.first->get_receiver_type() == ReceiverType::STOREHOUSE) {
            different_receiver_than_itself = true;
        }
        else {
            IPackageReceiver* receiver_ptr = receiver.first;
            auto worker_ptr = dynamic_cast<Worker*>(receiver_ptr);
            auto sendrecv_ptr = dynamic_cast<PackageSender*>(worker_ptr);

            if (sendrecv_ptr == sender) {
                continue;
            }
            different_receiver_than_itself = true;

            if (node_colors.at(sendrecv_ptr) != NodeColor::VISITED) {
                has_reachable_storehouse(sendrecv_ptr, node_colors);
            }
        }
    }

    node_colors.at(sender) = NodeColor::VERIFIED;

    if (different_receiver_than_itself) {
        return true;
    }
    else {
        throw std::logic_error("Storehouse not reachable");
    }
}

bool Factory::is_consistent() {

    std::map<const PackageSender*, NodeColor> color;

    for (auto &r : ramps_list_) {
        color.insert(std::pair<PackageSender*, NodeColor>(&r, NodeColor::UNVISITED));
    }
    for (auto &w : workers_list_) {
        color.insert(std::pair<PackageSender*, NodeColor>(&w, NodeColor::UNVISITED));
    }

    try {
        for (const auto& r: ramps_list_) {
            has_reachable_storehouse(&r, color);
        }
    }
    catch (std::logic_error& ex) {
        return false;
    }

    return true;
}

void Factory::do_deliveries(Time t) {
    for (auto& r : ramps_list_) {
        r.deliver_goods(t);
    }
}

void Factory::do_package_passing() {
    for (auto& r : ramps_list_) {
        r.send_package();
    }
    for (auto& w : workers_list_) {
        w.send_package();
    }
}

void Factory::do_work(Time t) {
    for (auto& w : workers_list_) {
        w.do_work(t);
    }
}
