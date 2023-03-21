# Elevator-model-arduino-Integrated
I have designed and developed an Arduino-based miniature elevator model with integrated sensors. The project involved creating a scaled-down version of a real elevator, complete with a working motor, pulleys, and cables to move the elevator up and down.

To ensure safety and reliability, the miniature elevator was equipped with sensors such as motion sensors. These sensors were integrated with the Arduino microcontroller to provide real-time feedback on the position and status of the elevator.

The project showcased my ability to apply my technical knowledge of microcontrollers, electronics, and programming to create a functional and realistic miniature model. It also demonstrated my attention to detail, as I carefully calibrated and tested each component of the model to ensure smooth and reliable operation.

Overall, the Arduino-based miniature elevator model with integrated sensors is an excellent example of my expertise in embedded systems engineering and my ability to develop innovative solutions to complex problems.

This is an elevator model Made for a University Model Fair
***

# Construction of the model
The model is made using a few pieces of 2X4 Pieces of the wood.
The wood is cut to make up the base of the of the project and the vertcal supports with a slit in between where the elevator will glide up and down.
The elevator here is a 2mm metal plate. The pullies and the stopper are placed in the appropriate locations.

***

# Electronics Used
The electronics used here are
1. Arduino UNO R3 With a basic shield
2. IR transmitter reciever
3. LCD display with I2C
4. Low RPM, High torque DC motor
5. 12V AC power supply
6. Toggle Switches
***

# Working Of the Model
The IR sensors are places on the different locations mimicking different floors.
When the model is booted up, there is an initial calibration where the elevator moves to the lowest floor.
The Toggle switches are wired for the respective floors. When the button for a floor is pressed, the elevator moves to the appropriate floor.
A built in safety feature is when a elevator is in any single floor and the postion of the elevator gets misplaces, the elevator moves to the floor one below from which the elevators last position was.
The display shows current floor and the ascending and descending status of the elevator. It also shows the calibraton and if the elevator has been misplaced, it gives the error message.

The arduino, senors can be powered over usb power, the 12V DC power supply is for the motor.


[pic1]: Elevator-model-arduino-Integrated/005.JPG
[pic2]: Elevator-model-arduino-Integrated/004.JPG
