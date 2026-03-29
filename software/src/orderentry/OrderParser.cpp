// Crypto Matching Engine
// File: OrderParser.cpp
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

#include "OrderParser.hpp"

Order OrderParser::parseRawMessage(const std::string& rawMessage) const
{
    nlohmann::json j;

    try {
        j = nlohmann::json::parse(rawMessage);

    } catch (const nlohmann::json::exception& e) {

        throw std::runtime_error(std::string("Invalid JSON: ") + e.what());
    }

    return parseJson(j);
}

Order OrderParser::parseJson(const nlohmann::json& jsonData) const
{
    // Real field extraction will be added later
    Order result;

    result.symbol = "PLACEHOLDER"; 

    return result;
}
