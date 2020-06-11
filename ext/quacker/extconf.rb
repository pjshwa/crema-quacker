require 'mkmf'

have_library("curl", "curl_easy_init")
create_makefile('quacker/quacker')  # Create Makefile
