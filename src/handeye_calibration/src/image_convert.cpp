#include <ros/ros.h>
#include <sensor_msgs/CompressedImage.h>
#include <sensor_msgs/Image.h>
#include <cv_bridge/cv_bridge.h>

class Compressed2Image
{
    public:

        Compressed2Image(ros::NodeHandle nh)
        {
            pub = nh.advertise<sensor_msgs::Image>("/image", 1);
            sub = nh.subscribe("/left_arm_camera/color/image_raw/compressed", 1, &Compressed2Image::compressedImageCallback, this);

        }

        void compressedImageCallback(const sensor_msgs::CompressedImageConstPtr& msg)
        {
            // ROS_INFO("Convert compressed image to image message\n");
            cv_bridge::CvImagePtr cv_ptr;
            try
            {
                cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
            }
            catch (cv_bridge::Exception& e)
            {
                ROS_ERROR("cv_bridge exception: %s", e.what());
                return;
            }

            sensor_msgs::ImagePtr image_msg = cv_ptr->toImageMsg();
            image_msg->header = msg->header;

            pub.publish(image_msg);
            // ROS_INFO("Publish image message\n");
        }
    private:
        ros::Publisher pub;
        ros::Subscriber sub;
};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "compressed_to_image");
    ros::NodeHandle nh;

    Compressed2Image c2i(nh);

    ros::spin();

    return 0;
}

