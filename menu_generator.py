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
             print("More.")
             branches.append(name)

         if(int(depth)<int(last_depth)):
              print("Diff:"+str(int(last_depth)-int(depth)))
              print("Less.")
              for i in range(int(last_depth)-int(depth)):
                   branches.pop()
              #depth=str(int(depth)-int(last_depth)-int(depth));
              #branches.pop()




         print(prev_node+"."+"node_next=&"+name+";")
         print(name+"."+"node_prev=&"+prev_node+";")

         prev_node=name
         if(depth!=last_depth):
             #print(depth)
             last_depth=depth;
             prev_node="null"
             print("####Changed depth####")

         if(int(depth)==int(last_depth)):

             print("Same.")
             branches.pop()
             branches.append(name)

         print(branches)
         
         structure.append(branches[:])

for st in structure:
    print(st)
