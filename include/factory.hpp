#ifndef NETSIM_FACTORY_HPP
#define NETSIM_FACTORY_HPP

#include "nodes.hpp"


template<class Node>
class NodeCollection{
public:
    using container_t = typename std::list<Node>;
    using iterator = typename container_t::iterator;
    using const_iterator = typename container_t::const_iterator;

    iterator begin() {return nodes_.begin();}
    iterator end() {return nodes_.end();}
    const_iterator begin() const {return nodes_.begin();}
    const_iterator end() const {return nodes_.end();}
    const_iterator cbegin() const {return nodes_.cbegin();}
    const_iterator cend() const {return nodes_.cend();}

    void add(Node&& node) {nodes_.emplace_back(std::move(node));}
    NodeCollection<Node>::iterator find_by_id(ElementID id) {return std::find_if(nodes_.begin(), nodes_.end(), [&id](const auto& i){return id == i.get_id();});}
    NodeCollection<Node>::const_iterator find_by_id(ElementID id) const {return std::find_if(nodes_.begin(), nodes_.end(), [&id](const auto& i){return id == i.get_id();});}
    void remove_by_id(ElementID id) {
        iterator i = find_by_id(id);
        if (i != nodes_.end()) {
            nodes_.erase(i);
        }
    };
private:
    container_t nodes_ {};
};


class Factory{
public:
    void add_ramp(Ramp&& r) {ramps_list_.add(std::move(r));}
    void remove_ramp(ElementID id) {ramps_list_.remove_by_id(id);}
    NodeCollection<Ramp>::iterator find_ramp_by_id(ElementID id) {return ramps_list_.find_by_id(id);}
    NodeCollection<Ramp>::const_iterator find_ramp_by_id(ElementID id) const {return ramps_list_.find_by_id(id);}
    NodeCollection<Ramp>::const_iterator ramp_cbegin() const {return ramps_list_.cbegin();}
    NodeCollection<Ramp>::const_iterator ramp_cend() const {return ramps_list_.cend();}

    void add_worker(Worker&& w) {workers_list_.add(std::move(w));}
    void remove_worker(ElementID id) {remove_receiver(ramps_list_, id);
        remove_receiver(workers_list_, id); workers_list_.remove_by_id(id);}
    NodeCollection<Worker>::iterator find_worker_by_id(ElementID id) {return workers_list_.find_by_id(id);}
    NodeCollection<Worker>::const_iterator find_worker_by_id(ElementID id) const {return workers_list_.find_by_id(id);}
    NodeCollection<Worker>::const_iterator worker_cbegin() const {return workers_list_.cbegin();}
    NodeCollection<Worker>::const_iterator worker_cend() const {return workers_list_.cend();}

    void add_storehouse(Storehouse&& s) {storehouses_list_.add(std::move(s));}
    void remove_storehouse(ElementID id) {remove_receiver(workers_list_, id); storehouses_list_.remove_by_id(id);}
    NodeCollection<Storehouse>::iterator find_storehouse_by_id(ElementID id) {return storehouses_list_.find_by_id(id);}
    NodeCollection<Storehouse>::const_iterator find_storehouse_by_id(ElementID id) const {return storehouses_list_.find_by_id(id);}
    NodeCollection<Storehouse>::const_iterator storehouse_cbegin() const {return storehouses_list_.cbegin();}
    NodeCollection<Storehouse>::const_iterator storehouse_cend() const {return storehouses_list_.cend();}

    bool is_consistent();
    void do_deliveries(Time t);
    void do_package_passing();
    void do_work(Time t);

private:
    template<class Node>
    void remove_receiver(NodeCollection<Node>& collection, ElementID id){
        for (auto& sender : collection) {
            auto map = sender.receiver_preferences_.get_preferences();
            for (auto& receiver : map) {
                if (receiver.first->get_id() == id) {
                    sender.receiver_preferences_.remove_receiver(receiver.first);
                }
            }
        }
    }
    NodeCollection<Ramp> ramps_list_ {};
    NodeCollection<Worker> workers_list_ {};
    NodeCollection<Storehouse> storehouses_list_ {};
};

#endif //NETSIM_FACTORY_HPP
