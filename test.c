#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
#include <stdlib.h>
#include <cjson/cJSON.h>
#include <time.h>


int main(){
    FILE* profiles;
    profiles = fopen("profiles.json","rb");
    if(profiles == NULL){
        printf("Failed to open file\n");
        exit(1);
    }

    fseek(profiles,0L, SEEK_END);
    int size = ftell(profiles);
    rewind(profiles);

    char data[size+1];
    fgets(data,size,profiles);

    sprintf(data, "%s", data);
    // printf("%s", data);
    sprintf(data, "%s%s", data, "}");


    cJSON* root = cJSON_Parse(data);
    if (root == NULL) {
        printf("Error parsing JSON data: %s\n", cJSON_GetErrorPtr());
        return 1;
    }

    cJSON* potato = cJSON_GetObjectItem(root, "potato");
    if (potato == NULL) {
        printf("Error getting 'potato' object\n");
        return 1;
    }

    cJSON* ideal_temperature = cJSON_GetObjectItem(potato, "ideal_temperature");
    if (ideal_temperature == NULL) {
        printf("Error getting 'ideal_temperature' value\n");
        return 1;
    }

    int temperature_value = ideal_temperature->valueint;
    // printf("The ideal temperature for potatoes is %d degrees Fahrenheit\n", temperature_value);

    cJSON_Delete(root);
    return 0;

    fclose(profiles); // don't forget to close the file after use







    time_t current_time = time(NULL);   // get the current time in seconds
    struct tm *local_time = localtime(&current_time);   // convert to local time

    int year = local_time->tm_year + 1900;   // years since 1900
    int month = local_time->tm_mon + 1;      // months since January (0-11)
    int day = local_time->tm_mday;           // day of the month (1-31)

    printf("Today is %04d-%02d-%02d\n", year, month, day);







    return 0;
}
