import subprocess
import time
import os

def main():
	name_descriptions = [	("recursive functionality", "recursion_test.qk"),
				("nested if/else/while functionality", "if_else_while_test.qk"),
				("boolean expression functionality", "boolean_expression_test.qk"),
				("dynamic dispatch functionality", "inheritance_walking_test.qk"),
				("math expression functionality", "math_expression_test.qk"),
				("mutual recursion functionality", "mutual_recursion_test.qk"),
				("user input functionality", "read_test.qk"),
				("string concatenation functionality", "string_operations.qk"),
				("'this' lookup functionality (this will fail)", "this_difference_test.qk")
				]

	print("Beginning test sequence...")

	os.system("make clean");
	os.system("make all");

	for description, filename in name_descriptions:
		input("Press ENTER to test " + description)
		print("Compiling " + filename)
		
		#os.system("./quack " + "DriverPrograms/" + filename)

		p = subprocess.Popen(["./quack", "DriverPrograms/" + filename], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
		stdout1, stderr1 = p.communicate()

		time.sleep(1)
		filename = filename[:len(filename)-3]
		print("Executing " + filename)
		q = subprocess.Popen(["./DriverPrograms/" + filename], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
		stdout2, stderr2 = q.communicate()
		
		
		print("Printing output from program: " + "./DriverPrograms/" + filename)
		print("\n"*2);
		
		print(stdout2)
		print("\n"*2);
if __name__ == '__main__':
	main()
