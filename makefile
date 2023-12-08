# Jason Lin's Project-02 Makefile
# 10/21/2023
# CPSC1070
compile:
	make date
	make pizzaStore
	make pizzaWar
	g++ -Wall driver.cpp *.o -o battle.out
date:
	g++ -Wall -c Date.cpp
pizzaStore:
	g++ -Wall -c PizzaStore.cpp
pizzaWar:
	g++ -Wall -c PizzaWars.cpp
run:
	./battle.out
clean:
	rm *.out Date.o PizzaStore.o PizzaWars.o
