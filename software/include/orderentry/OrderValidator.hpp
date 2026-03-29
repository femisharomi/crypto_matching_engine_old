// Crypto Matching Engine
// File: OrderValidator.hpp
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

#ifndef ORDERVALIDATOR_HPP
#define ORDERVALIDATOR_HPP

#include "InstrumentRegistry.hpp"
#include "Order.hpp"

class OrderValidator {
    public: 
        OrderValidator(std::shared_ptr<InstrumentRegistry> registry) : m_registry(std::move(registry)) {}
        bool validate(const Order& order) const;
        void throwIfInvalid(const Order& order) const;

    private:
        std::shared_ptr<InstrumentRegistry> m_registry;

        bool isPriceAlignedWithTickSize(double price, double tickSize) const;
        bool isQuantityValid(double qty, double minQty, double stepSize) const;
};

#endif // ORDERVALIDATOR_HPP