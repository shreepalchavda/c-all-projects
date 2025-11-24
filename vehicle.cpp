#include <iostream>
using namespace std;

class Vehicle
{
protected:
    int vehicleID;
    string manufacturer;
    string model;
    int year;
    string fuel;

public:
    Vehicle(int id = 0, string m = "NA", string mo = "NA", int y = 0)
    {
        vehicleID = id;
        manufacturer = m;
        model = mo;
        year = y;
    }

    int getId() { return vehicleID; }

    void display()
    {
        cout << endl<< "\tID : " << vehicleID<< "\t | manufacturer : " << manufacturer<< "\t | model : " << model<< "\t | Year : " << year;

    }
};

class Car : public Vehicle
{
    string fuelType;

public:
    Car(int id, string m, string mo, int y, string fuel)
        : Vehicle(id, m, mo, y), fuelType(fuel) {}

    void display()
    {
        Vehicle::display();
        cout << " | Fuel: " << fuelType;
    }
};

class ElectricCar : public Car
{
    int battery;

public:
    ElectricCar(int id, string m, string mo, int y, string fuel, int b)
        : Car(id, m, mo, y, fuel), battery(b) {}

    void display()
    {
        Car::display();
        cout << " | Battery: " << battery << " kWh";
    }
};

class VehicleRegistry
{
    Vehicle *list[20];
    int count = 0;

public:
    void add(Vehicle *v)
    {
        if (count < 20)
        {
            list[count] = v;
            count++;
        }
        else
        {
            cout << "full!" << endl;
        }
    }

    void showAll()
    {
        if (count == 0)
        {
            cout << "----";
            cout <<endl<< "No vehicles in list." << endl;
            return;
        }
        for (int i = 0; i < count; i++)
        {
            list[i]->display();
            cout << endl;
        }
    }
};

int main()
{
    VehicleRegistry reg;
    int choice;

    do
    {
        cout << endl
             << "\t\t ~Vehicle Registry System ~" << endl;
        cout << "1.Add Car" << endl;
        cout << "2.Add Ev. Car" << endl;
        cout << "3.display All Vehicles" << endl;
        cout << "4.Exit" << endl;
        cout << endl
             << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int id, year;
            string manu, model, fuel;
            cout << endl<< "Enter ID : ";
            cin >> id;
            cout << "Enter Manufacturer : ";
            cin >> manu;
            cout << "Enter Model : ";
            cin >> model;
            cout << "Enter Year : ";
            cin >> year;
            cout << "Enter Fuel : ";
            cin >> fuel;
            cout << endl<< "\t\t Added Sucsessfully..." << endl;
            reg.add(new Car(id, manu, model, year, fuel));
        }
        else if (choice == 2)
        {
            int id, year, battery;
            string manu, model, fuel;
            cout << endl<< "Enter ID : ";
            cin >> id;
            cout << "Enter Manufacturer : ";
            cin >> manu;
            cout << "Enter Model : ";
            cin >> model;
            cout << "Enter Year : ";
            cin >> year;
            cout << "Enter Fuel : ";
            cin >> fuel;
            cout << "Enter Battery Capacity : ";
            cin >> battery;
            cout << endl<< "\t\t Added...." << endl;
            reg.add(new ElectricCar(id, manu, model, year, fuel, battery));
        }
        else if (choice == 3)
        {
            reg.showAll();
        }
        else if (choice == 4)
        {
            cout << endl<< "Exiting..." << endl;
            break;
        }

        else
        {
            cout << "Invalid Choise :)" << endl;
        }

    } while (1);

    return 0;
}