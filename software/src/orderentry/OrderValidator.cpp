// Crypto Matching Engine
// File: OrderValidator.cpp
//
// What:
// Validates orders (price, qty, symbol rules)
//
// Notes:
// - Uses InstrumentRegistry for constraints
// - No mutation, read-only checks
//
// Author: Femi
// Created: 2026-03-21

#include <stdexcept>
#include "orderentry/OrderValidator.hpp"

bool OrderValidator::validate(const Order& order) const
{
    // Real symbol, tick and quatity check will be added later
    return true;
}

void OrderValidator::throwIfInvalid(const Order& order) const
{
    if (OrderValidator::validate(order))
    {
        throw std::invalid_argument("Order Invalid!");
    }
}

bool OrderValidator::isPriceAlignedWithTickSize(double price, double tickSize) const
{
    // Floating-point safe tick validation will be added later
    return true;
}

bool OrderValidator::isQuantityValid(double qty, double minQty, double stepSize) const
{
    // Quantity rules will be added later
    return true;
}
        