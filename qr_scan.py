import cv2
import numpy as np
import pyzbar.pyzbar as pyzbar
import urllib.request
import serial

#cap = cv2.VideoCapture(0)
font = cv2.FONT_HERSHEY_PLAIN
 
url='http://192.168.1.61/' # IP ADDRESS OF THE CAM MODULE (will obtain during hardware implementation)
cv2.namedWindow("live transmission", cv2.WINDOW_AUTOSIZE)
 
prev=""
pres=""
while True:
    img_resp=urllib.request.urlopen(url+'cam-hi.jpg') #checking frames from esp32cam
    imgnp=np.array(bytearray(img_resp.read()),dtype=np.uint8)
    frame=cv2.imdecode(imgnp,-1)
    #_, frame = cap.read()
 
    decodedObjects = pyzbar.decode(frame) # decode QR code using pyzbar
    for obj in decodedObjects:
        pres=obj.data
        if prev == pres:
            pass
        else:
            print("Type:",obj.type)
            print("Data: ",obj.data) # data will be print on the screen
            arduino = serial.Serial('COM3', 9600)
            arduino.write(obj.data.encode())
            arduino.close()
            prev=pres
        cv2.putText(frame, str(obj.data), (50, 50), font, 2,
                    (255, 0, 0), 3)
 
    cv2.imshow("live transmission", frame)
 
    key = cv2.waitKey(1)
    if key == 27:
        break
 




cv2.destroyAllWindows()