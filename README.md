# Program 2: Sorting
### London Kasper and Hazel Eroy

**Summary**

This program implements six different sorting algorithms and compares the performances on different set sizes

Sorting algorithm implemented:
- insertion sort
- randomized quicksort
- merge sort
- shellsort
- introsort
- timsort

<br>"You’ll write a report on the analysis of the data in the README.md.  I won’t dictate the requirements, but I would like you to answer the following questions:
- How did you generate the various data sets?
- How does the performance of the various sorting algorithms differ between randomized data and pre-sorted data? Does this change with integers vs strings? - How do the algorithms perform as the datasets grow very large?  
- Does the performance of the sorting algorithms match published upper bounds?  
- How does the performance of the algorithms change as duplicates are introduced?
- How does the performance of the algorithms change when the input is mostly sorted?
- Which algorithm is the best?

Generate appropriate graphs for each data organization (randomized, sorted, etc) that plot the various data set sizes against run time.  Include a CSV file of your raw data in your repo. 


### Data Generation
In order to generate datasets for our algorithms, we created a Python function that accepted an initial dataset size, 
created all of the required datasets for that size, and then multiplied the size by 5. From there, the program would 
loop and create a new dataset of 5x the size. In order to generate the randomized datasets we first 

### Performance Analysis
### The Best Algorithm
