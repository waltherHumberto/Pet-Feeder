Firmware do Dispensador de Comida para Pet

Este é o README para o firmware do projeto de Dispensador de Comida para Pet, que é executado no microcontrolador ESP32. O firmware é responsável por controlar o funcionamento do dispensador, receber comandos do aplicativo e acionar o servo motor para a dispensação da comida.
Funcionalidades

    Comunicação com o aplicativo móvel para receber comandos e configurações.
    Controle do servo motor para a dispensação da comida.
    Programação de horários de alimentação.
    Monitoramento do nível de comida no recipiente (opcional).

Requisitos

    ESP32 microcontrolador.
    Ambiente de desenvolvimento ESP-IDF configurado para programar o ESP32.
    Bibliotecas necessárias para o ESP32 e servo motor instaladas.

Configuração

    No arquivo do firmware, localize a seção de configuração.
    Defina as configurações necessárias, como pinos utilizados, tempo de dispensação, etc.
    Se desejar utilizar um sensor de nível de comida, conecte-o ao ESP32 de acordo com as instruções da biblioteca.
    Compile o firmware e faça o upload para o ESP32 novamente, se necessário.

Uso

    Após a instalação do firmware no ESP32, conecte o dispositivo ao dispensador de comida para pet.
    Ligue o dispensador e aguarde a inicialização.
    Certifique-se de que o dispositivo esteja conectado à rede Wi-Fi correta.
    Abra o aplicativo móvel e siga o processo de configuração para conectar o aplicativo ao firmware.
    Configure os horários de alimentação e a quantidade de comida desejada pelo aplicativo.
    O firmware irá receber os comandos do aplicativo nos horários programados e acionar o servo motor para a dispensação da comida.
    Se o sensor de nível de comida estiver sendo utilizado, o firmware monitorará o nível de comida no recipiente e enviará notificações para o aplicativo quando estiver vazio.

Contribuição

Contribuições são bem-vindas! Se você tiver sugestões, correções de bugs ou melhorias para este firmware, fique à vontade para enviar um pull request ou abrir uma issue neste repositório.