from Person import Person
import random
import os

class Bank(Person):
    __noCuenta=''
    __clabe=''
    __pas=''
    saldo=0


    def genCuenta (self):
        noCuenta4=random.randint(1000,9999)
        noCuenta8=random.randint(1000,9999)
        noCuenta12=random.randint(1000,9999)
        noCuenta16=random.randint(1000,9999)
        Cuenta=str(noCuenta4)+str(noCuenta8)+str(noCuenta12)+str(noCuenta16)
        return Cuenta

    def genClabe(self):
        __clabe3=random.randint(100,999)
        __clabe6=random.randint(100,999)
        __clabe17=random.randint(10000000000,99999999999)
        __clabe18=random.randint(1,9)
        Clabe=str(__clabe3)+str(__clabe6)+str(__clabe17)+str(__clabe18)
        return Clabe

    def __init__(self, name, app, apm, day, month, year, mail, numPhone,passwoard):
        super().__init__(name, app, apm, day, month, year, mail, numPhone)
        # if cuenta==0:
        #     self.__noCuenta = self.genCuenta()
        # else:
        #     self.__noCuenta=cuenta
        # if clabe==0:
        #     self.__clabe = self.genClabe()
        # else:
        #     self.__clabe=clabe
        # self.saldo = float(saldo)
        self.__pas=passwoard
    
    def getPas(self):
        return self.__pas
    
    def getClabe(self):
        return self.__clabe

    def viewSaldo (self):
        print("Saldo actual:",self.saldo)
        os.system("PAUSE")

    def depositar(self):
        print("Depositar")
        print("Cuanto desea depositar?")
        count=float(input())
        
        print("Usted va a depositar",count,"Esta seguro?\n1.-Cancelar\t2.-Continuar")
        op=int(input())
        if op == 2:
            self.saldo+=count
            print("Depositados",count)
        elif op ==1:
            print("Operacion cancelada")
            os.system("Pause")
    
    def retirar(self):
        print("Retirar")
        print("Cuanto desea retirar?")
        count=float(input())
        
        print("Usted va a retirar",count,"Esta seguro?\n1.-Cancelar\t2.-Continuar")
        op=int(input())
        if op == 2:
            self.saldo-=count
            print("Retirados",count)
        elif op ==1:
            print("Operacion cancelada")
            os.system("Pause")

    def transaccion(self):
        print("Transaccion")
        print("Depositar por medio de:")
        print("1.-Clabe\t2.-Numero de cuenta")
        op=int(input())

        if op == 1:
            print("Ingrese la clabe")

        if op == 2:
            print("Ingrese la numero de cuenta")



