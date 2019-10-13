#1. Embedded device example

Using the telegraph example, and the challenges listed in the module as reference, and describe another device that you would like to discuss. Describe how you think its embedded system works, and what design challenges it presents.

Answer: 

Motor controller could be an example. It is time sensitive in many applications, so a special communication protocol with time stamp is required. Higher data rate and computation speed are desired. Low power comsuption is another challenge. Because lower cost is always preferred, hardware resouces is limited. 
The controller stores control algorithms and motor parameters in its flash memory. It takes input command from PLC (Programmable logic controller) or other user interface, and output PWM signals to control motor's current. It talks to its peripherals through I2C, UART, SPI, and GPIOs. 
