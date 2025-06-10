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
### 2. Run Detection
```bash
python detect.py --source 0 --weights yolov5s.pt --conf 0.25 --view-img
```
