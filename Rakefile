require "bundler/gem_tasks"
require 'rake/extensiontask'

task :default => :spec

Rake::ExtensionTask.new("quacker") do |extension|
  extension.lib_dir = "lib/quacker"
end
