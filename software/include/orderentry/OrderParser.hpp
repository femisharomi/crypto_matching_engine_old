// Crypto Matching Engine
// File: OrderParser.hpp
//
// What:
// Parses raw input (e.g. JSON) into Order objects
//
// Notes:
// - Input boundary of system
// - Validation handled separately
//
// Author: Femi
// Created: 2026-03-21

#ifndef ORDERPARSER_HPP
#define ORDERPARSER_HPP

#include "Order.hpp"
#include "InstrumentRegistry.hpp"
#include <json.hpp>

// Class responsible for parsing raw messages into Order objects
class OrderParser {
    public: 
        // Constructor
        OrderParser(std::shared_ptr<InstrumentRegistry> registry) : m_registry(std::move(registry)) {}
        
        // Function to parse in raw messages into orders
        Order parseRawMessage(const std::string& rawMessage) const;

    private: 
        // Member variable
        std::shared_ptr<InstrumentRegistry> m_registry;

        // Function to parse in Json messagges into orders
        Order parseJson(const nlohmann::json& jsonData) const;
};

#endif // ORDERPARSER_HPP