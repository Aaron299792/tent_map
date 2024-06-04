set terminal epslatex color size 6.0in,5.0in standalone font "" 14
set output 'Figure_01.tex'

set border linewidth 6 

set ylabel '\textbf{tent map $(\alpha = 0.7)$} $x_N$'
set xlabel '\textbf{Número de iteraciones} $n$'

set ytics scale 2
set xtics scale 2
set grid

plot 'tent_map.dat' u 1:3 w linespoints pt 7 ps 2.5 lc rgb "#80471c" t '$x_N$'

set output
system('latex Figure_01.tex')
system('dvips Figure_01.dvi')
system('ps2pdf Figure_01.ps')
system('rm Figure_01.tex Figure_01.log Figure_01.aux Figure_01-inc.eps Figure_01.dvi Figure_01.ps')
