#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
    map<string, long long> costs;
    map<string, set<string>> users;
    string command;

    while (cin >> command) {
        if (command == "FINISH") {
            break;
        }

        if (command == "CREATE") {
            string eventName;
            long long cost;
            cin >> eventName >> cost;

            if (costs.count(eventName)) {
                cout << "UNSUCCESSFUL CREATE\n";
            } else {
                costs[eventName] = cost;
                cout << "SUCCESSFUL\n";
            }
        } else if (command == "DELETE") {
            string eventName;
            cin >> eventName;

            if (!costs.count(eventName)) {
                cout << "INVALID EVENTNAME\n";
            } else {
                costs.erase(eventName);
                users.erase(eventName);
                cout << "SUCCESSFUL\n";
            }
        } else if (command == "ADD") {
            string userName, eventName;
            cin >> userName >> eventName;

            if (!costs.count(eventName)) {
                cout << "INVALID EVENTNAME\n";
            } else if (users[eventName].count(userName)) {
                cout << "USER ALREADY ADDED TO EVENT\n";
            } else {
                users[eventName].insert(userName);
                cout << "SUCCESSFUL\n";
            }
        } else if (command == "REMOVE") {
            string userName, eventName;
            cin >> userName >> eventName;

            if (!costs.count(eventName)) {
                cout << "INVALID EVENTNAME\n";
            } else if (!users[eventName].count(userName)) {
                cout << "USER NOT FOUND IN EVENT\n";
            } else {
                users[eventName].erase(userName);
                cout << "SUCCESSFUL\n";
            }
        } else if (command == "COST") {
            string eventName;
            cin >> eventName;

            if (!costs.count(eventName)) {
                cout << "INVALID EVENTNAME\n";
            } else {
                cout << costs[eventName] * users[eventName].size() << '\n';
            }
        }
    }

    return 0;
}
