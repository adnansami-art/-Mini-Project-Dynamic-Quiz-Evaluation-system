# Dynamic  Quiz  System Using C

## Brief One Line Summary

This project implements a time-based quiz system in C where users must answer questions within a fixed time limit.

---

## Overview

The Timed Quiz Examination System is a console-based application developed using the C programming language. Questions are loaded from an external text file, and the examinee must answer each question within 30 seconds. If the time limit is exceeded, the question is automatically skipped. The final score is displayed and saved to a file.

---

## Problem Statement

Manual quiz or examination systems are time-consuming and prone to evaluation errors. Storing results manually is also inefficient. This project aims to automate the quiz process with time constraints and accurate result generation.

---

## Dataset

- **File Name:** `questions.txt`
- **Contains:**
  - Question
  - Four options (A, B, C, D)
  - Correct answer
- **Maximum Questions Supported:** 200

---

## Tools and Technologies

- **Programming Language:** C
- **Compiler:** GCC
- **Libraries Used:**
  - stdio.h
  - stdlib.h
  - string.h
  - time.h

---

## Methods

1. Load questions from `questions.txt`
2. Store data using C structures
3. Display questions one by one
4. Start a 30-second timer for each question
5. Accept user input or skip option
6. Evaluate answers and calculate score
7. Save result to `result.txt`

---

## Key Insights

- Time-based quizzes improve concentration
- File handling makes data management easier
- Automated checking reduces human error
- Suitable for basic quiz and exam systems

---

## Output

- Console-based question display
- Automatic time checking
- Final score shown at the end
- Result saved in `result.txt`

---

## How to Run This Project

1. Create a file named `questions.txt` in the project directory
2. Add questions following the required format
3. Compile the program using a C compiler
4. Run the executable file
5. Enter the number of questions to attempt
6. Answer each question within 30 seconds

---

## Results & Conclusion

The project successfully conducts a timed quiz with accurate scoring. It provides a fast, reliable, and user-friendly solution for quiz-based assessments.

---

## Future Work

- Random question shuffling
- Negative marking system
- Graphical User Interface (GUI)
- Online examination support

---

## Author & Contact

**Name:** Muhammad Adnan Sami\
**ID:** 2025-3-60-152\
**Department:** CSE

Mail: [adnansamitngl5050@gmail.com](mailto\:adnansamitngl5050@gmail.com)



