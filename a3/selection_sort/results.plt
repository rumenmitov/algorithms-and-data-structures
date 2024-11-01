# Sources:
# - tldr gnuplot
# - https://www.ap.smu.ca/~thacker/teaching/3437/gnuplot.pdf
# - https://stackoverflow.com/questions/2075283/choosing-line-type-and-color-in-gnuplot-4-0#2075500
set title "Selection Sort" 
set xlabel "Inputs, n" 
set ylabel "Time, µs" 
plot 'build/results_average.txt' with linespoints title "Average Case" linecolor rgb "purple", \
     'build/results_worst.txt' with linespoints title "Worst Case" linecolor rgb "red", \
     'build/results_best.txt' with linespoints title "Best Case" linecolor rgb "blue"

