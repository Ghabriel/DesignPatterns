/* created by Ghabriel Nunes <ghabriel.nunes@gmail.com> [2017] */

#ifndef IMPL_HPP
#define IMPL_HPP

#include <unordered_set>

template<typename T>
class Observable;

// Utilizes the Non-Virtual Interface (NVI) idiom
template<typename T>
class Observer {
 public:
    void notify(const T& data) {
        onNotify(data);
    }

 private:
    virtual void onNotify(const T& data) = 0;
};

template<typename T>
class Observable {
 public:
    void notifyObservers(const T& data) {
        for (auto& observer : observers) {
            observer->notify(data);
        }
    }

    void addObserver(Observer<T>& observer) {
        observers.insert(&observer);
    }

    void removeObserver(Observer<T>& observer) {
        observers.erase(&observer);
    }

 private:
    // raw pointer is ok for non-owning pointers
    std::unordered_set<Observer<T>*> observers;
};

#endif
