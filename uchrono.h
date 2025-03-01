#pragma once
#ifndef UCHRONO_LIB
#define UCHRONO_LIB

#define UCHRONO_LIB_VERSION_MAJOR 1
#define UCHRONO_LIB_VERSION_MINOR 0
#define UCHRONO_LIB_VERSION_PATCH 0

#include "../DumpHDB/lib/types.h"
#include <stdio.h>
#include <time.h>

// Starts counting time.
void start_chrono();

// Gets time elapsed since last start_chrono call.
u64 get_chrono();

// Gets time elapsed and prints its value.
void print_chrono();

// Gets time elapsed, returns it and prints its value.
u64 store_print_chrono();

// Gets time elapsed and executes a start_chrono call.
u64 get_reset_chrono();

// Gets time elapsed, prints its value and executes a start_chrono call.
void print_reset_chrono();

// Gets time elapsed, returns it, prints its value and executes a start_chrono call.
u64 store_print_reset_chrono();

// Converts t in s, ms, us, ns and prints it
void print_time_result(u64 t);

// Sleeps for a specified amount of microseconds
void sleep_us(u64 us);

// Sleeps for a specified amount of milliseconds
void sleep_ms(u64 ms);

// Sleeps for a specified amount of seconds
void sleep(u64 s);

#endif
