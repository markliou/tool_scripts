import cv2
import numpy as np

"""
use the local camera as the streaming camera. the stream will be send by using 
the RTSP.
"""

def send_cam_to_rtsp(rtsp_url):
    cap = cv2.VideoCapture(0)

    # check if the VideoCapture object is successfully opened
    if not cap.isOpened():
        print("Failed to open camera")
        return

    # set the video codec and resolution for the output video
    fourcc = cv2.VideoWriter_fourcc(*'MJPG')
    width, height = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH)), int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))

    # create an OpenCV VideoWriter object to write the video frames to the RTSP stream
    out = cv2.VideoWriter(rtsp_url, fourcc, 25, (width, height))

    while True:
        ret, frame = cap.read()

        if ret:
            cv2.imshow("frame", frame)
            # write the frame to the output video
            out.write(frame)

            if cv2.waitKey(1) & 0xFF == ord('q'):
                break
        else:
            break
    cap.release()
    out.release()
    cv2.destroyAllWindows()

def main():
    rtsp_url = "rtsp://localhost:8554/"
    send_cam_to_rtsp(rtsp_url)

if __name__ == "__main__":
    main()