require 'rbconfig'
is_windows = (RbConfig::CONFIG['host_os'] =~ /mswin|mingw|cygwin/)
OUT_FILE = "./test/simulation/out.txt"
File.delete OUT_FILE if File.exists? OUT_FILE
if is_windows
	var = IO.popen("#{ENV['MPLABX_ROOT']}\\mplab_ide\\bin>mdb.bat ./test/simulation/sim_instructions.txt > " + OUT_FILE)
else
	var = IO.popen("#{ENV['MPLABX_ROOT']}mplab_ide/bin/mdb.sh ./test/simulation/sim_instructions.txt > " + OUT_FILE)
end
Process.wait
if File.exists? OUT_FILE
    file_contents = File.read OUT_FILE
    print file_contents
end
