# X-Ray-Project
MyProjectXRay is a C++ application that processes .ppm medical images, applying X-ray-like transformations based on user input. It allows customization of intensity levels and outputs the processed image. Built to demonstrate basic image processing and C++ command-line handling.

# MyProjectXRay

**MyProjectXRay** is a simple C++ program that processes a medical image file (`.ppm` format) and applies a transformation based on user input. It's designed as a learning project to demonstrate image file handling, basic processing, and command-line input in C++.

---

## 📁 Project Structure
MyProjectXRay/
├── src/ # C++ source files
│ ├── main.cpp
| |__EdgeFilter.cpp
| |__EdgeFilter.h
| |__Filter.cpp
| |__Filter.h
| |__Image.cpp
| |__Image.h
| |__MyProjectXRay
| |__My
├─images
│ ├── Chest2.ppm # Input image
│ └── Chest.ppm # Output image
| |___Brain.ppm
├── MyProjectXRay.exe # Compiled application (Windows)
├── run.bat # Batch file to compile & run the app
├── README.md
└── .gitignore


---

## 🛠️ How to Build

If you're using **Windows** and have **g++ installed** (via MinGW or similar), open a terminal or double-click the `run.bat` file:

```bash
run.bat

Or manually compile:
g++ -o MyProjectXRay.exe src\*.cpp


🚀 How to Run
Run the program with the input .ppm image and an intensity level (e.g., 2):
MyProjectXRay.exe assets\Chest.ppm 2 > assets\image.ppm

Input: Chest.ppm (an image file in PPM format)
Output: image.ppm (processed result)
Parameter: a number from 1–5 to apply different transformations
