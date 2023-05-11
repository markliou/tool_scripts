import cv2
import numpy as np

btn_down = False

# Create a window to display the image.
window = cv2.namedWindow("Image")

# Load the image.
image = cv2.imread("view0000.png")

# Create a blank image to store the path.
path = np.zeros_like(image)
path = path.astype(int)

# Set the mouse callback function.
def mouse_callback(event, x, y, flags, param):
    global btn_down

    # If the left mouse button is clicked, start recording the path.
    if event == cv2.EVENT_LBUTTONDOWN:
        btn_down = True
        path[y, x] = 255
        
        width = 5
        for i in range(width):
            for j in range(width):
                path[y+i, x+j] = 255
                path[y-i, x-j] = 255

    # If the left mouse button is released, stop recording the path and save it to a file.
    elif event == cv2.EVENT_LBUTTONUP and btn_down:
        btn_down = False
        cv2.imwrite("path.png", path)

    elif event == cv2.EVENT_MOUSEMOVE and btn_down:
        path[y, x] = 255


# Set the mouse callback function.
cv2.setMouseCallback("Image", mouse_callback)

# Display the image and wait for the user to click the mouse.
cv2.imshow("Image", image)
cv2.waitKey(0)

# Close the window.
cv2.destroyWindow("Image")