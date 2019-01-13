# Author:  Marie Knapp
# Makefile for Final Project
#*****************************

CXX = g++
CXXFLAGS = -Wall -g -std=c++11
#****************************

main: main.o Space.o intValid.o Menu.o Myrtle.o Elliott.o Cecily.o Player.o Hulk.o Xena.o WallClimb1.o Tightrope2.o Rings3.o GauntletOfHammers4.o Zipline5.o Snakepit6.o TrapezeTraverse7.o DeepDive8.o MovingBridges9.o RopeClimb10.o FoamPit11.o VictoryLap12.o
	$(CXX) $(CXXFLAGS) -o main main.o Space.o intValid.o Menu.o Myrtle.o Elliott.o Cecily.o Player.o Hulk.o Xena.o WallClimb1.o Tightrope2.o Rings3.o GauntletOfHammers4.o Zipline5.o Snakepit6.o TrapezeTraverse7.o DeepDive8.o MovingBridges9.o RopeClimb10.o FoamPit11.o VictoryLap12.o

main.o: main.cpp
		$(CXX) $(CXXFLAGS) -c main.cpp

Menu.o: Menu.hpp intValid.hpp Space.hpp Player.hpp

Space.o: Space.hpp intValid.hpp Menu.hpp Player.hpp

intValid.o: intValid.hpp

Player.o: Player.hpp Space.hpp intValid.hpp

Myrtle.o: Myrtle.hpp Player.hpp

Elliott.o: Elliott.hpp Player.hpp

Cecily.o: Cecily.hpp Player.hpp

Hulk.o: Hulk.hpp Player.hpp

Xena.o: Xena.hpp Player.hpp

WallClimb1.o: WallClimb1.hpp Space.hpp intValid.hpp Player.hpp

Tightrope2.o: Tightrope2.hpp Space.hpp intValid.hpp Player.hpp

Rings3.o: Rings3.hpp Space.hpp intValid.hpp Player.hpp

GauntletOfHammers4.o: GauntletOfHammers4.hpp Space.hpp intValid.hpp Player.hpp

Zipline5.o: Zipline5.hpp Space.hpp intValid.hpp Player.hpp

Snakepit6.o: Snakepit6.hpp Space.hpp intValid.hpp Player.hpp

TrapezeTraverse7.o: TrapezeTraverse7.hpp Space.hpp intValid.hpp Player.hpp

DeepDive8.o: DeepDive8.hpp Space.hpp intValid.hpp Player.hpp

MovingBridges9.o: MovingBridges9.hpp Space.hpp intValid.hpp Player.hpp

RopeClimb10.o: RopeClimb10.hpp Space.hpp intValid.hpp Player.hpp

FoamPit11.o: FoamPit11.hpp Space.hpp intValid.hpp Player.hpp

VictoryLap12.o: VictoryLap12.hpp Space.hpp intValid.hpp Player.hpp
