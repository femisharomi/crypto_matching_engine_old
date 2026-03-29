// Crypto Matching Engine
// File: OrderFactory.cpp
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

#include "orderentry/OrderFactory.hpp"

Order OrderFactory::createOrder(OrderType type, 
                                const std::string& symbol, 
                                Side side, 
                                double price, 
                                double qty) const
{
    // Dispatch logic will be expanded later
    if(type == OrderType::LIMIT)
    {
        return createLimitOrder(symbol, side, price, qty);
    }
    else if(type == OrderType::MARKET)
    {
        return createMarketOrder(symbol, side, qty);
    }
    else
    {
        // STUB FOR UNSUPPORTED TYPES
        return Order{};
    }
}

Order OrderFactory::createLimitOrder(const std::string& symbol, 
                                     Side side, 
                                     double price, 
                                     double qty) const
{
    Order order;

    order.id = m_idGenerator->generateId();
    order.symbol = symbol;
    order.side = side; 
    order.price = price;
    order.qty = qty;
    order.type = OrderType::LIMIT;
    order.timestamp = std::chrono::system_clock::now();

    return order;
}

Order OrderFactory::createMarketOrder(const std::string& symbol, 
                                     Side side, 
                                     double qty) const
{
    Order order; 

    order.id = m_idGenerator->generateId();
    order.symbol = symbol;
    order.side = side; 
    order.qty = qty;
    order.type = OrderType::MARKET;
    order.timestamp = std::chrono::system_clock::now();

    return order;
}
