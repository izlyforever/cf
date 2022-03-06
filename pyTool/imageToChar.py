# imageToChar.py 使用说明：
# 把图片(例如xx.png)和这个文件放在同一文件夹中
# 命令行进入上面的文件夹路径输入
# py imageTochar.py xx.png (自选宽度：78，可不填)

from PIL import Image
chars = ['y', 'l', 'z', '#', '?', '*', '+', ';', ':', ',', '.']

def resize(image, newW):
  (w, h) = image.size
  # 0.58 大致是单个字符在DOS界面的宽高比
  newDim = (newW, int(0.58*h*newW/w))
  newImg = image.resize(newDim)
  return newImg

def garytochar(grayImg,newW):
  newPix = [];step=256//len(chars) + 1
  for i,data in enumerate(grayImg.getdata()):
    if(i%newW == 0): newPix.append('\n')
    newPix.append(chars[data//step])  #也可以用 data%len(chars)
  return ''.join(newPix)

def imagetochar(imgPath, newW = 78):
  img = Image.open(imgPath)
  newImg = resize(img,newW)
  grayImg = newImg.convert('L')
  return garytochar(grayImg,newW)

if __name__ == '__main__':
  import sys
  imgPath, newW, *tmp = sys.argv[1:3]+ [78]
  charPix = imagetochar(imgPath,int(newW))
  print(charPix)
