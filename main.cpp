#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <thread>
#include <string>
#include <chrono>

struct Zone {
    std::string name;
    std::string city;
    int offset;
};

void moveCursorHome() {
    std::cout << "\033[H";
}

void clearScreen() {
    std::cout << "\033[2J\033[H";
}

class Clock {
private:
    std::vector<Zone> zones;
    bool running = true;

public:
    Clock() {
        zones.push_back({ "UTC",  "London",      0 });
        zones.push_back({ "EST",  "New York",    -5 });
        zones.push_back({ "CST",  "Chicago",     -6 });
        zones.push_back({ "MST",  "Denver",      -7 });
        zones.push_back({ "PST",  "Los Angeles", -8 });
        zones.push_back({ "CET",  "Paris",        1 });
        zones.push_back({ "IST",  "India",        5 });
        zones.push_back({ "JST",  "Tokyo",        9 });
        zones.push_back({ "AEST", "Sydney",       10 });
        zones.push_back({ "ALMT", "Almaty",       5 }); 
    }

    void start() {
        clearScreen();
        bool first = true;

        while (running) {
            if (!first) {
                moveCursorHome();
            }
            first = false;

            std::cout << "\n";
            std::cout << "  +===============================================+\n";
            std::cout << "  |      WORLD DIGITAL CLOCK APP v1.0             |\n";
            std::cout << "  +===============================================+\n\n";
            std::time_t now = std::time(nullptr);

            for (auto& z : zones) {
                std::time_t zone_time = now + (std::time_t)(z.offset * 3600);
                struct tm tm_info = {};
                gmtime_s(&tm_info, &zone_time);

                std::cout << "  " << std::left << std::setw(6) << z.name;
                std::cout << std::left << std::setw(15) << z.city;
                std::cout << "| ";
                std::cout << std::setfill('0')
                    << std::setw(2) << tm_info.tm_hour << ":"
                    << std::setw(2) << tm_info.tm_min << ":"
                    << std::setw(2) << tm_info.tm_sec;
                std::cout << " |\n";
            }

            std::cout << "\n  [Press Ctrl+C to exit]\n\n";
            std::cout.flush(); 

            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }
};
int main() {
    Clock clock;
    clock.start();
    return 0;
}
