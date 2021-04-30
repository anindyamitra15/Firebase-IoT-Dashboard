# Firebase-IoT-Dashboard

This is a demonstration of IoT using Firebase Realtime Database.
It is very beginner friendly and can easily be implemented in firebase without knowing backend infrastructure and hosted across the world, and so can be accessed from anywhere!

* Go through this repo for all the instructions including the schematic diagrams.

### Here is a breadboard prototype diagram:
![fbdo_bb](https://user-images.githubusercontent.com/55695557/116693034-f39c3f00-a9da-11eb-859f-85daf065cf56.png)

### Use this diagram for NodeMCU GPIOs to use with Arduino IDE
![NodeMCU GPIOs](https://user-images.githubusercontent.com/55695557/105572448-2bad3980-5d7d-11eb-80c7-3420dcf9717b.png)

### The following steps to get started:
 ├── Clone this repository <br>
 ├── Head over to the `Firebase-basic-iot` folder <br>
 ├── Open the `Firebase-basic-iot.ino` file with Arduino <br>
 ├── Set the board as generic ESP8266 <br>
 └── Upload <br>

 ### Follow the procedure below to setup ESP8266 (nodeMCU) for your Arduino
Use generic ESP8266 module Board
<br> Go to File -> Preferences <br> <br>
![image](https://user-images.githubusercontent.com/55695557/105572502-8777c280-5d7d-11eb-8e78-e0c0d0c96d9d.png) <br>
And paste the link: `https://arduino.esp8266.com/stable/package_esp8266com_index.json` in Additional Board Manager URLs <br>
![image](https://user-images.githubusercontent.com/55695557/105572519-a413fa80-5d7d-11eb-8d8a-53d593645f51.png) <br>
<br> Go to Tools -> Board -> Board Manager -> Search for `ESP8266` and Download that package <br>
![image](https://user-images.githubusercontent.com/55695557/105572665-8e530500-5d7e-11eb-88f6-ac3942e6513b.png) <br>

### Upload the code
Keep the USB connected to NodeMCU to access the serial monitor in case you want to debug! <br>
Type the URL from your Firebase Hosting page, if you did everything properly, you will see something like this: <br>
![image](https://user-images.githubusercontent.com/55695557/116693694-e7fd4800-a9db-11eb-90ce-ed2155b34553.png)