#include "runtime_clock.hpp"

float run_with_timer(float method()){
    auto start_time = high_resolution_clock::now();
    method();
    auto end_time = high_resolution_clock::now();
    auto run_time_ms = duration_cast<microseconds>(end_time - start_time);
    return (float)run_time_ms.count() / 1000000;
}
