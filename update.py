import os
import sys
 
#os.system('git init')
os.system('git add .')
 
#os.system('git remote rm origin')
#os.system('git remote add origin git@github.com:izlyforever/cf.git')
if len(sys.argv) < 2:
	os.system('git commit -m "update"')
else:
	os.system('git commit -m "' + ' '.join(sys.argv[1:]) + '"')
os.system('git push origin master')

# 强制让本地和服务器的一致.
# git fetch --all
# git reset --hard origin/master

# 创建新分支并上传
# git checkout -b [branch name]
# git add .
# git push origin [branch name]

# 切换分支
# git checkout [branch name]
