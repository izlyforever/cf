from moviepy.editor import *
clip = VideoFileClip('1.mp4').subclip(43,48)
clip.to_videofile('updated.mp4')