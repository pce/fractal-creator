#ifndef PROF_TIMER_H
#define PROF_TIMER_H

#include <chrono>

class ProfTimer {
    public:
        ProfTimer();
        void restart();
        void end();
        // add(std::string label)
        long elapsed();
    private:
        // bool _hasEnd = false;
        std::chrono::time_point<std::chrono::high_resolution_clock> _start;
        std::chrono::time_point<std::chrono::high_resolution_clock> _end;
};

#endif