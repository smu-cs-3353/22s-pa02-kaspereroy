# Program 2: Sorting
### London Kasper and Hazel Eroy

**Summary**

This program implements six different sorting algorithms and compares the performances on different set sizes


<br>"You’ll write a report on the analysis of the data in the README.md.  I won’t dictate the requirements, but I would like you to answer the following questions:
- How does the performance of the various sorting algorithms differ between randomized data and pre-sorted data? Does this change with integers vs strings? - How do the algorithms perform as the datasets grow very large?  
- Does the performance of the sorting algorithms match published upper bounds?  
- How does the performance of the algorithms change as duplicates are introduced?
- How does the performance of the algorithms change when the input is mostly sorted?
- Which algorithm is the best?

Generate appropriate graphs for each data organization (randomized, sorted, etc) that plot the various data set sizes against run time.  Include a CSV file of your raw data in your repo. 


### Data Generation
In order to generate datasets for our algorithms, we created a Python function that accepted an initial dataset size, 
created all of the required datasets for that size, and then multiplied the size by 5. From there, the program would 
loop and create a new dataset of 5x the size. We generated multiple different types of datasets: a dataset of size s with 
0% duplicates sorted in ascending order, another with 0% duplicates with only 60% of the array pre-sorted ascending, a 
randomized dataset of size s with 0% duplicates, and finally two different datasets with 20% and 40% duplicates.
In order to generate 'randomized' datasets, we first generated a list of numbers from 1 to the desired size,
and used the Python shuffle function to randomize the order. For the datasets with % duplicates, we made a percentDupe function that
took in the desired size and the desired percent and first created a dataset from 1 to the desired percent of the size. From there, we extended the list for the remaining percent beginning at 1 again. 
Afterwards, we shuffled the dataset to randomize the order.

### Performance Analysis
### The Best Algorithm
