from time import sleep
from djitellopy import Tello

tello = Tello()

tello.connect()
tello.takeoff()
sleep(1)
tello.rotate_counter_clockwise(90)
sleep(1)
tello.land()
