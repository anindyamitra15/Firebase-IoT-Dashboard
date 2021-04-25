/*=== Libraries ===*/
#include <WiFiManager.h> 
#include <FirebaseESP8266.h>
#include "Interval.h"

/*
  * config.h should contain all the required credentials used by firebase to connect to the database
  * As it contains all the sensitive informations, therefore it is not uploaded to Github
  * FIREBASE_HOST "PROJECT_ID.firebaseio.com"
  * FIREBASE_AUTH "DATABASE_SECRET"
*/
#include "config.h"



/*=== All the GPIO Pins ===*/
#define LED 2
#define analogInput A0
#define digitalInput 4


/*Define the Firebase Data object*/
FirebaseData fbdo;

/*Define the Interval Objects*/
Interval showDebugDataSchedule;
Interval inputHandler;
Interval outputHandler;

/*=== prototypes ===*/
void WiFiSetup(void);
void configModeCallback(WiFiManager *wifi);
void showDebugData();
void handleInput();
void handleOutput();

void setup()
{
// For debugging
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  
// Setting GPIO pins as Inputs/Outputs
  pinMode(LED, OUTPUT);
  pinMode(analogInput, INPUT);
  pinMode(digitalInput, INPUT);

// Setting and connecting to Wifi using WiFiManager
  WiFiSetup();

// Firebase setup section
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  fbdo.setBSSLBufferSize(1024, 1024);
  fbdo.setResponseSize(1024);

// Interval task setup
  showDebugDataSchedule.setTicker(true);
  showDebugDataSchedule.setDelay(10000); // every 10 seconds

  inputHandler.setTicker(true);
  inputHandler.setDelay(3000);
  
  outputHandler.setTicker(true);
  outputHandler.setDelay(2000);
}

void loop()
{
  showDebugDataSchedule.tick(showDebugData);//every 10 seconds
  inputHandler.         tick( handleInput );// every 3 sec
  outputHandler.        tick(handleOutput );// every 2 sec
}


/*=== functions ===*/
void WiFiSetup()
{
  WiFiManager wifi;
  wifi.setDebugOutput(false);
  wifi.setTimeout(300);
  wifi.setAPCallback(configModeCallback);
  if(!wifi.autoConnect("FirebaseIOT", "12345678"))
  {
    Serial.println("Couldn't Connect to remote AP");
    ESP.restart();
    digitalWrite(LED, LOW);
    delay(2500);
    digitalWrite(LED, HIGH);
    delay(2500);
  }
  else
  {
    // blink thrice on connection
    for(int i = 0; i < 3; i++)
    {
      digitalWrite(LED, LOW);
      delay(200);
      digitalWrite(LED, HIGH);
      delay(200);
    }
  }
}

void configModeCallback (WiFiManager *wifi)
{
  Serial.println("Entered config mode: ");
  Serial.println(WiFi.softAPIP());
  Serial.println(wifi->getConfigPortalSSID());
}

void showDebugData()
{
  if(Firebase.get(fbdo, "/devices"))
  {
    Serial.println("PATH: " + fbdo.dataPath());
    Serial.println("TYPE: " + fbdo.dataType());
    Serial.print("VALUE: ");
    Serial.println(fbdo.jsonString());
  }
  else
  {
    Serial.println("FAILED");
    Serial.println("REASON: " + fbdo.errorReason());
    Serial.println("...");
    Serial.println();
  }
}


void handleInput()
{
  Serial.println("handleInput");
  int a_data = analogRead(analogInput);
  bool d_data = digitalRead(digitalInput);
  while(!Firebase.setInt(fbdo, "/devices/Inputs/A0", a_data) 
  || !Firebase.setBool(fbdo, "/devices/Inputs/D0", d_data) )
  {
    Serial.println("Updating");
  }
  Serial.println(a_data);
  Serial.println(d_data);
}

void handleOutput(){
  Serial.println("handleOutput");
  int level;
  bool state;
  bool _isUpdated = false;
  
  if (Firebase.getInt(fbdo, "/devices/Keys/level"))
  {
    if (fbdo.dataType() == "int")
    {
      level = fbdo.intData();
      Serial.println(level);
      _isUpdated = true;
    }

  }
  else
  {
    Serial.println(fbdo.errorReason());
  }
  
  if (Firebase.getBool(fbdo, "/devices/Keys/state"))
  {
    if (fbdo.dataType() == "boolean")
    {
      state = fbdo.boolData();
      Serial.println(state);
      _isUpdated = true;
    }

  }
  else
  {
    Serial.println(fbdo.errorReason());
  }
  
  if(_isUpdated)
    analogWrite(LED, state?level:0);
}
