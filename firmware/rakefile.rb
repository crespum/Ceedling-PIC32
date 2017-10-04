require 'ceedling'

ENV['HARMONY_ROOT'] = "/opt/microchip/harmony/v1_11/"
ENV['COMPILER_ROOT'] = "/opt/microchip/xc32/v1.43/"
ENV['MPLABX_ROOT'] = "/opt/microchip/mplabx/v3.61/"

Ceedling.load_project

task :default => %w[ test:all release ]

desc "Convert the output binary to a hex file"
task :convert => :release do
  elf_file = "build/release/#{RELEASE_BUILD_OUTPUT}"
  cmd = "#{ENV['COMPILER_ROOT']}bin/xc32-bin2hex #{elf_file}.elf"
  puts "Generating #{RELEASE_BUILD_OUTPUT}.hex..."
  puts cmd
  sh cmd
end

desc "Program the PIC"
task :program => :convert do
  hex_file = "build/release/#{RELEASE_BUILD_OUTPUT}.hex"
  cmd = "#{ENV['MPLABX_ROOT']}mplab_ipe/ipecmd.sh -P#{ENV['MCU']} -TPPK3 -M -OL -F#{hex_file}"
  puts "Programming #{RELEASE_BUILD_OUTPUT}.hex..."
  puts cmd
  sh cmd
end