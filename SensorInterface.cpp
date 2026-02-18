/**
 * @file SensorInterface.cpp
 * @brief Implementation of the SensorInterface class methods.
 *
 * @author Ozge Erarslan
 * @contact 152120221095@ogrenci.ogu.edu.tr
 * @date December 24, 2024
 *
 * This file contains the implementation of the non-pure virtual methods
 * of the SensorInterface class, specifically the retrieval of the sensor type.
 */

#include "SensorInterface.h"

/**
 * @brief Retrieves the type of the sensor.
 *
 * This method returns the type of the sensor as a string. It is implemented
 * in the base class and can be inherited or overridden by derived classes.
 *
 * @return A string representing the type of the sensor.
 */
std::string SensorInterface::getSensorType() const {
    return sensorType;
}
