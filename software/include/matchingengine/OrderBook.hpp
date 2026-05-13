// Crypto Matching Engine
// File: OrderBook.hpp
//
// What:
// Maintains bids, asks, and active orders for one symbol
//
// Notes:
// - Core book data structure
// - Tracks best bid / ask state
//
// Author: Femi
// Created: 2026-03-21
#ifndef ORDERBOOK_HPP
#define ORDERBOOK_HPP

#include <map>
#include <unordered_map>
#include <memory>
#include <mutex>
#include <string>
#include "matchingengine/PriceLevel.hpp"
#include "orderentry/Order.hpp"

class OrderBook{
    public: 
        OrderBook(std::string& symbol) : m_symbol(symbol){}

        void addOrder(std::shared_ptr<Order> order);
        bool cancelOrder(uint64_t orderId);
        std::pair<double, double> getBestBidAsk() const;

        private:
        std::string m_symbol;
        
        std::map<double, std::shared_ptr<PriceLevel>, std::greater<double>> m_bids;

        std::map<double, std::shared_ptr<PriceLevel>> m_asks;

        std::unordered_map<uint64_t, std::shared_ptr<Order>> m_activeOrders;

        mutable std::mutex m_bookMutex;
};

#endif //ORDERBOOK_HPP