// Crypto Matching Engine
// File: OrderRouter.cpp
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

#include "OrderRouter.hpp"

void OrderRouter::routeOrder(Order order)
{
    std::lock_guard<std::mutex> lock(m_routerMutex);

    std::shared_ptr<OrderBook> book = OrderRouter::getBookForSymbol(order.symbol);

    if(book)
    {
        book->addOrder(std::move(order));
    }
}

std::shared_ptr<OrderBook> OrderRouter::getBookForSymbol(const std::string& symbol)
{
    // Real lookup / lazy creation will be added later
    return nullptr;
}

