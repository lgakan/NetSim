#ifndef NETSIM_NODES_HPP
#define NETSIM_NODES_HPP

#include <memory>
#include <map>
#include <iterator>
#include <optional>
#include "storage_types.hpp"
#include "helpers.hpp"
#include "config.hpp"

enum class ReceiverType{
    WORKER = 0,
    STOREHOUSE = 1
};


class IPackageReceiver{
public:
    virtual void receive_package(Package&& p) = 0;
    virtual ElementID get_id() const = 0;
    virtual ~IPackageReceiver() {};

    #if (EXERCISE_ID > EXERCISE_ID_NODES)
    virtual ReceiverType get_receiver_type() const = 0;
    #endif

//    virtual ReceiverType get_receiver_type() const = 0;
};


class Storehouse : public IPackageReceiver{
public:
    Storehouse(ElementID id, std::unique_ptr<IPackageStockpile> d =
            std::make_unique<PackageQueue>(PackageQueueType::LIFO)) :
            id_(id), ptr_(std::move(d)) {};

    Storehouse(Storehouse&&) = default;

    void receive_package(Package&& p) override;
    ElementID get_id() const override {return id_;}
    ~Storehouse() {};

    #if (EXERCISE_ID > EXERCISE_ID_NODES)
    ReceiverType get_receiver_type() const override{return ReceiverType::STOREHOUSE;}
    #endif

//    ReceiverType get_receiver_type() const {return ReceiverType::STOREHOUSE;}
private:
    ElementID id_;
    std::unique_ptr<IPackageStockpile> ptr_;
};


class ReceiverPreferences {
    using preferences_t = std::map<IPackageReceiver*, double>;
    using const_iterator = preferences_t::const_iterator;
public:
    ReceiverPreferences(ProbabilityGenerator pg = probability_generator): pg_(pg) {};

    void add_receiver(IPackageReceiver* r);

    void remove_receiver(IPackageReceiver* r);

    IPackageReceiver* choose_receiver();

    const preferences_t& get_preferences() const {return preferences_;}

    const_iterator begin() const {return preferences_.begin();}
    const_iterator cbegin() const {return preferences_.cbegin();}
    const_iterator end() const {return preferences_.end();}
    const_iterator cend() const {return preferences_.cend();}
private:
    preferences_t preferences_;
    ProbabilityGenerator pg_;
};


class PackageSender {
public:
    PackageSender() = default;
    ReceiverPreferences receiver_preferences_;

    PackageSender(PackageSender&&) = default;

    void send_package();

    std::optional<Package>& get_sending_buffer() {return buffer_;}
protected:
    void push_package(Package&& p) {buffer_.emplace(p);}
private:
    std::optional<Package> buffer_ = std::nullopt;
};

class Ramp : public PackageSender{
public:
    Ramp(ElementID id, TimeOffset di): id_(id), time_offset_(di){};

    void deliver_goods(Time t);

    TimeOffset get_delivery_interval() const {return time_offset_;};

    ElementID get_id() const  {return id_;}
private:
    ElementID id_;
    TimeOffset time_offset_;
};

class Worker : public PackageSender, public IPackageReceiver{
public:
    Worker(ElementID id, TimeOffset pd, std::unique_ptr<IPackageQueue> q) : id_(id), time_offset_(pd), ptr_(std::move(q)) {};

    Worker(Worker&&) = default;

    void do_work(Time t);

    TimeOffset get_processing_duration() const {return time_offset_;};

    Time get_package_processing_start_time() const {return starting_time_;}

    //IPackageReceiver
    void receive_package(Package&& p) override;
    ElementID get_id() const override {return id_;}
    ~Worker() {};


    #if (EXERCISE_ID > EXERCISE_ID_NODES)
    ReceiverType get_receiver_type() const override {return ReceiverType::WORKER;}
    #endif

//    ReceiverType get_receiver_type() const {return ReceiverType::WORKER;}
private:
    Time starting_time_ = 0;
    ElementID id_;
    TimeOffset time_offset_;
    std::unique_ptr<IPackageQueue> ptr_;
    std::optional<Package> processing_buffer_ = std::nullopt;
};
#endif //NETSIM_NODES_HPP
