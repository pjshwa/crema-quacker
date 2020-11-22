require "bundler/gem_tasks"
require 'rake/extensiontask'
require 'rake/testtask'

Rake::ExtensionTask.new("quacker") do |extension|
  extension.lib_dir = "lib/quacker"
end

Rake::TestTask.new do |t|
  t.libs << 'test'
end

desc "Run tests"
task :default => :test
