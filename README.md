# Ass4 - made by Noy and Avigail


# Summary
In this task our server will be able to handle several clients at the same time.
When a client connects to the server, the server sends the client a text that will list the function of the server.
The client will print to the screen the text received from the server.
We were asked to use a design pattern called command, where each command in our program has its own Command class. Different commands are defined in the Command class, for example: abstract execute for activation, description for printing the part of that command in the menu. All command classes inherit from Command and implement these 2 methods. Later we will detail more about each command.
For each command that the client sends to the server, an appropriate Command object will be activated that will continue the interaction with the client as needed. The interaction is done by the DeafultIO object so we can later replace with communication-based I/O.
All communication between the server and the client will take place using the TCP protocol, as we asked for.
In our task, the server will print the following menu:

Welcome to the KNN Classifier Server. Please choose an option:
 1. upload an unclassified csv data file
 2. algorithm settings
 3. classify data
 4. display results
 5. download results
 8. exit

# The Commands
* Command1-
upload an unclassified csv data file: asks the client to provide a train csv file that contains a list of vectors and their classifications. Vectors from this file will be used in the KNN algorithm to classify vectors. Then, it asks the client to upload a test csv file that contains a list of vectors without classifications. these vectors will be then classified (in command 3) by the KNN algorithm.

* Command 2-
algorithm settings: shows the client the parameters of the KNN algorithm, and gives them an option to change them. After shown the settings, the client can either not provide new parameters by pressing the enter key, or provide new parameters by typing them in the form: "K D", So K is a number between 1 and the number of lines in the unclassified file, and D is the name of a known distance function. Currently we have 5 known distances.
If the client tries to provide parameters but does so in the wrong format, the command will keep asking for parameters until valid ones are given (in this mode the 'enter' key doesn't exit the function. new parameters must be given after the first try failed).
We decided that when the user bring to the program k greater than the number of lines in the unclassified file, we will put the maximum number of lines in the parameter. And we will not return an error.


* Command 3-
classify data: The server will run the algorithm on the CSV files uploaded earlier. At the end of running the server will write "complete data classifying" and we will return to the main menu.
If no files have been uploaded yet, print "data upload please."

* Command 4-
display results: The server will return the list of classifications. For each classification the print will be as follows: number The line in the test file, tab, the classification and then line drop. Finally "Done." will be printed. After 'enter' of The user we will return to the main menu.
If no files have been uploaded yet, print "data upload please."
If the files have not yet been classified, print "data the classify please."

* Command 5-
download results: The behavior will be similar to option 4, only instead of printing the results, the user will enter a path to create the file locally and there the client will save the results, in the same format from the previous section.
If no files have been uploaded yet, print "data upload please."
If the files have not yet been classified, print "data the classify please."
In this command, after the user's enter, the main menu will immediately appear again and the user will be able to send additional commands immediately, even if the file has not yet been downloaded finished, meaning - this process happens in a separate thread.


# How we divided the work
We divided it into 2 parts: The 1-6 commands portion, and the SocketIO + threads portion. Avigail did the 1-6 commands portion, and NOY did the SocketIO and threads portion. 
Of course we were both partners in every part of the work, and when one got stuck the other helped her. We had great teamwork :)


# How to compile?
Compile using the "make" command only, then:

The server runs by the following pattern: 
```
./server.out port
```
The client runs by the following pattern: 
```
./client.out ip port
```

# Previous missions
task2:
In this task, we had to read from a file information, remember these details, and when we received data about a new object, we had to know how to classify it. We received from the command line member k, the type of sorting we want to use, and the name of the file from which we want to read the information.

We'll tell you how we did it: Initially, we checked the distances between the input vector and existing classified vectors. We saved the distances in the array with the classification. Then we found the k smallest members- the k members that are closest to the vector we received. After finding the closest k, we checked which name appears the most in our info array, and returned its string. ofcourse we added header files too.

In the command line we receive the following parameters: a.out k file distance

(k expresses the k nearest neighbors of the input vector file expresses the name of the file from which the information is read distance expresses the distance algorithm we want to use).

Notes about distance functions:
Euclidean distance is a special case of Minkowski distance when P = 1 and Manhattan distance is also a special case of the Minkowski distance when P = 2, so we did them both by placing different p in a general formula.
In function Minkowsk Distance we chose: P = 100.

task3:
we had to write code that implements the following process: The client sends the information received from the user to the server, the server classifies accordingly, and sends the classification to the client. The client prints the received answer to the screen and receives the next input from the user. If the user entered the input -1 the client closes the connection with the server and closes the program. The server, in this case, continues to the next connection In any case of invalid input, we print "input invalid" and continue to the next input ("k"expresses the k nearest neighbors of the input vector file expresses the name of the file from which the information is read, "distance" expresses the distance algorithm we want to use) actually, The client runs in an infinite loop, and receives from the user a vector for classification and the distance metric as follows: vector distance k. (k must be > 0)

Thank You! It was a cool course :)
