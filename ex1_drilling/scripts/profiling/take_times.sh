holes=$1
size=$2
divisions=$3
for (( i = 0; i < 7; i++ )); do
	bash scripts/run/run_ru.sh $holes $size
	bash scripts/run/run_rg.sh $holes $size $divisions
	bash scripts/run/run_rg_Manh.sh $holes $size $divisions
	bash scripts/run/run_345.sh
	bash scripts/run/run_tsp12.sh
	bash scripts/run/run_tsp60.sh
done