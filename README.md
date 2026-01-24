# Crypto Matching Engine

A modern, high-performance cryptocurrency order matching engine written in **C++20** with strong emphasis on concurrency, low-latency design, and testability.

I built this project to deeply understand how real crypto exchanges process millions of orders per second with strict FIFO priority, thread-safety, and multi-instrument/venue support.

### Features (as of Jan 2026)

- Order types: Limit, Market, IOC, FOK  
- Strict **FIFO** matching at each price level  
- Multi-instrument support (separate OrderBook per symbol)  
- Multi-venue routing (planned — venue-specific books & rules)  
- Full lifecycle: parsing → validation → routing → matching → trade publication  
- Thread-safe design (std::mutex, std::shared_mutex, std::atomic)  
- Mock market-data feed simulator for stress testing  
- Comprehensive GoogleTest suite (unit + integration + concurrency)  
- Modern CMake 3.30.2 build system with FetchContent for dependencies  

### Tech Stack

- **Language**: C++20 (with selected C++23 features where supported)  
- **IDE**: Eclipse CDT (latest stable)  
- **Build system**: CMake 3.30.2  
- **Testing**: GoogleTest (latest release via FetchContent)  
- **JSON parsing**: nlohmann/json (latest single-header via FetchContent)  
- **Concurrency primitives**: std::mutex, std::shared_mutex, std::atomic, std::jthread (C++20)  
- **Diagrams**: draw.io (diagrams.net)  

[//]: # (System Image)
![Crypto Matching Engine - System Architecture](docs/diagrams/system-block-diagram.png)  
*High-level block diagram — drawn in draw.io*

### Project Layout
                       
```
crypto_matching_engine/
├── CMakeLists.txt
├── README.md
├── .gitignore                          # (git-ignored) 
├── software/
│   ├── include/                        # All public header files (.hpp) – this is the main public API
│   │   ├── core/                       # Core domain models & enums (used project-wide)
│   │   ├── orderentry/                 # Order entry & processing components
│   │   ├── matchingengine/             # Core matching logic & order book structures
│   │   ├── cancelreplace/              # Cancel and replace request handling
│   │   ├── trading/                    # Trade events, publishing, and market data aggregation
│   │   ├── feedhandler/                # External market feed connection & parsing
│   │   └── config/                     # Instrument & venue configuration
│   ├── src/                            # All implementation files (.cpp)
│   │   ├── core/
│   │   ├── orderentry/
│   │   ├── matchingengine/
│   │   ├── cancelreplace/
│   │   ├── trading/
│   │   ├── feedhandler/
│   │   └── config/
│   └── tests/                          # All unit & integration tests (GoogleTest)
├── build/                              # Build artifacts – Eclipse or CMake output
└── docs/                               # Documentation, notes, architecture decisions
    └── diagrams/                       # UML diagrams, system block diagrams (.drawio + .png exports)
```

### Build Instructions

#### Prerequisites

- CMake ≥ 3.30.2  
- C++20 capable compiler (GCC 12+, Clang 15+, MSVC 2022+)  
- Eclipse CDT (latest stable recommended)  
- Git

#### Build from command line

```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --parallel $(nproc)
```

#### Build & run in Eclipse

1. Generate Eclipse project files:
   ```bash
   cd build
   cmake -G "Eclipse CDT4 - Unix Makefiles" ..
   ```
2. In Eclipse: File → Import → Existing Projects into Workspace → select project root  
3. Build → Run as → Local C/C++ Application

#### Run unit tests

```bash
cd build
ctest -V
```

or in Eclipse: Run → Run Configurations → C/C++ Unit → Google Test Runner

### Current Status (Jan 2026)

- Core matching (FIFO, partial fills) fully implemented & tested  
- Order parsing/validation/routing/cancel/replace working  
- Trade publishing & basic NBBO aggregation complete  
- Feed handler + mock simulator ready  
- Multi-instrument support solid  
- Multi-venue routing partially done (next focus)  
- Concurrency stress-tested (multi-thread order entry/cancel)  
- Latency measurements started (nanosecond timers)

### Roadmap (next steps)

1. Full IOC / FOK semantics  
2. Configurable venue routing rules  
3. Async logging (spdlog)  
4. Real Binance testnet WebSocket feed integration  
5. Pro-Rata matching variant  
6. Prometheus metrics / simple dashboard  
7. GitHub Actions CI/CD pipeline  
8. Docker container for easy demo

### Why I Built This

I wanted real hands-on experience with:
- Low-latency C++ patterns  
- Fine-grained locking vs lock-free approaches  
- Domain-driven design in trading systems  
- Testing highly concurrent code  
- Going from UML → skeletons → real implementation → stress testing

This project has been an incredible learning journey into what actually makes crypto exchanges tick.

### License

MIT License — feel free to fork, use, or learn from it.

Feedback, questions, or collaboration welcome, just get in touch!

— Femi, London (January 2026)
