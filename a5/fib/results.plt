set title "Fibonacci Numbers"
set xlabel "Time, µs"
set logscale y 2
set ylabel "Amount of inputs successfully calculated in given time"
plot 'build/results_naive_recursive.txt' with linespoints title "Naive Recursive" linecolor rgb "blue", \
     'build/results_bottom_up.txt' with linespoints title "Bottom-Up" linecolor rgb "red", \
     'build/results_closed_form.txt' with linespoints title "Closed-Form" linecolor rgb "green", \
     'build/results_matrix.txt' with linespoints title "Matrices" linecolor rgb "purple"
