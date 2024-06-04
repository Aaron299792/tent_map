set terminal epslatex color size 6.0in,5.0in standalone font "" 14
set output 'Figure.tex'

set border linewidth 6 

set ylabel '\textbf{tent map $(\alpha = 0.4)$} $x_n$'
set xlabel '\textbf{Número de iteraciones} $n$'

set ytics scale 2
set xtics scale 2
set grid

plot 'tent_map.dat' u 1:2 w linespoints pt 7 ps 2.5 lc rgb "#005254" t '$x_N$'

set output
system('latex Figure.tex')
system('dvips Figure.dvi')
system('ps2pdf Figure.ps')
system('rm Figure.tex Figure.log Figure.aux Figure-inc.eps Figure.dvi Figure.ps')
