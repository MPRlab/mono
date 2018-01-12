# Close the opened DriverBoardOutput lines, if not done
echo 4 > /sys/class/gpio/unexport
echo 17 > /sys/class/gpio/unexport
echo 22 > /sys/class/gpio/unexport
echo 27 > /sys/class/gpio/unexport
