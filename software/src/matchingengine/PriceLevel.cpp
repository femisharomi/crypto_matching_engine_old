// Crypto Matching Engine
// File: PriceLevel.cpp
//
// What:
// Represents one price level in the order book
//
// Notes:
// - Stores orders at the same price
// - Tracks total quantity at this level
//
// Author: Femi
// Created: 2026-03-31

#include "matchingengine/PriceLevel.hpp"

void PriceLevel::addOrder(std::shared_ptr<Order> order)
{   //Stub logic
    std::lock_guard<std::mutex> lock(m_mutex);
    m_orders.push_back(order);
    m_totalQty += order->qty;
}

bool PriceLevel::removeOrder(uint64_t orderId)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    for(std::deque<std::shared_ptr<Order>>::iterator it = m_orders.begin(); it != m_orders.end(); ++it)
    {
        if( (*it)->id == orderId)
        {
            m_totalQty -= (*it)->qty;
            m_orders.erase(it);
            return true;
        }
    }
    return false;
}

double PriceLevel::getTotalQty() const
{
    std::lock_guard<std::mutex> lock(m_mutex);

    return m_totalQty;
}

std::shared_ptr<Order> PriceLevel::getFrontOrder() const
{
    std::lock_guard<std::mutex> lock(m_mutex);

    return (m_orders.empty()) ? nullptr : m_orders.front();
}
