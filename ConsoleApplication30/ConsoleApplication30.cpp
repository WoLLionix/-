#include <iostream>
#include <iomanip>

class Chessboard;

class DisplayHelper     // Клас, який містить метод для виведення шахової дошки
{
public:
    static void displayBoard(const Chessboard& board, bool isWhitePerspective);   // Статичний метод, який виводить шахову дошку
};

class Chessboard 
{
    friend class DisplayHelper;  // Оголошення дружби

private:
    char board[8][8] =         // Масив для зберігання фігур на шаховій дошці
    {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},        // Маленькі букви - білі фігури, великі букви - чорні фігури
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };

    

public:
    void display(bool isWhitePerspective) const 
    {
        DisplayHelper::displayBoard(*this, isWhitePerspective);     // Публічний метод для виведення шахової дошки
    }
};

void DisplayHelper::displayBoard(const Chessboard& board, bool isWhitePerspective) 
{
    for (int rank = isWhitePerspective ? 7 : 0; isWhitePerspective ? (rank >= 0) : (rank < 8); isWhitePerspective ? --rank : ++rank) 
    {
        std::cout << std::setw(2) << rank + 1 << " ";   // Виведення номера рядка

        for (int file = isWhitePerspective ? 0 : 7; isWhitePerspective ? (file < 8) : (file >= 0); isWhitePerspective ? ++file : --file)  // Виведення символів фігур на кожному рядку
        {
            std::cout << board.board[rank][file] << " ";
        }

        std::cout << std::endl;
    }

    std::cout << "   a b c d e f g h" << std::endl;   // Виведення літер для позначення стовпців
}

int main() 
{
    Chessboard chessboard;

    std::cout << "Chessboard from White's perspective:" << std::endl;
    chessboard.display(true);

    std::cout << "\nChessboard from Black's perspective:" << std::endl;
    chessboard.display(false);

    return 0;
}