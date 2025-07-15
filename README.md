# fwt2

**fwt2** is a command-line tool that performs a Fast Wavelet Transform on a series of numbers, decomposing an input array into wavelet coefficients and (optionally) performing the inverse transform.

This project is based off the fwt code found here:

https://github.com/bindatype/fwt

---
## Features

- Supports **1, 2, or 3 columns** of input data (value; timestamp + value; or timestamp + value + uncertainty).  
- **Daubechies** filters (support 2, 4, 6) and **Coiflet** filters (support 6, 12, 18).  
- **Forward** and **inverse** transform modes.  
- **Offset** option to circularly shift the input prior to transform.  
- **Gaussian** or **Poisson** bootstrap noise from an uncertainty column.  
- Written in **ANSI C (C99)** with no external dependencies.

---

## Installation

```
cd fwt2
make
sudo make install
```

## Usage

```
Usage: fwt2 [OPTIONS] [< input_file]
```

### Examples 
```
# Haar (Daub2) on stdin:
echo -e "3\n2\n4\n1" | ./fwt2 -d2

# Daubechies-4 on a file:
./fwt2 -d4 < data.txt

# Coiflet-12 with offset 3:
cat data.txt | ./fwt2 -c12 --offset 3

# Inverse transform (reconstruct):
./fwt2 -i < coefficients.txt
```


## Options
| Flag               | Description                                                                                   |
|--------------------|-----------------------------------------------------------------------------------------------|
| `-d, --daub=NUM`   | Daubechies filter (support 2, 4, 6). NUM=2 → Haar.                                             |
| `-c, --coif=NUM`   | Coiflet filter (support 6, 12, 18).                                                           |
| `-i, --inverse`    | Perform inverse wavelet transform.                                                            |
| `-o, --offset=NUM` | Circularly shift input by `NUM` (default 0).                                                   |
| `-g, --gaussian`   | Add Gaussian noise: σ from column 3 or √value if missing. Incompatible with `--poisson`.      |
| `-p, --poisson`    | Add Poisson noise: λ from column 3 or √value if missing. Incompatible with `--gaussian`.      |
| `-h, --help`       | Show help and exit.                                                                           |
| `-v, --version`    | Show version and license info and exit.                                                       |


## Input Format

-1 column: each line is a value; index = line number; uncertainty = √value
-2 columns: index value; uncertainty = √value
-3 columns: index value uncertainty
All series must have length 2^m.

## Output

Two-column ASCII:

Index (same as input or line number)
Transformed coefficient (interleaved approximation and detail)
Author & License

Written by Glen Alan MacLachlan (bindatype@gmail.com).
Released under GPL v3; see the LICENSE file for details.



