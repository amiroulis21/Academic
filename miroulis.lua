-- This program asks the user if the want an area calculation
-- of a rectangle, triangle, or circle.
-- It then calls the corresponding function and takes user input
-- of certain dimensions, depending on the shape the user chose,
-- and calculates the area.
-- The program then returns to the main fucntion and prints the
-- calculated area.
-- Written in Lua
-- Written by Andrew Miroulis
-- Replit Compiler
-- 5/1/23

function main()
  print("Enter 1 to calculate the area of a rectangle,\n")
  print("or enter 2 to calculate the area of a triangle,\n")
  print("or enter 3 to calculate the area of a circle: ")
  input = io.read()
  if (input == "1")
  then rarea = rectangle()
    print(string.format("Area of your rectangle = %f", rarea))
  elseif (input == "2")
    then tarea = triangle()
    print(string.format("Area of your triangle = %f", tarea))
  elseif (input == "3")
    then carea = circle()
    print(string.format("Area of your circle = %f", carea))
  end
end

-- This function asks the user for width and height
-- and calculates the area of the rectangle.
-- It then returns that value to the main function.
-- Written in Lua
-- Written by Andrew Miroulis
-- Replit Compiler
-- 5/1/23
function rectangle()
  print ("Enter a value for width: ")
  width = io.read()
  print("Enter a value for height: ")
  height = io.read()
  return width * height
end

-- This function asks the user for base and height
-- and calculates the area of the triangle.
-- It then returns that value to the main function.
-- Written in Lua
-- Written by Andrew Miroulis
-- Replit Compiler
-- 5/1/23
function triangle()
  print ("Enter a value for base: ")
  base = io.read()
  print("Enter a value for height: ")
  height = io.read()
  return base * height / 2
end

-- This function asks the user for the radius
-- and calculates the area of the circle.
-- It then returns that value to the main function.
-- Written in Lua
-- Written by Andrew Miroulis
-- Replit Compiler
-- 5/1/23
function circle()
  print ("Enter a value for radius: ")
  radius = io.read()
  return 3.14 * math.pow(radius, 2)
end

main()
