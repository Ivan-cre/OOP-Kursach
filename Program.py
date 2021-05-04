from tkinter import*
#           //// Conversion from binary on decimal ////

def Get(): # function for radiobutton
    n=int(ent.get())
    if my_k.get()==0: # first radiobutton  
        b=str(n)
        c=int(b,2)
        label['text']= str(c)
    elif my_k.get()==1: 
        b= ''
        while n>0:
            b = str(n%2)+b
            n = n//2
        label['text']= b



def red():
    my_okno['bg']='#DC143C'
    r1['bg']='#DC143C'
    r2['bg']='#DC143C'
    label['bg']=''
    label1['bg']='#8B0000'
    my_a1['bg']='#FF0000'
    my_a2['bg']='#FF0000'

def blue():
    my_okno['bg']='#94dee2'
    r1['bg']='#a4e6f4'
    r2['bg']='#a4e6f4'
    label['bg']='#a4e6f4'
    label1['bg']='#6998a3'
    my_a1['bg']='#a4e6f4'
    my_a2['bg']='#a4e6f4'

def silver():
    my_okno['bg']='#c0c0c0'
    r1['bg']='#f0f0f0'
    r2['bg']='#f0f0f0'
    label['bg']='#f0f0f0'
    label1['bg']='#f0f0f0'
    my_a1['bg']='#f0f0f0'
    my_a2['bg']='#f0f0f0'

def green():
    my_okno['bg']='#58827e'
    r1['bg']='#4b6856'
    r2['bg']='#4b6856'
    label['bg']='#adbda3'
    label1['bg']='#4b6856'
    my_a1['bg']='#4b6856'
    my_a2['bg']='#4b6856'

def black():
    my_okno['bg']='#303032'
    r1['bg']='#dcdbe1'
    r2['bg']='#dcdbe1'
    label['bg']='#f1f2f2'
    label1['bg']='#dcdbe1'
    my_a1['bg']='#dcdbe1'
    my_a2['bg']='#dcdbe1'



def Her():
    label['text']= ' '
    ent.delete(0, END)

my_okno=Tk()
my_okno.geometry('700x430+150+125')
label1=Label(my_okno,text='D E ? ш и ф р а т о р',width=100,height=2,bg="#8B0000",font="30")
label = Label(my_okno,text='',width=48,height=3 ,bg="#F08080",font=15)
label.place(x=75,y=75)
label1.pack()
my_okno.maxsize(width=700,height=430)
my_okno.minsize(width=700,height=430)
 
mainmenu = Menu(my_okno)
my_okno.config(menu=mainmenu) 
BGG = Menu(mainmenu,tearoff=0, bg="sky blue",font=("Times", 10))
mainmenu.add_cascade(label="Color", menu=BGG) 


BGG.add_command(label="red",command=red)
BGG.add_command(label="blue",command=blue)
BGG.add_command(label="green",command=green)
BGG.add_command(label="silver",command=silver)
BGG.add_command(label="black",command=black)



my_okno['bg']='#DC143C' # color main window
my_okno.title("ДЕШИФРАТОР")
ent=Entry(my_okno,width=32,bg='white', font=15,textvariable='Hui')
ent.place(x=249,y=182)

my_k=BooleanVar() # tkinter
my_k.set(0) # bool values 
r1=Radiobutton(text="Двійковий",variable=my_k,value=0,bg='#DC143C',font=10) # create radiobutton №1
r2=Radiobutton(text="Десятковий",variable=my_k,value=1,bg='#DC143C',font=10)
r1.place(x=75,y=180)
r2.place(x=75,y=255)

my_a1=Button(my_okno,text="Перевести",width=47,height=2,background="#FF0000",font="10",command=Get)
my_a1.place(x=75,y=320)
my_a2=Button(my_okno,text='Delete',width=31,height=0,background="#FF0000",bd=3,font="10",command=Her)
my_a2.place(x=250,y=250)

my_okno.mainloop()
from os import system
system("pause")

