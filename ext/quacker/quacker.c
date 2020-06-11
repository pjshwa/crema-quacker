#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <ruby.h>

struct MemoryStruct {
  char *memory;
  size_t size;
};
 
static size_t
WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
  size_t realsize = size * nmemb;
  struct MemoryStruct *mem = (struct MemoryStruct *)userp;
  
  mem->memory = realloc(mem->memory, mem->size + realsize + 1);
  if(mem->memory == NULL) {
    printf("not enough memory (realloc returned NULL)\n");
    return 0;
  }
  
  memcpy(&(mem->memory[mem->size]), contents, realsize);
  mem->size += realsize;
  mem->memory[mem->size] = 0;
  
  return realsize;
}

VALUE method_quack_response(VALUE self) {
  CURL *curl_handle;
  struct MemoryStruct chunk;

  chunk.memory = malloc(1);
  chunk.size = 0;
  
  curl_global_init(CURL_GLOBAL_ALL);
  curl_handle = curl_easy_init();
  curl_easy_setopt(curl_handle, CURLOPT_URL, "http://api.openweathermap.org/data/2.5/weather?id=1835848&APPID=ddaa30ea4f531944617c179cc7c1b270");
  curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
  curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);
  curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");
  curl_easy_perform(curl_handle);

  // the json segment indicates rainy weather
  // `strstr()` returns index if substring is present
  return rb_sprintf(strstr(chunk.memory, "\"weather\":[{\"id\":5") == NULL ? "..." : "quack");
}

void Init_quacker() {
  VALUE QUACKER = rb_define_class("Quacker", rb_cObject);
  rb_define_method(QUACKER, "quack", method_quack_response, 0);
}
