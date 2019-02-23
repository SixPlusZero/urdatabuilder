# Data Builder

## Getting Started
* In order to perform data extraction on Live Journal(LJ) data, please place **soc-LiveJournal1.txt** outside this folder.
* Please make sure folders **data** and **bin** exist inside this main folder.

## Compile
Please use command **make bins** to compile. After compilation, there should be **nodeSel**, **graphSplit** and **graphAnonymity** in bin folder. 

## LJ Graph Creator
Please specify parameters in Makefile:
* NODE: Number of nodes extracted from original LJ dataset.
* OVERLAP: Number of nodes two graphs have in common.
* ENCRTPY: Anonymization algorithm id. (0: Naive, 1: Sparsify, 2: Switch). The defualt rate for Sparsify and Switch are both 0.1(Specified in graphAnonymity.cpp).

After setting parameters, use **make graph** to generate dataset in data folder.

### Example:
To get two graphs each contains 7500 nodes and use Sparsify to anonymize, set 
* OVERLAP = 5000
* NODE = 10000
* ENCRYPT = 1

Explanation: （NODE - OVERLAP）/ 2 + OVERLAP = 7500  
Execute **make graph** and you will get crawled.txt and anonymized.txt for G1 and G2 respectively.
