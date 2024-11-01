set title "Comaprison of Heap Sort (Top-Down vs. Bottom-Up)"
set xlabel "Input size, n"
set ylabel "Time, µs"
plot 'build/results_top_down.txt' with linespoints title 'Top-Down' linecolor rgb "red", \
     'build/results_bottom_up.txt' with linespoints title 'Bottom-Up' linecolor rgb "blue"
