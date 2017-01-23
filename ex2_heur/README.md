# PART II - Heuristic

Here you can run, with different configurations, a genetic algorithm that was
developed for the part II of the memoco exercises.

## Run GA on different instances

You can solve a Pythagorean 3-4-5 instance by entering the following command in
this folder:

    bash scripts/run/run_<instance>.sh <configuration>

Where:
* `instance`: is one of the instances available (*345*, *gerber*, *rg*,
  *rg_Manh*, *ru*, *tsp12*, *tsp60*). __IMPORTANT: place in the `instances/`
  folder the files present in the `../ex1_drilling/instances` folder, if the desired instance is not already present in the `instances/` folder__
* `configuration` is a full path to a file used for configuration.
  Configuration files are described below.

### Configuration files

Configuration files are composed as follows:

    <population_size>
    <time_limit>
    <mutation_prob>
    <init_sa>
    <elite>

Where:
* *population_size* is the size of the population for the genetic algorithm;
* *time_limit* is the timeout used as stopping criterion;
* *mutation_prob* is the probability for a mutation to occur for each element
  of the population;
* *init_sa* is the number of elements generated at first with Simulated
  Annealing;
* *elite* is the size of the elite, i.e. the best elements of the population
  which are not involved in replacement at each iteration of the algorithm.
