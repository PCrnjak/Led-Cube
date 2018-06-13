# Led-Cube

[![34053068_1499386373505176_169624549329993728_n](https://user-images.githubusercontent.com/30388414/40851342-6bceb6f2-65c7-11e8-82b1-2a388cab09af.jpg)](https://www.youtube.com/watch?v=qzwoztolV-c)



# **Intro**

Small and compact led cube powered by usb  that is (kinda) easy to build.I decided to make this project for my own amusement and to train smd soldering and pcb design. Code and program are not made  by me all credit goes to: http://www.instructables.com/id/LED-CUBE-CODE-4x4x4-Arduino/ .

# **Contents**

# **Bill of materials**
  [ Bill of materials](https://github.com/Ropecar5/Led-Cube/blob/master/BILL%20OF%20MATERIALS.txt)
# **Making boards**
in [GBRLS](https://github.com/Ropecar5/Led-Cube/tree/master/GRBLS) folder there are all grbl files needed to make boards for led cube.
you will need to make 2 boards ,one top one on wich you will place your led cube and one bottom one that has all electronics.
There are also Eagle schematic and board files for both pcbs . I ordered them [JLC pcb](https://jlcpcb.com/) and they came fine.
![8253991a-6bf4-496f-b503-892c4d37bfae](https://user-images.githubusercontent.com/30388414/40852599-364db718-65cb-11e8-89c3-0b44dfcc94bc.jpg)

# **Soldering components**
 Well you will need to have some skills with soldering iron and solder all those smd components. Hardest part is soldering leds .You will need to cut 16 3mm holes that are 1.5 mm one from another on peace of cardboard. This will keep all leds at exact distance and make soldering easier.you will need to solder all 4 led planes with magnet wire to pcb board.
 
 # **Burning Arduino bootlaoder**
 Maybe you can find those smd atmega 328 with already burnt bootloader or you can burn it yourself. I made a mistake on board and didnt want to redo it so to burn bootloader follow these instructions.![ledkocka bootloader](https://user-images.githubusercontent.com/30388414/40853525-ae76581e-65ce-11e8-86de-0de6731c919b.jpg)
 solder wires like shown in picture ,  and connect them to ftdi programmer .
Miso to miso , mosi to mosi , sck to sck , gnd to gnd ,vcc to vcc,DTR ON LED BOARD is not dtr .
Connect dtr from ftdi programmer to wire that is shown on picture.Cap on picture is 47 uF.


# **Code**
Once again code is not written by me. There are 2 example programs [LEDFADE](https://github.com/Ropecar5/Led-Cube/tree/master/LEDFADE) and
[shooting star](https://github.com/Ropecar5/Led-Cube/tree/master/shooting_star).[LCCG.exe](https://github.com/Ropecar5/Led-Cube/blob/master/LCCG.exe) is program used to generate patterns in wich cube will light up.  To upload code you will need FTDI usb to TTL serial converter that connects to corresponding pins on board.
# **Case**
[STL](https://github.com/Ropecar5/Led-Cube/tree/master/files) file. Printed on cheap chinese prusa clone with 0.2 mm layer height.


