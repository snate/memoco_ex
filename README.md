# memoco_ex
Exercises for 2016/2017 MEMOCO course @University of Padua

## RUN TESTS

In the root folder of the project (here) you can run some scripts to measure
the performance of the two methods implemented for exercise.

### Measure performance on fixed instances

To measure the performance of the exact method on the fixed instances (*345*,
*tsp12*, *tsp60* and the *gerber* one), run the following command:

    bash run_on_fixed_instances_1.sh

To measure the performance of the genetic algorithm on the same instances as
above, run the following command:

    bash run_on_fixed_instances_2.sh

__These script are intended to be used to execute repeated measurings of the
program performance (7 by default), thus if you simply want to run the programs
just once to look how they behave, see below.__

### Measure performance on randomly generated instances

To measure the performance of both parts of the exercise on the randomly
generated instances (*random uniform*, *random grid uniform*, *random grid
uniform with Manhattan distance*), run the following command:

    bash run_on_random_instances.sh

__These script are intended to be used to execute repeated measurings of the
program performance (7 by default), thus if you simply want to run the programs
just once to look how they behave, see below.__

## PART I - Exact methods

You can build and run several types of instances for the part I of the
exercises looking at the README instructions in the `ex1_drilling/` folder.

## PART II - Meta-heuristics

You can build and run several types of instances for the part II of the
exercises looking at the README instructions in the `ex2_heur/` folder.
