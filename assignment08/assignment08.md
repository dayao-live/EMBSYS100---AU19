# EMBSYS100 - AU19 ASSIGNMENT 08
### Goal
The goals for the assignment this week:
1. Explore the use of PWM on our NUCLEO-F401RE board.

### Problems:
1. Bonus:
* a. Study the tutorial: https://www.waveshare.com/wiki/STM32CubeMX_Tutorial_Series:_PWM
* b. Use the STM32CubeMx similar to what’s described in the tutorial in order to generate the code that connects one of the PWM channels to our user LED.
* c. Modify the code generated similar to the tutorial in order to control the LED blinking and brightness.
* d. Create a video demonstrating the brightness of the LED changing overtime.
* e. Submit your video along with your entire IAR project to your GitHub.
__Video and entire IAR project have been submitted.__
* f. Describe one problem you encountered
__After implementing the code following the tutorial, it is found that the PWM period is too long. To reduce PWM period, "htim2.Init.Prescaler" is reduced from "1080-1" to "54-1";__
