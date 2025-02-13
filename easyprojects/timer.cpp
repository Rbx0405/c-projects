#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

// Function to create a timer
void start_timer(int duration_seconds)
{
    cout << "Timer started for " << duration_seconds << " seconds...\n";

    for (int i = duration_seconds; i > 0; --i)
    {
        cout << "Time left: " << i << " seconds\r"; // Overwrites the same line
        cout.flush();                               // Force output to be displayed
        this_thread::sleep_for(chrono::seconds(1)); // Wait for 1 second
    }

    cout << "\nTimer complete! Time's up!\n";
}

int main()
{
    char button;
    int timer_duration;

    cout << "Press 's' to start the timer: ";
    cin >> button;

    if (button == 's' || button == 'S')
    {
        cout << "Enter timer duration (in seconds): ";
        cin >> timer_duration;

        // Start the timer
        start_timer(timer_duration);
    }
    else
    {
        cout << "Invalid input. Exiting program.\n";
    }

    return 0;
}