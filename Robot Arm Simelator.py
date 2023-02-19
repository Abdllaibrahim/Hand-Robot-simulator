import cv2
import time
import os
import HandTrackingModule  as htm
from cvzone.SerialModule import SerialObject
from time import sleep
wCam, hCam = 640, 480
arduino = SerialObject()
cap = cv2.VideoCapture(0)
cap.set(3, wCam)
cap.set(4, hCam)

folderPath = "E:/Engineering Materials/ST Smart/Robotics Level 3/respberry pi projects/Hand Counter in Raspberry Pi/Data"
myList = os.listdir(folderPath)
myList.sort()
print(myList)
overlayList = []
for imPath in myList:
    image = cv2.imread(f'{folderPath}/{imPath}')
    print(f'{folderPath}/{imPath}')
    overlayList.append(image)

print(len(overlayList))
pTime = 0

detector = htm.handDetector()

tipIds = [4, 8, 12, 16, 20]

while True:
    success, img = cap.read()
    img= cv2.flip(img,1)
    img = detector.findHands(img)
    lmList = detector.findPosition(img, draw=False)
    # print(lmList)
    time.sleep(0.05)
    if len(lmList) != 0:
        fingers = []

        # Thumb
        if lmList[tipIds[0]][1] > lmList[tipIds[0] - 1][1]:
            print("thump up")
            arduino.sendData([1])
        else:
            print("thump down")
            arduino.sendData([2])
        
        if lmList[tipIds[1]][2] < lmList[tipIds[1] - 2][2]:
            print("index Up")
            arduino.sendData([3])
        else:
            print("index down")
            arduino.sendData([4])

        if lmList[tipIds[2]][2] < lmList[tipIds[2] - 2][2]:
            print("middle Up")
            arduino.sendData([5])
        else:
            print("middle down")
            arduino.sendData([6])
        
        if lmList[tipIds[3]][2] < lmList[tipIds[3] - 2][2]:
            print("ring Up")
            arduino.sendData([7])
        else:
            print("ring down")
            arduino.sendData([8])

        if lmList[tipIds[4]][2] < lmList[tipIds[4] - 2][2]:
            print("pinky Up")
            arduino.sendData([9])
        else:
            print("pinky down")
            arduino.sendData([10])
        
        # 4 Fingers
        
        #for id in range(1, 5):
            #if lmList[tipIds[id]][2] < lmList[tipIds[id] - 2][2]:
                #print("index Up")
            #else:
                #print("index down")

        # print(fingers)
        #totalFingers = fingers.count(1)
        #print(totalFingers)

        #h, w, c = overlayList[totalFingers - 1].shape
        #img[0:h, 0:w] = overlayList[totalFingers - 1]

        #cv2.rectangle(img, (20, 225), (170, 425), (0, 255, 0), cv2.FILLED)
       # cv2.putText(img, str(totalFingers), (45, 375), cv2.FONT_HERSHEY_PLAIN,
                    #10, (255, 0, 0), 25)

    cTime = time.time()
    fps = 1 / (cTime - pTime)
    pTime = cTime

    cv2.putText(img, f'FPS: {int(fps)}', (400, 70), cv2.FONT_HERSHEY_PLAIN,
                3, (255, 0, 0), 3)

    cv2.imshow("Image", img)
    
    if cv2.waitKey(1) & 0xFF == ord('q'):
            break
        