#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
#include <cjson/cJSON.h>






// int main(void) {
//     CURL *curl;
//     CURLcode res;

//     char url[256];
//     sprintf(url, "https://api.openweathermap.org/data/2.5/weather?q=%s&appid=%s", "tunis", "f25b506ac957b7f573f28dcfa939679a");
//     curl = curl_easy_init();
//     printf("%s",curl);
//     if (curl) {
//         curl_easy_setopt(curl, CURLOPT_URL, url);
//         curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
//         res = curl_easy_perform(curl);
        
//         // printf("%s",curl_easy_strerror(res));
//         // if (res != CURLE_OK) {
//         //     fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
//         // }

//         char result[] = "";
//         if (res != CURLE_OK) {
//             strcat(result, curl_easy_strerror(res));
//         }
//         // printf("%s",result);
//         cJSON *root = cJSON_Parse(curl_easy_strerror(res));
//         cJSON *coord = cJSON_GetObjectItem(root, "coord");
//         cJSON *lon = cJSON_GetObjectItem(coord, "lon");
//         cJSON *lat = cJSON_GetObjectItem(coord, "lat");
//         cJSON *main = cJSON_GetObjectItem(root, "main");
//         cJSON *temp = cJSON_GetObjectItem(main, "temp");
//         cJSON *humidity = cJSON_GetObjectItem(main, "humidity");

//         printf("Latitude: %f\n", lat->valuedouble);
//         printf("Longitude: %f\n", lon->valuedouble);
//         printf("Temperature: %.2f K\n", temp->valuedouble);
//         printf("Humidity: %d%%\n", humidity->valueint);

//         cJSON_Delete(root);

//         printf("%s",result);

//         curl_easy_cleanup(curl);
//     }


    
//     return 0;
// }
