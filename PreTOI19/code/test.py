"""Raspberry Pi Face Recognition Treasure Box
Treasure Box Script
Copyright 2013 Tony DiCola
"""
import cv2
import config
import face
import hardware
if _name_ == '_main_':
# Load training data into model
print 'Loading training data...'
model = cv2.createEigenFaceRecognizer()
model.load(config.TRAINING_FILE)
print 'Training data loaded!'
# Initialize camer and box.
camera = config.get_camera()
box = hardware.Box()
# Move box to locked position.
box.lock()
print 'Running box...'
19
print 'Press button to lock (if unlocked), or unlock if the correct face is detected.'
print 'Press Ctrl-C to quit.'
while True:
# Check if capture should be made.
# TODO: Check if button is pressed.
if box.is_button_up():
if not box.is_locked:
# Lock the box if it is unlocked
box.lock()
print 'Box is now locked.'
else:
print 'Button pressed, looking for face...'
# Check for the positive face and unlock if found.
image = camera.read()
# Convert image to grayscale.
image = cv2.cvtColor(image, cv2.COLOR_RGB2GRAY)
# Get coordinates of single face in captured image.
result = face.detect_single(image)
if result is None:
print 'Could not detect single face! Check the image in
capture.pgm' \
 ' to see what was captured and try again with only one
face visible.'
20
continue
x, y, w, h = result
# Crop and resize image to face.
crop = face.resize(face.crop(image, x, y, w, h))
# Test face against model.
label, confidence = model.predict(crop)
print 'Predicted {0} face with confidence {1} (lower is more
confident).'.format(
'POSITIVE' if label == config.POSITIVE_LABEL else
'NEGATIVE',
confidence)
if label == config.POSITIVE_LABEL and confidence <
config.POSITIVE_THRESHOLD:
print 'Recognized face!'
box.unlock()
else:
print 'Did not recognize face!'
from RPIO import PWM
import time
import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
servo = PWM.Servo()
21
GPIO.setup(21,GPIO.OUT)
# Set Buttom
GPIO.setup(4, GPIO.IN) # Right 1
GPIO.setup(17, GPIO.IN) # Left 1
GPIO.setup(27, GPIO.IN) # Right 2
GPIO.setup(22, GPIO.IN) # Left 2
# Set Pin Servo
# Right 1 and Left 1
KR1 = 18
R1 = 23
#Right 1 and Left 2
KL1 = 24
L1 = 25
while True:
if GPIO.input(4) == 1 : # Right 1
print 'Right 1'
#Keep Can #1
servo.set_servo(KR1,1500)
time.sleep(2)
#Right
servo.set_servo(R1,750)
time.sleep(2)
22
#Can #1
servo.set_servo(KR1,500)
time.sleep(2)
#Center
servo.set_servo(R1,1450)
time.sleep(2)
elif GPIO.input(17) == 1 : # Left 1
print 'Left 1'
#Keep Can #1
servo.set_servo(KR1,1500)
time.sleep(2)
#Left
servo.set_servo(R1,2400)
time.sleep(4)
#Can #1
servo.set_servo(KR1,500)
time.sleep(2)
#Center
servo.set_servo(R1,1450)
time.sleep(4)
elif GPIO.input(27) == 1 : # Right 2
print 'Right 2'
23
 #Keep Can #1
servo.set_servo(KL1,1400)
time.sleep(2)
 #Right
servo.set_servo(L1,750)
 time.sleep(2)
 #Can #1
servo.set_servo(KL1,2300)
time.sleep(2)
#Center
servo.set_servo(L1,1450)
time.sleep(2)
elif GPIO.input(22) == 1 : # Left 2
 print 'Left 2'
 #Keep Can #1
servo.set_servo(KL1,1400)
time.sleep(2)
 #Left
servo.set_servo(L1,2400)
time.sleep(4)
 #Can #1
servo.set_servo(KL1,2300)
24
time.sleep(2)
 #Center
servo.set_servo(L1,1450)
time.sleep(2)
else:
GPIO.output(21,0)