// Crypto Matching Engine
// File: OrderRouter.hpp
//
// What:
// Routes orders to correct order book (by symbol)
//
// Notes:
// - Thread-safe entry point
// - Manages book lookup/creation
// - Performance critical (avoid unnecessary allocations)
//
// Author: Femi
// Created: 2026-03-21

#ifndef ORDERROUTER_HPP
#define ORDERROUTER_HPP

#include "Order.hpp"
#include "matchingengine/OrderBook.hpp"
#include "config/InstrumentRegistry.hpp"

class OrderRouter{
    public:
        OrderRouter(std::shared_ptr<InstrumentRegistry> registry) : m_registry(std::move(registry)) {}
        void routeOrder(Order order);
    
    private: 
        std::unordered_map<std::string, std::shared_ptr<OrderBook>> m_booksBySymbol;
        std::shared_ptr<InstrumentRegistry> m_registry;
        std::mutex m_routerMutex;

        std::shared_ptr<OrderBook> getBookForSymbol(const std::string& symbol);
};

#endif // ORDERROUTER_HPP
