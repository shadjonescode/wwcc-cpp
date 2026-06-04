#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <iomanip>
using namespace std;

enum class EventCategory { CONCERT, CONFERENCE, SPORTS, WORKSHOP };

struct Event {
    string name;
    string date;          // format: "YYYY-MM-DD"
    EventCategory category;
    int attendees;
    double ticketPrice;
};

// Returns the display name for a category
string categoryName(EventCategory cat) {
    switch (cat) {
        // BUG: Concert and workshop returned the wrong category names.
        // FIX: Changed concert to return concert and workshop to return workshop
        case EventCategory::CONCERT:    return "Concert";   
        case EventCategory::CONFERENCE: return "Conference";
        case EventCategory::SPORTS:     return "Sports";
        case EventCategory::WORKSHOP:   return "Workshop";   
        default:                        return "Unknown";
    }
}

// Display a single event
void printEvent(const Event& e) {
    cout << left << setw(30) << e.name
         << setw(12) << e.date
         << setw(12) << categoryName(e.category)
         << "Attendees: " << setw(5) << e.attendees
         << " Price: $" << fixed << setprecision(2) << e.ticketPrice
         << "\n";
}

// Display all events
void displayAll(const vector<Event>& events) {
    cout << "\n=== All Events ===\n";
    cout << left << setw(30) << "Name" << setw(12) << "Date"
         << setw(12) << "Category" << "\n";
    cout << string(70, '-') << "\n";
    for (const auto& e : events) {
        printEvent(e);
    }
}

// Calculate total revenue across all events
// BUG: Revenue calculation only added attendees and ignored ticket price.
// FIX: Multiply attendes by ticket price to calculate revenue for each event.
double totalRevenue(const vector<Event>& events) {
    return accumulate(events.begin(), events.end(), 0.0,
        [](double sum, const Event& e) {
            return sum + (e.attendees * e.ticketPrice);
        });
}

// Calculate average ticket price across all events
double averageTicketPrice(const vector<Event>& events) {
    // BUG: Total was stored as an int, causing ticket price decimals to be lost.
    // FIX: Use a double so deciaml values are preserved
    double total = 0;                      // Bug 2: should be double

    // BUG: Adding ticket prices to an int truncated the fractional portion.
    // FIX: Store the running total in a double.
    for (const auto& e : events) {
        total += e.ticketPrice;         // Bug 2: fractional part truncated
    }

    // BUG: Integer division could produce an incorrect average.
    // FIX: Divide using double arithmetic.
    return total / events.size(); // Bug 2: integer division
}

// Sort events by date, oldest first
void sortByDateAscending(vector<Event>& events) {
    // BUG: Events were sorted newest-to-oldest instead of oldest-to-newest.
    // FIX: Changed comparison from > to < so earlier dates appear first.
    sort(events.begin(), events.end(),
        [](const Event& a, const Event& b) {
            return a.date < b.date;     // Bug 3: > sorts descending, not ascending
        });
}

// Search for events whose name contains the search term (case-sensitive)
// BUG: find_if() only returns the first matching event.
// FIX: Replaced find_if() with a loop so every matching even is displayed
void searchByName(const vector<Event>& events, const string& term) {
    cout << "\n=== Search Results for \"" << term << "\" ===\n";
    bool found = false;

    for (const auto& e : events){
        if (e.name.find(term) != string::npos){
            printEvent(e);
            found = true;
        }
    }

    if (!found){
        cout << "No events found.\n";
    }
}

void sortByAttendees(vector<Event>& events){
    sort(events.begin(), events.end(), 
    [](const Event& a, const Event& b){
        return a.attendees > b.attendees;
    });
}

void filterByCategory(const vector<Event>& events, EventCategory cat){
    vector<Event> filtered;

    copy_if(events.begin(), events.end(),
    back_inserter(filtered),
    [cat](const Event& e){
        return e.category == cat;
    });

    cout << "\n=== " << categoryName(cat) << " Events ===\n";

    for (const auto& e : filtered){
        printEvent(e);
    }
}

void exportUpcomingEvents(const vector<Event>& events, const string& filename) {

    ofstream outFile(filename);

    if (!outFile) {
        cout << "Error: could not open " << filename << endl;
        return;
    }

    for (const auto& e : events) {

        if (e.date >= "2025-06-01") {

            outFile << e.name << " | "
                    << e.date << " | "
                    << categoryName(e.category) << " | "
                    << e.attendees << " | $"
                    << fixed << setprecision(2)
                    << e.ticketPrice << endl;
        }
    }

    outFile.close();

    cout << "Upcoming events saved to " << filename << endl;
}

int main() {
    vector<Event> events = {
        {"Spring Music Fest",     "2025-04-12", EventCategory::CONCERT,    1200, 45.50},
        {"Tech Summit 2025",      "2025-06-20", EventCategory::CONFERENCE,  350, 129.00},
        {"City 5K Run",           "2025-05-03", EventCategory::SPORTS,      800, 25.25},
        {"Watercolor Workshop",   "2025-07-15", EventCategory::WORKSHOP,     40, 60.00},
        {"Jazz Under the Stars",  "2025-08-02", EventCategory::CONCERT,     600, 35.75},
        {"Leadership Workshop",   "2025-06-28", EventCategory::WORKSHOP,     75, 89.00},
        {"Regional Soccer Cup",   "2025-09-14", EventCategory::SPORTS,     2500, 18.00},
        {"Dev Conf Northwest",    "2025-10-05", EventCategory::CONFERENCE,   420, 199.00},
    };

    cout << "=== Community Event Scheduler ===\n";

    displayAll(events);

    cout << "\nTotal revenue (all events): $"
         << fixed << setprecision(2) << totalRevenue(events) << "\n";

    cout << "Average ticket price: $"
         << fixed << setprecision(2) << averageTicketPrice(events) << "\n";

    sortByDateAscending(events);
    cout << "\n=== Events sorted by date (oldest first) ===\n";
    for (const auto& e : events) {
        printEvent(e);
    }

    searchByName(events, "Workshop");

    
    sortByAttendees(events);
    filterByCategory(events, EventCategory::CONCERT);
    exportUpcomingEvents(events, "upcoming_events.txt");

    return 0;
}