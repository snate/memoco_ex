# PART I - Exact method

Here you can build and run several types of instances for the part I of the
memoco exercises.

## 3-4-5 hard-coded instance

You can solve a Pythagorean 3-4-5 instance by entering the following command in
this folder:

    bash scripts/run/run_345.sh

Holes will be placed as a right-angled triangle with 3, 4 and 5 as the sizes of
its sides.

## Tsp12 hard-coded instance

You can solve a 12 holes TSP instance by entering the following command in this
folder:

    bash scripts/run/run_tsp12.sh

## Tsp60 hard-coded instance

You can solve a 60 holes TSP instance by entering the following command in this
folder:

    bash scripts/run/run_tsp60.sh

## Gerber instance

You can solve a TSP instance generated from a Gerber file by entering the
following command in this folder:

    bash scripts/run/run_gerber.sh

You may also enjoy to view the board and where holes are placed on it by opening
`gen/gerber.html` in a browser by clicking on `Choose Files` and selecting the
file `gen/gerber_files/three-components.gbr`.

## Random uniform instance

In order to create a random uniform instance you have to run this command in
this folder:

    bash scripts/generation/generateRandomData_ru.sh <no_of_holes> <board_size_factor>

Where:
* `no_of_holes`: parameter for the number of holes (you should put an
  integer number in it);
* `board_size_factor` is a multiplier for the board dimension.

You can then solve the TSP instance just created by entering the following
command in this folder:

    bash scripts/run/run_ru.sh

## Random grid uniform instance

In order to create a random grid uniform instance you have to run this command
in this folder:

    bash scripts/generation/generateRandomData_rg.sh <no_of_holes> <board_size_factor> <divisions>

Where:
* `no_of_holes`: parameter for the number of holes (you should put an
  integer number in it);
* `board_size_factor` is a multiplier for the board dimension;
* `divisions` is the number of divisions *per side* in the board.

You can then solve the TSP instance just created by entering the following
command in this folder:

    bash scripts/run/run_rg.sh

## Random grid uniform instance with Manhattan distance

In order to create a random grid uniform instance with Manhattan distance you
have to run this command in this folder:

    bash scripts/generation/generateRandomData_rg_Manh.sh <no_of_holes> <board_size_factor> <divisions>

Where:
* `no_of_holes`: parameter for the number of holes (you should put an
  integer number in it);
* `board_size_factor` is a multiplier for the board dimension;
* `divisions` is the number of divisions *per side* in the board.

You can then solve the TSP instance just created by entering the following
command in this folder:

    bash scripts/run/run_rg_Manh.sh
