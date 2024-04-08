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
cd src/aruco_ros
git checkout noetic-devel # depends on your ros version

# Build
# cd handeye_calibration_ws
rosdep install -yir --from-paths src
catkin build
source devel/setup.bash
```

## Run
### Galbot
```bash
roslaunch galbot_left_arm_handeye_calibration.launch
```

## Troubleshooting
- ERROR: cannot launch node of type [aruco_ros/single]: Cannot locate node of type [single] in package [aruco_ros]. Make sure file exists in package path and permission is set to executable (chmod +x)
    ```bash
    switch the aruco_ros to the correct branch
    ```
- [aruco_single-14] process has died [pid 54706, exit code -11, cmd /home/galbot_orin_231113/workspace/handeye_calibration_ws/devel/lib/aruco_ros/single /camera_info:=/left_arm_camera/color/camera_info /image:=/left_arm_camera/color/image_raw __name:=aruco_single __log:=/home/galbot_orin_231113/.ros/log/69aec104-f582-11ee-bc76-48b02ded2d4a/aruco_single-14.log].
log file: /home/galbot_orin_231113/.ros/log/69aec104-f582-11ee-bc76-48b02ded2d4a/aruco_single-14*.log
- [ERROR] [1712570415.322532593]: Robot semantic description not found. Did you forget to define or remap '/robot_description_semantic'?
    ```
    Because you don't use Moveit, if you have tf published, just ignore.
    ```
