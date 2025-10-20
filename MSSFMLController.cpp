#include "MSSFMLController.h"
#include "MSSFMLView.h"
#include "rungame.cpp"

MSSFMLController::MSSFMLController(MinesweeperBoard &board, sf::RenderWindow &window, MSSFMLView &view)
        : board(board), window(window), view(view) {}


void MSSFMLController::play() {


    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(30);

    int cellWidth = 32;
    int cellHeight = 32;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                // Przeliczenie współrzędnych myszy na współrzędne pola na planszy
                int row = event.mouseButton.y / cellHeight; // cellHeight to wysokość pojedynczej komórki
                int col = event.mouseButton.x / cellWidth; // cellWidth to szerokość pojedynczej komórki

                if (event.mouseButton.button == sf::Mouse::Left) {
                    board.revealField(row, col);

                    // Sprawdzenie, czy trafiono na minę
                    if (board.getGameState() == FINISHED_LOSS) {

                        for (int row = 0; row < board.getBoardHeight(); ++row) {
                            for (int col = 0; col < board.getBoardWidth(); ++col) {
                                board.revealField(row, col);
                            }
                        }
                        window.clear();
                        view.draw(window);
                        window.display();

                        sf::sleep(sf::seconds(1)); // Możesz zmienić czas wyświetlania komunikatu

                        sf::Font font;
                        if (!font.loadFromFile("C:/Users/egors/programowanie obiektowe/saper1/saper_yahor_shved/arial_bolditalicmt.ttf")) {
                            // Obsługa błędu ładowania czcionki
                            return;
                        }

                        sf::Text lossMessage;
                        lossMessage.setFont(font);
                        lossMessage.setString("Przegrales!");
                        lossMessage.setCharacterSize(24);
                        lossMessage.setFillColor(sf::Color::Red);
                        lossMessage.setPosition(100, 100);

                        window.clear();
                        window.draw(lossMessage);
                        window.display();

                        // Zatrzymanie gry na chwilę
                        sf::sleep(sf::seconds(2)); // Możesz zmienić czas wyświetlania komunikatu
                        window.close(); // Opcjonalne zamknięcie okna po przegranej
                        rungame::start();
                    }
                }


                 else if (event.mouseButton.button == sf::Mouse::Right) {
                    board.toggleFlag(row, col);
                }
                if (board.getGameState() == FINISHED_WIN) {
                    sf::Font font;
                    if (!font.loadFromFile("C:/Users/egors/programowanie obiektowe/saper1/saper_yahor_shved/arial_bolditalicmt.ttf")) {

                        return;
                    }

                    sf::Text winMessage;
                    winMessage.setFont(font);
                    winMessage.setString("Wygrales!");
                    winMessage.setCharacterSize(24);
                    winMessage.setFillColor(sf::Color::Red);
                    winMessage.setPosition(100, 100);

                    window.clear();
                    window.draw(winMessage);
                    window.display();

                    // Zatrzymanie gry na chwilę
                    sf::sleep(sf::seconds(2)); // Możesz zmienić czas wyświetlania komunikatu
                    window.close(); // Opcjonalne zamknięcie okna po przegranej
                    rungame::start();

                }

            }

        }

        // Aktualizacja ekranu i rysowanie planszy
        window.clear();
        view.draw(window);
        window.display();
}}