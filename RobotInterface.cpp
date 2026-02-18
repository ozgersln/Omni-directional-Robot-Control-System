/**
 * @file RobotInterface.cpp
 * @brief Implementation of the RobotInterface class methods.
 *
 * * @author Ozge Erarslan
 * @contact 152120221095@ogrenci.ogu.edu.tr
 * @date December 24, 2024
 * 
 * This file contains the implementation of the constructor and destructor
 * for the abstract class RobotInterface.
 */

#include "RobotInterface.h"

/**
 * @brief Default constructor for the RobotInterface class.
 *
 * Initializes the position pointer to nullptr and sets the connection status to false.
 * This constructor ensures that the robot starts with a clean state.
 */
RobotInterface::RobotInterface() : position(nullptr), connectionStatus(false) {}

/**
 * @brief Virtual destructor for the RobotInterface class.
 *
 * Ensures proper cleanup of dynamically allocated memory in derived classes.
 * This destructor does not perform any specific action in the base class,
 * but it is declared virtual to allow derived class destructors to be called correctly.
 */
RobotInterface::~RobotInterface() {}
