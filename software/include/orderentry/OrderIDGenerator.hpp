// Crypto Matching Engine
// File: OrderIDGenerator.hpp
//
// What:
// Generates unique order IDs
//
// Notes:
// - Atomic counter
// - Can extend with timestamp later
//
// Author: Femi
// Created: 2026-03-21

#ifndef ORDERIDGENERATOR_HPP
#define ORDERIDGENERATOR_HPP

class OrderIDGenerator {
public:
    OrderIDGenerator(); 
    uint64_t generateId();

private:
    std::atomic<uint64_t> m_nextId;
};
#endif // ORDERIDGENERATOR_HPP