/**
 * @file SensorInterface.h
 * @brief Abstract base class for sensor interfaces.
 *
 * This file defines a pure virtual interface for sensor classes, providing methods for updating sensor values
 * and retrieving specific sensor information. Derived classes must implement the pure virtual methods.
 *
 * @author Ozge Erarslan
 * @contact 152120221095@ogrenci.ogu.edu.tr
 * @date December 24, 2024
 */

#ifndef SENSOR_INTERFACE_H
#define SENSOR_INTERFACE_H

#include <string>

 /**
  * @class SensorInterface
  * @brief Abstract base class for different types of sensors.
  *
  * This class serves as an interface for sensors, defining common functionality that all sensors must implement.
  */
class SensorInterface {
protected:
    std::string sensorType; ///< The type of the sensor.

public:
    /**
     * @brief Virtual destructor for the SensorInterface class.
     *
     * Ensures proper cleanup of derived class objects when deleted through a SensorInterface pointer.
     */
    virtual ~SensorInterface() = default;

    /**
     * @brief Pure virtual function to update the sensor value.
     *
     * This function must be implemented by derived classes to update the internal state of the sensor.
     */
    virtual void update() = 0;

    /**
     * @brief Retrieves the type of the sensor.
     *
     * @return A string representing the type of the sensor.
     */
    virtual std::string getSensorType() const {
        return sensorType;
    }

    /**
     * @brief Pure virtual function to get a specific sensor value by index.
     *
     * @param index The index of the desired sensor value.
     * @return The sensor value at the specified index.
     */
    virtual double getSensorValue(int index) const = 0;
};

#endif // SENSOR_INTERFACE_H
