#include "prof_timer.h"

ProfTimer::ProfTimer() : _start(std::chrono::high_resolution_clock::now()) {}

void ProfTimer::restart() {
    _start = std::chrono::high_resolution_clock::now();
}

void ProfTimer::end() {
    // _hasEnd = true;
    _end = std::chrono::high_resolution_clock::now();
}

long ProfTimer::elapsed() {
    // if (!_hasEnd) 
    end(); 
    return std::chrono::duration_cast<std::chrono::milliseconds>(_end - _start).count();
}
