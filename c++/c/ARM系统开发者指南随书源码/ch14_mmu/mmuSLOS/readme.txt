
mmuSLOS

  mmuSLOS is a version of the SLOS operating system that makes use of the 
  ARM memory management unit.

Processor Supported

  ARM920T

Board Supported

  ARM Integrator/AP

Host Platform

  Microsofts Windows XP

Build Process

  To build mmuSLOS you need to have ARM Developers Suite v1.2 installed,
  as well as the make utility.

  1. CD into the mmuSLOS directory

  2. Type: make all at the command prompt.

  If there are no errors the binary image is placed into build/image 
  directory and is given the name slos.bin. slos.bin can then be loaded 
  and executed on an Integrator/AP with ARM920T core module. 







 