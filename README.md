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

## 🗂️ Project Structure (Main Branch)

## 📋 UML Diagrams

### Structural Diagrams
- [**Class Diagram**](./Diagram/Class%20Diagram.jpg) - System class structure and relationships
- [**Object Diagram**](./Diagram/Object%20Diagram.jpg) - Runtime object instances and links
- [**Communication Diagram**](./Diagram/Communication%20Diagram.jpg) - Object interactions and messaging

### Behavioral Diagrams
- [**Sequence Diagrams**](./Diagram/Sequence%20Diagram.jpg) - Time-ordered object interactions
- [**State Machine Diagram**](./Diagram/State%20Machine%20Diagram.pdf) - Object state transitions
- [**Activity Diagram**](./Diagram/Activity%20Diagram.jpg) - Business process workflows

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

### Prerequisites
- C++ Compiler (GCC, Clang, or MSVC) in version C++ 14

### Build Instructions
*add it here when we are done w project fully*
- C++ Compiler (GCC, Clang, or MSVC) in version C++ 14

### Build Instructions
add it here when we are done w project fully

