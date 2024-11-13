#include <iostream>
using namespace std;

class Device {
protected:
    bool status;

public:
    Device() : status(false) {}
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual ~Device() {}
};

class DeviceControl : public Device {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual ~DeviceControl() {}
};

class LightControl : public DeviceControl {
private:
    int brightness = 100;
    static int totalLightsOn;

public:
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

    void setBrightness(float level) {
        if (level >= 0.0f && level <= 100.0f) {
            this->brightness = static_cast<int>(level);
            cout << "Brightness set to " << this->brightness << "%" << endl;
        } else {
            cout << "Invalid brightness level. Must be between 0.0 and 100.0." << endl;
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
    int temperature = 22;
    static int maxTemperature;

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

    bool isDoorLocked() const {
        return this->doorLocked;
    }
};

int main() {
    LightControl livingRoomLight;
    TemperatureControl thermostat;
    SecuritySystem securitySystem;

    livingRoomLight.turnOn();
    livingRoomLight.setBrightness(80);
    livingRoomLight.setBrightness(75.5f);
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
