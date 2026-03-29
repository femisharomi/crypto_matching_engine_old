// Crypto Matching Engine
// File: OrderIDGenerator.cpp
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

#include "OrderIDGenerator.hpp"

// Initialises the member variables
OrderIDGenerator::OrderIDGenerator() : m_nextId(1){}

// Generates a new id per call, using atmoic ensures thread safety
uint64_t OrderIDGenerator::generateId() 
{
    return m_nextId++;
}


