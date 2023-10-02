# KNN Algorithm Classifier

Welcome to the KNN (K-Nearest Neighbors) Algorithm Classifier! This project allows multiple clients to connect to the server, upload unclassified data, configure KNN algorithm parameters, classify data, and download results. Developed by Noy and Avigail, this system utilizes a command design pattern and communicates over TCP protocol.

## Overview

In this task, our server handles multiple clients concurrently. When a client connects, the server sends a menu outlining available functionalities. The program uses the KNN algorithm to classify vectors based on uploaded data. Each command is encapsulated within a separate Command class, providing a modular and maintainable structure.

## Commands and Functionality

### 1. Upload Unclassified Data
Clients can upload a train CSV file containing vectors and their classifications. Additionally, clients provide a test CSV file with unclassified vectors to be classified using the KNN algorithm.

### 2. Algorithm Settings
Clients can view and modify KNN algorithm parameters, including the number of nearest neighbors (K) and the chosen distance function. The system supports various distance functions for flexibility.

### 3. Classify Data
The server executes the KNN algorithm on the uploaded data, classifying the test vectors. After completion, the server notifies clients with "complete data classifying."

### 4. Display Results
Clients receive the list of classifications, displayed as line numbers, classifications, and newline characters. After user input, clients return to the main menu. If no data is uploaded or classified, appropriate messages are displayed.

### 5. Download Results
Similar to option 4, clients can download the results by specifying a local path. The results are saved in the specified file in the same format as displayed in option 4. This process occurs asynchronously in a separate thread.

## How We Divided the Work

- **Commands Implementation:** Avigail implemented commands 1-6, focusing on the core functionalities of the KNN algorithm.
  
- **SocketIO and Threads:** Noy implemented the SocketIO functionality and managed threading for concurrent client communication. Both partners collaborated and supported each other throughout the project, fostering excellent teamwork.

## Compilation and Execution

### Compilation
Compile the project using the following command:
```bash
make
```

### Server Execution
Run the server with the following pattern:
```bash
./server.out port
```

### Client Execution
Execute the client with the following pattern:
```bash
./client.out ip port
```

## Previous Missions

- **Task 2:** Implemented a classifier capable of reading data from a file and classifying new objects using the KNN algorithm. The implementation involved calculating distances, finding the nearest neighbors, and selecting the majority classification.

- **Task 3:** Developed a client-server interaction where clients sent input vectors to the server, which classified them using KNN and sent back the results. The client ran in a loop, accepting user input for classification and displaying the results. The connection was terminated when the user entered -1.

Thank you for being a part of this exciting course! If you have any questions or issues, feel free to reach out. Happy classifying! 😊
