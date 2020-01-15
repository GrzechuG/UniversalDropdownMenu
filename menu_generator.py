import sys

if len(sys.argv)<=1:
    print("Usage: python menu_generator.py [menu.conf] [menu.h]")
    quit()

menu_conf_path = sys.argv[1]
menu_h_path  = sys.argv[2]

config = open(menu_conf_path, "r").read()
file_menu_h = open(menu_h_path, "r")

injectCode = ""
globalCode = """
TNODE *actual;
TNODE *deadEnd;

TNODE null;
"""
initCode = """
void MENU_init()
{

"""

injectCode+=("\n// Generated using menu generator v2.0 (C) Grzegorz Gajewski Industries\n")

injectCode+=("\n// Generating nodes 'Objects' and setting up names:\n")
nodes = []
sets = []

last_depth = "-1"
prev_node = "null"
higher_lord = 0
branches = []
nodes_origin = []
structure = []
actual = ""
first = 0

for line in config.split("\n"):
     if len(line) > 0:
         name = line.replace(":", "").replace(" ", "")
         if("|" in name):
             name = name.split("|")[0]

         nodes_origin.append(name)
         fname = str(name+"_"+str(nodes_origin.count(name)))
         nodes.append(fname)
         if first == 1:
             actual=fname;
             initCode += ("null"+".title = \""+"null"+"\";\n")
         first += 1
         globalCode+=("TNODE "+fname+"; \n")
         initCode += (fname+".title = \""+name+"\";\n")
         depth = (str(line.count(" ")/4))


         if(int(depth) > int(last_depth)):
             #print("More.")
             branches.append(fname)

         if(int(depth) < int(last_depth)):
             # print("Diff:"+str(int(last_depth)-int(depth)))
              #print("Less.")
              for i in range(int(last_depth)-int(depth)):
                   branches.pop()
              #depth=str(int(depth)-int(last_depth)-int(depth));
              #branches.pop()

         prev_node = name
         if(not depth == last_depth):
             #print(depth)
             last_depth = depth
             prev_node = "null"
            # print("####Changed depth####")

         if(int(depth) == int(last_depth)):

            # print("Same.")
             branches.pop()
             branches.append(fname)

         #print(branches)

         structure.append(branches[:])

highest = 0
#print("#######################SORTED#########################")

print("\n// Generating menu node structure:")
for st in structure:
    #print(st)
    if(len(st) > highest):
        highest = len(st)+4


sorted = []
for i in range(1, highest):
    j = 0
    for st in structure:

        if(len(st) == i):
            sorted.append(st[:])
            #print(st)

j = 0

mini_groups = []
done = []
for st1 in structure:
    tmp = [st1[:].pop()]

    for st2 in structure:
        if(True):
             base1 = st1[:]
             base2 = st2[:]

             n1 = base1.pop()
             n2 = base2.pop()
            # print(st1)
             if(str(base1) == str(base2) and not n1 == n2):
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
            if(g.index(node)+1 > len(g)):
                raise Exception
            initCode+=(node+".node_next = &"+g[g.index(node)+1]+";\n")
        except:
            initCode+=(node+".node_next = &"+""+"null;\n")
            #print(str(e))

        try:
            if(g.index(node)-1 < 0):
                raise Exception
            initCode+=(node+".node_prev = &"+g[g.index(node)-1]+";\n")
        except:
            initCode+=(node+".node_prev = &"+"null"+";\n")


has_next = []
has_prev = []
initCode+=("\n// Generating menu branch structure:\n")
for node in nodes:
    longest = []

    for st in sorted:
        if (node in st):
            if len(st) > len(longest):
                longest = st[:]
    #print(longest)
    try:
        if(longest.index(node)+1 > len(longest)):
            raise Exception
        initCode+=(node+".branch_next = &"+longest[longest.index(node)+1]+";\n")
    except:
        initCode+=(node+".branch_next = &"+""+"null;\n")
        #print(str(e))

    try:
        if(longest.index(node)-1 < 0):
            raise Exception
        initCode+=(node+".branch_prev = &"+longest[longest.index(node)-1]+";\n")
    except:
        initCode+=(node+".branch_prev = &"+"null"+";\n")

print("Merged code:")
initCode += "actual = &"+actual+";\n"
initCode += "deadEnd = &"+"MENU_1"+";\n"
injectCode+=globalCode+"\n //Menu structure initialization \n"+initCode+"\n}"

#print(injectCode)

print("Looking for // MENU STRUCTURE GENERATION START in menu.h...")

file_menu_h_contents = file_menu_h.read();
output_code = ""


inject_finishing = False;
for line in file_menu_h_contents.split("\n"):
    if "MENU STRUCTURE GENERATION START" in line and line.replace(" ","").startswith("//"):
        output_code+="//MENU STRUCTURE GENERATION START\n"
        output_code+=injectCode+"\n"
        inject_finishing=True

    if not inject_finishing:
        output_code+=line+"\n";

    if inject_finishing:
        if "MENU STRUCTURE GENERATION END" in line and line.replace(" ","").startswith("//"):
            inject_finishing=False;
            output_code+="//MENU STRUCTURE GENERATION END\n"

if inject_finishing == True:
    print("No 'MENU STRUCTURE GENERATION END' reached! exiting...")
    quit()

print(output_code)

print("Writing to file...")

try:
    open(menu_h_path,"w").write(output_code)
except Exception as e:
    print("Exception occured:"+str(e))
    exit(0)

print("Everything done. File "+menu_h_path+" has been updated!")
