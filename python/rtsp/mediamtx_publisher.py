import cv2
import numpy as np
from time import sleep, time

fps = 15
width = 800
height = 600
colors = [
    (0, 0, 255),
    (255, 0, 0),
    (0, 255, 0),
]

out = cv2.VideoWriter('appsrc ! videoconvert' +
                      ' ! x264enc speed-preset=ultrafast bitrate=600 key-int-max=' + str(fps * 2) +
                      ' ! video/x-h264,profile=baseline' +
                      ' ! rtspclientsink location=rtsp://127.0.0.1:8554/mystream',
                      cv2.CAP_GSTREAMER, 0, fps, (width, height), True)
if not out.isOpened():
    raise Exception("can't open video writer")

curcolor = 0
start = time()

while True:
    frame = np.zeros((height, width, 3), np.uint8)

    # create a rectangle
    color = colors[curcolor]
    curcolor += 1
    curcolor %= len(colors)
    for y in range(0, int(frame.shape[0] / 2)):
        for x in range(0, int(frame.shape[1] / 2)):
            frame[y][x] = color

    out.write(frame)
    print("frame written to the server")

    now = time()
    diff = (1 / fps) - now - start
    if diff > 0:
        sleep(diff)
    start = now
