# fwt2

**fwt2** is a command-line tool that performs a Fast Wavelet Transform on a series of numbers, decomposing an input array into wavelet coefficients and (optionally) performing the inverse transform.

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

```bash
git clone https://github.com/your-org/fwt2.git
cd fwt2
make

