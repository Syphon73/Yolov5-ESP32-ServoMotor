# Yolov5-ESP32-ServoMotor
This project demonstrates a real-time AI-powered object detection system that integrates YOLOv5 with an ESP32 microcontroller to control a servo motor over Wi-Fi.

## 🚀 Overview

- YOLOv5 detects objects from webcam input in Python.
- On detecting a target (e.g., "banana"), it sends a POST request to ESP32 via Wi-Fi.
- ESP32 runs an HTTP server and controls a servo motor upon receiving the request.

## 🛠️ Hardware Required

- ESP32 Dev Board
- Servo Motor (e.g., SG90)
- Jumper wires, Breadboard
- 5V Power Supply for Servo
- PC with camera and Python installed

## 🧠 How It Works

1. Run `detect.py` in Python with YOLOv5 model.
2. When a banana is detected:
   - Python sends `POST /detect` to ESP32 server.
3. ESP32 receives `"banana"` and rotates the servo to 90°, holds 2 seconds, returns to 0°.

## ⚙️ Setup Instructions
ESP32 to Servo connections
![image](https://github.com/user-attachments/assets/8357e217-e413-436f-824a-22ce5357545c)

### 1. YOLOv5 on PC

```bash
git clone https://github.com/ultralytics/yolov5.git
cd yolov5
pip install -r requirements.txt
```
### 2. Run yoloservo.ino
make sure the webserver is live (serial monitor logs)
```bash
Connected to WiFi.
192.168.1.102
HTTP server started

```
### 3. Update detect.py file
Uses requests module to contact the ESP32 web server
```bash
import requests
```
code to be updated inside the detection loop after class name extraction

```bash
ESP32_URL = "http://192.168.1.102/detect"  # Replace with your ESP32's IP
if names[c] == "banana":
try:
requests.post(ESP32_URL, data=names[c])
print("sent banana to esp32")
except Exception as e:
print(f"[!] Failed to send to ESP32: {e}")

```

### 4. Run Detection
```bash
python detect.py --source 0 --weights yolov5s.pt --conf 0.25 --view-img
```
