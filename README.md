
# Philosophers: Dining Philosophers Problem

## Overview
The **Philosophers** project is an implementation of the classic Dining Philosophers Problem using threading and mutexes in C. The project simulates a group of philosophers sitting at a table with a bowl of spaghetti and a limited number of forks. Philosophers alternate between eating, thinking, and sleeping, ensuring no data races or deadlocks occur. 🍝🧵🕰️

## Features
- Multi-threaded simulation of philosophers' behavior.
- Mutex-based synchronization to manage shared resources (forks).
- Handles starvation prevention and ensures philosophers do not die unnecessarily.
- Optional bonus implementation using processes and semaphores.

## Program Details
- **Program Name:** `philo`
- **Arguments:**
  ```
  ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
  ```
  - `number_of_philosophers`: Number of philosophers and forks.
  - `time_to_die`: Maximum time (ms) a philosopher can go without eating before dying.
  - `time_to_eat`: Time (ms) a philosopher spends eating.
  - `time_to_sleep`: Time (ms) a philosopher spends sleeping.
  - `number_of_times_each_philosopher_must_eat` (optional): Ends the simulation once all philosophers have eaten the specified times. 🍽️🕒🛌

## Logs
All actions of philosophers are logged in the following format:
```plaintext
[timestamp_in_ms] [philosopher_id] [action]
```
- Actions:
  - `has taken a fork`
  - `is eating`
  - `is sleeping`
  - `is thinking`
  - `died`

📜⏱️👨‍💻

## Requirements
- Written in C.
- Adheres to the 42 Norm.
- No memory leaks or unexpected crashes.
- No race conditions or deadlocks.

## Running the Program
1. Clone the repository:
   ```bash
   git clone https://github.com/MohammadHusssein/42-philosophers.git
   cd 42-philosophers/philo
   ```
2. Compile the program:
   ```bash
   make
   ```
3. Run the simulation:
   ```bash
   ./philo 5 800 200 200
   ```
   This command simulates 5 philosophers with the following parameters:
   - `time_to_die = 800 ms`
   - `time_to_eat = 200 ms`
   - `time_to_sleep = 200 ms`

👨‍🍳⏳💡

## Testing
Here are some general test cases to use:
[Philo tests](https://docs.google.com/spreadsheets/d/1CxXKwCUi4EaIyKyI7uoA18C4Vjk6BwmfoUPWIBgbkNg/edit?usp=sharing)

I encourage to come up with your own test cases and try to find any case that your program fails at. 🧪🖥️✅

## License
This project is licensed under the [MIT License](https://opensource.org/licenses/MIT). Feel free to use, modify, and distribute the code as long as proper attribution is given. 📜🔓✨

---
