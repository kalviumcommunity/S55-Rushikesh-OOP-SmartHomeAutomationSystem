#include <iostream>
using namespace std;

class DeviceControl {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual ~DeviceControl() {
        cout << "DeviceControl Destructor called." << endl;
    }
};

class LightControl : public DeviceControl {
private:
    bool status = false;
    int brightness = 100;
    static int totalLightsOn;

public:
    LightControl() {
        cout << "LightControl default constructor called." << endl;
    }

    LightControl(int brightnessLevel) : brightness(brightnessLevel) {
        cout << "LightControl parameterized constructor called with brightness: " << brightness << "%" << endl;
    }

    ~LightControl() {
        cout << "LightControl Destructor called." << endl;
    }

    void turnOn() override {
        if (!this->status) {
            this->status = true;
            totalLightsOn++;
        }
        cout << "Lights turned on. Brightness: " << this->brightness << "%" << endl;
    }

    void turnOff() override {
        if (this->status) {
            this->status = false;
            totalLightsOn--;
        }
        cout << "Lights turned off." << endl;
    }

    void setBrightness(int level) {
        if (level >= 0 && level <= 100) {
            this->brightness = level;
            cout << "Brightness set to " << this->brightness << "%" << endl;
        } else {
            cout << "Invalid brightness level. Must be between 0 and 100." << endl;
        }
    }

    int getBrightness() const {
        return this->brightness;
    }

    static int getTotalLightsOn() {
        return totalLightsOn;
    }
};

int LightControl::totalLightsOn = 0;

class TemperatureControl : public DeviceControl {
private:
    bool status = false;
    int temperature = 22;
    static int maxTemperature;

public:
    TemperatureControl() {
        cout << "TemperatureControl default constructor called." << endl;
    }

    TemperatureControl(int initialTemp) : temperature(initialTemp) {
        cout << "TemperatureControl parameterized constructor called with temperature: " << temperature << "°C" << endl;
    }

    ~TemperatureControl() {
        cout << "TemperatureControl Destructor called." << endl;
    }

    void turnOn() override {
        this->status = true;
        cout << "Thermostat turned on. Temperature: " << this->temperature << "°C" << endl;
    }

    void turnOff() override {
        this->status = false;
        cout << "Thermostat turned off." << endl;
    }

    void setTemperature(int temp) {
        if (temp >= 16 && temp <= 30) {
            this->temperature = temp;
            if (temp > maxTemperature) {
                maxTemperature = temp;
            }
            cout << "Temperature set to " << this->temperature << "°C" << endl;
        } else {
            cout << "Invalid temperature. Must be between 16°C and 30°C." << endl;
        }
    }

    int getTemperature() const {
        return this->temperature;
    }

    static int getMaxTemperature() {
        return maxTemperature;
    }
};

int TemperatureControl::maxTemperature = 22;

class SecuritySystem : public DeviceControl {
private:
    bool status = false;
    bool doorLocked = true;

public:
    SecuritySystem() {
        cout << "SecuritySystem default constructor called." << endl;
    }

    ~SecuritySystem() {
        cout << "SecuritySystem Destructor called." << endl;
    }

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

    bool isDoorLocked() const {
        return this->doorLocked;
    }
};

int main() {
    LightControl livingRoomLight;
    TemperatureControl thermostat;
    SecuritySystem securitySystem;

    LightControl kitchenLight(60);
    TemperatureControl bedroomThermostat(24);

    livingRoomLight.turnOn();
    livingRoomLight.setBrightness(80);
    cout << "Current brightness: " << livingRoomLight.getBrightness() << "%" << endl;

    thermostat.turnOn();
    thermostat.setTemperature(25);
    cout << "Current temperature: " << thermostat.getTemperature() << "°C" << endl;
    cout << "Maximum temperature: " << TemperatureControl::getMaxTemperature() << "°C" << endl;

    securitySystem.turnOn();
    securitySystem.lockDoors();
    cout << "Are doors locked? " << (securitySystem.isDoorLocked() ? "Yes" : "No") << endl;

    cout << "Total lights turned on: " << LightControl::getTotalLightsOn() << endl;

    return 0;
}
