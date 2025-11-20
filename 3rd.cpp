#include <iostream>
using namespace std;

class Vehicle {
private:
    int vehicleID;
    string manufacturer;
    string model;
    int year;

public:
    static int totalVehicles;

    Vehicle(int id = 0, string mfg = "", string mdl = "", int yr = 0) {
        vehicleID = id;
        manufacturer = mfg;
        model = mdl;
        year = yr;
        totalVehicles++;
        cout << "Vehicle Created\n";
    }

    ~Vehicle() {
        cout << "Vehicle Destroyed\n";
    }

    int getID() { return vehicleID; }
    string getManufacturer() { return manufacturer; }
    string getModel() { return model; }
    int getYear() { return year; }

    void setID(int id) { vehicleID = id; }
    void setManufacturer(string m) { manufacturer = m; }
    void setModel(string m) { model = m; }
    void setYear(int y) { year = y; }
};

int Vehicle::totalVehicles = 0;

class Car : public Vehicle {


private:
    string fuelType;

public:
    Car(int id, string mfg, string mdl, int yr, string fuel)
        : Vehicle(id, mfg, mdl, yr)
    {
        fuelType = fuel;
        cout << "Car Created\n";
    }

    ~Car() {
        cout << "Car Destroyed\n";
    }

    void setFuelType(string fuel) { fuelType = fuel; }
    string getFuelType() { return fuelType; }
};

// electric car

class ElectricCar : public Car {
private:
    int batteryCapacity;

public:
    ElectricCar(int id, string mfg, string mdl, int yr, string fuel, int bc)
        : Car(id, mfg, mdl, yr, fuel)
    {
        batteryCapacity = bc;
        cout << "ElectricCar Created\n";
    }

    ~ElectricCar() {
        cout << "ElectricCar Destroyed\n";
    }

    void setBatteryCapacity(int bc) { batteryCapacity = bc; }
    int getBatteryCapacity() { return batteryCapacity; }
};


class Aircraft {
private:
    int flightRange;

public:
    Aircraft(int range = 0) {
        flightRange = range;
        cout << "Aircraft Created\n";
    }

    ~Aircraft() {
        cout << "Aircraft Destroyed\n";
    }

    void setFlightRange(int r) { flightRange = r; }
    int getFlightRange() { return flightRange; }
};

// flying car 

class FlyingCar : public Car, public Aircraft {
public:
    FlyingCar(int id, string mfg, string mdl, int yr, string fuel, int range)
        : Car(id, mfg, mdl, yr, fuel), Aircraft(range)
    {
        cout << "FlyingCar Created\n";
    }

    ~FlyingCar() {
        cout << "FlyingCar Destroyed\n";
    }
};

// sports car

class SportsCar : public ElectricCar {
private:
    int topSpeed;

public:
    SportsCar(int id, string mfg, string mdl, int yr, string fuel, int bc, int ts)
        : ElectricCar(id, mfg, mdl, yr, fuel, bc)
    {
        topSpeed = ts;
        cout << "SportsCar Created\n";
    }

    ~SportsCar() {
        cout << "SportsCar Destroyed\n";
    }

    void setTopSpeed(int ts) { topSpeed = ts; }
    int getTopSpeed() { return topSpeed; }
};


class Sedan : public Car {
public:
    Sedan(int id, string mfg, string mdl, int yr, string fuel)
        : Car(id, mfg, mdl, yr, fuel)
    {
        cout << "Sedan Created\n";
    }

    ~Sedan() {
        cout << "Sedan Destroyed\n";
    }
};

class SUV : public Car {
public:
    SUV(int id, string mfg, string mdl, int yr, string fuel)
        : Car(id, mfg, mdl, yr, fuel)
    {
        cout << "SUV Created\n";
    }

    ~SUV() {
        cout << "SUV Destroyed\n";
    }
};


int main() {
    Car c(1, "Toyota", "Corolla", 2020, "Petrol");

    ElectricCar ec(2, "Tesla", "Model 3", 2021, "Electric", 75);

    FlyingCar fc(3, "SkyTech", "SkyRider", 2025, "Hybrid", 500);

    SportsCar sc(4, "Tesla", "Roadster", 2024, "Electric", 90, 300);

    Sedan sd(5, "Honda", "City", 2022, "Petrol");

    SUV sv(6, "Mahindra", "XUV700", 2023, "Diesel");

    cout << "\nTotal Vehicles Created = " << Vehicle::totalVehicles << endl;

    return 0;
}
