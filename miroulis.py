#This program reads a file of numbers
#and prints the minimum and maximum values
#Written by Andrew Miroulis
#Written in Python
#Replit compiler
#4/21/23

def main():
  f = open("readnum.txt", "r")
  lines = f.readlines()
  nums = []
  
  #For loop iterates through each line
  #and appends the nums array with every
  #line without the new line character
  for line in lines:
    if line[-1] == '\n':
      nums.append(line[:-1])
    else:
      nums.append(line)
  min = int(nums[0])
  max = int(nums[0])
  
  #Loop iterates through nums and compares
  #each number to min and max and updates
  #either value accordingly
  for num in nums:
    if int(num) < min:
      min = int(num)
    elif int(num) > max:
      max = int(num)

  print("Min: " + str(min) + "\n")
  print("Max: " + str(max) + "\n")
  
  f.close()
main()