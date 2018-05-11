require 'mkmf'

extension_name = 'quack_curl_agent'

CONFIG['LDSHARED'] << ' -lcurl'

dir_config(extension_name)       # The destination
create_makefile(extension_name)  # Create Makefile
