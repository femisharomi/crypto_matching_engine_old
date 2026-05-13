// Crypto Matching Engine
// File: OrderFactory.hpp
//
// What:
// Creates Order objects with unique IDs
//
// Notes:
// - Centralised order creation
// - Uses OrderIDGenerator
//
// Author: Femi
// Created: 2026-03-21

#ifndef ORDERFACTORY_HPP
#define ORDERFACTORY_HPP

#include <string>
#include "Order.hpp"
#include "OrderIDGenerator.hpp"

class OrderFactory {
    public:
        // Constructor that takes a shared OrderIDGenerator to generate unique IDs
        OrderFactory(std::shared_ptr<OrderIDGenerator> idGenerator) : m_idGenerator(std::move(idGenerator)) {}

        // General method to create an Order based on type (LIMIT, MARKET, etc.)
        Order createOrder(OrderType type, const std::string &symbol, Side side, double price, double qty) const;
        
        // Creates a LIMIT order with price and quantity
        Order createLimitOrder(const std::string& symbol, Side side, double price, double qty) const;

        // Creates a MARKET order (no price needed, executes at market)
        Order createMarketOrder(const std::string& symbol, Side side, double qty) const;

private:
        // Shared pointer to ID generator to ensure all orders get unique IDs
        std::shared_ptr<OrderIDGenerator> m_idGenerator;
};

#endif //ORDERFACTORY_HPP