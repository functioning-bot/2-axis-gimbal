# IoT-Enabled 2-Axis Gimbal System

This project is a low-cost, IoT-enabled 2-axis gimbal stabilizer designed to keep a mounted object (like a camera) steady by correcting motion along the pitch and roll axes. It uses an Arduino Nano ESP32, an MPU6050 motion sensor, and two servo motors to achieve real-time stabilization. Orientation data and servo positions are sent to the Arduino IoT Cloud, allowing the system to be monitored remotely from any device with internet access.

We built this as part of our undergraduate mini project to explore embedded control systems and IoT integration for real-time motion correction in robotics and imaging applications.

## What it does

- Measures pitch and roll using the MPU6050 motion sensor  
- Applies a complementary filter to smooth sensor data  
- Controls two servo motors to actively correct tilt  
- Uploads orientation and servo data to the Arduino IoT Cloud  
- Uses a 3D-printed chassis to support the hardware with precise alignment  

## Why this project?

Stabilization is essential in robotics, drone imaging, and handheld video systems. While commercial gimbals can be expensive and inflexible, this project shows how affordable components and open-source tools can be combined to build a customizable, cloud-connected gimbal system. The IoT integration adds remote visibility, making the system both educational and practical.

## How it works

The MPU6050 continuously sends acceleration and gyroscopic data to the Arduino Nano ESP32 via I2C communication. A complementary filter is applied to calculate stable pitch and roll angles. These angles are mapped to servo motor positions, which then physically correct the tilt of the platform. Orientation and servo data are transmitted to the Arduino IoT Cloud, where they are displayed in real time through a customizable dashboard.

## Components used

- Arduino Nano ESP32  
- MPU6050 motion sensor (accelerometer + gyroscope)  
- Two SG90 or MG90 servo motors  
- Voltage regulators and capacitors for power management  
- Breadboard and jumper wires for prototyping  
- Custom 3D-printed chassis (printed with a Bambu Labs A1 printer)  
- Power source (USB or battery)  

## Software and Libraries

- Arduino IDE for programming  
- `Wire.h` for I2C communication  
- `MPU6050.h` for sensor data access  
- `ESP32Servo.h` for PWM control of servos  
- `ArduinoIoTCloud.h` and `Arduino_ConnectionHandler.h` for cloud communication  

## IoT Cloud Features

- Live pitch and roll angle display  
- Real-time servo position monitoring  
- Remote access via desktop or mobile browser  
- Automatic reconnection in case of Wi-Fi drop  

## Future ideas

- Add yaw axis for 3-axis stabilization  
- Replace complementary filter with Kalman filter for more accurate sensor fusion  
- Add manual control using joystick or mobile app  
- Use brushless motors for smoother, more precise motion  
- Add onboard data logging and battery monitoring  

## Developed by

Sai Preeth Aduwala  
Alekhya Marini  
Uday Kumar Reddy Pesala  

Department of General and Computer Engineering  
San Jose State University
