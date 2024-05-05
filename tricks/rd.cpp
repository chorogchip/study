
#include <iostream>
#include <random>
#include <chrono>
int main() {
    std::random_device rd;  // hardware random value generator
    if (rd.entropy() == 0.0) std::cout << "Not using HW rand\n";

    unsigned seed1 = rd();
    unsigned long seed2 = std::chrono::system_clock::now().time_since_epoch().count();
    
    std::default_random_engine gen1(seed1);
    std::mt19937 gen2{seed2};
    
    std::uniform_int_distribution dist1(10);  // [0, 10) uniform
    std::uniform_real_distribution dist2(0.2, 0.5);  // [0.2, 0.5) uniform
    std::discrete_distribution<int> dist3{4, 1, 5};  // 40% 0, 10% 1, 50% 2

    std::cout << dist1(gen1) << '/' << dist2(gen2) << '/' << dist3(gen1);
}