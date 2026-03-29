#include <iostream>
#include <thread>
#include <chrono>

int main() {
    std::cout << "Crypto Matching Engine starting..." << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(5));

    std::cout << "Crypto Matching Engine finishing..." << std::endl;

    return 0;
}