#ifndef TIMER_HPP_
#define TIMER_HPP_

#include <iostream>
#include <chrono>

class Timer
{
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1>>;

    std::chrono::time_point<clock_t> start_time = clock_t::now();

public:
    void elapsed()
    {
        std::chrono::time_point<clock_t> end_time = clock_t::now();
        std::cout << std::chrono::duration_cast<second_t>(end_time - start_time).count() << std::endl;
    }
};

#endif