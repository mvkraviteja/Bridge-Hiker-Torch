# Bridge-Hiker-Torch
Trying to build a solution for the bridge-hiker-torch puzzle in C++


FILES INCLUDED :
  - Notes : Indicating the effort in timeline and strategy used to addressing the problem at hand
  - bridgeTorch.cpp
      - Used a single file to define all the classes for seggregating the problem in to managebale objects.
   

Strategy used to resolve the problem at hand and identify a strategy to help calculate the time it would take for people to cross the bridge optimally is to have the hikers with fastest speed help getting the torch back to people that need to cross the bridge.
      - The optimization that can be done to the current provided solution is to continue to identify the fastest hiker that has already crossed the bridge and assign him the job of crossing the bridge multiple times (pass the torch to the fastest hiker always vs passing the torch to the next available faster hiker)

P.S : Have to get the YAML read working and change the test-cases to read in from there
(also to add new test cases - have to add hikers and bridges to the environment by calling in the objects)
Example : 
...

    environment.addBridge(250); // Allows for adding a bridge of length 250 ft
    environment.updateBridgeCount();
    environment.addHiker(2.5); // Allows for adding a hiker with speed 2.5 ft/minute
    environment.updateHikerCount();
...
