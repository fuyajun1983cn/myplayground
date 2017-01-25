#!/usr/bin/env ruby
#coding: utf-8

puts "Hello, World"

puts "Hens: #{25 + 30 / 6}"

puts "." * 6

puts %q{
     这是一个测试
     这是多行字符串
     这只是测试而已
}

#print "How old are you?"
#age = gets.chomp.to_i
#puts "I'm #{age}"


first, second, third = ARGV
puts "#{first}, #{second}, #{third}"

fruits = ['apple', 'orange', 'pears', 'apricots']
change = [1, 'pennis', 2, 'dimes', 3, 'quaters']

fruits.each do |fruit|
  puts "a fruit type : #{fruit}"
end

change.each {|i| puts "I got #{i}"}
