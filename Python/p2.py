import re
import subprocess
def dameIPEquipo():
    IP="192.168.1.244"
    MS="255.255.255.0"
    return IP,MS
def devuelveIPs(IP,MS):
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
        print("%.2f"%(x*100/(NoRedes-1)))
        if (x%256)==0:
            c=(c+1)%256
        if (x%65536)==0:
            b=(b+1)%256
        if (x%16777216)==0:
            a=(a+1)%256
        IPS.append([HOST[0]+a,HOST[1]+b,HOST[2]+c,HOST[3]+(x%256)])
        p1 = subprocess.run(['ping','-c 1',"-w 1", '-l',"1", ".".join(str(x) for x in IPS[x-1])], stdout=subprocess.PIPE).returncode
        if p1==0:
            IPSActivas.append(IPS[x-1])
        else:
            IPSNoActivas.append(IPS[x-1])
    return IPSActivas,IPSNoActivas

IPS,MS=dameIPEquipo()
print(IPS)
print(MS)
IPSActivas,IPSNoActivas=devuelveIPs(IPS,MS)
for x in IPSActivas:
    print(x)