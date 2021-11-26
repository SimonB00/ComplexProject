import combine as cb 

def main():
    ls = cb.autoinputfiles("Anim", 299, "dat")
    cb.combinefiles(ls, "\n\n","Animazione.dat")

main()