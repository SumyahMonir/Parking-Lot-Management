# Parking Lot Management System

### Data Structure Project – Stack, Queue and Linked List Based Simulation

**Parking Lot Management System** is a C++ console-based application that simulates a structured parking lot environment using core data structures.

The system:

* Models a parking lot as a grid (rows × columns)
* Assigns unique tokens to vehicles
* Manages vehicle entry and exit operations
* Tracks vehicles waiting to exit
* Calculates total earnings
* Displays real-time parking visualization

This project demonstrates the practical application of fundamental data structures in solving real-world management problems.

---

## Project Objective

The objective of this project is to implement and integrate multiple data structures to build a structured parking management simulation.

The system focuses on:

* Efficient vehicle entry allocation
* Controlled vehicle exit processing
* Queue-based token management
* Stack-based parking slot modeling
* Linked list-based exit waiting system

---

## Core Data Structures Used

### 1. Stack

Each parking column is represented using:

```
vector<stack<string>> parking;
```

Purpose:

* Models vertical parking slots
* Enforces LIFO behavior (Last In, First Out)
* Simulates real-world stacked parking behavior

---

### 2. Queue

```
queue<string> token;
```

Purpose:

* Generates and assigns unique parking tokens
* Ensures FIFO (First In, First Out) allocation
* Recycles tokens after vehicle exit

---

### 3. Linked List (Custom Implementation)

```
struct Node
```

Purpose:

* Tracks cars waiting to exit
* Dynamically manages exit requests
* Supports ordered exit processing

---

### 4. 2D Grid Visualization

```
vector<vector<string>> serial;
```

Purpose:

* Displays the real-time parking lot structure
* Shows slot occupancy visually in terminal

---

## Features

### 1. Dynamic Parking Lot Configuration

* User sets:

  * Number of rows
  * Number of columns
  * Entry fee per vehicle
* Parking capacity = rows × columns

---

### 2. Token Generation System

* Automatically generates zero-padded unique tokens
* Example format: 001, 002, 003
* Tokens are reused after exit

---

### 3. Vehicle Entry System

* Assigns next available token
* Fills parking column-wise
* Uses stack push operation
* Updates total vehicles entered
* Calculates revenue dynamically

---

### 4. Vehicle Exit System

* User enters token number
* System verifies token existence
* Uses linked list to manage exit requests
* Pops vehicles from stack if they are at top
* Recycles token into queue
* Updates parking visualization

---

### 5. Waiting Queue Handling

If:

* Parking lot is full
* Cars are waiting to enter

System:

* Maintains count of waiting vehicles
* Automatically assigns slots when available

---

### 6. Real-Time Visualization

Displays:

* Parking grid structure
* Filled slots
* Empty slots
* Waiting exit vehicles
* Total vehicles entered
* Total earnings

---

### 7. Earnings Calculation

```
Total Earning = total cars entered × ticket fee
```

Displays earnings both during operation and on exit.

---

## System Flow

1. Configure parking lot
2. Choose operation:

   * Enter a car
   * Exit a car
   * View details
   * Exit system
3. System updates parking structure dynamically
4. Maintains full operational loop

---

## Algorithmic Logic Applied

* Grid traversal for slot allocation
* LIFO stack removal logic
* FIFO queue token assignment
* Dynamic linked list traversal and deletion
* State synchronization between multiple data structures
* Structured simulation loop

---

## Technical Concepts Demonstrated

* Stack operations (push, pop, top)
* Queue operations (push, pop, front)
* Custom linked list creation and manipulation
* Memory management using dynamic allocation
* Multi-dimensional vector handling
* Console-based UI structuring
* Real-time state rendering
* Modular function design (`printCentered`, `loading`)

---

## Complexity Analysis

Let:

* R = number of rows
* C = number of columns
* N = R × C

Time Complexity:

* Entry operation: O(N)
* Exit operation: O(N)
* Display rendering: O(N)

Space Complexity:

* O(N) for parking structure
* O(N) for visualization grid

---

## Career Relevance

This project demonstrates:

* Strong understanding of core data structures
* Ability to combine multiple structures in one system
* Practical simulation design
* Real-world problem abstraction
* Memory management skills
* Logical state synchronization
* Interactive console-based software development

Applicable in:

* Systems programming
* Backend development
* Embedded systems
* Data structure interviews
* Simulation-based system design
* Competitive programming

---

## Learning Outcomes

After completing this project:

* You understand how stacks model constrained environments
* You understand how queues manage resource allocation
* You can implement custom linked lists
* You can design state-driven simulation systems
* You can manage dynamic memory effectively
* You can integrate multiple data structures cohesively

---

## Collaborator

### Sumyah Monir Mithy - All

---

## Possible Future Improvements

* Replace `system("cls")` with cross-platform screen handling
* GUI-based interface
* Database integration for persistent storage
* Time-based billing system
* Vehicle number tracking
* Reservation system
* Multi-level parking support
* Exception handling improvements

---

## Academic Context

This project was developed as part of a Data Structure course to demonstrate the integration of stacks, queues, linked lists, and grid-based simulations in solving a structured management problem.
