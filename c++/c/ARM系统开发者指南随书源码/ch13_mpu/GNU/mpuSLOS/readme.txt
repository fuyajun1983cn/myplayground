
mpuSLOS

  mpuSLOS is a version of the SLOS operating system that makes use of the 
  ARM memory protection unit.

Processor Supported

  ARM940T

Board Supported

  ARM Integrator/AP

Host Platform

  Microsofts Windows XP

Build Process

  To build mpuSLOS you need to have GNU tools installed, as well as the make 
  utility.
  
  GNU tools version
  
  arm-elf-gcc (GCC) 3.3.1
  GNU ld version 2.14 20030612
  GNU assembler 2.14 20030612


  1. CD into the mpuSLOS directory

  2. Type: make all or build.bat at the command prompt.

  If there are no errors the binary image is placed into build/image 
  directory and is given the name slos.bin. slos.bin can then be loaded 
  and executed on an Integrator/AP with ARM940T core module. 







 