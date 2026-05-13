// Crypto Matching Engine
// File: OrderQueue.hpp
//
// What:
// Thread-safe queue for Order objects
//
// Notes:
// - Simple FIFO wrapper
// - Uses locking around shared state
//
// Author: Femi
// Created: 2026-03-31
#ifndef ORDERQUEUE_HPP
#define ORDERQUEUE_HPP

#include <deque>
#include <memory>
#include <mutex>
#include <orderentry/Order.hpp>

class OrderQueue
{
    public:
        OrderQueue();
        
        void push(std::shared_ptr<Order> order);
        std::shared_ptr<Order> pop();
        std::shared_ptr<Order> front() const;
        size_t size() const;

    private:
        std::deque<std::shared_ptr<Order>> m_queue;
        mutable std::mutex m_mutex;

};
#endif // ORDERQUEUE_HPP