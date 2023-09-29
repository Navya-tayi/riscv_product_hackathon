import cv2            # Import the OpenCV library for computer vision
import numpy as np    # Import NumPy for numerical operations
import pyzbar.pyzbar as pyzbar  # Import pyzbar for QR code decoding
import urllib.request # Import urllib.request for making HTTP requests
import serial         # Import the serial library for serial communication with Arduino

#cap = cv2.VideoCapture(0) # Initialize a video capture object (not currently used)
font = cv2.FONT_HERSHEY_PLAIN  # Define a font for text overlay

url = 'http://192.168.1.61/'  # Set the URL to the IP address of the camera module (to be obtained during hardware implementation)
cv2.namedWindow("live transmission", cv2.WINDOW_AUTOSIZE)  # Create a window for displaying the live transmission

prev = ""  # Initialize a variable for storing the previous QR code data
pres = ""  # Initialize a variable for storing the current QR code data

while True:
    img_resp = urllib.request.urlopen(url + 'cam-hi.jpg')  # Make an HTTP request to fetch the camera image
    imgnp = np.array(bytearray(img_resp.read()), dtype=np.uint8)  # Convert the image data into a NumPy array
    frame = cv2.imdecode(imgnp, -1)  # Decode the image using OpenCV
    
    decodedObjects = pyzbar.decode(frame)  # Decode QR codes using pyzbar
    for obj in decodedObjects:
        pres = obj.data  # Store the current QR code data in 'pres'
        if prev == pres:
            pass  # If the current data is the same as the previous, do nothing
        else:
            print("Type:", obj.type)  # Print the type of the detected QR code
            print("Data: ", obj.data)  # Print the data from the detected QR code

            # Establish serial communication with Arduino on 'COM3' port at 9600 baud rate
            arduino = serial.Serial('COM3', 9600)
            arduino.write(obj.data.encode())  # Send the QR code data to Arduino
            arduino.close()  # Close the serial communication
            prev = pres  # Update 'prev' with the current data

        cv2.putText(frame, str(obj.data), (50, 50), font, 2, (255, 0, 0), 3)  # Overlay the QR code data on the frame

    cv2.imshow("live transmission", frame)  # Display the frame in the "live transmission" window

    key = cv2.waitKey(1)
    if key == 27:
        break

cv2.destroyAllWindows()  # Close all OpenCV windows
