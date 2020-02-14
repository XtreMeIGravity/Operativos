import subprocess
path="/home/xtreme/"
s = subprocess.check_output(["find",path,"-type","f","-iname","*.pdf","-o","-name","*.mp4","-o","-name","*.jpg"]).decode("utf-8")
rb=[s]
rb=rb[0].split("\n")
rb.pop(len(rb)-1)
for x in rb:
    print(x)
subprocess.run(["mkdir", "-p", path+"*.jpg", path+"*.pdf", path+"*.mp4" ])