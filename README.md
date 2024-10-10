# Embedded Snake Game using Linux Kernel, Device Tree, I2C OLED Display on BeagleBone Black

## Summary:
This project demonstrates the development of a Snake Game on the BeagleBone Black platform. The game interfaces with an OLED SSD1306 display using I2C communication and configures hardware interfaces via the Linux Kernel Device Tree. The project showcases key skills in embedded systems, Linux device driver development, low-level hardware interaction, and hardware-software integration.

## Project Structure:
├── bin # Directory for the compiled executable files.

├── button_driver # Directory containing the button driver source code and Makefile. 

├── oled_driver # Directory containing the SSD1306 OLED driver source code and Makefile 

├── obj # Directory for storing object files during the build process. 

├── inc # Directory for the header files (.h files).

├── src # Directory for the main source code files (.c files).

└── lib # Directory for the static and shared library files (.a or .so files).

## Hardware Configuration
### Button Pinout:
- `GND`: Connected to P9_02
- `Up`: Connected to P8_13
- `Down`: Connected to P8_10
- `Left`: Connected to P8_12
- `Right`: Connected to P9_02
- `Enter`: Connected to P9_02

### OLED SSD1306 I2C Pinout:
- `GND`: Connected to P9_01
- `VCC`: Connected to P9_07
- `SCK`: Connected to P9_19
- `SDA`: Connected to P9_20

## Build Instructions
### On Ubuntu:
1. **Button Driver:**
   - Navigate to the `button_driver` directory.
   - Run `make` to build the `button_driver.ko` file.
   - Transfer the `button_driver.ko` file to the BeagleBone Black.

2. **OLED Driver:**
   - Navigate to the `oled_driver` directory.
   - Run `make` to build the `ssd1306_oled_driver.ko` file.
   - Transfer the `ssd1306_oled_driver.ko` file to the BeagleBone Black.

3. **Main Program Build:**
   - **Static Library:**
     - Run `make sta_all` to build the executable file named `main` in the `bin/` directory.
     - Transfer the `main` file to the BeagleBone Black.
   - **Shared Library:**
     - Run `sudo make shared_all` to build the executable file named `main_shared` and the shared library.
     - Transfer both the `main_shared` file and the shared library to the BeagleBone Black.

### On BeagleBone Black:
1. **Insert the Button Driver:**
   - Run `sudo insmod button_driver.ko` to insert the button driver module into the kernel.

2. **Insert the OLED Driver:**
   - Run `sudo insmod ssd1306_oled_driver.ko` to insert the OLED driver module into the kernel.

3. **Run the Game:**
   - **Using Static Library:**
     - Run `./main_static` to launch the game.
   - **Using Shared Library:**
     - Copy the shared library file to the same directory as `main_shared`.
     - Run `./main_shared` to launch the game.

## Notes:
- Ensure that all necessary dependencies are installed before compiling the drivers and the main program.
- Double-check the hardware connections to the BeagleBone Black to avoid errors during driver insertion or program execution.
  
## Demo:
You can view the demo of the project here: [Watch on YouTube](https://youtu.be/nwtFyOQk7lc)

