# 🌱 COS 214 - Plant Nursery Management System

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)
![University](https://img.shields.io/badge/COS_214-Project-blue)

## 🌱 Branch Structure

- **`main`** - Production-ready code with final implementation
- **`dev`** - Development branch for ongoing work
- **Feature Branches** - Individual feature development

## 📊 Project Overview

This C++ project implements a comprehensive plant nursery management system for COS 214, showcasing object-oriented design principles and software design patterns in C++.
It involves a variety of features and interactions, such as being able to view plants, create orders and take care and monitor plant growth and many more.
We as a team of 7 distributed an even workload in which each team member all contirbuted in building this fully functional system as all as the related documentation and diagrams to follow with it.

## 🗂️ Project Structure (Main Branch)

```
⚙️ Plant-Nursery-Management-System/
├── 📁 documentation/
│   ├── 📄 COS214_Project_Report.pdf
│   ├── 📄 Presentation_Slides.pptx
│   ├── 📁 Diagrams/
│   │   ├── Class Diagram.jpg
│   │   ├── Object Diagram.jpg
│   │   ├── Communication Diagram.jpg
│   │   ├── Sequence Diagram.jpg
│   │   ├── State Machine Diagram.pdf
│   │   └── Activity Diagram.jpg
│   └── README_Documentation.txt
├── 📁 include/
│   ├── 📁 Patterns/
│   │   ├── 📁 AbstractFactory/
│   │   │   ├── 📁 PlantTypes/
│   │   │   │   ├── AloeVera.h
│   │   │   │   ├── BirdOfParadise.h
│   │   │   │   ├── Condelabra.h
│   │   │   │   ├── Daisy.h
│   │   │   │   ├── HenAndChicks.h
│   │   │   │   ├── LargePlant.h
│   │   │   │   ├── Lilac.h
│   │   │   │   ├── MediumPlant.h
│   │   │   │   ├── Nepenthes.h
│   │   │   │   ├── Nerve.h
│   │   │   │   ├── Pitcher.h
│   │   │   │   ├── Rubber.h
│   │   │   │   ├── SmallPlant.h
│   │   │   │   ├── Sundew.h
│   │   │   │   └── WhiteOak.h
│   │   │   └── 📁 Factories/
│   │   │       ├── CarnivorousPlantFactory.h
│   │   │       ├── GreenHouse.h
│   │   │       ├── SucculentPlantFactory.h
│   │   │       ├── TemperatePlantFactory.h
│   │   │       └── TropicalPlantFactory.h
│   │   ├── 📁 State/
│   │   │   ├── 📁 OrderState/
│   │   │   │   ├── Cancelled.h
│   │   │   │   ├── Completed.h
│   │   │   │   ├── Draft.h
│   │   │   │   ├── OrderState.h
│   │   │   │   └── Paid.h
│   │   │   ├── 📁 HealthState/
│   │   │   │   ├── Dead.h
│   │   │   │   ├── Good.h
│   │   │   │   ├── HealthState.h
│   │   │   │   └── NeedsCare.h
│   │   │   └── 📁 GrowthState/
│   │   │       ├── GrowthState.h
│   │   │       ├── Mature.h
│   │   │       ├── Seed.h
│   │   │       └── Sprout.h
│   │   ├── 📁 Command/
│   │   │   ├── Command.h
│   │   │   ├── Fertilizer.h
│   │   │   ├── Prune.h
│   │   │   ├── Sun.h
│   │   │   └── Water.h
│   │   ├── 📁 ChainOfResponsibility/
│   │   │   ├── FertilizerHandler.h
│   │   │   ├── PlantCareHandler.h
│   │   │   ├── PruneHandler.h
│   │   │   ├── SunHandler.h
│   │   │   └── WaterHandler.h
│   │   ├── 📁 Decorator/
│   │   │   ├── FertilizerDecorator.h
│   │   │   ├── PlantDecorator.h
│   │   │   └── PotDecorator.h
│   │   ├── 📁 Iterator/
│   │   │   ├── 📁 Inventory/
│   │   │   │   ├── Inventory.h
│   │   │   │   └── InventoryIterator.h
│   │   │   ├── 📁 Order/
│   │   │   │   ├── Order.h
│   │   │   │   └── OrderIterator.h
│   │   │   ├── 📁 Stock/
│   │   │   │   ├── Stock.h
│   │   │   │   └── StockIterator.h
│   │   │   ├── Iterator.h
│   │   │   ├── PlantNode.h
│   │   │   └── Storage.h
│   │   ├── 📁 Mediator/
│   │   │   ├── CommMediator.h
│   │   │   ├── ConcreteCommMediator.h
│   │   │   ├── Manager.h
│   │   │   ├── StaffMember.h
│   │   │   └── Worker.h
│   │   ├── 📁 Composite/
│   │   │   ├── Company.h
│   │   │   ├── Customer.h
│   │   │   ├── Normal.h
│   │   │   └── Premium.h
│   │   ├── 📁 Observer/
│   │   │   ├── ConcreteGrowthObserver.h
│   │   │   └── Plant.h
│   │   └── 📁 Memento/
│   │       ├── Caretaker.h
│   │       └── Memento.h
│   ├── 📁 Core/
│   │   └── Plant.h
│   └── 📄 DemoMain.h
├── 📁 src/
│   ├── 📁 Patterns/
│   │   ├── 📁 AbstractFactory/
│   │   │   ├── 📁 PlantTypes/
│   │   │   │   ├── AloeVera.cpp
│   │   │   │   ├── BirdOfParadise.cpp
│   │   │   │   ├── Condelabra.cpp
│   │   │   │   ├── Daisy.cpp
│   │   │   │   ├── HenAndChicks.cpp
│   │   │   │   ├── LargePlant.cpp
│   │   │   │   ├── Lilac.cpp
│   │   │   │   ├── MediumPlant.cpp
│   │   │   │   ├── Nepenthes.cpp
│   │   │   │   ├── Nerve.cpp
│   │   │   │   ├── Pitcher.cpp
│   │   │   │   ├── Rubber.cpp
│   │   │   │   ├── SmallPlant.cpp
│   │   │   │   ├── Sundew.cpp
│   │   │   │   └── WhiteOak.cpp
│   │   │   └── 📁 Factories/
│   │   │       ├── CarnivorousPlantFactory.cpp
│   │   │       ├── GreenHouse.cpp
│   │   │       ├── SucculentPlantFactory.cpp
│   │   │       ├── TemperatePlantFactory.cpp
│   │   │       └── TropicalPlantFactory.cpp
│   │   ├── 📁 State/
│   │   │   ├── 📁 OrderState/
│   │   │   │   ├── Cancelled.cpp
│   │   │   │   ├── Completed.cpp
│   │   │   │   ├── Draft.cpp
│   │   │   │   ├── OrderState.cpp
│   │   │   │   └── Paid.cpp
│   │   │   ├── 📁 HealthState/
│   │   │   │   ├── Dead.cpp
│   │   │   │   ├── Good.cpp
│   │   │   │   ├── HealthState.cpp
│   │   │   │   └── NeedsCare.cpp
│   │   │   └── 📁 GrowthState/
│   │   │       ├── GrowthState.cpp
│   │   │       ├── Mature.cpp
│   │   │       ├── Seed.cpp
│   │   │       └── Sprout.cpp
│   │   ├── 📁 Command/
│   │   │   ├── Command.cpp
│   │   │   ├── Fertilizer.cpp
│   │   │   ├── Prune.cpp
│   │   │   ├── Sun.cpp
│   │   │   └── Water.cpp
│   │   ├── 📁 ChainOfResponsibility/
│   │   │   ├── FertilizerHandler.cpp
│   │   │   ├── PlantCareHandler.cpp
│   │   │   ├── PruneHandler.cpp
│   │   │   ├── SunHandler.cpp
│   │   │   └── WaterHandler.cpp
│   │   ├── 📁 Decorator/
│   │   │   ├── FertilizerDecorator.cpp
│   │   │   ├── PlantDecorator.cpp
│   │   │   └── PotDecorator.cpp
│   │   ├── 📁 Iterator/
│   │   │   ├── 📁 Inventory/
│   │   │   │   ├── Inventory.cpp
│   │   │   │   └── InventoryIterator.cpp
│   │   │   ├── 📁 Order/
│   │   │   │   ├── Order.cpp
│   │   │   │   └── OrderIterator.cpp
│   │   │   ├── 📁 Stock/
│   │   │   │   ├── Stock.cpp
│   │   │   │   └── StockIterator.cpp
│   │   │   ├── Iterator.cpp
│   │   │   ├── PlantNode.cpp
│   │   │   └── Storage.cpp
│   │   ├── 📁 Mediator/
│   │   │   ├── CommMediator.cpp
│   │   │   ├── ConcreteCommMediator.cpp
│   │   │   ├── Manager.cpp
│   │   │   ├── StaffMember.cpp
│   │   │   └── Worker.cpp
│   │   ├── 📁 Composite/
│   │   │   ├── Company.cpp
│   │   │   ├── Customer.cpp
│   │   │   ├── Normal.cpp
│   │   │   └── Premium.cpp
│   │   ├── 📁 Observer/
│   │   │   ├── ConcreteGrowthObserver.cpp
│   │   │   └── Plant.cpp
│   │   └── 📁 Memento/
│   │       ├── Caretaker.cpp
│   │       └── Memento.cpp
│   ├── 📁 Core/
│   │   └── Plant.cpp
│   └── 📄 DemoMain.cpp
|   └── 📄 TestingMain.cpp
├── 📄 Makefile
├── 📄 .gitignore
└── 📄 README.md
```

## 📋 UML Diagrams

### Structural Diagrams
- [**Class Diagram**](./Diagram/Class%20Diagram.jpg) - System class structure and relationships
- [**Object Diagram**](./Diagram/Object%20Diagram.jpg) - Runtime object instances and links
- [**Communication Diagram**](./Diagram/Communication%20Diagram.jpg) - Object interactions and messaging

### Behavioral Diagrams
- [**Sequence Diagrams**](./Diagram/Sequence%20Diagram.jpg) - Time-ordered object interactions
- [**State Machine Diagram**](./Diagram/State%20Machine%20Diagram.pdf) - Object state transitions
- [**Activity Diagram**](./Diagram/Activity%20Diagram.jpg) - Business process workflows

## 📋 Documentation

### Powerpoint 

### Functional Requirements

### Doxygen 

## 👥 Team Members & Contributions

| Team Member | Role & Focus | Key Contributions | Design Patterns & Features |
|-------------|--------------|-------------------|----------------------------|
| **Ayush Beekum** | *Structural Foundations & Creational Patterns* | - Object Diagram design<br>- Plant creation systems | **Abstract Factory**: Factory interfaces for plant families<br>**Decorator**: Flexible plant enhancements<br>**Prototype**: Efficient plant cloning |
| **Diya Narotam** | *Plant Lifecycle Management* | - Class Diagram design<br>- Plant health & growth systems | **State - HealthState**: Dynamic transitions (Good → NeedsCare → Dead)<br>**State - GrowthState**: Growth progression (Seed → Sprout → Mature) |
| **Jaitin Moodally** | *Request Handling & Command System* | - Communication Diagram<br>- Plant care operations | **Command Pattern**: Encapsulated plant care operations<br>**Chain of Responsibility**: Sequential request handling<br>**Observer Pattern**: Monitors plant growth changes |
| **Shavir Vallabh** | *Data Access & Order Management* | - Sequence Diagram<br>- Plant collection traversal | **Iterator Pattern**: BST-based collection traversal<br>**State - OrderState**: Order lifecycle (Draft → Completed → Paid → Cancelled) |
| **Fabio Berrino** | *System Persistence & Demonstration* | - Activity Diagram<br>- System state management | **Memento Pattern**: Templatized state capture/restore<br>**DemoMain**: Comprehensive system demonstration |
| **Chinmayi Santosh** | *Communication Mediation* | - Class Diagram design<br>- Object communication | **Mediator Pattern**: Centralized worker-customer communications |
| **Mahadio Tlaka** | *Hierarchical Structures* | - State Machine Diagram<br>- Customer management | **Composite Pattern**: Customer grouping hierarchy |

---

## 🎯 Design Patterns Overview

This project demonstrates 10+ Gang of Four design patterns working in harmony:
- **Creational**: Abstract Factory, Prototype
- **Structural**: Decorator, Composite
- **Behavioral**: State, Command, Chain of Responsibility, Iterator, Memento, Mediator, Observer

Each pattern addresses specific domain problems in plant nursery management while maintaining clean separation of concerns and extensible architecture.

---

### Prerequisites⠀
- C++ Compiler (GCC, Clang, or MSVC) in version C++ 14

### Build Instructions
*add it here when we are done w project fully*

