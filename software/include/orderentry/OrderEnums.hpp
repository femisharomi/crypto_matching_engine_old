// Crypto Matching Engine
// File: OrderEnums.hpp
//
// What:
// Defines order-related enums (OrderType, Side)
//
// Notes:
// - Used across matching engine (shared types)
// - Keep lightweight (no logic, no dependencies)
//
// Author: Femi
// Created: 2026-03-21

#ifndef ORDER_ENUMS_HPP
#define ORDER_ENUMS_HPP

#include <cstdint>

enum class OrderType : uint8_t
{
    LIMIT,
    MARKET,
    IOC,
    FOK
};

enum class Side : uint8_t
{
    BUY,
    SELL
};

#endif // ORDER_ENUMS_HPP