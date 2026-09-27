# ⚡ ESP32 Web Server & HTML LED Control

## 📌 ProtoSem — Week 7 | Task 1

This task demonstrates how to use an **ESP32 as a web server** to control its onboard LED through a **web browser**.

The ESP32 connects to a Wi-Fi network and hosts a simple HTML control interface. A laptop or mobile device connected to the same network can access the ESP32's IP address and control the LED remotely.

---

## 🎯 Task Objective

The main objective of this task is to:

* Connect the **ESP32 to a Wi-Fi network**
* Configure the ESP32 as a **web server**
* Create an **HTML-based control interface**
* Control the ESP32's onboard LED using a web browser
* Understand how **HTTP requests** can be used to control GPIO pins

---

## 🧠 Concepts Learned

### 1. ESP32 Web Server

The ESP32 connects to Wi-Fi and starts a web server on **port 80**.

Once connected, the ESP32 receives an IP address that can be entered into a web browser.

The browser then communicates directly with the ESP32.

### 2. Browser ↔ ESP32 Communication

The communication follows this process:

**Browser → Wi-Fi Network → ESP32 Web Server → GPIO → LED**

The browser sends HTTP requests to the ESP32, and the ESP32 responds by controlling the LED.

### 3. HTTP Routes

Two control routes are implemented:

* `/on` → Turns the LED ON
* `/off` → Turns the LED OFF

The ESP32 processes these requests and changes the GPIO output accordingly.

---

## 🔧 Hardware Used

| Component                   | Purpose                                     |
| --------------------------- | ------------------------------------------- |
| ESP32 Dev Module (WROOM-32) | Main controller and web server              |
| Micro-USB Cable             | Programming, power and serial communication |
| Laptop / PC                 | Programming and web browser control         |
| Wi-Fi Network               | Communication between ESP32 and browser     |

### LED Configuration

The project uses the **built-in LED of the ESP32**.

**LED GPIO Pin:** `GPIO 2`

No external LED or breadboard is required for this task.

---

## 💻 Software Used

* **Arduino IDE 2.3.10**
* **ESP32 Board Package by Espressif**
* **WiFi.h**
* **WebServer.h**
* Web browser

---

## ⚙️ System Architecture

```text
┌───────────────┐
│    Browser    │
│ Laptop / PC   │
└───────┬───────┘
        │
        │ HTTP Request
        ▼
┌────────────────┐
│   Wi-Fi Router │
└───────┬────────┘
        │
        │ Wi-Fi
        ▼
┌─────────────────────┐
│ ESP32 Web Server    │
│ Port: 80            │
└─────────┬───────────┘
          │
          │ GPIO 2
          ▼
┌─────────────────────┐
│   Onboard LED       │
└─────────────────────┘
```

---

## 🛠️ Implementation

The ESP32 program uses the following main components:

```cpp
#include <WiFi.h>
#include <WebServer.h>
```

The Wi-Fi credentials are configured in the program:

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";
```

The onboard LED is configured on GPIO 2:

```cpp
#define LED_PIN 2
```

A web server is created on port 80:

```cpp
WebServer server(80);
```

The ESP32 provides separate routes for controlling the LED:

```text
/on
/off
```

When `/on` is requested, the ESP32 sets GPIO 2 HIGH.

When `/off` is requested, the ESP32 sets GPIO 2 LOW.

---

## 🌐 Web Interface

A simple HTML interface is hosted directly by the ESP32.

The interface provides an interactive toggle control for switching the LED:

**LED OFF → LED ON**

and

**LED ON → LED OFF**

JavaScript sends the corresponding HTTP request to the ESP32 without requiring a separate application.

---

## 🚀 How the System Works

1. The ESP32 is connected to the computer using a USB cable.
2. The Wi-Fi name and password are entered into the Arduino sketch.
3. The program is uploaded to the ESP32.
4. The ESP32 connects to the configured Wi-Fi network.
5. The ESP32 receives an IP address.
6. The IP address is displayed in the Serial Monitor.
7. The IP address is entered into a browser on a device connected to the same Wi-Fi network.
8. The ESP32 web interface appears.
9. The browser sends commands to the ESP32.
10. The ESP32 controls the onboard LED through GPIO 2.

---

## 🖥️ Serial Monitor

The Serial Monitor is used to verify the Wi-Fi connection and obtain the ESP32's IP address.

The program communicates using:

```text
Baud Rate: 115200
```

After obtaining the IP address, it can be entered into a web browser to access the control page.

---

## 🧪 Testing

| Test                      | Expected Result                |
| ------------------------- | ------------------------------ |
| ESP32 powered ON          | Board starts successfully      |
| Wi-Fi credentials correct | ESP32 connects to Wi-Fi        |
| IP address displayed      | ESP32 web server is accessible |
| Open ESP32 IP in browser  | LED control page appears       |
| Select ON                 | Onboard LED turns ON           |
| Select OFF                | Onboard LED turns OFF          |

---

## 📚 Learning Outcomes

Through this task, the following concepts were learned:

* ESP32 Wi-Fi connectivity
* Basic web-server implementation
* HTTP request handling
* HTML web interfaces
* JavaScript-based control
* GPIO control through web requests
* Communication between a browser and an embedded device
* Using the Serial Monitor for network debugging

---

## ✅ Final Result

The ESP32 successfully operates as a **Wi-Fi-enabled web server**, allowing its onboard LED to be controlled remotely through a browser.

This task demonstrates the basic principle of **IoT device control through a web interface**, where a physical hardware component can be controlled using commands sent over a network.

---

## 📌 Project Information

**Program:** ProtoSem
**Week:** 7
**Task:** 1 of 5
**Project:** ESP32 Web Server & HTML LED Control
**Controller:** ESP32 Dev Module (WROOM-32)
**LED Pin:** GPIO 2
**Server Port:** 80
**Communication:** Wi-Fi + HTTP
