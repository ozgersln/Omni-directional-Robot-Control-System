# Omni-Directional Robot Control System

## Project Overview

This project is an object-oriented C++ implementation of an omni-directional robot control system.  
The system was designed using an interface-based architecture to ensure modularity, scalability, and hardware abstraction.

The project focuses on applying OOP principles such as abstraction, encapsulation, inheritance, and polymorphism in a robotics control environment.


## Architecture
The system was redesigned in the second phase to follow a UML-based layered architecture.
Key architectural components:

- **RobotController**
- **RobotInterface (Abstract Class)**
- **SensorInterface (Abstract Class)**
- **FestoRobotInterface**
- **IRSensor**
- **LidarSensor**
- **SafeNavigation**
- **Mapper**
- Supporting classes: `Point`, `Pose`, `Map`, `Record`, `RobotOperator`, `Encryption`

### Core Design Principles
- Hardware abstraction using abstract interfaces  
- Decoupling robot API from control logic  
- Sensor management via dynamic sensor list  
- Access control with password-based authorization  
- Extensible design for future robot platforms  

## Features
- Omni-directional motion control  
- Interface-based robot API integration  
- Centralized sensor update mechanism  
- IR and Lidar sensor abstraction  
- Secure access system (openAccess / closeAccess)  
- Menu-driven console control system  

## Technologies Used

- C++
- Object-Oriented Programming
- UML-based class design
- Interface-based architecture
- Robotics simulation environment

---

# Türkçe Açıklama

## Genel Bakış

Bu proje, her yöne hareket edebilen (omni-directional) bir robotun kontrol sistemi için nesne yönelimli C++ ile geliştirilmiş bir yazılımdır.  
Sistem, modülerlik, ölçeklenebilirlik ve donanım soyutlaması sağlamak amacıyla arayüz (interface) tabanlı mimari kullanılarak tasarlanmıştır.

Projede soyutlama, kapsülleme, kalıtım ve çok biçimlilik gibi OOP prensipleri uygulanmıştır.

## Mimari

İkinci aşamada sistem UML sınıf diyagramına göre yeniden yapılandırılmıştır.

Temel bileşenler:

- **RobotController**
- **RobotInterface (Soyut Sınıf)**
- **SensorInterface (Soyut Sınıf)**
- **FestoRobotInterface**
- **IRSensor**
- **LidarSensor**
- **SafeNavigation**
- **Mapper**
- Destek sınıfları: `Point`, `Pose`, `Map`, `Record`, `RobotOperator`, `Encryption`

### Tasarım Yaklaşımı

- Donanım soyutlaması için abstract arayüzler  
- Robot API ile kontrol katmanının ayrıştırılması  
- Sensörlerin dinamik liste yapısı ile yönetilmesi  
- Şifre tabanlı erişim kontrol sistemi  
- Yeni robot platformlarına açık genişletilebilir mimari  


## Özellikler

- Omni-directional hareket kontrolü  
- Arayüz tabanlı robot API entegrasyonu  
- Merkezi sensör güncelleme mekanizması  
- IR ve Lidar sensör soyutlaması  
- Güvenli erişim sistemi (openAccess / closeAccess)  
- Menü tabanlı konsol uygulaması  

## Kullanılan Teknolojiler

- C++
- Nesne Yönelimli Programlama
- UML tabanlı sınıf tasarımı
- Arayüz tabanlı yazılım mimarisi
- Robotik simülasyon ortamı
