/* Marathon Calculator
 * Author: Camille Crumpton
 * Standard input: marathon finish time
 * Standard output: average mile pace
 * TODO: metric (km)
 * */

#include <iostream>
#include <cmath>
#include <math.h>
#include <cstdio>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

#define marathon_length 26.2188

string to_string_with_precision(double value, const int n = 2) {
    ostringstream out;
    out << setprecision(n) << value;

    return out.str();
}

int convert_to_seconds(int h, int m, int s) {
    int rv;

    rv = (h * 60 * 60) + (m * 60) + s;

    return rv;
}

double all_secs_to_secs_per_mile(int s) {
    double rv;

    rv = s / marathon_length;

    return rv;
}

string secs_to_pace_string(double s) {
    int minutes;
    double seconds;
    bool pad = false;
    string pace, stringSeconds;

    minutes = (int) floor(s / 60);
    seconds = fmod(s, 60);

    if (seconds < 10)
        pad = true;
    stringSeconds = to_string_with_precision(seconds);

    if (pad) pace = to_string(minutes) + ':' + '0' + stringSeconds;
    else pace = to_string(minutes) + ':' + stringSeconds;

    return pace;
}

string finish_time_to_avg_pace(int h, int m, int s) {
    int time_in_secs;
    double secs_per_mile;
    string avg_pace;

    time_in_secs = convert_to_seconds(h, m, s);
    secs_per_mile = all_secs_to_secs_per_mile(time_in_secs);
    avg_pace = secs_to_pace_string(secs_per_mile);

    return avg_pace;
}

int main() {
    string finish_time, pace;
    int hrs, mins, secs;

    printf("Enter a marathon finish time (hh:mm:ss): ");
    cin >> finish_time;
    sscanf(finish_time.c_str(), "%d:%d:%d", &hrs, &mins, &secs);

    pace = finish_time_to_avg_pace(hrs, mins, secs);
    printf("Average mile pace: %s\n", pace.c_str());

    return 0;
}