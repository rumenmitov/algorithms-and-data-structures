set title "Merge-Insertion Sort Performance"
set xlabel "Division Boundary, k"
set ylabel "Time, µs"
plot 'build/average.txt' with linespoints title "Average Case" linecolor rgb "purple", \
     'build/best.txt' with linespoints title "Best Case" linecolor rgb "blue", \
     'build/worst.txt' with linespoints title "Worst Case" linecolor rgb "red"
