boolean value;
#include "thingProperties.h"
#include <Wire.h>
#include <MPU6050.h>
#include <ESP32Servo.h>
//#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

MPU6050 mpu;
Servo myservo1;  
Servo myservo2;  

float roll, pitch, yaw;
int16_t accX, accY, accZ;
int16_t gyroX, gyroY, gyroZ;
float rollAcc, pitchAcc;
float dt = 0.01; 
float alpha = 0.98; 
 int servoPos1;
   int servoPos2;
long lastTime;

void setup() {
  Serial.begin(115200);
	delay(1500); 
	initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  Wire.begin();
  mpu.initialize();

  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed!");
    while (1);
  }

  myservo1.attach(5); 
  myservo2.attach(6);  

  Serial.println("MPU6050 connected!");
  lastTime = millis();
}

void loop() {
	ArduinoCloud.update();
   mpu.getMotion6(&accX, &accY, &accZ, &gyroX, &gyroY, &gyroZ);
  rollAcc = atan2(accY, accZ) * 180.0 / PI;
  pitchAcc = atan2(-accX, sqrt(accY * accY + accZ * accZ)) * 180.0 / PI;
  long now = millis();
  dt = (now - lastTime) / 1000.0;
  lastTime = now;
  float gyroRoll = gyroX * dt / 131.0;  
  float gyroPitch = gyroY * dt / 131.0;
  roll = alpha * (roll + gyroRoll) + (1.0 - alpha) * rollAcc;
  pitch = alpha * (pitch + gyroPitch) + (1.0 - alpha) * pitchAcc;
 servoPos1 = map(pitch, -90, 90, 180, 0);
 servoPos2 = map(roll, -90, 90, 180, 0);
  myservo1.write(servoPos1);
  myservo2.write(servoPos2);
  Serial.print("Pitch: ");
  Serial.print(pitch);
  Serial.print("°, Roll: ");
  Serial.print(roll);
  Serial.print("°, Servo1 Position: ");
  Serial.print(servoPos1);
  Serial.print(", Servo2 Position: ");
  Serial.println(servoPos2);
pitch_IoT = pitch;
roll_IoT = roll;
servo1_IoT = servoPos1;
servo2_IoT = servoPos2;
  delay(10);  
}
