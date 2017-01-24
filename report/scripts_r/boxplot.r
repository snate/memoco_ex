# Sample boxplot for Tsp12 data

tunings = c("Avg", "BE", "Mut", "NH", "Time")
avg = c(101.2, 87.9, 87.1, 83.3, 94.8, 93.8, 96.8)
big = c(85, 95.1, 93.2, 102.8, 88.4, 93.1, 78.8)
mutation = c(102.9, 92, 96, 87.6, 97.6, 83.7, 86.9)
no_heur = c(101.5, 90.9, 96.1, 93.6, 98.7, 94.8, 91.4)
time = c(75, 65, 75, 70.3, 71.5, 77.8, 68.6)
boxplot(avg, big, mutation, no_heur, time,
        main="Obj fun value for Tsp12",
        xlab="Calibration")
axis(1, at=1:5, labels=tunings)
