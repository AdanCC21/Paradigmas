from Person import Person
from Bank import Bank
import platform

import random
import time
import os

system=platform.system()

"""Cosas que faltan
    1.-Restar dinero cuando haces una transaccion
    2.-Validar los datos de entrada
    3.-Quizas una transaccion por medio de clabe`
"""



"""-------------------------------------Funciones--------------------------------------"""

def clear():
    if system == "Linux":
        os.system("clear")
    elif system == "Windows":
        os.system("cls")

def pause():
    if system == "Linux":
        input()
    elif system == "Windows":
        os.system("pause")


"""-----------MENU----------"""
def MenuLogin():
    print("\tBienvenido al CimaBanck")
    print(f"{'Porfavor seleccione una opcion':>35}\n")
    print("1.-Iniciar sesion\t\t2.-Registrarse\t\t0.-Salir")

def MenuMain():
    # print("Bienvenido",PerBase._name)
    print("Que desea realizar hoy?")
    print("1.-Ver saldo actual\t2.-Transaccion\t3.-Depositar\t4.-Retirar\t0.-Salir")
    op=int(input())
    return op

"""-------Documentos--------"""
#Depositar
def depTxt(user):
    dirActual=os.path.dirname(os.path.realpath(__file__))
    dirReg=os.path.join(dirActual,"reg")
    dirReg=os.path.join(dirReg,'cuentas.txt')

    with open(dirReg, "r+") as doc:
        # Leer todas las líneas del archivo
        lines = doc.readlines()
        
        # Buscar la línea que quieres sobrescribir
        for i, line in enumerate(lines):
            tUser = line.strip().split(" ")
            if tUser[0] == user.name and tUser[1] == user.getPas():
                # Construir la nueva línea con los datos actualizados
                new_line = " ".join([
                    user.name, user.getPas(), user.__noCuenta, user.__clabe, str(user.saldo),
                    user.app, user.apm, str(user.day), str(user.month), str(user.year),
                    user.mail, str(user.numPhone)
                ]) + '\n'
                
                # Sobrescribir la línea en la lista de líneas
                lines[i] = new_line
                break  # Romper el bucle una vez que se haya encontrado la línea

        # Retroceder al principio del archivo y sobrescribir todas las líneas
        doc.seek(0)
        doc.writelines(lines)

#Transferir
def traTxt(user,noCuenta,amount):

    #obtener direccion actual y construir la ruta
    dirActual=os.path.dirname(os.path.realpath(__file__))
    dirReg=os.path.join(dirActual,"reg")
    dirReg=os.path.join(dirReg,'cuentas.txt')

    bandFound=0
    with open(dirReg, "r+") as doc:
        # Leer todas las líneas del archivo
        lines = doc.readlines()
        
        #Usuario a transferir
        # Buscar la línea que quieres sobrescribir
        for i, line in enumerate(lines):
            tUser = line.strip().split(" ")
            if noCuenta== tUser[2]:
                tSaldo=float(tUser[4])+amount

                # Construir la nueva línea con los datos actualizados
                new_line = " ".join([
                    tUser[0], tUser[1], tUser[2], tUser[3], str(tSaldo),
                    tUser[5], tUser[6], tUser[7], tUser[8], tUser[9],
                    tUser[10], tUser[11]
                ]) + '\n'
                
                # Sobrescribir la línea en la lista de líneas
                lines[i] = new_line
                bandFound=1
                
                #Usuario base
                #Reducir saldo y escribirlo
                usuarioCount=user.__noCuenta
                for i, line in enumerate(lines):
                    tUser = line.strip().split(" ")
                    if usuarioCount== tUser[2]:
                        #Restar saldo a transferir
                        tSaldo=user.saldo
                        new_line = " ".join([
                            tUser[0], tUser[1], tUser[2], tUser[3], str(tSaldo),
                            tUser[5], tUser[6], tUser[7], tUser[8], tUser[9],
                            tUser[10], tUser[11]
                        ]) + '\n'
                        
                        lines[i] = new_line
                        bandFound=1
                        break
        if bandFound==0:
            print("Cuenta no encontrada")
            pause()

        # Retroceder al principio del archivo y sobrescribir todas las líneas
        doc.seek(0)
        doc.writelines(lines)

#Registrar usuario en el txt
def createTxt(user):
    #Obtener direccion actual del main
    dirActual=os.path.dirname(os.path.realpath(__file__))

    #Moverse a la carpeta registros y juntarla a la ruta de dirActual
    dirReg=os.path.join(dirActual,"reg")

    #Si no existe registros, la creara
    if not os.path.exists(dirReg):
        os.makedirs(dirReg)

    #Construimos la ruta
    docName=os.path.join(dirReg,"cuentas.txt")

    tPas=user.getPas()

    with open(docName,'a') as doc:
        doc.write(user.name + " ")
        doc.write(tPas + " ")

        doc.write(user.__noCuenta + ' ')
        doc.write(user.__clabe + ' ')
        doc.write(str(user.saldo) + ' ')
    
        doc.write(user.app + ' ')
        doc.write(user.apm + ' ')
        doc.write(str(user.day) + ' ')
        doc.write(str(user.month) + ' ')
        doc.write(str(user.year) + ' ')
        doc.write(user.mail + ' ')
        doc.write(str(user.numPhone) + '\n')

#Iniciar sesion
def readFile(name,pas):
    dirReg= folderName()
    bandFound=0
    with open (dirReg, "r") as doc:
        for line in doc:
            tUser=line.strip().split(" ")
            if tUser[0] == name and tUser[1]==pas:
                bandFound=1
                break

        if bandFound==0:
            print("No encontrado")
            pause()
            return None
        elif bandFound==1:
            tName=tUser[0]
            tPass=tUser[1]
            
            tCuenta=tUser[2]
            tClabe=tUser[3]
            tSaldo=tUser[4]
            
            tApp=tUser[5]
            tApm=tUser[6]
            tDay=tUser[7]
            tMonth=tUser[8]
            tYear=tUser[9]
            tMail=tUser[10]
            
            tPhone=tUser[11]
            tuser = Bank(tName,tApp,tApm,tDay,tMonth,tYear,tMail,tPhone,tPass)
            tuser.__noCuenta=tCuenta
            tuser.__clabe=tClabe
            tuser.saldo=float(tSaldo)
            
            return tuser

"""---------Registro----------"""
def registro():
    clear()
    print("Bienvenido al sistema de registro\n","Porfavor ingrese los datos que se piden")
    
    while True:
        tName=input("Nombre de Usuario\n")
        usado=validName(tName)
        if usado == False:
            break

    tApp=input("Apellido Paterno\n")
    tApm=input("Apellido Materno\n")

    clear()
    print("Fecha de nacimiento")
    while True:
        tDay = input("Ingrese su día de nacimiento (1-31): ")
        if tDay.isdigit():
            tDay = int(tDay)
            if 1 <= tDay <= 31:
                break
            else:
                print("Por favor, ingrese un número entre 1 y 31.")
        else:
            print("Por favor, ingrese solo dígitos.")

    
    tMonth=0
    while True:
        print("ingrese el mes")
        tMonth=int(validNum(tMonth))
        if tMonth >=1 and tMonth <=12: 
            break
        else:
            print("Ingrese un mes valido")
        
            
    while True:
        tYear=input("Año\n")
        if tYear.isdigit():
            tYear=int(tYear)
            break
        else:
            print("Ingrese un año valido")


    clear()
    print("Informacion de contacto")
    tMail=input("Correo\n")
    
    while True:
        tPhone=input("Numero de celular\n")
        if tPhone.isdigit():
            tPhone=int(tPhone)
            break
        else:
            print("Ingrese un numero de celular valido")


    while True:
        print("Escriba su contraseña")
        tPass=input("Contraseña\n")
        print("Confirmar Contraseña")
        temp=input()
        if temp == tPass:
            break
        else:
            print("Las contraseñas no concuerdan\n")
    

    clear()
    user= Bank(tName,tApp,tApm,tDay,tMonth,tYear,tMail,tPhone,tPass)
    user.__noCuenta=user.genCuenta()
    user.__clabe=user.genClabe()
    print("Usuario registrado correctamente")
    print("Su cuenta es",user.__noCuenta,"\nSu CLABE es",user.__clabe,"\nY su saldo actual es",user.saldo,"")
    pause()
    
    return user


"""---------Validacion----------"""
def validNum(num):
    while True:
        num=input()
        if num.isdigit():
            return num
        else:
            print("Ingrese un numero valido")

def folderName():
    dirActual=os.path.dirname(os.path.realpath(__file__))
    #Moverse a la carpeta registros y juntarla a la ruta de dirActual
    dirReg=os.path.join(dirActual,"reg")
    dirReg=os.path.join(dirReg,'cuentas.txt')
    return dirReg

#Verificacion de nombre
def validName(name):
    directorio=folderName()
    bandFound=False
    with open(directorio, "r") as doc:
        for line in doc:
            tUser=line.strip().split(" ")
            if tUser[0] == name:
                bandFound=True
                break
    if bandFound==True:
        print("Nombre ocupado, porfavor intente de nuevo")
        pause()
        return True
    else:
        return False
        


"""-------------------------------------MAIN---------------------------------------"""
bandOp=False

"""Inicio de sesion"""
while bandOp!=True: #ciclo de inicio de sesion
    op=1
    ins=False
    
    clear()
    MenuLogin()
    op=int(input())
    
    if op == 1 and ins == False: #Iniciar sesion
        while ins == False:
            print("Para salir ingrese 0")
            print("ingrese su nombre")
            name=input()
            if name=='0':
                ins=True
            else:
                print("ingrese su contraseña")
                pas=input()
                if pas == '0':
                    ins=True
                else:
                    user= readFile(name,pas)
                    if user != None:
                        if user.name == name and user.getPas() == pas:
                            print("Inicio exitoso")
                            pause()
                            ins=True
                            bandOp=True
                        else:
                            print("Datos incorrectos")
                            pause()
                clear()
            
    elif op == 2: #Registrar nuevo usuario
        user = registro()
        createTxt(user)
    elif op == 0:
        print("Adiooos")
        break

"""Dentro del programa"""
if bandOp == True:
    bandSesion=False

    while bandSesion !=True:
        clear()
        op=MenuMain()
        # print("1.-Ver saldo actual\t2.-Transaccion\t3.-Depositar\t4.-Retirar\t0.-Salir")
        if op == 1:
            user.viewSaldo()
        
        elif op == 2:
            print("Transaccion")
            print("A que cuneta desea transferir")
            tCuenta=input()
            
            print("Cuanto desea transferir: ")
            tAmount=float(0)
            tAmount=float(validNum(tAmount))


            if user.saldo < tAmount:
                print("Lo lamento, no cuenta con el saldo suficiente")
                pause()
            else:
                user.saldo-=tAmount
                traTxt(user,tCuenta,tAmount)
        
        elif op == 3:
            user.depositar()
            depTxt(user)
            pause()
        
        elif op==4:
            user.retirar()
            depTxt(user)
            pause()
        
        elif op == 0:
            print("Seguro que quieres salir?\n1.-Cancelar\t2.-Continuar")
            op=int(input())
            if op == 2:
                bandSesion=True


