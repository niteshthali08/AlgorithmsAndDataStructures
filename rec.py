def  reciprocal( N):
	d = []
	count = 0
	rem = 1%N
	while (	rem not in d and rem!= 0):
		d.append(rem)
		rem =rem *10
		rem = rem % N
		count = count + 1
	#print d
	result = str(1.0/N)
	if (rem == 0):
		print result+ '0' + ' ' + '0'	
	else:
		for index in range(len(d)):
			if d[index] == rem :
				break
		#print "index:", index
		print '0.'+ result[2:count+2] + ' ' + result[index+2: count+2]
				