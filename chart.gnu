set terminal pngcairo  transparent enhanced font "arial,10" fontscale 1.0 size 500, 350 
set output 'histograms.2.png'
set boxwidth 0.9 absolute
set style fill   solid 1.00 border lt -1
set key inside right top vertical Right noreverse noenhanced autotitles nobox
set style histogram clustered gap 1 title  offset character 0, 0, 0
set datafile missing '-'
set datafile separator ","
set style data histograms
set xtics border in scale 0,0 nomirror rotate by -45  offset character 0, 0, 0 autojustify
set xtics  norangelimit font ",8"
set xtics   ()
set title "Tempo de execução por linha" 
i = 22
plot 'Results.csv' using 1:xtic(1) ti col