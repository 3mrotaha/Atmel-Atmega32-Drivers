# ATmega32 Microcontroller Drivers
these drivers follows the 'layered Architecture' which is a common design pattern used in software development that offers a number of benefits, including:

- 'Separation of concerns': Each layer has a distinct responsibility or function, which promotes a clear separation of concerns and makes the code easier to    understand, maintain, and modify.
- 'Reusability': By separating the code into layers, developers can reuse the code in other projects, reducing development time and effort.
- 'Scalability': Layered architecture allows for easier scalability because new layers can be added to accommodate new features or changes in requirements.
- 'Testability': With a clear separation of concerns, each layer can be tested independently, making it easier to identify and isolate errors.
- 'Modularity': Each layer can be developed and maintained independently, making it easier to add, remove, or modify functionality without affecting other layers.

This repository contains drivers for ATmega32 microcontroller peripherals, organized as follows:

## APP 

This folder contains application-specific code that interfaces with the drivers in the HAL and MCAL folders. It includes the `main.c` file, which is the main application code that uses the peripheral drivers to achieve the desired functionality.
## HAL 

This folder contains drivers for the hardware abstraction layer (HAL), which abstracts the hardware details of the ATmega32 peripherals and provides a consistent interface for the application to use. The HAL folder includes subfolders for each of the supported peripheral types, including:

- `DC_Motor`: This folder contains the driver files for controlling a DC motor.
- `KeyPad`: This folder contains the driver files for reading input from a keypad.
- `LCD`: This folder contains the driver files for controlling an LCD display.
- `LED`: This folder contains the driver files for controlling an LED.
- `SevenSegment`: This folder contains the driver files for controlling a seven-segment display.
- `Switch`: This folder contains the driver files for reading input from a switch.

## LIB 

This folder contains header files for common utilities used throughout the driver code, including bit-level operations, error states, general-purpose registers, and standard types.

## MCAL 

This folder contains drivers for the microcontroller abstraction layer (MCAL), which provides low-level access to the ATmega32 peripherals. The MCAL folder includes subfolders for each of the supported peripheral types, including:

- `ADC`: This folder contains the driver files for the analog-to-digital converter (ADC).
- `DIO`: This folder contains the driver files for the digital I/O pins.
- `EX_Interrupt`: This folder contains the driver files for external interrupts.
- `SPI`: This folder contains the driver files for the serial peripheral interface (SPI).
- `Timer0`: This folder contains the driver files for timer/counter 0.
- `Timer1`: This folder contains the driver files for timer/counter 1.
- `Timer2`: This folder contains the driver files for timer/counter 2.
- `UART`: This folder contains the driver files for the universal asynchronous receiver/transmitter (UART).

Each peripheral driver folder includes header files (`*.h`), source files (`*.c`), and private header files (`*_priv.h`). The header files define the public interface of the driver, while the source files implement the functionality of the driver. The private header files contain internal declarations used by the driver implementation but not exposed to the application.

The drivers are designed to be used with the Atmel Studio development environment and are written in C programming language. The user can include the required header files and use the provided functions to interact with the ATmega32 peripherals.
