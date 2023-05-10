# Smart-Home-using-Atmega32
- There are 2 AVR Atmega32 MCUs acting as Master

& Slave.

- Software Architecture: Layered Architecture.

   1) Application Layer.

   2) LIB: STD_Types, Bit_Math.

   3)HAL: RTC(DS1307), EEPROM (24AA08), LDR, LM35,16x2, LCD,

              Keypad, Servo Motor, DC Motor, NPN Transistor, Push             

              Button, LEDs, Buzzer.         

  4) MCAL: DIO, ADC, EXTI, Timers, PWM, SPI, I2C.



- Master MCU interfaces with the user using Keypad and the LCD and is responsible for managing system security. It interfaces with the EEPROM Module and RTC using I2C communication protocol.



Slave MCU is responsible for home managing features such as conditioning system, outer light system, garden pump and emergency system using sensors and actuators.

- SPI communication protocol is used for communication between Master MCU and Slave MCU.
