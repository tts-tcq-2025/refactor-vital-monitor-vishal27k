#include "./monitor.h"
#include <stdio.h>
#include <unistd.h>

// Constants for vital sign thresholds
#define CRITICAL_TEMP_LOW 95.0f
#define CRITICAL_TEMP_HIGH 102.0f
#define PULSE_RATE_LOW 60.0f
#define PULSE_RATE_HIGH 100.0f
#define SPO2_LOW 90.0f

// Function prototypes
static int checkVital(float value, float min, float max, const char *alertMsg, void (*flashWarningFunc)(const char *));
static void flashWarning(const char *message);

// Function to check if a vital is out of range and handle alerting
static int checkVital(float value, float min, float max, const char *alertMsg, void (*flashWarningFunc)(const char *)) {
    if (value < min || value > max) {
        flashWarningFunc(alertMsg);
        return 0;  // Vital out of range
    }
    return 1;  // Vital within range
}

int isSpo2Ok(float spo2, void (*flashWarningFunc)(const char *)) {
    if(spo2 < CRITICAL_SPO2_MIN){
      flashWarningFunc("Oxygen Saturation is out of range!");
}


// Function to handle vitals and check each one
static int handleVitals(float temperature, float pulseRate, float spo2) {
    int tempResult = checkVital(temperature, CRITICAL_TEMP_LOW, CRITICAL_TEMP_HIGH, "Temperature is critical!",flashWarning);
    int pulseResult = checkVital(pulseRate, PULSE_RATE_LOW, PULSE_RATE_HIGH, "Pulse Rate is out of range!",flashWarning);
    int spo2Result = isSpo2Ok(spo2,flashWarning);

    return tempResult || pulseResult || spo2Result;
}

