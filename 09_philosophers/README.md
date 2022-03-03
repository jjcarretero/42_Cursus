# Philosophers

*I’ve never thought philosophy would be so deadly*

![125/100 score](./philosophers_success.png)

In this project, you will learn the basics of threading a process. You will learn how to make threads. You will discover the mutex.

## Statement

One or more philosophers are sitting at a round table either eating, either thinking, either sleeping. While they are eating, they do not think or sleep; while thinking
they don’t eat or sleep; and, of course, while sleeping, they do not eat or think.

The philosophers sit at a circular table with a large bowl of spaghetti in the center.

There are some forks on the table. Serving and eating spaghetti with a single fork is very inconvenient, so the philosophers will eat with two forks, one for each hand.

Each time a philosopher finishes eating, they will drop their forks and start sleeping. Once they have finished sleeping, they will start thinking. The simulation stops
when a philosopher dies.

Every philosopher needs to eat and they should never starve.

Philosophers don’t speak with each other.

Philosophers don’t know when another philosopher is about to die.

No need to say that philosophers should avoid dying!

### Mandatory:

Each philosopher should be a thread.

One fork between each philosopher, therefore if they are multiple philosophers, there will be a fork at the right and the left of each philosopher.

To avoid philosophers duplicating forks, you should protect the forks state with a mutex for each of them.


### For bonus:

All the forks are in the middle of the table.

They have no states in memory but the number of available forks is represented by a semaphore.

Each philosopher should be a process and the main process should not be a philosopherEnemy patrols that cause the player to lose in case of contact.

##

Enjoy!
