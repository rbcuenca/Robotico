# The  *ROBÓTICO*  Arduino robot

This project starts with my little child idea to create his own robot, called Robótico, by herself.

She has only 4 years at the momment (May, 2022), so daddy help her to accomplish the idea. 
We use some different softwares for android, so you can use that you like.. The important thing is to configure the commands at the program.
Now, you should use (to plug and play the code):
*Every Character is UPPERCASE! It's important!!
Forward: Character F
Backward: Character B
Left: Character L
Right: Character R
[Optional] Front-Left: Character G
[Optional] Front-Right: Character I

We used some parts I brought some time late:

- Four motors chassis;
- Four motors kits with Weels and Reduce Gear
- Battery 6V/4.5Ah Pb Battery;
- Arduino UNO;
- Protoboard Shield;
- HC05 Bluetooth Module;
- L298N for DC Motor control;
- Some software that work with android tablet.

The first idea was to make a line follower, but she want to "play" with them, so we use the Bluetooth to control with her tablet, the second and third steps will to use a joystick (I didn't chose if we'll use another Arduino or some Bluetooth controller) and then implement the line follower.

Later then, we'll change the Arduino to a RapberryPI3 with ROS to control with camera and vision computing (one day.. ;-) )

Lets work with code ;-) Now I'll explain the code parts. You can clone this repository and have all the files, but ir you'll fork or share, please reference me!
