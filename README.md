# Firebase-IoT-Dashboard

This is a demonstration of IoT using Firebase Realtime Database.
It is very beginner friendly and can easily be implemented in firebase without knowing backend infrastructure and hosted across the world, and so can be accessed from anywhere!

## Requirements
1. Firebase - to host a dashboard page and to make a realtime database
2. Node Package Manager or npm from [Node.js](https://nodejs.org/en/)
3. A NodeMCU - which is an ESP8266 based microcontroller kit/board
4. Arduino IDE - arduino.cc
5. Some LEDs, resistors, sensors and other components as per requirement, to test this project.
## The following are the steps to get started:
 → Clone this repository <br>
 → Host the `index.html` inside the `Webpage` folder, on firebase hosting<br>
 → Create a Realtime Database on Firebase<br>
 → Head over to the `Firebase-basic-iot` folder <br>
 → Open the `Firebase-basic-iot.ino` file with Arduino <br>
 → Set the board as generic ESP8266 <br>
 → Upload <br>

## Firebase Integration:
* We are using Firebase Realtime Database and Firebase Hosting services, those are available under the spark plan with certain limitations, but it won't be an issue for our purpose. <br>
├── Realtime Database - To store the states and Values and communicate with the IoT device(s)<br>
└── Firebase Hosting - Hosts an web app to interact with the realtime database<br>
* Detailed instructions about firebase integration are available [on this page!](Firebase-Instructions.md)<br>

* Firebase Hosting:<br>
├── Go to the `Webpage` folder in this repository <br>
└── The `index.html` contains basic html, styling, and the scripting to connect to the firebase database <br>
* Firebase Realtime Database: <br>
├── Realtime Database in Firebase is a big nested JSON which holds all the Key and Value pairs <br>
└── The values can be changed both from the device and from the web page based on certain logic <br>

## NodeMCU setup part:
Go through this repository for all the instructions including the schematic diagrams.
* Note: If you are working with NodeMCU on Arduino IDE for the first time, you may go ahead and take a look into [the NodeMCU setup instructions!](NodeMCU-Instructions.md)

### Here is a breadboard prototype diagram:
![fbdo_bb](https://user-images.githubusercontent.com/55695557/123997787-62ebda80-d9ee-11eb-983d-de0c9aa1787e.png)

### Use this diagram for NodeMCU GPIOs to use with Arduino IDE
<img src="https://user-images.githubusercontent.com/55695557/105572448-2bad3980-5d7d-11eb-80c7-3420dcf9717b.png" width="60%" alt="Node MCU GPIOs">

### Upload the code to NodeMCU
* At first download the [FirebaseESP8266.h](https://github.com/mobizt/Firebase-ESP8266) library.
* Then navigate to the [Firebase-basic-iot](./Firebase-basic-iot) folder and make a file named `config.h`.<br>
Put,<br>
`#inlcude FIREBASE_HOST "PROJECT_ID.firebaseio.com"` and<br>
`#include FIREBASE_AUTH "DATABASE_SECRET"`<br>
inside `config.h`. 
    1. You will find these credentials inside settings of your [firebase console page](https://console.firebase.google.com/) -> choose your firebase project -> Realtime Database -> Data copy the URL you see above the DB table, replace `PROJECT_ID.firebaseio.com` in the macro `FIREBASE_HOST` with that URL. Note that the URL may not end with `firebaseio.com`, as in this case, you can see it ends with `firebasedatabase.app`. <br><br>
    ![image](https://user-images.githubusercontent.com/55695557/123860094-18f9ea80-d943-11eb-82fa-7d2b492c1dbb.png)<br>
    2. And, ⚙ -> project settings -> Service accounts -> Database Secrets, click Show and then copy the database secret and replace it with `DATABASE_SECRET` in `config.h`<br><br>
    ![image](https://user-images.githubusercontent.com/55695557/123998821-7b102980-d9ef-11eb-92b1-2988dab53c97.png)


* Your code is now ready, compile it, plug the USB to Node MCU, select the proper board and port(mentioned earlier) and upload!<br>
* Keep the USB connected to NodeMCU to access the serial monitor in case you want to debug! <br>
Type the URL from your Firebase Hosting page, if you did everything properly, you will see something like this: <br>
![image](https://user-images.githubusercontent.com/55695557/116693694-e7fd4800-a9db-11eb-90ce-ed2155b34553.png)
* You have successfully hosted an webpage on firebase to control your IoT device using Firebase RTDB.

#### Just to see the gist or summary of this project, head over to [summary](Summary.md)
