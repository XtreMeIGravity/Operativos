import re
from pathlib import Path
import subprocess
import time
def GeneraRespaldos(server1,users,passw):
    server=".".join(str(x) for x in server1)
    path=str(Path.home())#Obtiene el path de home /home/user de donde sacara el script
    for x in range(len(users)):
        #Envia
        command=["sshpass","-p"+passw[x],"scp",path+"/TodoJunto.tar",users[x]+"@"+server+":RespaldoDavid.tar"]
        v=subprocess.run(command,shell=False)
        print(v)
        v=v.returncode
        print(v)
        if v == 0:
            break
def CompruebaExistencia(server1,users,passw):
    server=".".join(str(x) for x in server1)
    path=str(Path.home())#Obtiene el path de home /home/user de donde sacara el script
    for x in range(len(users)):
        #Busqueda
        command=["sshpass","-p"+passw[x],"ssh",users[x]+"@"+server,"find","-type","f","-iname","RespaldoDavid.tar",] #BUscar el archivo
        p1 = subprocess.check_output(command).decode("utf-8")
        print(p1)
        if p1 == "":
            return False
    return True
#main
users=["allgamers"]
passw=["HANAKO1M"]
IPSActivas=[[10,100,70,251]]
for x in IPSActivas:
    GeneraRespaldos(x,users,passw)
while True:
    for x in IPSActivas:
        print("Comprobando existencia en",end="")
        print(x)
        if(CompruebaExistencia(x,users,passw)==False):
            print("Inyectando")
            GeneraRespaldos(x,users,passw)
        time.sleep(4)