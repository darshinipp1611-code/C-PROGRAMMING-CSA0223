# C Programming – Assignment 1

**Project:** Design, Implement and Validate a Reliable Billing Program  
**Organisation scenario:** Grama Jyothi Rural Electricity Co-operative  
**Student name:** [Enter your name]  
**Register number:** [Enter your register number]  
**Repository name:** `CSA02-<RegisterNumber>-Assignment1`

## Overview

This repository contains the work for Tasks 1–12 of C Programming Assignment 1. The program design covers monthly electricity billing, tariff slabs, meter rollover, input validation, exact money calculations using integer paise, compilation stages, scale analysis and a smart-meter redesign.

## Tariff rules

- First 100 units: ₹0 per unit
- Units 101–200: ₹2.25 per unit (225 paise)
- Units above 200: ₹4.50 per unit (450 paise)
- Fixed charge: ₹50.00 (5,000 paise)
- Original meter register: 0–65,535, with rollover handled only according to the specified meter rule

## Suggested folder structure

```text
CSA02-<RegisterNumber>-Assignment1/
├── README.md
├── Task01/
│   └── task01_analysis.md
├── Task02/
│   ├── task02_rollover.c
│   └── task02_types.c
├── Task03/
│   └── task03_constants.c
├── Task04/
│   └── task04_macros.c
├── Task05/
│   ├── billing.h
│   └── task05_debug.c
├── Task06/
│   └── task06_input_output.c
├── Task07/
│   └── precision_examples.c
├── Task08/
│   └── task05_debug.c
├── Task09/
│   └── task09_billing.c
├── Task10/
│   ├── type_measurements.c
│   └── floating_point_comparison.c
├── Task11/
│   └── design_recommendation.md
└── Task12/
    ├── task12_smart_meter.c
    └── tariff.txt
```

For each task, add the source file(s), any input/configuration files, and a screenshot of the program output. Keep the actual filenames aligned with the filenames specified in the supplied task documents.

## Compiler and environment

Record the compiler and version used for your own run:

```bash
gcc --version
```

**Compiler used:** `[Fill in your compiler and version]`  
**Operating system:** `[Fill in your operating system]`

## Build and run

Use the command that matches the source file and any required header/configuration files. Example commands for the tasks are shown below; adjust the filename if your source uses a different name.

```bash
# Task 2 – rollover
gcc -Wall -Wextra -std=c11 task02_rollover.c -o task02_rollover
./task02_rollover

# Task 2 – type sizes and ranges
gcc -Wall -Wextra -std=c11 task02_types.c -o task02_types
./task02_types

# Task 3
gcc -Wall -Wextra -std=c11 task03_constants.c -o task03_constants
./task03_constants

# Task 4
gcc -Wall -Wextra -std=c11 task04_macros.c -o task04_macros
./task04_macros

# Task 5 – include the current directory so billing.h can be found
gcc -Wall -Wextra -std=c11 task05_debug.c -o task05_debug
./task05_debug

# Task 6
gcc -Wall -Wextra -std=c11 task06_input_output.c -o task06_input_output
./task06_input_output

# Task 9
gcc -Wall -Wextra -std=c11 task09_billing.c -o task09_billing
./task09_billing

# Task 12 – keep tariff.txt in the working directory
gcc -Wall -Wextra -std=c11 task12_smart_meter.c -o task12_smart_meter
./task12_smart_meter
```

### Task 8 compilation-stage commands

Run these in the directory containing `task05_debug.c` and `billing.h`:

```bash
gcc -E task05_debug.c -o task05_debug.i
gcc -S task05_debug.c -o task05_debug.s
gcc -c task05_debug.c -o task05_debug.o
gcc task05_debug.c -o task05_debug
gcc -Wall -Wextra -pedantic task05_debug.c -o billing
```

## Task-by-task result notes

1. **Task 1 – Problem analysis:** identify inputs, outputs, tariff constants, assumptions and validation requirements. Compare integer and string representations.
2. **Task 2 – Data types:** verify meter rollover calculations and record `sizeof`/range output from the actual compiler.
3. **Task 3 – Constants:** define slab limits and rates once; use paise for monetary values.
4. **Task 4 – Safe macros:** test macro precedence and compare with a `static inline` function.
5. **Task 5 – Header and conditional compilation:** use include guards and a debug build option.
6. **Task 6 – Input/output:** match format specifiers to data types and reject invalid input.
7. **Task 7 – Conversion and precision:** demonstrate integer division, floating-point approximation and unsafe out-of-range conversion.
8. **Task 8 – Compilation process:** save or record preprocessing, assembly, object-file, link and warning-enabled compile results.
9. **Task 9 – Billing implementation:** test slab boundaries, rollover, valid input and invalid input.
10. **Task 10 – Expected versus actual:** measure type sizes and compare integer-paise and floating-point totals for 4,000, 60,000 and 800,000 bills. Enter only measured results.
11. **Task 11 – Final recommendation:** explain data types, configuration-based tariffs, limitations and district-scale requirements.
12. **Task 12 – Smart meter redesign:** process 15-minute watt-hour readings, apply the 6 PM–10 PM surcharge, read tariff values from `tariff.txt`, and use streaming totals.

## Sample billing checks

These are expected checks based on the supplied tariff rules; confirm them by running your own program.

| Consumption | Expected bill |
|---:|---:|
| 0 units | ₹50.00 |
| 100 units | ₹50.00 |
| 150 units | ₹162.50 |
| 200 units | ₹275.00 |
| 350 units | ₹950.00 |

## Task 12 tariff file

Create `tariff.txt` with the three values in the order required by your supplied program:

```text
225
450
5000
```

These represent the second-slab rate in paise, third-slab rate in paise, and fixed charge in paise. If the program expects a different format, follow the exact input format in the supplied Task 12 code.

## Testing and evidence

For each task:
- Run the program using the required sample input.
- Test at least one boundary case where relevant.
- Test invalid input for programs that accept readings.
- Save a genuine screenshot of the output.
- Record compiler warnings or errors and correct them where possible.
- For Task 10, record measured values from your own computer. Do not replace actual results with predicted values.

## GitHub submission

1. Create the repository named `CSA02-<RegisterNumber>-Assignment1`.
2. Upload the task folders, source code, input/configuration files, screenshots and this README.
3. Commit the work progressively, with at least one meaningful commit per task.
4. Share the repository with the course faculty.
5. Add the repository URL to the assignment submission and cover page.

**Repository URL:** `[Paste your GitHub repository URL here]`
