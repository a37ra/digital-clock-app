#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <thread>
#include <map>

#ifdef _WIN32
#define CLEAR system("cls")
#else
#define CLEAR system("clear")
#endif

struct Zone {
    std::string name;
    std::string city;
    int offset;
};

class Clock {
private:
    std::vector<Zone> zones;
    bool running = true;

public:
    Clock() {
        zones.push_back({"UTC", "London", 0});
        zones.push_back({"EST", "New York", -5});
        zones.push_back({"CST", "Chicago", -6});
        zones.push_back({"MST", "Denver", -7});
        zones.push_back({"PST", "Los Angeles", -8});
        zones.push_back({"CET", "Paris", 1});
        zones.push_back({"IST", "India", 5});
        zones.push_back({"JST", "Tokyo", 9});
        zones.push_back({"AEST", "Sydney", 10});
    }

    void start() {
        while (running) {
            CLEAR;
            std::cout << "\n";
            std::cout << "  ╔═══════════════════════════════════════════╗\n";
            std::cout << "  ║      WORLD DIGITAL CLOCK APP v1.0       ║\n";
            std::cout << "  ╚═══════════════════════════════════════════╝\n\n";

            std::time_t t = std::time(nullptr);
            
            for (auto& z : zones) {
                std::time_t zone_time = t + (z.offset * 3600);
                std::tm* tm = std::gmtime(&zone_time);
                
                std::cout << "  " << std::left << std::setw(15) << z.name;
                std::cout << std::left << std::setw(15) << z.city;
                std::cout << "║ ";
                std::cout << std::setfill('0') 
                         << std::setw(2) << tm->tm_hour << ":"
                         << std::setw(2) << tm->tm_min << ":"
                         << std::setw(2) << tm->tm_sec;
                std::cout << " ║\n";
            }

            std::cout << "\n  [Press Ctrl+C to exit]\n\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }

    void stop() {
        running = false;
    }

    void addZone(std::string name, std::string city, int offset) {
        Zone z;
        z.name = name;
        z.city = city;
        z.offset = offset;
        zones.push_back(z);
    }
};

int main() {
    Clock clock;
    clock.start();
    return 0;
}