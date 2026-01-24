# ============================================================================
# CMakeLists.txt - Crypto Matching Engine
# ============================================================================

cmake_minimum_required(VERSION 3.20)
project(crypto_matching_engine LANGUAGES CXX)

# ============================================================================
# Global settings
# ============================================================================

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ============================================================================
# Dependencies (FetchContent)
# ============================================================================

include(FetchContent)

# GoogleTest
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# nlohmann/json
FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.12.0
)
FetchContent_MakeAvailable(json)

# ============================================================================
# Main executable
# ============================================================================

add_executable(crypto_matching_engine)

target_include_directories(crypto_matching_engine
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(crypto_matching_engine
    PRIVATE nlohmann_json::nlohmann_json
)

# ============================================================================
# Source files – uncomment as you create them
# ============================================================================

# Core domain
# target_sources(crypto_matching_engine PRIVATE src/core/SomeCoreFile.cpp)

# Order entry module
# target_sources(crypto_matching_engine PRIVATE src/orderentry/OrderParser.cpp)
# target_sources(crypto_matching_engine PRIVATE src/orderentry/OrderValidator.cpp)
# target_sources(crypto_matching_engine PRIVATE src/orderentry/OrderFactory.cpp)
# target_sources(crypto_matching_engine PRIVATE src/orderentry/OrderIDGenerator.cpp)
# target_sources(crypto_matching_engine PRIVATE src/orderentry/OrderRouter.cpp)

# Matching engine module
# target_sources(crypto_matching_engine PRIVATE src/matchingengine/PriceLevel.cpp)
# target_sources(crypto_matching_engine PRIVATE src/matchingengine/OrderQueue.cpp)
# target_sources(crypto_matching_engine PRIVATE src/matchingengine/OrderBook.cpp)
# target_sources(crypto_matching_engine PRIVATE src/matchingengine/MatchEngine.cpp)

# Cancel / Replace module
# target_sources(crypto_matching_engine PRIVATE src/cancelreplace/CancelProcessor.cpp)
# target_sources(crypto_matching_engine PRIVATE src/cancelreplace/ReplaceProcessor.cpp)

# Trading / reporting module
# target_sources(crypto_matching_engine PRIVATE src/trading/TradePublisher.cpp)
# target_sources(crypto_matching_engine PRIVATE src/trading/MarketDataAggregator.cpp)

# Feed handler module
# target_sources(crypto_matching_engine PRIVATE src/feedhandler/FeedConnector.cpp)
# target_sources(crypto_matching_engine PRIVATE src/feedhandler/MessageParser.cpp)
# target_sources(crypto_matching_engine PRIVATE src/feedhandler/FeedDispatcher.cpp)

# Configuration module
# target_sources(crypto_matching_engine PRIVATE src/config/InstrumentRegistry.cpp)

# Main entry point
target_sources(crypto_matching_engine PRIVATE src/main.cpp)

# ============================================================================
# GoogleTest executable
# ============================================================================

enable_testing()

add_executable(crypto_matching_engine_regression_tests
    tests/example_test.cpp
)

target_include_directories(crypto_matching_engine_regression_tests
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(crypto_matching_engine_regression_tests
    PRIVATE GTest::gtest_main
            nlohmann_json::nlohmann_json
)

# Additional test files
# target_sources(crypto_matching_engine_regression_tests PRIVATE tests/test_orderparser.cpp)
# target_sources(crypto_matching_engine_regression_tests PRIVATE tests/test_ordervalidator.cpp)
# target_sources(crypto_matching_engine_regression_tests PRIVATE tests/test_orderfactory.cpp)
# target_sources(crypto_matching_engine_regression_tests PRIVATE tests/test_orderidgenerator.cpp)
# target_sources(crypto_matching_engine_regression_tests PRIVATE tests/test_orderrouter.cpp)
# target_sources(crypto_matching_engine_regression_tests PRIVATE tests/test_pricelevel.cpp)
# target_sources(crypto_matching_engine_regression_tests PRIVATE tests/test_orderqueue.cpp)
# target_sources(crypto_matching_engine_regression_tests PRIVATE tests/test_orderbook.cpp)
# target_sources(crypto_matching_engine_regression_tests PRIVATE tests/test_matchengine.cpp)
# target_sources(crypto_matching_engine_regression_tests PRIVATE tests/test_cancelprocessor.cpp)
# target_sources(crypto_matching_engine_regression_tests PRIVATE tests/test_replaceprocessor.cpp)
# target_sources(crypto_matching_engine_regression_tests PRIVATE tests/test_tradepublisher.cpp)
# target_sources(crypto_matching_engine_regression_tests PRIVATE tests/test_feedconnector.cpp)
# target_sources(crypto_matching_engine_regression_tests PRIVATE tests/test_messageparser.cpp)
# target_sources(crypto_matching_engine_regression_tests PRIVATE tests/test_feeddispatcher.cpp)
# target_sources(crypto_matching_engine_regression_tests PRIVATE tests/test_instrumentregistry.cpp)

# Register tests
add_test(NAME AllTests COMMAND crypto_matching_engine_regression_tests)

# ============================================================================
# Compiler warnings
# ============================================================================

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(crypto_matching_engine PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(crypto_matching_engine_regression_tests PRIVATE -Wall -Wextra -Wpedantic)
endif()
