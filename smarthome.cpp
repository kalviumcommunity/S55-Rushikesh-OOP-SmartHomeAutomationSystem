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
        status = true;
        cout << "Lights turned on. Brightness: " << brightness << "%" << endl;
    }

    void turnOff() override {
        status = false;
        cout << "Lights turned off." << endl;
    }

    void setBrightness(int level) {
        brightness = level;
        cout << "Brightness set to " << brightness << "%" << endl;
    }
};

class TemperatureControl : public DeviceControl {
private:
    bool status = false;
    int temperature = 22;

public:
    void turnOn() override {
        status = true;
        cout << "Thermostat turned on. Temperature: " << temperature << "°C" << endl;
    }

    void turnOff() override {
        status = false;
        cout << "Thermostat turned off." << endl;
    }

    void setTemperature(int temp) {
        temperature = temp;
        cout << "Temperature set to " << temperature << "°C" << endl;
    }

    int getTemperature() {
        return temperature;
    }
};

class SecuritySystem : public DeviceControl {
private:
    bool status = false;
    bool doorLocked = true;

public:
    void turnOn() override {
        status = true;
        cout << "Security system activated." << endl;
    }

    void turnOff() override {
        status = false;
        cout << "Security system deactivated." << endl;
    }

    void lockDoors() {
        doorLocked = true;
        cout << "Doors locked." << endl;
    }

    void unlockDoors() {
        doorLocked = false;
        cout << "Doors unlocked." << endl;
    }
};


int main() {
    LightControl livingRoomLights;
    TemperatureControl mainThermostat;
    SecuritySystem homeSecurity;

    livingRoomLights.turnOn();
    livingRoomLights.setBrightness(75);

    mainThermostat.turnOn();
    mainThermostat.setTemperature(24);

    homeSecurity.turnOn();
    homeSecurity.lockDoors();

    return 0;
}
