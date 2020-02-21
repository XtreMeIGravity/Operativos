import subprocess
from pathlib import Path

path=str(Path.home())#Obtiene el path de home
print(path)
jpg=path+"/jpg"
pdf=path+"/pdf"
mp4=path+"/mp4"
s = subprocess.check_output(["find",path,"-type","f","-iname","*.pdf","-o","-name","*.mp4","-o","-name","*.jpg"]).decode("utf-8")
rb=[s]
rb=rb[0].split("\n")
rb.pop(len(rb)-1)
subprocess.run(["mkdir", "-p",jpg, pdf, mp4 ])
for x in rb:
    if x.find(".jpg")>=0:
        dest=jpg
    elif x.find(".mp4")>=0:
        dest=mp4
    elif x.find(".pdf")>=0:
        dest=pdf
    subprocess.run(["cp",x,dest])
subprocess.run(["tar", "-czvf", path+"/TodoJunto.tar",jpg, pdf, mp4 ])