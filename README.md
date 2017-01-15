# memoco_ex
Exercises for 2016/2017 MEMOCO course @University of Padua

## PART I - Exact methods

You can build and run several types of instances for the part I of the
exercises.

### 3-4-5 hard-coded instance

You can build a pitagorian 3-4-5 instance by entering the following command in
the `ex1_drilling` folder:

    bash scripts/run_345.sh

Holes will be placed as a right-angled triangle with 3, 4 and 5 as the sizes of
its sides.

### Random uniform instance

You can build a uniform random instance by entering the following command in
the `ex1_drilling` folder:

    bash scripts/run_ru.sh <no_of_holes> <board_size_factor>

Where `no_of_holes` is the parameter for the number of holes (you should put an
integer number in it) and `board_size_factor` is a multiplier for the board
dimension.
