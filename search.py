import os
from time import sleep

def word_search(word,file2):
        for word_in_file in file2:
            split_word=word_in_file.split()
            for search_word in split_word:
                if word==search_word:
                    return True
        return False


main_choice=int(input("""Chose what number you want
(1) search file 
(2) read file
(3) overwrite file
(4) write file
(5) create file
(6) remove file

Please enter your number. """))

sleep(1)

if main_choice==1:
    search_option=int(input("""you want to search with filename or file extention?
    (1) file name
    (2) file extension
    (3) search with word
    
    Please enter your number   """))
    sleep(0.6)
    path_option=int(input("""Chose a number below
    (1) own path
    (2) desktop
    (3) entire computer
    
    Please enter a number"""))
    sleep(0.6)
    if path_option==1:
        if search_option==1:
            nuj=(input('what file you want to search '))
            nua=(input("what drive do you want to search in?(more accuracy faster speed to load.)"))
            for (root, dirs, files) in os.walk(nua, topdown=True):
                for item in files:
                    if item.startswith(nuj):
                        print(item)
        if search_option==2:
            nuj=(input('what kind file you want to search '))
            drives=(input("what drive do you want to search in?(more accuracy faster speed to load.)"))
            for (root, dirs, files) in os.walk(drives, topdown=True):
                for item in files:
                    if item.endswith(nuj):
                        print(item)
        if search_option==3:
            word2=input("what word you want to search.")
            drives=(input("what drive do you want to search in?(more accuracy faster speed to load.)"))
            for (root, dirs, files) in os.walk(drives, topdown=True):
                for thing in files:
                     if os.path.exists(thing):
                        file2=open(thing, "r")
                        if word_search(word2, file2):
                            print(thing)    
    
    if path_option==2:
        desktop=int(input("""have you ever type your desktop path?
        (1) yes
        (2) No(it will automatically stop the program)
            
        Please enter your number"""))
        sleep(0.6)
        if desktop==1:
            if search_option==1:
                nuj=(input('what file you want to search '))
                desktopfile1=open("desktop.txt","r")
                desktopfile2=desktopfile1.read()
                for (root, dirs, files) in os.walk(desktopfile2, topdown=True):
                    for item in files:
                        if item.startswith(nuj):
                            print(item)
            if search_option==2:
                nuj=(input('what kind file extension you want to search '))
                desktopfile1=open("desktop.txt","r")
                desktopfile2=desktopfile1.read()
                for (root, dirs, files) in os.walk(desktopfile2, topdown=True):
                    for item in files:
                        if item.endswith(nuj):
                            print(item)
            if search_option==3:
                word2=input("what word you want to search.")
                desktopfile1=open("desktop.txt","r")
                desktopfile2=desktopfile1.read()
                for (root, dirs, files) in os.walk(desktopfile2, topdown=True):
                    for thing in files:
                        if os.path.exists(thing):
                            file2=open(thing, "r")
                            if word_search(word2, file2):
                                print(thing) 
                               
        if desktop==2:   
            nuo=input("what is your desktop path")
            with open('desktop.txt', 'w') as f:
                f.write(nuo)
                f.close
    
    if path_option==3:
        if search_option==1:
            nuj=(input('what file you want to search '))
            for (root, dirs, files) in os.walk("/", topdown=True):
                for item in files:
                    if item.startswith(nuj):
                        print(item)
        if search_option==2:
            nuj=(input('what kind file you want to search '))

            for (root, dirs, files) in os.walk("/", topdown=True):
                for item in files:
                    if item.endswith(nuj):
                        print(item)
        if search_option==3:
            word2=input("what word you want to search.")
            for root, dirs, files in os.walk("/", topdown=True):
                for thing in files:
                     if os.path.exists(thing):
                        file2=open(thing, "r")
                        if word_search(word2, file2):
                            print(thing)    

if main_choice==2:
    nue=(input("What file you want to read?"))
    nut = open(nue, "r")
    for nuo in nut:
        print(nuo)

if main_choice==3:
    nul=(input("Please  what you want to overtype."))
    nuh=(input("What file you want to overwrite?"))
    f = open(nuh, "w")
    f.write(nul)
    f.close()

if main_choice==4:
    nuo=(input("Please  what you want to type."))
    nuk=(input("what file you want to write?"))
    f = open(nuk, "a")
    f.write(nuo)
    f.close()

if main_choice==5:
    nug=(input("please enter file name and file extension"))
    f = open(nug, "x")

if main_choice==6:
    nuz=(input("what file you want to delete"))
    if os.path.exists(nuz):
        os.remove(nuz)
    else:
        print("The file does not exist")