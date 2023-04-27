# Agricultural Land Management

## Introduction
This project is created for ISSAT GAFSA. The intention of this program is to help farms in their job by giving them the best plans and treatment for their Agricultural Land for better products. The program collects data and provides information on the plant type, location, planting date, temperature, and humidity. The collected data is then used to calculate the water need of the plants.

## Installation
1. Clone the repository:
git clone https://github.com/example-user/agricultural-land-management.git

2. Install dependencies:

sudo apt-get install libcurl4-openssl-dev
sudo apt-get install libcjson-dev

3. Compile the program:

gcc -o agri agri.c -lcurl -lcjson

4. Run the program:

./agri


## Usage
1. When the program is run, it displays the program logo and collects data on the plant type, location, and planting date from the user.
2. The program then collects temperature and humidity data for the given location using the OpenWeatherMap API.
3. The collected data is displayed on the screen.
4. The program then calculates the water need of the plants and displays it on the screen.

## Contributing
Contributions to this project are welcome. If you find any bugs or want to suggest improvements, please open an issue or a pull request.


