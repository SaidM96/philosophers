# The dining philosopher's problem
![shapes-1](https://github.com/Mushigarou/Philosophers/assets/115739322/2c538004-ddde-428e-a1ae-bde719fe3737)

## Overview :
- One or more philosophers sit at a round table.
There is a large bowl of spaghetti in the middle of the table.
- The philosophers alternatively eat, think, or sleep.
While they are eating, they are not thinking nor sleeping;
while thinking, they are not eating nor sleeping;
and, of course, while sleeping, they are not eating nor thinking.
- There are also forks on the table. There are as many forks as philosophers.
- Because serving and eating spaghetti with only one fork is very inconvenient, a
philosopher takes their right and their left forks to eat, one in each hand.
- When a philosopher has finished eating, they put their forks back on the table and
start sleeping. Once awake, they start thinking again. The simulation stops when
a philosopher dies of starvation.
- Every philosopher needs to eat and should never starve.
- Philosophers don’t speak with each other.
- Philosophers don’t know if another philosopher is about to die.

## Usage :

```
$> make
$./philo 5 800 200 200
```
## Rules :
The program should take the following arguments:
```
$> ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
- number_of_philosophers: The number of philosophers and also the number
of forks.
- time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die
milliseconds since the beginning of their last meal or the beginning of the sim-
ulation, they die.
- time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.
- time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.
- number_of_times_each_philosopher_must_eat (optional argument): If all
philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies.
- Each philosopher has a number ranging from 1 to number_of_philosophers.
- Philosopher number 1 sits next to philosopher number number_of_philosophers.
Any other philosopher number N sits between philosopher number N - 1 and philoso-
pher number N + 1.
- A message announcing a philosopher died should be displayed no more than 10 ms
after the actual death of the philosopher.

![Eating](https://github.com/Mushigarou/Philosophers/assets/115739322/cef600c6-d5e7-4776-9e25-655f0047d614)

## Contributing

Contributions to this project are welcome! If you find any issues or have improvements to suggest, please feel free to submit a pull request.
## License

This project is licensed under the MIT license
