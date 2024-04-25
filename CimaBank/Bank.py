import Person
import random

class Bank(Person):
    #datos bancarios
    #titular Sera de la clase Person
    _noCuenta=''
    _saldo=0
    _clabe=''

    def __init__(self,titular):
        #Numero de cuenta
        self._titular=titular
        
        #cuenta
        self._noCuenta= '0'
        
        #saldo
        self._saldo=0
        
        #clabe
        self._clabe= '0'

    def newUser(self,titular):
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