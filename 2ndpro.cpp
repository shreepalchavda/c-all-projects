#include <iostream>
#include <cstring>
using namespace std;

class Train {
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];
    static int trainCount;

public:
    // Default Constructor
    Train() {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");
        trainCount++;
    }

    // Parameterized Constructor
    Train(int num, const char* name, const char* src, const char* dest, const char* time) {
        trainNumber = num;
        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);
        trainCount++;
    }

    // Getter methods
    int getTrainNumber() {
        return trainNumber;
    }

    const char* getTrainName() {
        return trainName;
    }

    const char* getSource() {
        return source;
    }

    const char* getDestination() {
        return destination;
    }

    const char* getTrainTime() {
        return trainTime;
    }

    // Input train details from user
    void inputTrainDetails() {
        cout << "\nEnter Train Details:\n";
        cout << "Train Number: ";
        cin >> trainNumber;
        cin.ignore(); // 
        
        cout << "Train Name: ";
        cin.getline(trainName, 50);
        
        cout << "Source: ";
        cin.getline(source, 50);
        
        cout << "Destination: ";
        cin.getline(destination, 50);
        
        cout << "Train Time (HH:MM): ";
        cin.getline(trainTime, 10);
        
        cout << "Train details added successfully!\n";
    }

    void displayTrainDetails() {
        cout << "\n--- fill Train Detail ---\n";
        cout << "Train Number: " << trainNumber << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Train Time: " << trainTime << endl;
        cout << "----------------------\n";
    }

    static int getTrainCount() {
        return trainCount;
    }
};

int Train::trainCount = 0;

int main() {
    cout << "=== Train management ===\n";
    
    Train train1;
    train1.inputTrainDetails();
    
    Train train2(12345, "Rajdhani Express", "Delhi", "Mumbai", "16:30");
    
    cout << "\n=== all train in display===\n";
    train1.displayTrainDetails();
    train2.displayTrainDetails();
    
    cout << "Total number of trains: " << Train::getTrainCount() << endl;
    cout << "Train 1 Name: " << train1.getTrainName() << endl;
    cout << "Train 2 Number: " << train2.getTrainNumber() << endl;
    
    return 0;
}