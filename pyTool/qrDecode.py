import sys,cv2
from pyzbar.pyzbar import decode
img = cv2.imread(sys.argv[1])
for qrcode in decode(img):
	print(qrcode.data.decode('utf8'))
