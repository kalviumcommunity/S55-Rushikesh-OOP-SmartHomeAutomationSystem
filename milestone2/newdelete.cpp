#include <iostream>
using namespace std;

class DeviceControl {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual ~DeviceControl() {}
};

class LightControl : public DeviceControl {
private:
    bool status = false;
    int brightness = 100;

public:
    void turnOn() override {
        this->status = true;
        cout << "Lights turned on. Brightness: " << this->brightness << "%" << endl;
    }

    void turnOff() override {
        this->status = false;
        cout << "Lights turned off." << endl;
    }

    void setBrightness(int level) {
        this->brightness = level;
        cout << "Brightness set to " << this->brightness << "%" << endl;
    }
};

class TemperatureControl : public DeviceControl {
private:
    bool status = false;
    int temperature = 22;

public:
    void turnOn() override {
        this->status = true;
        cout << "Thermostat turned on. Temperature: " << this->temperature << "°C" << endl;
    }

    void turnOff() override {
        this->status = false;
        cout << "Thermostat turned off." << endl;
    }

    void setTemperature(int temp) {
        this->temperature = temp;
        cout << "Temperature set to " << this->temperature << "°C" << endl;
    }

    int getTemperature() {
        return this->temperature;
    }
};

class SecuritySystem : public DeviceControl {
private:
    bool status = false;
    bool doorLocked = true;

public:
    void turnOn() override {
        this->status = true;
        cout << "Security system activated." << endl;
    }

    void turnOff() override {
        this->status = false;
        cout << "Security system deactivated." << endl;
    }

    void lockDoors() {
        this->doorLocked = true;
        cout << "Doors locked." << endl;
    }

    void unlockDoors() {
        this->doorLocked = false;
        cout << "Doors unlocked." << endl;
    }
};

int main() {
    const int numLights = 3;
    LightControl* livingRoomLights = new LightControl[numLights];

    const int numThermostats = 2;
    TemperatureControl* thermostats = new TemperatureControl[numThermostats];

    const int numSecuritySystems = 1;
    SecuritySystem* securitySystems = new SecuritySystem[numSecuritySystems];

    for (int i = 0; i < numLights; ++i) {
        livingRoomLights[i].turnOn();
        livingRoomLights[i].setBrightness(50 + i * 10);
    }

    for (int i = 0; i < numThermostats; ++i) {
        thermostats[i].turnOn();
        thermostats[i].setTemperature(20 + i * 5); 
    }

    for (int i = 0; i < numSecuritySystems; ++i) {
        securitySystems[i].turnOn();
        securitySystems[i].lockDoors();
    }

    delete[] livingRoomLights;
    delete[] thermostats;
    delete[] securitySystems;

    return 0;
}
