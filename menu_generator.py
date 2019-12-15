import sys
print("\n// Generated using menu generator v1.1 (C) Grzegorz Gajewski Industries")
config = open("menu.conf", "r").read()
print("\n//Generating nodes 'Objects' and setting up names:")
nodes=[]
sets = []

last_depth = "-1";
prev_node = "null"
higher_lord = 0;
branches=[]
nodes_origin = []
structure = []
for line in config.split("\n"):
     if len(line)>0:
         name=line.replace(":", "").replace(" ", "")
         if("|" in name):
             name=name.split("|")[0]
         
         nodes_origin.append(name)
         fname = str(name+"_"+str(nodes_origin.count(name)));
         nodes.append(fname)

         print("TNODE "+fname+";")
         print(fname+".title=\""+name+"\";")
         depth = (str(line.count(" ")/4))


         if(int(depth)>int(last_depth)):
             #print("More.")
             branches.append(fname)

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
             branches.append(fname)

         #print(branches)

         structure.append(branches[:])

highest=0;
#print("#######################SORTED#########################")

print("\n//Generating menu node structure:")
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
            #print(st)

j=0;

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
                #print(st1)
                tmp.append(n2)
    tmp2 = tmp[:]
    tmp2.sort()
    if(not tmp2 in done):
        done.append(tmp2[:])
        mini_groups.append(tmp[:])

for g in mini_groups:
    #print(g)
    #print(g[0]+".node_prev=&null;")
    for node in g:
        try:
            if(g.index(node)+1>len(g)):
                raise Exception;
            print(node+".node_next=&"+g[g.index(node)+1]+";")
        except Exception as e:
            print(node+".node_next=&"+""+"null;")
            #print(str(e))

        try:
            if(g.index(node)-1<0):
                raise Exception;
            print(node+".node_prev=&"+g[g.index(node)-1]+";")
        except:
            print(node+".node_prev=&"+"null"+";")


has_next=[]
has_prev=[]
print("\n //Generating menu branch structure:")
for node in nodes:
    longest=[]

    for st in sorted:
        if (node in st):
            if len(st)>len(longest):
                longest=st[:]
    #print(longest)
    try:
        if(longest.index(node)+1>len(longest)):
            raise Exception;
        print(node+".branch_next=&"+longest[longest.index(node)+1]+";")
    except Exception as e:
        print(node+".branch_next=&"+""+"null;")
        #print(str(e))

    try:
        if(longest.index(node)-1<0):
            raise Exception;
        print(node+".branch_prev=&"+longest[longest.index(node)-1]+";")
    except:
        print(node+".branch_prev=&"+"null"+";")
