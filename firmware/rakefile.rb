require 'ceedling'
Ceedling.load_project

task :default => %w[ test:all release ]
