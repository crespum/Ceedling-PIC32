require 'ceedling'
Ceedling.load_project

task :default => %w[ test:all release ]

desc "Convert the output binary to a hex file"
task :convert => :release do
  elf_file = "build/release/#{RELEASE_BUILD_OUTPUT}"
  cmd = "#{ENV['BIN2HEX']} #{elf_file}.elf"
  puts "Generating #{RELEASE_BUILD_OUTPUT}.hex..."
  puts cmd
  sh cmd
end

desc "Program the PIC"
task :program => :convert do
  hex_file = "build/release/#{RELEASE_BUILD_OUTPUT}.hex"
  cmd = "/opt/microchip/mplabx/v3.61/mplab_ipe/ipecmd.sh -P#{ENV['MCU']} -TPPK3 -M -OL -F#{hex_file}"
  puts "Programming #{RELEASE_BUILD_OUTPUT}.hex..."
  puts cmd
  sh cmd
end
