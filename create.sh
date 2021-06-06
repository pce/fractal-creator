

width=800  # px
height=800 # px
zoom=100   # percent

# width 1920 --height 1920


cd build

# zoom/scale, left, top, ... 
./fractal-creator --width $width --height $height --zoom 10 --zoom-to 290


# convert ppm to png
ffmpeg -i out-%d.ppm out-%d.png
# convert to gif
ffmpeg -i out-%d.png output.gif
