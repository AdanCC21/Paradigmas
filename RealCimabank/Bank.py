from Person import Person
import random
import os

class Bank(Person):
    noCuenta=''
    clabe=''
    saldo=0


    def genCuenta (self):
        noCuenta4=random.randint(1000,9999)
        noCuenta8=random.randint(1000,9999)
        noCuenta12=random.randint(1000,9999)
        noCuenta16=random.randint(1000,9999)
        Cuenta=str(noCuenta4)+str(noCuenta8)+str(noCuenta12)+str(noCuenta16)
        return Cuenta

    def genClabe(self):
        clabe3=random.randint(100,999)
        clabe6=random.randint(100,999)
        clabe17=random.randint(10000000000,99999999999)
        clabe18=random.randint(1,9)
        Clabe=str(clabe3)+str(clabe6)+str(clabe17)+str(clabe18)
        return Clabe

    
    def __init__(self, name, app, apm, day, month, year, mail, numPhone,passwoard,cuenta,clabe,saldo):
        super().__init__(name, app, apm, day, month, year, mail, numPhone)
        if cuenta==0:
            self.noCuenta = self.genCuenta()
        else:
            self.noCuenta=cuenta
        if clabe==0:
            self.clabe = self.genClabe()
        else:
            self.clabe=clabe
        self.saldo = float(saldo)
        self.pas=passwoard
    

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

        



    
        

