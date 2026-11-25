#pragma once
#include <string>
#include <chrono>

namespace fast_utils {
    inline std::string trim(const std::string& str) {
        size_t first = str.find_first_not_of(" \t\n\r");
        if (first == std::string::npos) return "";
        size_t last = str.find_last_not_of(" \t\n\r");
        return str.substr(first, (last - first + 1));
    }

    class Timer {
        std::chrono::high_resolution_clock::time_point start_time;
    public:
        Timer() : start_time(std::chrono::high_resolution_clock::now()) {}
        double elapsed_ms() const {
            auto end_time = std::chrono::high_resolution_clock::now();
            return std::chrono::duration<double, std::milli>(end_time - start_time).count();
        }
    };
}
