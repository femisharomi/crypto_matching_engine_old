// Crypto Matching Engine
// File: OrderQueue.cpp
//
// What:
// Implements OrderQueue operations
//
// Notes:
// - Push / pop / front / size
// - Mutex-protected access
//
// Author: Femi
// Created: 2026-03-31

#include "matchingengine/OrderQueue.hpp"

OrderQueue::OrderQueue() {}

void OrderQueue::push(std::shared_ptr<Order> order)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    m_queue.push_back(order);
}

std::shared_ptr<Order> OrderQueue::pop()
{
    std::lock_guard<std::mutex> lock(m_mutex);

    if (m_queue.empty()) return nullptr;

    std::shared_ptr<Order> front = m_queue.front(); // store front
    m_queue.pop_front();                            // remove it

    return front;                                   // return stored
}

std::shared_ptr<Order> OrderQueue::front() const
{
    std::lock_guard<std::mutex> lock(m_mutex);

    return (m_queue.empty()) ? nullptr : m_queue.front();
}

size_t OrderQueue::size() const
{
    std::lock_guard<std::mutex> lock(m_mutex);
    
    return m_queue.size();
}