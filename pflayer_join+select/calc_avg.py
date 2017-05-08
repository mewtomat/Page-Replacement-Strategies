import sys

strategy=str(sys.argv[1]);
file = open(strategy+"_stats.txt","rb");

instances = 0;
sum=0;
timesum=0.0;
timeinstances=0;

for line in file:
	words=line.split();
	if(len(words)>1):
		if(words[0]=="misses"):
			instances = instances + 1;
			sum = sum + int(words[2]);
		if(words[1]=="milli"):
			timeinstances = timeinstances+1;
			timesum = timesum + float(words[0]);
			# if(sys.argv[1] == "belady"):
			# 	print(str(words[0]));

print("instances= "+ str(instances) + " timeinstances= "+str(timeinstances));
print("Avg misses for "+ strategy +" = "+ str(sum/(instances*1.0)));
print("Avg time for "+ strategy +" = "+ str(timesum/(timeinstances*1.0)));