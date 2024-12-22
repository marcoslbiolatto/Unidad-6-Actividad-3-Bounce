#include <SFML/Graphics.hpp>
#include <iostream>

const float gravedad = 981.0f;  // Aceleración de la gravedad en píxeles por segundo al cuadrado
const float velocidadReboteConstante = -300.0f;  // Velocidad constante de rebote en píxeles por segundo

int main() {
    // Crear la ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Caída de Esfera");

    // Crear la esfera
    sf::CircleShape sphere(50.0f);  // Radio de 50 píxeles
    sphere.setFillColor(sf::Color::Green);
    sphere.setPosition(window.getSize().x / 2 - sphere.getRadius(), 0);  // Posicionar la esfera en la parte superior central

    // Inicializar variables de movimiento
    float velocidadY = 0.0f;

    // Reloj para gestionar el tiempo
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Calcular el tiempo transcurrido
        sf::Time deltaTime = clock.restart();
        float dt = deltaTime.asSeconds();

        // Aplicar gravedad
        velocidadY += gravedad * dt;

        // Actualizar la posición de la esfera
        sphere.move(0, velocidadY * dt);

        // Si la esfera toca el suelo
        if (sphere.getPosition().y + sphere.getRadius() * 2 >= window.getSize().y) {
            sphere.setPosition(sphere.getPosition().x, window.getSize().y - sphere.getRadius() * 2);
            velocidadY = velocidadReboteConstante;  // Rebote con velocidad constante
        }

        // Dibujar la esfera
        window.clear();
        window.draw(sphere);
        window.display();
    }

    return 0;
}
