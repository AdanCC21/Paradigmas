import random
import os

class Person:
    #datos personales
    _name=''
    _app=''
    _apm=''
    _day=0
    _month=0
    _year=0
    
    def __init__(self, nombre, app, apm,day,month,year):
        self._name=nombre
        self._app=app
        self._apm=apm
        
        self._day=day
        self._month=month
        self._year=year

    #datos de cuenta
    _mail=''
    _pasword=''
    _phone=''

    def __count_init__(self, mail, pasword, phone):
        self._mail=mail
        self._pasword=pasword
        self._phone=phone

class Bank:
    #datos bancarios
    #titular Sera de la clase Person
    _noCuenta=''
    _saldo=0
    _clabe=''

    def __init__(self,titular):
        #Numero de cuenta
        self._titular=titular
        
        noCuenta4=random.randint(1000,9999)
        noCuenta8=random.randint(1000,9999)
        noCuenta12=random.randint(1000,9999)
        noCuenta16=random.randint(1000,9999)
        self._noCuenta=str(noCuenta4)+str(noCuenta8)+str(noCuenta12)+str(noCuenta16)
        
        #saldo
        self._saldo=0

        #Generar clabe por partes
        clabe3=random.randint(100,999)
        clabe6=random.randint(100,999)
        clabe17=random.randint(10000000000,99999999999)
        clabe18=random.randint(1,9)

        self._clabe=str(clabe3)+str(clabe6)+str(clabe17)+str(clabe18)
           

def registrar():
    os.system('cls')
    print("Favor de ingresar los datos")
    
    tname=input("Nombre\n")
    tapp=input("Apellido paterno\n")
    tapm=input("Apellido Materno\n")
    os.system('cls')

    print('Fecha de nacimiento')
    tday=input("Dia\n")
    tmonth=input("Mes\n")#metodo de validacion para solo numeros
    tyear=input("Year\n")

    #Pega los datos en una variable temporal
    PerBase=Person(tname,tapp,tapm,tday,tmonth,tyear)
    
    #datos de contacto
    tmail=input("Email\n")
    pas=input("Contrasena\n")
    phone=input("Phone number\n")
    perBase.__count_init__(tmail,pas,phone)
    
    print("Datos copiados\n")
    os.system("pause")

    return PerBase

def MenuLogin():
    print("\tBienvenido al CimaBanck")
    print(f'{'Porfavor seleccione una opcion':>35}\n')
    print("1.-Iniciar sesion\t\t2.-Registrarse")

#--------------------------MAIN---------------------------

#-----Inicio de sesio-----
op=1 #Variable para el ciclo
perBase=Person("","","","","","") #persona base

while op!=0: #ciclo de inicio de sesion
    os.system("cls")
    MenuLogin()
    op=int(input())

    if op ==1:
        print("\tDatos personales")
        print("Nombre :",PerBase._name, end=("\t"))
        print("Apellido paterno :",PerBase._app, end=("\t"))
        print("Apellido Materno :",PerBase._apm)
        
        print("")
        print("Fecha de nacimiento")
        print("Dia",PerBase._day,"Mes",PerBase._month,"Año",PerBase._year)

        print("")
        print("Correo",perBase._mail,"Contra",perBase._pasword,"Phone",perBase._phone)
        
        
        os.system("pause")
        op=0#una vez termine la operacion, inicamos la aplicacion
        #Iniciar sesion
    
    if op == 2:
        PerBase=registrar()
        #Una vez termine de registrarse, debera de inciar sesion

#-------------------------------------------------------------------------
def MenuMain():
    print("Bienvenido",perBase._name)
    print("Que desea realizar hoy?")
    print("1.-Ver saldo actual\t2.-Transaccion\t3.-Depositar\t4.-Retirar")
    op=int(input())
    return op

def saldo():
    print("saldo actual")
#---------------------------------------------------------------------------

BankBase=Bank(perBase)
print("clabe",BankBase._clabe,"cuenta",BankBase._noCuenta, "saldo",BankBase._saldo)
os.system("pause")

# op=1
# while(op!=0):
#     os.system("cls")
#     op=MenuMain()
    



