Omni-Directional Robot Control System

Project Overview

This project implements an object-oriented control system for an omni-directional mobile robot using C++.
The architecture is designed with abstraction and interface-based design principles to ensure scalability and modularity. The system simulates robot movement, navigation, and sensor interactions.
Developed as part of an Object-Oriented Programming course.

🇹🇷 Proje Hakkında

Bu proje, C++ kullanılarak geliştirilen nesne yönelimli (OOP) bir omni-directional mobil robot kontrol sistemidir.
Sistem; soyutlama (abstraction), arayüz tabanlı mimari ve modüler tasarım prensipleri kullanılarak geliştirilmiştir. Robot hareketi, navigasyon ve sensör etkileşimleri simüle edilmektedir.
Nesne Yönelimli Programlama dersi kapsamında geliştirilmiştir.

#Technical Highlights

C++
Object-Oriented Programming
Interface-based architecture
Sensor abstraction (IR & Lidar)
Modular system design
Access control mechanism
Navigation & mapping logic

 
#Architecture Overview
RobotController manages robot operations
RobotInterface provides abstraction between controller and API
SensorInterface abstracts sensor implementations
SafeNavigation and Mapper operate via SensorInterface
Access control is implemented using openAccess() / closeAccess()
The architecture allows integration of new robot APIs without affecting existing system components.

#Learning Outcomes

Advanced class design
Abstract class & interface usage
Separation of concerns
Writing scalable C++ architectures

Real-world OOP simulation
