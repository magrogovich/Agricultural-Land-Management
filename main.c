#include <stdio.h>
#include <curl/curl.h>

int main()
{
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        char url[128];
        sprintf(url, "https://api.openweathermap.org/data/2.5/weather?q=%s&appid=f25b506ac957b7f573f28dcfa939679a", "tunis");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }
}