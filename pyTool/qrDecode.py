# 运行下面命令（提前 pip install myqr）得到以 avatar为背景的二维码
# myqr "https://www.cnblogs.com/izlyforever/" -c -p avatar.png


# 上面的网址内容可以用下面的代码解析
# sudo apt install libzbar0
# pip install opencv-python
# qrDecode.py 只可以解码图片（解码gif的暂时不知道）
import sys,cv2
from pyzbar.pyzbar import decode
img = cv2.imread(sys.argv[1])
for qrcode in decode(img):
	print(qrcode.data.decode('utf8'))
