import cv2

def rstp_runner(url):
    """
    open the rstp channel by using the input url address.
    :return:
    void
    """
    # 開啟 RTSP 串流
    vidCap = cv2.VideoCapture(url)

    # 建立視窗
    cv2.namedWindow('image_display', cv2.WINDOW_AUTOSIZE)

    while True:
        # 從 RTSP 串流讀取一張影像
        ret, image = vidCap.read()

        if ret:
            # 顯示影像
            cv2.imshow('image_display', image)
            if cv2.waitKey(1) & 0xFF == ord('q'):
                break

    # 釋放資源
    vidCap.release()

    # 關閉所有 OpenCV 視窗
    cv2.destroyAllWindows()

def main():
    # use the wowza server example rtsp streaming
    # rstp_runner('rtsp://wowzaec2demo.streamlock.net/vod/mp4:BigBuckBunny_115k.mp4')

    # use the local server example rtsp streaming
    rstp_runner('rtsp://localhost:8554/')


if __name__ == '__main__':
    main()
