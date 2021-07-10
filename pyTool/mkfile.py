# 在某目录下的所有文件夹中创建 md 文件
import os
path = os.getcwd()
# path = 'C:\\Users\\izlyforever\\cf\\contest'
filelist = os.listdir(path)
for item in filelist:
	dir = path + '\\' + item
	if os.path.isdir(dir):
		file = open(dir + '\\README.md','w')
		file.close()
