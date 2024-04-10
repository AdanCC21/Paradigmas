import random
import os

class person:
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

class bank:
    #datos bancarios
    _noCuenta=''
    _saldo=0
    _clabe=''

    def __bank_init__(self, num,_clabe):
        #Numero de cuenta
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


def Menu():
    print("Bienvenido al CimaBanck")
    print("Porfavor seleccione una opcion")
    print("1.-Iniciar sesion\t2.-Registrarse")

def registrar():
    os.system('cls')
    print("Favor de ingresar los datos")
    
    tname=input("Nombre")
    tapp=input("Apellido paterno")
    tapm=input("Apellido Materno")
    os.system('cls')

    print('Fecha de nacimiento')
    tday=input("Dia")
    tmonth=input("Mes")#metodo de validacion para solo numeros
    tyear=input("Year")
    persona1=person(tname,tapp,tapm,tday,tmonth,tyear)
    return persona1


#--------------------------MAIN---------------------------

op=1 #Variable para el ciclo
persona1=person("","","","","","")
persona1=registrar()
print(persona1._name)


# while op!=0: #ciclo del usuario
#     Menu()
#     op=int(input())

    



