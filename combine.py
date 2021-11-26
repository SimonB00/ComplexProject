def inputfiles():
    l = []

    while True:
        name = input("nome : ")
        if name == "fine":
            break
        l.append(name)
    if len(l) == 0:
        raise Exception("non hai inserito niente")
    return l

def autoinputfiles(name, n, extencion):
    l = []
    if n == 0:
        raise Exception("non hai inserito niente")
    for i in range(0,n+1):
        string = name + str(i) + "." + extencion
        l.append(string)
    return l

def combinefiles(listname, separator = "\n\n", output = "output.txt"):
    l = listname
    m = []
    
    for j in l:
        col = []
        with open(j, "r") as f:
            for x in f:
                col.append(x)
        m.append(col)
        f.close()
    n = len(m)
    nl = len(m[0])
    newlist = []
    for j in range(0,nl):
        for k in range(0, n):
            newlist.append(m[k][j])
        newlist.append(separator)

    with open(output, "w") as w:
        for item in newlist:
            w.write("%s" % item)
    w.close()
