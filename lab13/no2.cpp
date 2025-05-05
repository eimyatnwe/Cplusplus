#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <limits>

using namespace std;

// Base class
class CarbonFootprint {
public:
    virtual double getCarbonFootprint() const = 0;
    virtual void displayInfo() const = 0;
    virtual ~CarbonFootprint() {}
};

// Factory class
class Building : public CarbonFootprint {
private:
    double energyConsumption;
    double numberOfOccupants;
public:
    Building(double energy, double occupants)
        : energyConsumption(energy), numberOfOccupants(occupants) {}

    double getCarbonFootprint() const override {
        // Calculate emissions for the entire building
        double emissions = energyConsumption / numberOfOccupants / 1000.0; // Conversion from kWh to tons of CO2
        return emissions;
    }

    void displayInfo() const override {
        cout << "Building Carbon Footprint: " << getCarbonFootprint() << " tons of CO2 per occupant\n";
    }
};

// Car class
class Car : public CarbonFootprint {
private:
    double fuelConsumption;
    double fuelEfficiency;
public:
    Car(double consumption, double efficiency)
        : fuelConsumption(consumption), fuelEfficiency(efficiency) {}

    double getCarbonFootprint() const override {
        // Calculate emissions based on fuel consumption and efficiency
        double emissions = fuelConsumption / fuelEfficiency * 2.3; // Conversion factor from liters to tons of CO2
        return emissions;
    }

    void displayInfo() const override {
        cout << "Car Carbon Footprint: " << getCarbonFootprint() << " tons of CO2\n";
    }
};

// Electric Car class
class ElectricCar : public CarbonFootprint {
private:
    double energyConsumption;
    double chargeEfficiency;
public:
    ElectricCar(double energy, double efficiency)
        : energyConsumption(energy), chargeEfficiency(efficiency) {}

    double getCarbonFootprint() const override {
        // Calculate emissions based on energy consumption and charge efficiency
        double emissions = energyConsumption * (1.0 - chargeEfficiency) * 0.000139; // Conversion factor from kWh to tons of CO2
        return emissions;
    }

    void displayInfo() const override {
        cout << "Electric Car Carbon Footprint: " << getCarbonFootprint() << " tons of CO2\n";
    }
};

// Utility function to get user input for a double value
double getUserInput(const string& prompt) {
    double input;
    cout << prompt;
    while (!(cin >> input) || input <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a positive number: ";
    }
    return input;
}

int main() {
    double buildingEnergy, buildingOccupants;
    double carFuelConsumption, carFuelEfficiency;
    double electricCarEnergy, electricCarChargeEfficiency;

    
    cout << "Enter building's energy consumption (kWh) and number of occupants: ";
    buildingEnergy = getUserInput("");
    buildingOccupants = getUserInput("");
    
    cout << "Enter car's fuel consumption (liters) and fuel efficiency (km/liter): ";
    carFuelConsumption = getUserInput("");
    carFuelEfficiency = getUserInput("");
    
    cout << "Enter electric car's energy consumption (kWh) and charge efficiency (ratio): ";
    electricCarEnergy = getUserInput("");
    electricCarChargeEfficiency = getUserInput("");

    
    Building building(buildingEnergy, buildingOccupants);
    Car car(carFuelConsumption, carFuelEfficiency);
    ElectricCar electricCar(electricCarEnergy, electricCarChargeEfficiency);

   
    building.displayInfo();
    car.displayInfo();
    electricCar.displayInfo();

    return 0;
}