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


# git fetch --all
# git reset --hard origin/master

# git checkout -b [branch name]
# git add .
# git commit -m "update"
# git push origin [branch name]

# git checkout [branch name]

# rm -rf .git 
# git init
# git add -A 
# git commit -m "ReInit" 
# git remote add origin git@github.com:izlyforever/cf.git
# git push -f -u origin master
