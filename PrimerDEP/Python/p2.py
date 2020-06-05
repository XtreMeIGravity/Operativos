import re
from pathlib import Path
import subprocess
def dameIPEquipo():
    s = subprocess.check_output(["ifconfig"]).decode("utf-8")#"ifconfig" para ubuntu
    salida=[s]
    salida=salida[0].split("\n")
    salida.pop(len(salida)-1)
    #busca la palabra netmask la cual solo existe 2 veces en el string
    palabra = 'netmask'
    res = [(string)for indice, string in enumerate(salida) if palabra in string]
    #limpia el string, seleccionanado el segundo netmask puede encontrarse en el primero o tercero rara veZ
    for x in range(len(res)):
        res[x]=res[x].strip()
        if res[x].find("inet 127.0.0.1")==-1:
            IR=res[x]
            break
    IR=[IR]
    IR=IR[0].split(" ")
    return IR[1],IR[4]

def devuelveIPs(IP,MS):#Devuelve el rango en base a la mascara de subred y la ip
    #DIVIDIENDO LA IP
    IP=[IP]
    IP=IP[0].split('.')
    IP=list(map(int,IP))
    #CREANDO LA MASCARA DE SUBRED
    MS=[MS]
    MS=MS[0].split('.')
    MS=list(map(int,MS))
    #Obteniendo el host
    HOST=[]
    for x in range(4):
        HOST.insert(x,IP[x] & MS[x])
    #Obteniendo el numero de subredes
    NoRedes=1
    for x in range(4):
        if ((256+~MS[x])!=0):
            NoRedes=NoRedes*(257+~MS[x])
    #IPS
    IPS=[]
    IPSActivas=[]
    IPSNoActivas=[]
    a=b=c=0
    #Imprimiendo el rango
    for x in range(1,NoRedes-1):
        if (x%256)==0:
            c=(c+1)%256
        if (x%65536)==0:
            b=(b+1)%256
        if (x%16777216)==0:
            a=(a+1)%256
        IPS.append([HOST[0]+a,HOST[1]+b,HOST[2]+c,HOST[3]+(x%256)])
        p1 = subprocess.run(['ping','-c 1',"-w 1", '-l',"1", ".".join(str(x) for x in IPS[x-1])], stdout=subprocess.PIPE).returncode
        print(IPS[x-1],end="")
        if p1==0:
            IPSActivas.append(IPS[x-1])
            print("Check")
        else:
            IPSNoActivas.append(IPS[x-1])
            print("NO")
    return IPSActivas,IPSNoActivas

def GeneraRespaldos(server1,users,passw):
    server=".".join(str(x) for x in server1)
    path=str(Path.home())#Obtiene el path de home /home/user de donde sacara el script
    for x in range(len(users)):
        #Envia
        command=["sshpass","-p"+passw[x],"scp","./p1.py",users[x]+"@"+server+":"]
        v=subprocess.run(command,shell=False).returncode
        if v == 0:
            #Ejecuta
            command=["sshpass","-p"+passw[x],"ssh",users[x]+"@"+server,"python3 p1.py"]
            p1 = subprocess.run(command).returncode
            #Trae
            command=["sshpass","-p"+passw[x],"scp",users[x]+"@"+server+":TodoJunto.tar",path+"/Respaldos/"+server+".tar"]
            p1 = subprocess.run(command).returncode
            break

#main
users=["l123","l1234","allgamers"]
passw=["123","1234","HANAKO1M"]
IPS,MS=dameIPEquipo()
print(IPS)
print(MS)
print("Analizando ip")
IPSActivas,IPSNoActivas=devuelveIPs(IPS,MS)
#IPSActivas=[[192,168,1,70],[192,168,1,76]]
path=str(Path.home())#Obtiene el path de home /home/user
subprocess.run(["mkdir", "-p",path+"/Respaldos"])
for x in IPSActivas:
    GeneraRespaldos(x,users,passw)
print("FIN")
