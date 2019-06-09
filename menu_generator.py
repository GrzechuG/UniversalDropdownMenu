import sys
config = open("menu.conf", "r").read()

nodes=[]
sets = []

last_depth = "-1";
prev_node = "null"
higher_lord = 0;
branches=[]

structure = []
for line in config.split("\n"):
     if len(line)>0:
         name=line.replace(":", "").replace(" ", "")
         nodes.append(name)
         print("TNODE "+name+";")
         print(name+".title="+name+";")
         depth = (str(line.count(" ")/4))


         if(int(depth)>int(last_depth)):
             #print("More.")
             branches.append(name)

         if(int(depth)<int(last_depth)):
             # print("Diff:"+str(int(last_depth)-int(depth)))
              #print("Less.")
              for i in range(int(last_depth)-int(depth)):
                   branches.pop()
              #depth=str(int(depth)-int(last_depth)-int(depth));
              #branches.pop()






         prev_node=name
         if(not depth==last_depth):
             #print(depth)
             last_depth=depth;
             prev_node="null"
            # print("####Changed depth####")

         if(int(depth)==int(last_depth)):

            # print("Same.")
             branches.pop()
             branches.append(name)

         #print(branches)

         structure.append(branches[:])

highest=0;
print("#######################SORTED#########################")
for st in structure:
    #print(st)
    if(len(st)>highest):
        highest = len(st)+4


sorted=[]
for i in range(1,highest):
    j=0;
    for st in structure:

        if(len(st)==i):
            sorted.append(st[:])
            print(st)

j=0;
print("#######################GENERATED:#########################")
mini_groups = []
done=[]
for st1 in structure:
    tmp = [st1[:].pop()]

    for st2 in structure:
        if(True):
             base1=st1[:]
             base2=st2[:]

             n1=base1.pop()
             n2=base2.pop()
            # print(st1)
             if(str(base1)==str(base2) and not n1==n2):

                tmp.append(n2)
    tmp2 = tmp[:]
    tmp2.sort()
    if(not tmp2 in done):
        done.append(tmp2[:])
        mini_groups.append(tmp[:])

for g in mini_groups:
    g.sort()
    print(g)


has_next=[]
has_prev=[]
for node in nodes:
    for st in sorted:
        if (node in st):
            #print(st)
            try:
                if not node in has_next:
                    print(node+".branch_next=&"+st[st.index(node)+1]+";")
                    has_next.append(node[:])
            except:
                pass



            try:
                if not node in has_prev:
                    print(node+".branch_prev=&"+st[st.index(node)-1]+";")
                    has_prev.append(node[:])
                #print(st.index(node))
            except:
                pass

for st in sorted:
    if not node in has_next:
        print(node+".branch_next=&null;")

    if not node in has_prev:
        print(node+".branch_prev=&null;")
