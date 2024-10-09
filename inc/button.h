?/*
    // Check if BUTTON_H has not been defined, then define it to prevent multiple inclusion issues.
*/
#ifndef BUTTON_H
#define BUTTON_H

/* Standard C libraries */
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <ctype.h>         // Library for character type handling and conversion functions.
#include <string.h>
#include <sys/time.h>      // Library for retrieving system time information.
#include <sys/types.h>     // Library defining system data types.

// Linux-specific libraries for hardware device interactions
#include <stdlib.h>   // Standard library for memory management, conversions, etc.
#include <unistd.h>   // Unix system calls for file and process operations.
#include <fcntl.h>    // File descriptor operations (like opening and closing files).
#include <termios.h>  // Library for configuring terminal I/O (e.g., serial port communication).

// Define the path to the button device file for handling button inputs.
#define SSD1306_BUTTON_FILE "/dev/button_snake"

// Define constants representing directional buttons and the ENTER button.
#define UP          1
#define LEFT        2
#define RIGHT       3
#define DOWN        4
#define ENTER       5

// Function to open the button device file.
int Button_OpenDevFile();

// Function to read data from the button device file.
int Button_read(int fdt, char *buff, size_t size);

// Function to check if any button is pressed.
int Button_check_any_press(int fd, char *buff, size_t size);

// Function to process and identify which button was pressed from the buffer.
int Button_press(char *buff);

// Function to wait until any button is pressed.
int Button_waitForAnyKey(int fd, char *buff, size_t size);

// Function to convert pressed keys into the corresponding direction (up, down, left, right, or enter).
int Button_KeysPressed_to_Direction(int fd, char *buff, size_t size, int direction);

#endif
