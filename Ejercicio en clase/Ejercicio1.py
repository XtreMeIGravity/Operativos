import re
from pathlib import Path
import subprocess
import time
def GeneraRespaldos(server1,users,passw):
    path=str(Path.home())#Obtiene el path de home /home/user de donde sacara el script
    for x in range(len(users)):
        #Envia
        command=["sshpass","-p"+passw[x],"scp",path+"/TodoJunto.tar",users[x]+"@"+server+":RespaldoDavid.tar"]
        v=subprocess.run(command,shell=False)
        print(v)
        v=v.returncode
        print(v)
        if v == 0:
            return users[x],passw[x],server
            break
def CompruebaExistencia(server,user,passw):
    #Busqueda
    command=["sshpass","-p"+passw,"ssh",user+"@"+server,"find","-type","f","-iname","RespaldoDavid.tar",] #BUscar el archivo
    p1 = subprocess.check_output(command).decode("utf-8")
    if p1 == "":
        return False
    return True
#main
users=["allgamers","lawiet"]
passw=["HANAKO1M","5Jm3Gm"]
IPSActivas=[[10,100,79,161],[10,100,67,156]]

userM=[]
passwM=[]
IPM=[]
user=""
password=""
server=""

for x in IPSActivas:
    server=".".join(str(y) for y in x)
    user,password,server=GeneraRespaldos(server,users,passw)
    userM.append(user)
    passwM.append(password)
    IPM.append(server)


while True:
    for x in range(len(userM)):
        print("Comprobando existencia en ",end="")
        print(IPM[x],userM[x],passwM[x])
        if(CompruebaExistencia(IPM[x],userM[x],passwM[x])==False):
            print("Inyectando")
            GeneraRespaldos(IPM[x],users,passw)
    time.sleep(4)