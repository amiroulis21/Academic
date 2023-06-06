#This program takes 5 prime numbers between 0 and 50 
#from the user and calculates the sum
#If not all numbers are prime, the program
#prints an error message
#If any number is not in the specified range,
#the program will print an error message
#Written in Ruby
#Written by Andrew Miroulis
#Replit Compiler
#4/28/23


nums = [5]
print("Enter 5 prime numbers between 0 and 50 \n")
nums[0] = gets.chomp.to_i
nums[1] = gets.chomp.to_i
nums[2] = gets.chomp.to_i
nums[3] = gets.chomp.to_i
nums[4] = gets.chomp.to_i
prime = true
inRange = true
sum = 0
for num in nums
  if(num < 0 or num > 50)
    inRange = false
    print("Error: 1 or more numbers are not between 0 and 50")
    break
  end
  if (num == 1)
    prime = false
  end
  for i in 2..num/2
    if num % i == 0 or num == 1
      prime = false
      break
    end
  end
  if not prime
    print("Error: 1 or more numbers are not prime")
    break
  end
  sum += num
end
if prime and inRange
  print("Sum = " + sum.to_s)
end
  

