// Crypto Matching Engine
// File: OrderBook.cpp
//
// What:
// Implements order book logic
//
// Notes:
// - Adds / cancels orders
// - Manages price levels and active orders
//
// Author: Femi
// Created: 2026-03-21

#include "matchingengine/OrderBook.hpp"

void OrderBook::addOrder(std::shared_ptr<Order> order)
{
    std::lock_guard<std::mutex> lock(m_bookMutex);

    m_activeOrders[order->id] = order;

    if(order->side == Side::BUY)
    {
        std::map<double, std::shared_ptr<PriceLevel>, std::greater<double>>::iterator it = m_bids.find(order->price);
        if(it == m_bids.end())
        {
            std::shared_ptr<PriceLevel> newLevel = std::make_shared<PriceLevel>(order->price, Side::BUY);
            m_bids[order->price] = newLevel;
            newLevel->addOrder(order);
        }
        else
        {
            it->second->addOrder(order);
        }
    }
    else
    {
        std::map<double, std::shared_ptr<PriceLevel>>::iterator it = m_asks.find(order->price);

        if (it == m_asks.end())
        {
            std::shared_ptr<PriceLevel> newLevel = std::make_shared<PriceLevel>(order->price, Side::SELL);
            m_asks[order->price] = newLevel;
            newLevel->addOrder(order);
        }
        else
        {
            it->second->addOrder(order);
        }
    }
}

bool OrderBook::cancelOrder(uint64_t orderId)
{
    // Lock the whole order book so no other thread changes it at the same time
    std::lock_guard<std::mutex> lock(m_bookMutex);

    // Look for the order by its ID in the active-orders lookup table
    std::unordered_map<uint64_t, std::shared_ptr<Order>>::iterator orderIt = m_activeOrders.find(orderId);

    // If the order ID does not exist, there is nothing to cancel
    if (orderIt == m_activeOrders.end()) {
        return false;
    }

    // Get the shared_ptr<Order> stored in the map
    // shared_ptr is used so the same Order object can be safely referred to
    // by multiple places without copying the whole order
    std::shared_ptr<Order> order = orderIt->second;

    // Decide which side of the book to search:
    // BUY orders live in m_bids, SELL orders live in m_asks
    if (order->side == Side::BUY) {
        // Find the price level that matches this order's price
        std::map<double, std::shared_ptr<PriceLevel>, std::greater<double>>::iterator levelIt = m_bids.find(order->price);

        // If that price level exists, ask it to remove the order from its queue
        if (levelIt != m_bids.end()) {
            levelIt->second->removeOrder(orderId);

            // Optional cleanup:
            // if the price level becomes empty, you would usually erase it here
        }
    } else {
        // Same idea for the sell side
        std::map<double, std::shared_ptr<PriceLevel>>::iterator levelIt = m_asks.find(order->price);

        if (levelIt != m_asks.end()) {
            levelIt->second->removeOrder(orderId);

            // Optional cleanup:
            // if the price level becomes empty, you would usually erase it here
        }
    }

    // Remove the order from the active order lookup table
    // After this, the book no longer considers it live
    m_activeOrders.erase(orderIt);

    // Cancel succeeded
    return true;
}

