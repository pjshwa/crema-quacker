require "crema/quacker/version"

module Crema
  module Quacker
    def quack_or_crema
      quack_response ? 'quack' : 'crema'
    end
  end
end
