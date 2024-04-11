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