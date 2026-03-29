// Crypto Matching Engine
// File: Order.hpp
//
// What:
// Base order type (shared fields for all orders)
//
// Notes:
// - Inherited by LimitOrder / MarketOrder
// - Performance critical (avoid unnecessary allocations)
//
// Author: Femi
// Created: 2026-03-21

#ifndef ORDER_HPP
#define ORDER_HPP

// Keeping all the includes for Order Entry in this file 
#include "OrderEnums.hpp"
#include <string>
#include <chrono>
#include <memory>
#include <atomic>
#include <cstdint>
#include <stdexcept>
#include <unordered_map>
#include <mutex>

struct Order {
    // Large object files 
    std::string symbol;
    std::chrono::system_clock::time_point timestamp;

    // 8-byte fields
    uint64_t id = 0;
    double qty = 0.0;
    double price = 0.0;

    // 4 bytes or less
    Side side;
    OrderType type;
};
#endif // ORDER_HPP