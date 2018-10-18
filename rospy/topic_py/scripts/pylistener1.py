#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Created on Sun Oct 14 18:16:39 2018

@author: exbot
"""
import rospy
import math
# 导入gps
from topic_py.msg import gps

#  回调函数输入的应该是msg
def callback(gps):
    distance = math.sqrt(math.pow(gps.x, 2) + math.pow(gps.y, 2))
    rospy.loginfo('Listener: GPS: distance=%f, state=%s', distance, gps.state)
    
def listener():
    rospy.init_node('pylistener1', anonymous=True)
    # Subscriber函数第一个参数是topic的名称,第二个参数是接受的数据类型,第三个参数是回调函数
    rospy.Subscriber('gps_info', gps, callback)
    rospy.spin()
    
if __name__ == '__main__':
    listener()
