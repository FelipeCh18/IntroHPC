plot 'dist.txt' w lp lw 4 ps 2 t 'Probability Density Function'
set xlabel 'samples'
set ylabel 'PDF'
set terminal pdf
set out "random_pdf.pdf"                            # restore the output redirection