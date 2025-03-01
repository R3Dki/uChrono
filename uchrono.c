#include "uchrono.h"

// Global Time Reference variable
u64 timestamp;
struct timespec start, end;

// Starts counting time.
void start_chrono() {
    timespec_get(&start, TIME_UTC);
}

// Gets time elapsed since last start_chrono call.
u64 get_chrono() {
    timespec_get(&end, TIME_UTC);
    return (end.tv_sec - start.tv_sec) * 1000000000 + end.tv_nsec - start.tv_nsec;
}

// Gets time elapsed and prints its value.
void print_chrono() {
    timespec_get(&end, TIME_UTC);
    printf("Time Elapsed: %llus %luns\n", end.tv_sec - start.tv_sec, end.tv_nsec - start.tv_nsec);
}

// Gets time elapsed, returns it and prints its value.
u64 store_print_chrono() {
    timespec_get(&end, TIME_UTC);
    printf("Time Elapsed: %llus %luns\n", end.tv_sec - start.tv_sec, end.tv_nsec - start.tv_nsec);
    return (end.tv_sec - start.tv_sec) * 1000000000 + end.tv_nsec - start.tv_nsec;
}

// Gets time elapsed and executes a start_chrono call.
u64 get_reset_chrono() {
    timespec_get(&end, TIME_UTC);
    return (end.tv_sec - start.tv_sec) * 1000000000 + end.tv_nsec - start.tv_nsec;
    start_chrono();
}

// Gets time elapsed, prints its value and executes a start_chrono call.
void print_reset_chrono() {
    timespec_get(&end, TIME_UTC);
    printf("Time Elapsed: %llus %luns\n", end.tv_sec - start.tv_sec, end.tv_nsec - start.tv_nsec);
    start_chrono();
}

// Gets time elapsed, returns it, prints its value and executes a start_chrono call.
u64 store_print_reset_chrono() {
    timespec_get(&end, TIME_UTC);
    printf("Time Elapsed: %llus %luns\n", end.tv_sec - start.tv_sec, end.tv_nsec - start.tv_nsec);
    u64 result = (end.tv_sec - start.tv_sec) * 1000000000 + end.tv_nsec - start.tv_nsec;
    start_chrono();
    return result;
}

void print_time_result(u64 t) {
    printf("Time Elapsed: %llus %llums %lluus %lluns\n", (u64)(t / 1000000000), (u64)(t / 1000000), (u64)(t / 1000), t);
}

void sleep_us (u64 us) {
    struct timespec begin, elapsed;
    timespec_get(&elapsed, TIME_UTC);
    elapsed.tv_nsec += 200;
    timespec_get(&begin, TIME_UTC);
    while(elapsed.tv_nsec - begin.tv_nsec <= (us * 1000))
        timespec_get(&elapsed, TIME_UTC);
    return;
}

void sleep_ms(u64 ms) {
    u64 elapsed = clock();
    while(clock() - elapsed <= ms);
    return;
}

void sleep(u64 s) {
    u64 elapsed = clock();
    while(clock() - elapsed <= s * 1000);
    return;
}