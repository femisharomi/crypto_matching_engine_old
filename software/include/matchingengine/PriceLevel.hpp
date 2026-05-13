// Crypto Matching Engine
// File: PriceLevel.hpp
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
#ifndef PRICELEVEL_HPP
#define PRICELEVEL_HPP

#include <deque>
#include <memory>
#include <mutex>
#include "orderentry/Order.hpp"
#include "orderentry/OrderEnums.hpp"

class PriceLevel {
    public:
        PriceLevel(double price, Side side) : m_price(price), m_side(side), m_totalQty(0.0){}
        void addOrder(std::shared_ptr<Order> order);
        bool removeOrder(uint64_t orderId);
        double getTotalQty() const;
        std::shared_ptr<Order> getFrontOrder() const;

    private:
        double m_price;
        Side m_side;
        std::deque<std::shared_ptr<Order>> m_orders;
        double m_totalQty;
        mutable std::mutex m_mutex;
};

#endif // PRICELEVEL_HPP