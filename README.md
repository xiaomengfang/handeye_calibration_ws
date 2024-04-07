# Handeye Calibration 
## Install 
```bash
# Install Dependencies
# 18.04/Melodic
pip install --user fpdf opencv-contrib-python
# 20.04/Noetic
pip3 install --user fpdf

# Download code
git clone https://github.com/xiaomengfang/handeye_calibration_ws.git
cd handeye_calibration_ws
git submodule update --init --recursive
# catkin_make
# source devel/setup.bash # setup.zsh

# Build
# cd handeye_calibration_ws
rosdep install -yir --from-paths src
catkin build
source devel/setup.bash
```

## Run
### Galbot
```bash
# open 1st terminal, launch robot moveit
roslaunch galbot_bringup galbot_bringup.launch
# open 2nd terminal, launch camera
roslaunch rs_
# open 3rd terminal, launch 
roslaunch galbot_handeye_calibration.launch
```

