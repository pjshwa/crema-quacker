require_relative 'lib/quacker/version'

Gem::Specification.new do |spec|
  spec.name          = "quacker"
  spec.version       = Quacker::VERSION
  spec.authors       = ["pjshwa"]
  spec.email         = ["pjshwa@gmail.com"]

  spec.summary       = "Quacks when it is raining in Seoul."
  spec.homepage      = "https://github.com/pjshwa/quacker"
  spec.license       = "MIT"

  spec.files         = `git ls-files -z`.split("\x0").reject do |f|
    f.match(%r{^(test|spec|features)/})
  end
  spec.extensions = %w[ext/quacker/extconf.rb]

  spec.add_development_dependency "bundler"
  spec.add_development_dependency "rake"
  spec.add_development_dependency "rake-compiler"
end
