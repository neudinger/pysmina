# pysmina

## Abstract

A fork of AutoDock Vina that is customized to better support scoring function development and high-performance energy minimization. smina is maintained by David Koes at the University of Pittsburgh and is not directly affiliated with the AutoDock project.

Pysmina is A fork of smina and customized with python boost to support python operation. It is easier to use with python environement.
Pysmina is maintained by Barre Kevin.

## Descriptions

[![GitHub license](https://img.shields.io/badge/license-EUPL-blue.svg)](https://raw.githubusercontent.com/herotc/hero-rotation/master/LICENSE)

## Local

### Requirement

- cmake
- zlib-dev
- gcc / clang
- python3-dev
- boost-dev
- py-pip
- openbabel
- libeigen

### Installation

```bash
pip install .
```

## Run Example

### Local running

```bash
python3 pysmina/example/example.py
```

### Docker

```bash
docker build -f dockerfiles/dockerfile . -t pysmina:latest
docker run -it pysmina
```

### Output

```python
$$$$
REMARK  Name = ZINC03814434
REMARK                            x       y       z     vdW  Elec       q    Type
REMARK                         _______ _______ _______ _____ _____    ______ ____
ROOT
ATOM      1  C   LIG    1      -21.034  24.182 -12.402  0.00  0.00    +0.148 C 
ATOM      2  C   LIG    1      -19.745  23.351 -12.208  0.00  0.00    +0.107 C 
ATOM      3  C   LIG    1      -18.845  24.088 -11.146  0.00  0.00    +0.196 C 
ATOM      4  C   LIG    1      -19.315  23.619  -9.758  0.00  0.00    +0.115 C 
ATOM      5  C   LIG    1      -19.097  22.111  -9.611  0.00  0.00    +0.147 C 
ATOM      6  C   LIG    1      -19.513  21.345 -10.874  0.00  0.00    +0.234 C 
ATOM      7  N   LIG    1      -18.433  20.727 -11.602  0.00  0.00    -0.338 N 
ATOM      8  C   LIG    1      -17.718  19.580 -11.193  0.00  0.00    +0.015 A 
ATOM      9  C   LIG    1      -17.877  18.819 -10.015  0.00  0.00    +0.052 A 
ATOM     10  C   LIG    1      -17.062  17.707  -9.798  0.00  0.00    +0.013 A 
ATOM     11  C   LIG    1      -16.102  17.341 -10.726  0.00  0.00    +0.008 A 
ATOM     12  C   LIG    1      -15.931  18.077 -11.902  0.00  0.00    +0.034 A 
ATOM     13  C   LIG    1      -16.726  19.213 -12.177  0.00  0.00    +0.004 A 
ATOM     14  C   LIG    1      -16.817  20.143 -13.242  0.00  0.00    +0.045 A 
ATOM     15  C   LIG    1      -16.002  20.186 -14.393  0.00  0.00    +0.082 A 
ATOM     16  C   LIG    1      -14.882  19.468 -14.926  0.00  0.00    +0.188 C 
ATOM     17  N   LIG    1      -14.583  20.156 -16.101  0.00  0.00    -0.309 N 
ATOM     18  H   LIG    1      -13.800  19.852 -16.663  0.00  0.00    +0.190 HD
ATOM     19  C   LIG    1      -15.415  21.304 -16.409  0.00  0.00    +0.204 C 
ATOM     20  O   LIG    1      -14.228  18.508 -14.555  0.00  0.00    -0.368 OA
ATOM     21  C   LIG    1      -16.317  21.252 -15.258  0.00  0.00    +0.009 A 
ATOM     22  C   LIG    1      -17.377  22.066 -14.826  0.00  0.00    +0.023 A 
ATOM     23  C   LIG    1      -17.776  23.285 -15.418  0.00  0.00    +0.000 A 
ATOM     24  C   LIG    1      -17.355  24.011 -16.558  0.00  0.00    +0.033 A 
ATOM     25  C   LIG    1      -17.913  25.251 -16.871  0.00  0.00    +0.008 A 
ATOM     26  C   LIG    1      -18.912  25.784 -16.079  0.00  0.00    +0.013 A 
ATOM     27  C   LIG    1      -19.369  25.105 -14.947  0.00  0.00    +0.052 A 
ATOM     28  C   LIG    1      -18.807  23.864 -14.577  0.00  0.00    +0.017 A 
ATOM     29  C   LIG    1      -18.167  22.029 -13.671  0.00  0.00    +0.056 A 
ATOM     30  C   LIG    1      -17.859  20.981 -12.805  0.00  0.00    +0.058 A 
ATOM     31  N   LIG    1      -19.045  23.048 -13.440  0.00  0.00    -0.329 N 
ATOM     32  O   LIG    1      -20.320  22.128 -11.724  0.00  0.00    -0.389 OA
ENDROOT
BRANCH   4  33
ATOM     33  N   LIG    1      -18.479  24.351  -8.715  0.00  0.00    +0.436 N 
ATOM     34  H   LIG    1      -17.485  24.301  -8.978  0.00  0.00    +0.138 HD
ATOM     35  H   LIG    1      -18.541  23.793  -7.844  0.00  0.00    +0.138 HD
ATOM     36  C   LIG    1      -18.822  25.771  -8.447  0.00  0.00    +0.161 C 
ENDBRANCH   4  33
BRANCH   3  37
ATOM     37  O   LIG    1      -17.431  23.792 -11.120  0.00  0.00    -0.441 OA
ATOM     38  C   LIG    1      -16.570  24.829 -11.588  0.00  0.00    +0.252 C 
ENDBRANCH   3  37
TORSDOF 2
> <minimizedAffinity>
-8.64454

> <rmsdLowerBound>
2.72153

> <rmsdUpperBound>
6.36860
$$$$
```

## Documentation

[pdoc3](https://pdoc3.github.io/pdoc/)

<img src="https://pdoc3.github.io/pdoc/logo.png" width="100" height="100">

```bash
pdoc3 pysmina --http localhost:8080
```

## Dev

Files changed :

- [main.cpp](https://github.com/neudinger/pysmina/blob/main/pysmina/lib/main.cpp)
- [pycompute.cpp](https://github.com/neudinger/pysmina/blob/main/pysmina/lib/pycompute.cpp)
- [result_info](https://github.com/neudinger/pysmina/blob/main/pysmina/lib/result_info.cpp)

## Library used

- [C++ boost](https://www.boost.org/)
- [python boost](https://www.boost.org/doc/libs/1_75_0/libs/python/doc/html/tutorial/index.html)
