#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
#include <stdlib.h>
#include <cjson/cJSON.h>

struct agri_data {   
    char plant_type[256];
    char location[256];
    char planting_date[256];
    double temp;
    double humidity;
};


void logo(){
    printf(" ________  ________  ________  ___                 ________  ________  ________     \n");
    printf("|\\   __  \\|\\   ____\\|\\   __  \\|\\  \\               |\\   __  \\|\\   __  \\|\\   __  \\    \n");
    printf("\\ \\  \\|\\  \\ \\  \\___|\\ \\  \\|\\  \\ \\  \\  ____________\\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\|\\  \\   \n");
    printf(" \\ \\   __  \\ \\  \\  __\\ \\   _  _\\ \\  \\|\\____________\\ \\   ____\\ \\   _  _\\ \\  \\\\\\  \\  \n");
    printf("  \\ \\  \\ \\  \\ \\  \\|\\  \\ \\  \\\\  \\\\ \\  \\|____________|\\ \\  \\___|\\ \\  \\\\  \\\\ \\  \\\\\\  \\ \n");
    printf("   \\ \\__\\ \\__\\ \\_______\\ \\__\\\\ _\\\\ \\__\\              \\ \\__\\    \\ \\__\\\\ _\\\\ \\_______\\\n");
    printf("    \\|__|\\|__|\\|_______|\\|__|\\|__|\\|__|               \\|__|     \\|__|\\|__|\\|_______|\n");



    printf("\n\nthis is a project created for ISSAT GAFSA. the intend of this program is to help\nfarms in there job by giving them the best plans and treatment for there Agricultural Land for better products.\n\n");
    printf("collecting data...\n");
}

void get_json(struct agri_data ad){
    CURL *curl;
    CURLcode res;

    char url[256];
    char secKEY[] = "f25b506ac957b7f573f28dcfa939679a";
    sprintf(url, "https://api.openweathermap.org/data/2.5/weather?q=%s&appid=%s", ad.location , secKEY);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        FILE *fp;
        fp = fopen("data.json", "w");
        if (fp == NULL) {
            printf("Failed to open file\n");
        }

        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);

        fclose(fp);
    }

    FILE* file = fopen("data.json","rb");

    if (file == NULL){
        printf("error");
        exit(1);
    }

    fseek(file,0L, SEEK_END);
    int size = ftell(file);
    rewind(file);


    char data[size+1];

    fgets(data,size,file);

    sprintf(data, "%s%s", data, "}");




    cJSON *root = cJSON_Parse(data);
    if (root == NULL) {
        printf("Error parsing JSON: %s\n", cJSON_GetErrorPtr());
    }
    cJSON *main = cJSON_GetObjectItemCaseSensitive(root,"main");

    if (main == NULL) {
        printf("Error getting 'main' object\n");
        cJSON_Delete(root);
    }
    cJSON *temp = cJSON_GetObjectItemCaseSensitive(main,"temp");

    if (temp == NULL) {
        printf("Error getting 'temp' value\n");
        cJSON_Delete(root);
    }
    cJSON *humidity = cJSON_GetObjectItemCaseSensitive(main,"humidity");

    if (humidity == NULL) {
        printf("Error getting 'humidity' value\n");
        cJSON_Delete(root);
    }

    ad.temp = temp->valuedouble;
    ad.humidity = humidity->valuedouble;
    cJSON_Delete(root);
    fclose(file);


}


void get_data(){

    struct agri_data ad;

    printf("enter plant type: potato, tomato, watermelon:\n");
    scanf("%s",ad.plant_type);
    printf("enter land location:\n");
    scanf("%s",ad.location);
    printf("enter planting date:\n");
    scanf("%s",ad.planting_date);
    get_json(ad);



}




int main() {
    struct agri_data ad;

    logo();
    get_data();

    printf("Plant type: %s\n", ad.plant_type);
    printf("Location: %s\n", ad.location);
    printf("Planting date: %s\n", ad.planting_date);
    printf("Temperature: %.2f\n", ad.temp);
    printf("Humidity: %.2f\n", ad.humidity);


    return 0;

}
